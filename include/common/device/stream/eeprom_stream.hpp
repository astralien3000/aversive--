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

#ifndef EEPROM_STREAM_HPP
#define EEPROM_STREAM_HPP

#include <device/stream/random_access_stream.hpp>
#include <device/device.hpp>

//! \class EepromStream eeprom_stream.hpp <device/stream/eeprom_stream.hpp>
//! \brief Eeprom stream device.
class EepromStream : public Device, public RandomAccessStream {
public:
  //! \brief EepromStream constructor.
  //! \param name : the device's name.
  EepromStream(const char* name);
  
  //! \brief Read a character from the stream.
  //! \return The read character.
  char getValue(void);
  
  //! \brief Write a character into the stream.
  //! \param c : the character to write.
  void setValue(char c);
};

#endif//EEPROM_STREAM_HPP
