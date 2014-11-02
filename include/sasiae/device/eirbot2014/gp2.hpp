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

#ifndef SASIAE_GP2_HPP
#define SASIAE_GP2_HPP

#include "../../../common/device/eirbot2014/gp2.hpp"

#include <aversive.hpp>
#include <client_thread.hpp>
#include <sstream>

template<u8 ID>
GP2<ID>::GP2(const char* name)
  : Device(name),
    _last_val(0) {
  Aversive::init();

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
			 _last_val = val;
		       }
		       else {
			 ClientThread::instance().sendMessage(ClientThread::ERROR, "unable to parse message correctly");
		       }
		     }));

  ClientThread::instance().
    sendDeviceMessage(*this, "init");
}

template<u8 ID>
u16 GP2<ID>::getValue(void) {
  return _last_val;
}

#endif//SASIAE_GP2_HPP
