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

#ifndef SASIAE_ENCODER_HPP
#define SASIAE_ENCODER_HPP

#include "../../../common/device/eirbot2014/encoder.hpp"

#include <aversive.hpp>
#include <client_thread.hpp>

#include <sstream>

template<typename T>
void get_value_from_msg(T* dest, const char* msg) {
  long long in;
  sscanf(msg, "%lld", &in);
  *dest = (T)in;
}

template<typename T>
Encoder<T>::Encoder(const char* name, T* addr)
  : Device(name), _addr(addr) {

  Aversive::init();
  *_addr = 0;

  ClientThread::instance().
    registerDevice(*this,
		   std::function<void(char*)>([&] (char* msg) mutable -> void {
		       using namespace std;
		       string cmd;
		       long long val;
		       istringstream iss(msg);
		       
		       iss >> cmd;
		       
		       if(cmd == "value") {
			 iss >> val;
			 *_addr = val;
		       }
		       else {
			 ClientThread::instance().sendMessage(ClientThread::ERROR, "unable to parse message correctly");
		       }
		     }));

  ClientThread::instance().
    sendDeviceMessage(*this, "init");
}

template<typename T>
s32 Encoder<T>::getValue(void) {
  return *_addr;
}

template<typename T>
inline void Encoder<T>::inverse(void) {
  _inverse = !_inverse;
}

#endif//SASIAE_ENCODER_HPP
