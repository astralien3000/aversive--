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

#ifndef AVR_SCHEDULER_HPP
#define AVR_SCHEDULER_HPP

#include "../../common/system/scheduler.hpp"

#include <hardware/timer.hpp>
#include <hardware/interrupts.hpp>

struct DefaultSchedulerConfig {
  static constexpr u32 MAX_TASKS = 8;

  static constexpr u32 TIMER_ID = 0;
  static constexpr u32 TIMER_COUNTER_SIZE = 8;
  static constexpr u32 TIMER_PRESCALER = 256;

  static constexpr double TIMER_FREQUENCY = 16000000;
};


template<class Config>
Scheduler<Config>::Scheduler(void) {
  static const double SCHEDULER_FREQ = (Config::TIMER_FREQUENCY/((1 << Config::TIMER_COUNTER_SIZE) * Config::TIMER_PRESCALER));
  static const u32 SCHEDULER_GRANULARITY = (1000000 / SCHEDULER_FREQ);

  _current = 0;
  Timer<Config::TIMER_ID>::init();
  Timer<Config::TIMER_ID>::template setPrescaler<Config::TIMER_PRESCALER>();
  Timer<Config::TIMER_ID>::overflowEvent().setFunction([](void){
      Scheduler& s = Scheduler::instance();
      s._current += SCHEDULER_GRANULARITY;
      s.processTasks();
    });
  Timer<Config::TIMER_ID>::overflowEvent().start();
}

template<class Config>
inline void Scheduler<Config>::lock(void) {
  Interrupts::lock();
}

template<class Config>
inline void Scheduler<Config>::unlock(void) {
  Interrupts::unlock();
}


#endif//AVR_SCHEDULER_HPP
