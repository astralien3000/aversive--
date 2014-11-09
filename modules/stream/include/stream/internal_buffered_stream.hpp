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

#ifndef INTERNAL_BUFFERED_STREAM_HPP
#define INTERNAL_BUFFERED_STREAM_HPP

#include <device/stream/buffered_stream.hpp>
#include <container/buffer.hpp>

//! \class InternalBufferedStream internal_buffered_stream.hpp <device/stream/internal_buffered_stream.hpp>
//! \brief Internal buffered stream interface.
class InternalBufferedStream : public BufferedStream {
protected:
  //! \brief The output buffer.
  Buffer<64, char> _output;
  
  //! \brief The input buffer.
  Buffer<64, char> _input;
  
public:
  //! \brief Default constructor.
  inline InternalBufferedStream(void)
    : BufferedStream() {
  }
  
  //! \brief Copy constructor.
  //! \param s : the internal buffered stream to copy.
  inline InternalBufferedStream(const InternalBufferedStream& s)
    : BufferedStream(s), _output(s._output), _input(s._input) {
  }
  
  //! \brief Flush the output (ie: wait for the output buffer to be empty).
  inline void flushOutput(void) const {
    while(!_output.isEmpty()) {
    }
  }
  
  //! \brief Discard every data in the input buffer.
  inline void flushInput(void) {
    _mini_buffer_used = false;
    _input.flush();
  }
  
  //! \brief Read a char from the stream's input buffer.
  //! \return The read character.
  //! \warning Blocking operation if the stream's input buffer is empty.
  virtual char getValue(void);
  
  //! \brief Write a char in the stream's input buffer.
  //! \param c : the character to write.
  //! \warning Blocking operation if the stream's output buffer is full
  virtual void setValue(char c);
  
  //! \brief Return the buffers' size.
  //! \return The buffers' size.
  virtual u16 bufferSize(void) const;
  
  //! \brief Return the amout of characters waiting to be sent into the output buffer.
  //! \return The amout of characters within the output buffer.
  virtual u16 outputFreeSpace(void) const;
  
  //! \brief Return the amount of characters currently pending into the input buffer.
  //! \return The amout of characters within the input buffer.
  virtual u16 inputUsedSpace(void) const;
};

#endif//INTERNAL_BUFFERED_STREAM_HPP
