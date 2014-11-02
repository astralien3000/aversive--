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

#ifndef UART_STREAM_HPP
#define UART_STREAM_HPP

#include <base/integer.hpp>
#include <device/stream/stream.hpp>
#include <device/device.hpp>

//! \class UartStream uart_stream.hpp <device/stream/uart_stream.hpp>
//! \brief Uart stream device.
//! \param _CHANNEL : the Uart connection the stream must be bound to.
template<u8 _CHANNEL>
class UartStream : public Device, public Stream {
public:
  //! \brief The UartStream's channel.
  static const u8 CHANNEL = _CHANNEL;
  
  //! \brief UartStream constructor.
  //! \param name : the device's name.
  UartStream(const char* name);
  
  //! \brief Read a character from the stream.
  //! \return The read character.
  char getValue(void);
  
  //! \brief Write a character into the stream.
  //! \param c : the character to write.
  void setValue(char c);
};

#endif//UART_STREAM_HPP
