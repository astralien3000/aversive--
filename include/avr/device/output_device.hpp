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

#ifndef AVR_OUTPUT_DEVICE_HPP
#define AVR_OUTPUT_DEVICE_HPP

#include "../../common/device/output_device.hpp"

#include <aversive.hpp>

template<typename T>
SimpleOutputDevice<T>::SimpleOutputDevice(const char* name) : Device(name) {
  Aversive::init();
}

template<typename T>
void SimpleOutputDevice<T>::setValue(T val) {
  (void)val;
}

#endif//AVR_OUTPUT_DEVICE_HPP
