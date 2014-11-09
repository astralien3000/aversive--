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

#ifndef BINARY_STREAM_HPP
#define BINARY_STREAM_HPP

#include <device/input.hpp>
#include <device/output.hpp>
#include <base/integer.hpp>

//! \class BinaryStream binary_stream.hpp <device/stream/binary_stream.hpp>
//! \brief Abstract two-way stream with binary read and write.
class BinaryStream : public Input<char>, public Output<char> {
public:

  //! \brief Default maximum length of string read from the stream and copied into the user's buffer.
  static const u8 DEFAULT_USER_BUFFER_SIZE = 32;
  
protected:
  //! \brief User's buffer size.
  u8 _user_buffer_size = DEFAULT_USER_BUFFER_SIZE;

protected:
  //! \brief Write a string into the stream.
  //! \param str : the string to write.
  void binaryWrite(const char* str);
  
  //! \brief Write an integer as binary into the stream.
  //! \param i : the integer to write.
  void binaryWrite(const s8& i);
  
  //! \brief Write an integer as binary into the stream.
  //! \param i : the integer to write.
  void binaryWrite(const s16& i);
  
  //! \brief Write an integer as binary into the stream.
  //! \param i : the integer to write.
  void binaryWrite(const s32& i);
  
  //! \brief Write an integer as binary into the stream.
  //! \param i : the integer to write.
  void binaryWrite(const s64& i);
  
  //! \brief Write an integer as binary into the stream.
  //! \param i : the integer to write.
  void binaryWrite(const u8& i);
  
  //! \brief Write an integer as binary into the stream.
  //! \param i : the integer to write.
  void binaryWrite(const u16& i);
  
  //! \brief Write an integer as binary into the stream.
  //! \param i : the integer to write.
  void binaryWrite(const u32& i);
  
  //! \brief Write an integer as binary into the stream.
  //! \param i : the integer to write.
  void binaryWrite(const u64& i);
  
  //! \brief Read a string from the stream.
  //! \param str : the buffer to write the read string into.
  //! \param len : the maximum amount of characters to write into the given buffer.
  void binaryRead(char* str, u16 len);
  
  //! \brief Read an integer as binary from the stream.
  //! \param i : a reference to the integer to overwrite.
  void binaryRead(s8& i);
  
  //! \brief Read an integer as binary from the stream.
  //! \param i : a reference to the integer to overwrite.
  void binaryRead(s16& i);
  
  //! \brief Read an integer as binary from the stream.
  //! \param i : a reference to the integer to overwrite.
  void binaryRead(s32& i);
  
  //! \brief Read an integer as binary from the stream.
  //! \param i : a reference to the integer to overwrite.
  void binaryRead(s64& i);
  
  //! \brief Read an integer as binary from the stream.
  //! \param i : a reference to the integer to overwrite.
  void binaryRead(u8& i);
  
  //! \brief Read an integer as binary from the stream.
  //! \param i : a reference to the integer to overwrite.
  void binaryRead(u16& i);
  
  //! \brief Read an integer as binary from the stream.
  //! \param i : a reference to the integer to overwrite.
  void binaryRead(u32& i);
  
  //! \brief Read an integer as binary from the stream.
  //! \param i : a reference to the integer to overwrite.
  void binaryRead(u64& i);

protected:
  //! \brief A boolean telling whether the minibuffer is used or not.
  bool _mini_buffer_used;
  
  //! \brief The mini buffer used by nextValue method.
  char _mini_buffer;

public:
  
  //! \brief Default constructor.
  inline BinaryStream(void)
    : _mini_buffer_used(false) {
  }
  
  //! \brief Copy constructor.
  //! \param s : the stream to copy.
  inline BinaryStream(const BinaryStream& s)
    : _mini_buffer_used(s._mini_buffer_used), _mini_buffer(s._mini_buffer) {
  }

  //! \brief Write an integer into the stream.
  //! \param val : the integer to write.
  //! \return A reference to the stream.
  inline BinaryStream& operator<<(const s8& val) {
    binaryWrite(val);
    return *this;
  }
  
  //! \brief Write an integer into the stream.
  //! \param val : the integer to write.
  //! \return A reference to the stream.
  inline BinaryStream& operator<<(const s16& val) {
    binaryWrite(val);
    return *this;
  }
  
  //! \brief Write an integer into the stream.
  //! \param val : the integer to write.
  //! \return A reference to the stream.
  inline BinaryStream& operator<<(const s32& val) {
    binaryWrite(val);
    return *this;
  }
  
  //! \brief Write an integer into the stream.
  //! \param val : the integer to write.
  //! \return A reference to the stream.
  inline BinaryStream& operator<<(const s64& val) {
    binaryWrite(val);
    return *this;
  }
  
  //! \brief Write an integer into the stream.
  //! \param val : the integer to write.
  //! \return A reference to the stream.
  inline BinaryStream& operator<<(const u8& val) {
    binaryWrite(val);
    return *this;
  }
  
  //! \brief Write an integer into the stream.
  //! \param val : the integer to write.
  //! \return A reference to the stream.
  inline BinaryStream& operator<<(const u16& val) {
    binaryWrite(val);
    return *this;
  }
  
  //! \brief Write an integer into the stream.
  //! \param val : the integer to write.
  //! \return A reference to the stream.
  inline BinaryStream& operator<<(const u32& val) {
    binaryWrite(val);
    return *this;
  }
  
  //! \brief Write an integer into the stream.
  //! \param val : the integer to write.
  //! \return A reference to the stream.
  inline BinaryStream& operator<<(const u64& val) {
    binaryWrite(val);
    return *this;
  }
  
  //! \brief Write a string into the stream.
  //! \param str : the string to write.
  //! \return A reference to the stream.
  inline BinaryStream& operator<<(const char* str) {
    binaryWrite(str);
    return *this;
  }
  
  //! \brief Read an integer from the stream.
  //! \param val : a reference to the integer to overwrite.
  //! \return A reference to the stream.
  inline BinaryStream& operator>>(s8& val) {
    binaryRead(val);
    return *this;
  }
  
  //! \brief Read an integer from the stream.
  //! \param val : a reference to the integer to overwrite.
  //! \return A reference to the stream.
  inline BinaryStream& operator>>(s16& val) {
    binaryRead(val);
    return *this;
  }
  
  //! \brief Read an integer from the stream.
  //! \param val : a reference to the integer to overwrite.
  //! \return A reference to the stream.
  inline BinaryStream& operator>>(s32& val) {
    binaryRead(val);
    return *this;
  }
  
  //! \brief Read an integer from the stream.
  //! \param val : a reference to the integer to overwrite.
  //! \return A reference to the stream.
  inline BinaryStream& operator>>(s64& val) {
    binaryRead(val);
    return *this;
  }
  
  //! \brief Read an integer from the stream.
  //! \param val : a reference to the integer to overwrite.
  //! \return A reference to the stream.
  inline BinaryStream& operator>>(u8& val) {
    binaryRead(val);
    return *this;
  }
  
  //! \brief Read an integer from the stream.
  //! \param val : a reference to the integer to overwrite.
  //! \return A reference to the stream.
  inline BinaryStream& operator>>(u16& val) {
    binaryRead(val);
    return *this;
  }
  
  //! \brief Read an integer from the stream.
  //! \param val : a reference to the integer to overwrite.
  //! \return A reference to the stream.
  inline BinaryStream& operator>>(u32& val) {
    binaryRead(val);
    return *this;
  }
  
  //! \brief Read an integer from the stream.
  //! \param val : a reference to the integer to overwrite.
  //! \return A reference to the stream.
  inline BinaryStream& operator>>(u64& val) {
    binaryRead(val);
    return *this;
  }
  
  //! \brief Read a string from the stream.
  //! \param str : the buffer to write the read string into.
  //! \return A reference to the stream.
  inline BinaryStream& operator>>(char* str) {
    binaryRead(str, _user_buffer_size);
    return *this;
  }
  
  //! \brief Return the current user's buffer size used by the stream.
  //! \return The user's buffer size.
  inline u8 userBufferSize(void) const {
    return _user_buffer_size;
  }
  
  //! \brief Change the user's buffer size.
  //! \param s : the new user's buffer size.
  inline void setUserBufferSize(u8 s) {
    _user_buffer_size = s;
  }

  //! \brief Read a character from the stream.
  //! \return The read character.
  virtual char getValue(void) = 0;
  
  //! \brief Return the next value to read from the stream without removing it from the head of the stream.
  //! \return The character at the head of the stream.
  inline char nextValue(void) {
    if(!_mini_buffer_used) {
      _mini_buffer = getValue();
      _mini_buffer_used = true;
    }
    return _mini_buffer;
  }

  //! \brief Write a character into the stream.
  //! \param c : the character to write.
  virtual void setValue(char c) = 0;
};

#endif//BINARY_STREAM_HPP
