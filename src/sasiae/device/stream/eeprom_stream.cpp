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

#include <device/stream/eeprom_stream.hpp>

#include <aversive.hpp>
#include <client_thread.hpp>
#include <sstream>

EepromStream::EepromStream(const char* name) : Device(name) {

}

char EepromStream::getValue(void) {
  seek(cursor()+1);
  return 0;
}

void EepromStream::setValue(char val) {
  std::ostringstream oss;
  oss << "value " << (int)((u8)val);

  ClientThread::instance().
    sendDeviceMessage(*this, 
		      oss.str().c_str());
  seek(cursor()+1);
}
