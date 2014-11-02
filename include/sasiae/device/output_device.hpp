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

#ifndef SASIAE_OUTPUT_DEVICE_HPP
#define SASIAE_OUTPUT_DEVICE_HPP

template<typename T>
struct SimpleOutputDevicePrivateData {

};

#include "../../common/device/output_device.hpp"

#include <aversive.hpp>
#include <client_thread.hpp>

#include <sstream>

template<typename T>
SimpleOutputDevice<T>::SimpleOutputDevice(const char* name) : Device(name) {
  Aversive::init();

  ClientThread::instance().
    registerDevice(*this,
		   std::function<void(char*)>([&] (char*) mutable -> void {}));
}

template<typename T>
void SimpleOutputDevice<T>::setValue(T val) {
  std::ostringstream oss;
  oss << "value " << (int)val;

  ClientThread::instance().
    sendDeviceMessage(*this, 
		      oss.str().c_str());
}

#endif//SASIAE_OUTPUT_DEVICE_HPP
