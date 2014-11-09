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

#ifndef FORMATTED_STREAM_HPP
#define FORMATTED_STREAM_HPP

#include <device/stream/binary_stream.hpp>

//! \class FormattedStream formatted_stream.hpp <device/stream/formatted_stream.hpp>
//! \brief Abstract two-way stream with formatted read and write.
class FormattedStream : public BinaryStream {
public:
    //! \brief Represents the different ways a stream can read string.
  //! \details Word separators are space, \\t and line separators.
  //! \details Line separators are \\n, \\r and \\0.
  //! \details Default is word.
  //! \note If the stream is in binary mode, whatever the string separator might be, a string reading will completely fulfil the user's buffer.
  enum SeparatorMode {
    WORD, //!< Read string word by word.
    LINE  //!< Read string line by line.
  };

private:
  //! \brief The current way the stream read string.
  SeparatorMode _sep = WORD;
  
protected:
  //! \brief Write a formatted integer into the stream.
  //! \param i : the integer to write.
  void formattedWrite(const s8& i);
  
  //! \brief Write a formatted integer into the stream.
  //! \param i : the integer to write.
  void formattedWrite(const s16& i);
  
  //! \brief Write a formatted integer into the stream.
  //! \param i : the integer to write.
  void formattedWrite(const s32& i);
  
  //! \brief Write a formatted integer into the stream.
  //! \param i : the integer to write.
  void formattedWrite(const s64& i);
  
  //! \brief Write a formatted integer into the stream.
  //! \param i : the integer to write.
  void formattedWrite(const u8& i);
  
  //! \brief Write a formatted integer into the stream.
  //! \param i : the integer to write.
  void formattedWrite(const u16& i);
  
  //! \brief Write a formatted integer into the stream.
  //! \param i : the integer to write.
  void formattedWrite(const u32& i);
  
  //! \brief Write a formatted integer into the stream.
  //! \param i : the integer to write.
  void formattedWrite(const u64& i);

  //! \brief Read a string from the stream.
  //! \param str : the buffer to write the read string into.
  //! \param len : the maximum amount of characters to write into the given buffer.
  void formattedRead(char* str, u16 len);

  //! \brief Read a formatted integer from the stream.
  //! \param i : a reference to the integer to overwrite.
  void formattedRead(s8& i);
  
  //! \brief Read a formatted integer from the stream.
  //! \param i : a reference to the integer to overwrite.
  void formattedRead(s16& i);
  
  //! \brief Read a formatted integer from the stream.
  //! \param i : a reference to the integer to overwrite.
  void formattedRead(s32& i);
  
  //! \brief Read a formatted integer from the stream.
  //! \param i : a reference to the integer to overwrite.
  void formattedRead(s64& i);
  
  //! \brief Read a formatted integer from the stream.
  //! \param i : a reference to the integer to overwrite.
  void formattedRead(u8& i);
  
  //! \brief Read a formatted integer from the stream.
  //! \param i : a reference to the integer to overwrite.
  void formattedRead(u16& i);
  
  //! \brief Read a formatted integer from the stream.
  //! \param i : a reference to the integer to overwrite.
  void formattedRead(u32& i);
  
  //! \brief Read a formatted integer from the stream.
  //! \param i : a reference to the integer to overwrite.
  void formattedRead(u64& i);

public:
  //! \brief Default constructor.
  inline FormattedStream(void)
    : BinaryStream() {
  }
  
  //! \brief Copy constructor.
  //! \param s : the stream to copy.
  inline FormattedStream(const FormattedStream& s)
    : BinaryStream(s) {
  }

  //! \brief Return the string separator the stream currently uses.
  //! \return The current stream's string separator.
  inline SeparatorMode separatorMode(void) const {
    return _sep;
  }
  
  //! \brief Change the way the stream read strings.
  //! \param s : the new string separtor.
  inline void setSeparatorMode(SeparatorMode s) {
    _sep = s;
  }

  //! \brief Write an integer into the stream.
  //! \param val : the integer to write.
  //! \return A reference to the stream.
  inline FormattedStream& operator<<(const s8& val) {
    formattedWrite(val);
    return *this;
  }
  
  //! \brief Write an integer into the stream.
  //! \param val : the integer to write.
  //! \return A reference to the stream.
  inline FormattedStream& operator<<(const s16& val) {
    formattedWrite(val);
    return *this;
  }
  
  //! \brief Write an integer into the stream.
  //! \param val : the integer to write.
  //! \return A reference to the stream.
  inline FormattedStream& operator<<(const s32& val) {
    formattedWrite(val);
    return *this;
  }
  
  //! \brief Write an integer into the stream.
  //! \param val : the integer to write.
  //! \return A reference to the stream.
  inline FormattedStream& operator<<(const s64& val) {
    formattedWrite(val);
    return *this;
  }
  
  //! \brief Write an integer into the stream.
  //! \param val : the integer to write.
  //! \return A reference to the stream.
  inline FormattedStream& operator<<(const u8& val) {
    formattedWrite(val);
    return *this;
  }
  
  //! \brief Write an integer into the stream.
  //! \param val : the integer to write.
  //! \return A reference to the stream.
  inline FormattedStream& operator<<(const u16& val) {
    formattedWrite(val);
    return *this;
  }
  
  //! \brief Write an integer into the stream.
  //! \param val : the integer to write.
  //! \return A reference to the stream.
  inline FormattedStream& operator<<(const u32& val) {
    formattedWrite(val);
    return *this;
  }
  
  //! \brief Write an integer into the stream.
  //! \param val : the integer to write.
  //! \return A reference to the stream.
  inline FormattedStream& operator<<(const u64& val) {
    formattedWrite(val);
    return *this;
  }
  
  //! \brief Read an integer from the stream.
  //! \param val : a reference to the integer to overwrite.
  //! \return A reference to the stream.
  inline FormattedStream& operator>>(s8& val) {
    formattedRead(val);
    return *this;
  }
  
  //! \brief Read an integer from the stream.
  //! \param val : a reference to the integer to overwrite.
  //! \return A reference to the stream.
  inline FormattedStream& operator>>(s16& val) {
    formattedRead(val);
    return *this;
  }
  
  //! \brief Read an integer from the stream.
  //! \param val : a reference to the integer to overwrite.
  //! \return A reference to the stream.
  inline FormattedStream& operator>>(s32& val) {
    formattedRead(val);
    return *this;
  }
  
  //! \brief Read an integer from the stream.
  //! \param val : a reference to the integer to overwrite.
  //! \return A reference to the stream.
  inline FormattedStream& operator>>(s64& val) {
    formattedRead(val);
    return *this;
  }
  
  //! \brief Read an integer from the stream.
  //! \param val : a reference to the integer to overwrite.
  //! \return A reference to the stream.
  inline FormattedStream& operator>>(u8& val) {
    formattedRead(val);
    return *this;
  }
  
  //! \brief Read an integer from the stream.
  //! \param val : a reference to the integer to overwrite.
  //! \return A reference to the stream.
  inline FormattedStream& operator>>(u16& val) {
    formattedRead(val);
    return *this;
  }
  
  //! \brief Read an integer from the stream.
  //! \param val : a reference to the integer to overwrite.
  //! \return A reference to the stream.
  inline FormattedStream& operator>>(u32& val) {
    formattedRead(val);
    return *this;
  }
  
  //! \brief Read an integer from the stream.
  //! \param val : a reference to the integer to overwrite.
  //! \return A reference to the stream.
  inline FormattedStream& operator>>(u64& val) {
    formattedRead(val);
    return *this;
  }

  //! \brief Write a string into the stream.
  //! \param str : the string to write.
  //! \return A reference to the stream.
  inline FormattedStream& operator<<(const char* str) {
    binaryWrite(str);
    return *this;
  }

  //! \brief Read a string from the stream.
  //! \param str : the buffer to write the read string into.
  //! \return A reference to the stream.
  inline FormattedStream& operator>>(char* str) {
    formattedRead(str, _user_buffer_size);
    return *this;
  }
};

#endif//FORMATTED_STREAM_HPP
