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

#ifndef SASIAE_SERVOMOTOR_HPP
#define SASIAE_SERVOMOTOR_HPP

#include "../../../common/device/servomotor/servomotor.hpp"

#include <aversive.hpp>
#include <client_thread.hpp>
#include <sstream>

Servomotor::Servomotor(const char* name)
  : Device(name),
    _min(0), _max(0) {

  ClientThread::instance().
    registerDevice(*this,
		   std::function<void(char*)>([&] (char*) mutable -> void {}));
}

void Servomotor::setValue(u32 val) {
  std::ostringstream oss;
  double sasiae_val = 0;
  if(_min < val && val < _max) {
    sasiae_val = (((double)val) - _min)/(_max - _min);
  }
  oss << "value " << sasiae_val;

  ClientThread::instance().
    sendDeviceMessage(*this, 
		      oss.str().c_str());
}

#endif//SASIAE_SERVOMOTOR_HPP
