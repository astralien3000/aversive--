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

#ifndef AVR_PIN_HPP
#define AVR_PIN_HPP

#include "../../../common/device/other/pin.hpp"

#include <hardware/pinmap.hpp>

template<int ID>
inline Pin<ID>::Pin(const char* name) : Device(name) {}

template<int ID>
inline bool Pin<ID>::getValue(void) {
  return Pinmap::Pin<ID>::read();
}

template<int ID>
inline void Pin<ID>::setValue(bool val) {
  if(Pinmap::Pin<ID>::mode() == Pinmap::OUT) {
    Pinmap::Pin<ID>::write(val);
  }
}

template<int ID>
inline void Pin<ID>::setMode(PinMode m) {
  if(m == PinMode::OUTPUT) {
    Pinmap::Pin<ID>::setMode(Pinmap::OUT);
  }
  else {
    Pinmap::Pin<ID>::setMode(Pinmap::IN);
  }
}

#endif//AVR_PIN_HPP
