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

#ifndef GPIO_HPP
#define GPIO_HPP

#include "architecture.hpp"
#include <aversive.hpp>

template<int ID>
class Gpio {
public:
  static inline void init(void) {
    stm32::rcc::ahb1::enable::reg |=
        stm32::rcc::ahb1::enable::gpio<ID>::enable;
    Aversive::sleep(0);
  }

  template<int PID>
  class Pin {
  public:
    static inline void setModeOutput(void) {
      stm32::gpio<ID>::mode::reg =
          (stm32::gpio<ID>::mode::reg & ~stm32::gpio<ID>::mode::template pin<PID>::mask) |
          stm32::gpio<ID>::mode::template pin<PID>::output;
    }

    static inline void setModeInput(void) {
      stm32::gpio<ID>::mode::reg =
          (stm32::gpio<ID>::mode::reg & ~stm32::gpio<ID>::mode::template pin<PID>::mask) |
          stm32::gpio<ID>::mode::template pin<PID>::input;
    }

    static inline void set(void) {
      stm32::gpio<ID>::bsr::reg =
          (stm32::gpio<ID>::bsr::reg & ~stm32::gpio<ID>::bsr::template pin<PID>::mask) |
          stm32::gpio<ID>::bsr::template pin<PID>::set;
    }

    static inline void reset(void) {
      stm32::gpio<ID>::bsr::reg =
          (stm32::gpio<ID>::bsr::reg & ~stm32::gpio<ID>::bsr::template pin<PID>::mask) |
          stm32::gpio<ID>::bsr::template pin<PID>::reset;
    }
  };
};

#endif//GPIO_HPP
