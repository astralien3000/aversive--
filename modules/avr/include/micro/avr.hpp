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

#ifndef AVR_HPP
#define AVR_HPP

//! \class AVR avr.hpp <micro/avr.hpp>
//! \brief Class providing meta-data for AVR microcontrollers.
class AVR {
  //! \brief Private default constructor to prevent instanciation.
  AVR();

public:
  //! \brief Give the API's ID of the pin on the given port at the given bit.
  //! \param port : the pin's port.
  //! \param bit : the pin's bit.
  //! \return The API's ID of the requested pin.
  static inline constexpr int pin(char port, char bit) {
    return ((int) ((port >= 'j' ? port - 1 : port) - 'a')) * 8 + bit;
  }
};

#endif//AVR_HPP
