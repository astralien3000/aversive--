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

#ifndef EEPROM_HPP
#define EEPROM_HPP

#include <base/integer.hpp>
#include "architecture.hpp"

class Eeprom {
private:
  //! \brief Default Constructor (private)
  Eeprom(void);
  Eeprom(const Eeprom&);

public:
  static inline void write(u16 addr, u8 data) {
    while(REG(eeprom<0>::control) & CFG(eeprom<0>::control::write));
    REG(eeprom<0>::address) = VAL(eeprom<0>::address, addr);
    REG(eeprom<0>::data) = VAL(eeprom<0>::data, data);
    REG(eeprom<0>::control) |= CFG(eeprom<0>::control::masterwrite);
    REG(eeprom<0>::control) |= CFG(eeprom<0>::control::write);
  }
  
  static inline u8 read(u16 addr) {
    while(REG(eeprom<0>::control) & CFG(eeprom<0>::control::write));
    REG(eeprom<0>::address) = VAL(eeprom<0>::address, addr);
    REG(eeprom<0>::control) |= CFG(eeprom<0>::control::read);
    return REG(eeprom<0>::data);
  }

  static inline void read(u16 addr, u8& data) {
    data = read(addr);
  }
};

#endif//EEPROM_HPP
