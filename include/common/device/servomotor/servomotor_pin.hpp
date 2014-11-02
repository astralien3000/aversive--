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

#ifndef SERVOMOTOR_PIN_HPP
#define SERVOMOTOR_PIN_HPP

#include <device/eirbot2014/servomotor.hpp>


//! \brief A servomotor
//! \param PORT : the port (1, 2, etc) where the servo is plugged
//! \param PIN : the number of the pin (1, 2, etc)

template<u8 PORT, u8 PIN>
class ServomotorPin : public Servomotor {
public:
  ServomotorPin(const char*);

  void setValue(u32);
};



#endif//SERVOMOTOR_PIN_HPP
