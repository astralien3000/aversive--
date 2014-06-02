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

#ifndef AVR_ENCODER_HPP
#define AVR_ENCODER_HPP

#include "../../../common/device/eirbot2014/encoder.hpp"

template<typename T>
inline Encoder<T>::Encoder(const char* name, T* addr)
  : Device(name), _addr(addr), _inverse(false) {

}

template<typename T>
inline s32 Encoder<T>::getValue(void) {
  if(_inverse) {
    return -(*_addr);
  }
  else {
    return *_addr;
  }
}

template<typename T>
inline void Encoder<T>::inverse(void) {
  _inverse = !_inverse;
}

#endif//AVR_ENCODER_HPP
