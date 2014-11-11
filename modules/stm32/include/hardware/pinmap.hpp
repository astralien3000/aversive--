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

#ifndef PINMAP_HPP
#define PINMAP_HPP

#include "hardware/gpio.hpp"

class Pinmap {

public:
  enum Mode {
    IN,
    OUT
  };

  template<int ID>
  class Pin {
  private:
    static constexpr u32 GPIO_ID = ID / 16;
    static constexpr u32 PIN_ID  = ID % 16;

    typedef typename Gpio<GPIO_ID>::template Pin<PIN_ID> MyPin;

  public:
    static inline void initGpio(void) {
      Gpio<GPIO_ID>::init();
    }

    static inline void setMode(Mode mod) {
      if(mod == OUT) {
        MyPin::setModeOutput();
      }
      else {
        MyPin::setModeInput();
      }
    }

    static inline void write(bool val) {
      if(val) {
        MyPin::set();
      }
      else {
        MyPin::reset();
      }
    }

  };
};

#endif//PINMAP_HPP
