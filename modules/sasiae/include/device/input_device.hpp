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

#ifndef SASIAE_INPUT_DEVICE_HPP
#define SASIAE_INPUT_DEVICE_HPP

template<typename T>
struct SimpleInputDevicePrivateData {
  T last_in;
};

#include <device/input_device.hpp>

#include <aversive.hpp>
#include <client_thread.hpp>

template<typename T>
void get_value_from_msg(T* dest, const char* msg) {
  long long in;
  sscanf(msg, "%lld", &in);
  *dest = (T)in;
}

template<typename T>
SimpleInputDevice<T>::SimpleInputDevice(const char* name) : Device(name) {
  Aversive::init();
  _data.last_in = 0;

  ClientThread::instance().
    registerDevice(*this,
		   std::function<void(char*)>([&] (char* msg) mutable -> void {
		       char cmd[32], msg2[1000];
		       sscanf(msg, "%s %s", cmd, msg2);

		       if(strcmp(cmd, "value") == 0) {
			 get_value_from_msg(&_data.last_in, msg2);
		       }
		     }));

  ClientThread::instance().
    sendDeviceMessage(*this, "init");
}

template<typename T>
T SimpleInputDevice<T>::getValue(void) {
  return _data.last_in;
}

#endif//SASIAE_INPUT_DEVICE_HPP
