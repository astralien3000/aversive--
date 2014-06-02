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

#ifndef SASIAE_RDS_HPP
#define SASIAE_RDS_HPP

struct RdsPrivateData {};

#include "../../../common/device/eirbot2014/rds.hpp"

#include <aversive.hpp>
#include <client_thread.hpp>
#include <sstream>

Rds::Rds(const char* name, Stream &stream) : Device(name) {
  (void) stream;
  ClientThread::instance().registerDevice(*this, std::function<void(char*)>([this] (char* msg) mutable -> void {
	using namespace std;
	istringstream iss(msg);
	string cmd;
	int n;
	iss >> cmd >> n;
	
	_values.flush();
	for(int i = 0 ; i < n ; i++) {
	  Vect<2, s32> v;
	  iss >> v.coord(0) >> v.coord(1);
	  _values.append(v);
	}
      }));
}

void Rds::setMode(Mode m) {
  if(m == CARTESIAN) {
    ClientThread::instance().sendDeviceMessage(*this, "mode cartesian");
  }
  else if(m == POLAR) {
    ClientThread::instance().sendDeviceMessage(*this, "mode polar");
  }
}

List<2, Vect<2, s32> > Rds::getValue(void) {
  return this->_values;
}

#endif//SASIAE_RDS_HPP
