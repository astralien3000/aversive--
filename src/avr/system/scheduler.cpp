#include <system/scheduler.hpp>
#include <hardware/interrupts.hpp>
#include <hardware/timer.hpp>

static const int TIMER_ID = 0;

// Work around because of GCC's bug asking for "this" to be captured in lambda while you are just accessing a static method
inline Scheduler& sched_instance(void) {
  return Scheduler::instance();
}

Scheduler::Scheduler(void) {
  _data.counter = 0;
  Timer<TIMER_ID>& t = Timer<TIMER_ID>::instance();
  t.init();
  t.setPrescaler<SCHEDULER_TIMER_PRESCALER>();
  t.overflowEvent().setFunction([](void){
      Interrupts::lock();
      Scheduler& s = sched_instance();
      s._data.counter++;
      
      while(!s._data.ordered_tasks.empty()) {
	TaskRef tr = s._data.ordered_tasks.max();
	if(tr.period() == 0) {
	  // This task has been removed so let's pop it and go to the next one
	  s._data.ordered_tasks.pop();
	  continue;
	}
	else {
	  if(tr()) {
	    s._data.ordered_tasks.pop();
	    if(tr.period()) {
	      // If it was not a one-shoot task, we add it again to the heap
	      s._data.ordered_tasks.insert(tr);
	    }
	    continue;
	  }
	  else {
	    // It is not time to execute the next task yet so we can stop browsing the heap
	    break;
	  }
	}
      }
      Interrupts::unlock();
    });
  t.overflowEvent().start();
}

bool Scheduler::addTask(Task& t) {
  if(!freeSlot()) {
    return false;
  }
  
  Interrupts::lock();
  for(u16 i = 0; i < SCHEDULER_MAX_TASKS; i++) {
    if(_data.tasks[i].period() == 0) {
      _data.tasks[i] = t;
      _data.ordered_tasks.insert(TaskRef(t, &(_data.counter)));
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
