/*
    Aversive++                                                           
    Copyright (C) 2014 Eirbot                                            
                                                                         
    This program is free software: you can redistribute it and/or modify 
    it under the terms of the GNU General Public License as published by 
    the Free Software Foundation, either version 3 of the License, or    
    (at your option) any later version.                                  
                                                                         
    This program is distributed in the hope that it will be useful,      
    but WITHOUT ANY WARRANTY; without even the implied warranty of       
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the        
    GNU General Public License for more details.                         
                                                                         
    You should have received a copy of the GNU General Public License    
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include <system/scheduler.hpp>
#include <hardware/interrupts.hpp>
#include <hardware/timer.hpp>

static const int SCHEDULER_TIMER_ID = 0;

static const u32 SCHEDULER_TIMER_PRESCALER = 8;
static const u32 SCHEDULER_FREQ = (16000000/(256 * ((SCHEDULER_TIMER_PRESCALER) ? SCHEDULER_TIMER_PRESCALER : 1)));
static const u32 SCHEDULER_GRANULARITY = (1000000 / SCHEDULER_FREQ);

static const u32 SCHEDULER_COUNTER_INC = ((1024/SCHEDULER_GRANULARITY) ? 1024/SCHEDULER_GRANULARITY : 1);

// Work around because of GCC's bug asking for "this" to be captured in lambda while you are just accessing a static method
inline Scheduler& sched_instance(void) {
  return Scheduler::instance();
}

Scheduler::Scheduler(void) {
  _data.current = 0;
  Timer<SCHEDULER_TIMER_ID>::init();
  Timer<SCHEDULER_TIMER_ID>::setPrescaler<SCHEDULER_TIMER_PRESCALER>();
  Timer<SCHEDULER_TIMER_ID>::overflowEvent().setFunction([](void){
      Interrupts::lock();
      Scheduler& s = sched_instance();
      s._current += SCHEDULER_COUNTER_INC;
      s.ProcessTasks();
      Interrupts::unlock();
    });
  Timer<SCHEDULER_TIMER_ID>::overflowEvent().start();
}

bool Scheduler::addTask(Task& t) {
  if(!freeSlot()) {
    return false;
  }
  
  Interrupts::lock();
  for(u16 i = 0; i < SCHEDULER_MAX_TASKS; i++) {
    if(_data.tasks[i].period() == 0) {
      _data.tasks[i] = t;
      _data.tasks[i].setPeriod(_data.tasks[i].period()/SCHEDULER_GRANULARITY);
      _data.ordered_tasks.insert(TaskRef(_data.tasks[i], _data.current));
      Interrupts::unlock();
      return true;
    }
  }
  Interrupts::unlock();
  return false;
}

bool Scheduler::rmTask(Task& t) {
  Interrupts::lock();
  for(u16 i = 0; i < SCHEDULER_MAX_TASKS; i++) {
    if(_data.tasks[i] == t) {
      _data.tasks[i] = Task();
      Interrupts::unlock();
      return true;
    }
  }
  Interrupts::unlock();
  return false;
}

u16 Scheduler::freeSlot(void) const {
  return (u16) _data.ordered_tasks.freeSpace();
}
