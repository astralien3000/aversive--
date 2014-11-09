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

#ifndef STRING_STREAM_HPP
#define STRING_STREAM_HPP

#include <device/stream/buffered_stream.hpp>
#include <container/buffer.hpp>

//! \class StringStream string_stream.hpp <device/stream/string_stream.hpp>
//! \brief StringStream that allows an easy integer-to-string conversion or in-application pipe.
//! \warning _SIZE must be a power of 2, it is verified with an assert.
//! \param _SIZE : the number of elements the stream's buffer can handle at any given time.
template<buffer_t _SIZE>
class StringStream : public BufferedStream {
  //! \brief The internal buffer representing the stream.
  Buffer<_SIZE, char> _buffer;
  
public:
  //! \brief Default constructor.
  inline StringStream(void)
    : BufferedStream(), _buffer() {
  }
  
  //! \brief Copy constructor.
  //! \param s : the buffered stream to copy.
  inline StringStream(const StringStream& s)
    : BufferedStream(s), _buffer(s._buffer) {
  }
  
  //! \brief Read a char from the stream's buffer.
  //! \return The read character.
  //! \warning Blocking operation if the stream's buffer is empty.
  virtual char getValue(void) {
    if(_mini_buffer_used) {
      _mini_buffer_used = false;
      return _mini_buffer;
    }
    else {
      while(_buffer.isEmpty()) {
      }
      
      char c = _buffer.head();
      _buffer.dequeue();
      return c;
    }
  }
  
  //! \brief Write a char in the stream's buffer.
  //! \param c : the character to write.
  //! \warning Blocking operation if the stream's buffer is full
  virtual void setValue(char c) {
    while(!_buffer.enqueue(c)) {
    }
  }
  
  //! \brief Return the buffer's size.
  //! \return The buffer's size.
  virtual u16 bufferSize(void) const {
    return _SIZE;
  }
  
  //! \brief Return the amout of characters that can be written into the stream without blocking.
  //! \return The amout of characters writtable without blocking.
  virtual u16 outputFreeSpace(void) const {
    return _buffer.freeSpace();
  }
  
  //! \brief Return the amount of characters currently pending into the buffer.
  //! \return The amout of characters within the buffer.
  virtual u16 inputUsedSpace(void) const {
    return _buffer.usedSpace();
  }
};

#endif//STRING_STREAM_HPP
