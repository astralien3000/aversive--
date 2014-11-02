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

#ifndef BUFFERED_STREAM_HPP
#define BUFFERED_STREAM_HPP

#include <device/stream/stream.hpp>
#include <base/integer.hpp>

//! \class BufferedStream buffered_stream.hpp <device/stream/buffered_stream.hpp>
//! \brief Buffered stream interface.
class BufferedStream : public Stream {
public:
  //! \brief Default constructor.
  inline BufferedStream(void)
    : Stream() {
  }
  
  //! \brief Copy constructor.
  //! \param s : the buffered stream to copy.
  inline BufferedStream(const BufferedStream& s)
    : Stream(s) {
  }
  
  //! \brief Read a char from the stream's input buffer.
  //! \return The read character.
  //! \warning Blocking operation if the stream's input buffer is empty.
  virtual char getValue(void) = 0;
  
  //! \brief Write a char in the stream's input buffer.
  //! \param c : the character to write.
  //! \warning Blocking operation if the stream's output buffer is full
  virtual void setValue(char c) = 0;
  
  //! \brief Return the buffers' size.
  //! \return The buffers' size.
  virtual u16 bufferSize(void) const = 0;
  
  //! \brief Return the amout of characters waiting to be sent into the output buffer.
  //! \return The amout of characters within the output buffer.
  virtual u16 outputFreeSpace(void) const = 0;
  
  //! \brief Return the amount of characters currently pending into the input buffer.
  //! \return The amout of characters within the input buffer.
  virtual u16 inputUsedSpace(void) const = 0;
};

#endif//BUFFERED_STREAM_HPP
