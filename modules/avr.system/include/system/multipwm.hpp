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

#ifndef AVR_MULTIPWM_HPP
#define AVR_MULTIPWM_HPP

#include "../../common/system/multipwm.hpp"

#include <hardware/timer.hpp>

struct DefaultMultiPWMConfig {
  static constexpr u32 MAX_PINS = 8;
  
  static constexpr u32 TIMER_ID = 0;
  static constexpr u32 TIMER_COUNTER_SIZE = 8;
  static constexpr u32 TIMER_PRESCALER = 1;
  
  static constexpr double TIMER_FREQUENCY = 16000000;
  
  static constexpr u32 PERIOD = 20000;
};

template<typename Config>
MultiPWM<Config>::MultiPWM(void) {
  static constexpr u32 OVERFLOW = (1 << Config::TIMER_COUNTER_SIZE);
  static constexpr u32 OVERFLOW_FREQUENCY = Config::TIMER_FREQUENCY / (Config::TIMER_PRESCALER * OVERFLOW);
  static constexpr u32 OVERFLOW_PERIOD = 1000000 / OVERFLOW_FREQUENCY;
  
  _current = 0;
  Timer<Config::TIMER_ID>::init();
  Timer<Config::TIMER_ID>::template setPrescaler<Config::TIMER_PRESCALER>();
  Timer<Config::TIMER_ID>::overflowEvent().setFunction([]() {
      MultiPWM::instance()._current += OVERFLOW_PERIOD;
      MultiPWM::instance().process();
    });
  Timer<Config::TIMER_ID>::overflowEvent().start();
}

#endif//AVR_MULTIPWM_HPP
