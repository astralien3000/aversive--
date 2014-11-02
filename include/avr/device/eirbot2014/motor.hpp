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

#ifndef AVR_MOTOR_HPP
#define AVR_MOTOR_HPP

#include "../../../common/device/eirbot2014/motor.hpp"

#include <math/saturate.hpp>

template<typename T>
inline Motor<T>::Motor(const char* name, T* addr)
  : Device(name), _addr(addr), _inverse(false) {

}

template<typename T>
inline void Motor<T>::setValue(s32 val) {  
  if(_inverse) {
    val = -val;
  }

  (*_addr) = Math::saturate<-127, 127>(val);
}

template<typename T>
inline void Motor<T>::inverse(void) {
  _inverse = !_inverse;
}


#endif//AVR_MOTOR_HPP
