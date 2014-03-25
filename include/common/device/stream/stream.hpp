#ifndef STREAM_HPP
#define STREAM_HPP

#include <device/input.hpp>
#include <device/output.hpp>
#include <base/integer.hpp>

//! \class Stream stream.hpp <device/stream/stream.hpp>
//! \brief Abstract two-way stream with formatted and binary read and write.
//! \todo Change SepMode into Separator (or StringSeparator).
class Stream : public Input<char>, public Output<char> {
public:
  //! \brief Represents the different ways a stream can read and write data.
  //! \details Defaut is formatted.
  enum Mode {
    BINARY,   //!< Read and write data as binary.
    FORMATTED //!< Read and write formatted data.
  };
  
  //! \brief Represents the different ways a stream can read string.
  //! \details Word separators are space and \\t.
  //! \details Line separators are \\n, \\r and \\0.
  //! \details Default is word.
  //! \note If the stream is in binary mode, whatever the string separator might be, a string reading will completely fulfil the user's buffer.
  enum SepMode {
    WORD, //!< Read string word by word.
    LINE  //!< Read string line by line.
  };
  
  //! \brief Default maximum length of string read from the stream and copied into the user's buffer.
  static const u8 DEFAULT_USER_BUFFER_SIZE = 32;
  
private:
  //! \brief The current mode of the stream.
  Mode _mode = FORMATTED;
  
  //! \brief The current way the stream read string.
  SepMode _sep = WORD;
  
  //! \brief User's buffer size.
  u8 _user_buffer_size = DEFAULT_USER_BUFFER_SIZE;
  
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
  
protected:
  //! \brief A boolean telling whether the minibuffer is used or not.
  bool _mini_buffer_used;
  
  //! \brief The mini buffer used by nextValue method.
  char _mini_buffer;
  
public:
  //! \brief Default constructor.
  inline Stream(void)
    : _mini_buffer_used(false) {
  }
  
  //! \brief Copy constructor.
  //! \param s : the stream to copy.
  inline Stream(const Stream& s)
    : _mini_buffer_used(s._mini_buffer_used), _mini_buffer(s._mini_buffer) {
  }
  
  //! \brief Return the mode the stream is currently in.
  //! \return The current stream's mode.
  inline Mode mode(void) const {
    return _mode;
  }
  
  //! \brief Change the mode the stream is currently in.
  //! \param m : the new mode.
  inline void setMode(Mode m) {
    _mode = m;
  }
  
  //! \brief Return the string separator the stream currently uses.
  //! \return The current stream's string separator.
  inline SepMode sepMode(void) const {
    return _sep;
  }
  
  //! \brief Change the way the stream read strings.
  //! \param s : the new string separtor.
  inline void setSepMode(SepMode s) {
    _sep = s;
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
  
  //! \brief Write an integer into the stream.
  //! \param val : the integer to write.
  //! \return A reference to the stream.
  inline Stream& operator<<(const s8& val) {
    if(_mode == BINARY) {
      binaryWrite(val);
    }
    else if(_mode == FORMATTED) {
      formattedWrite(val);
    }
    return *this;
  }
  
  //! \brief Write an integer into the stream.
  //! \param val : the integer to write.
  //! \return A reference to the stream.
  inline Stream& operator<<(const s16& val) {
    if(_mode == BINARY) {
      binaryWrite(val);
    }
    else if(_mode == FORMATTED) {
      formattedWrite(val);
    }
    return *this;
  }
  
  //! \brief Write an integer into the stream.
  //! \param val : the integer to write.
  //! \return A reference to the stream.
  inline Stream& operator<<(const s32& val) {
    if(_mode == BINARY) {
      binaryWrite(val);
    }
    else if(_mode == FORMATTED) {
      formattedWrite(val);
    }
    return *this;
  }
  
  //! \brief Write an integer into the stream.
  //! \param val : the integer to write.
  //! \return A reference to the stream.
  inline Stream& operator<<(const s64& val) {
    if(_mode == BINARY) {
      binaryWrite(val);
    }
    else if(_mode == FORMATTED) {
      formattedWrite(val);
    }
    return *this;
  }
  
  //! \brief Write an integer into the stream.
  //! \param val : the integer to write.
  //! \return A reference to the stream.
  inline Stream& operator<<(const u8& val) {
    if(_mode == BINARY) {
      binaryWrite(val);
    }
    else if(_mode == FORMATTED) {
      formattedWrite(val);
    }
    return *this;
  }
  
  //! \brief Write an integer into the stream.
  //! \param val : the integer to write.
  //! \return A reference to the stream.
  inline Stream& operator<<(const u16& val) {
    if(_mode == BINARY) {
      binaryWrite(val);
    }
    else if(_mode == FORMATTED) {
      formattedWrite(val);
    }
    return *this;
  }
  
  //! \brief Write an integer into the stream.
  //! \param val : the integer to write.
  //! \return A reference to the stream.
  inline Stream& operator<<(const u32& val) {
    if(_mode == BINARY) {
      binaryWrite(val);
    }
    else if(_mode == FORMATTED) {
      formattedWrite(val);
    }
    return *this;
  }
  
  //! \brief Write an integer into the stream.
  //! \param val : the integer to write.
  //! \return A reference to the stream.
  inline Stream& operator<<(const u64& val) {
    if(_mode == BINARY) {
      binaryWrite(val);
    }
    else if(_mode == FORMATTED) {
      formattedWrite(val);
    }
    return *this;
  }
  
  //! \brief Write a string into the stream.
  //! \param str : the string to write.
  //! \return A reference to the stream.
  inline Stream& operator<<(const char* str) {
    binaryWrite(str);
    return *this;
  }
  
  //! \brief Read an integer from the stream.
  //! \param val : a reference to the integer to overwrite.
  //! \return A reference to the stream.
  inline Stream& operator>>(s8& val) {
    if(_mode == BINARY) {
      binaryRead(val);
    }
    else if(_mode == FORMATTED) {
      formattedRead(val);
    }
    return *this;
  }
  
  //! \brief Read an integer from the stream.
  //! \param val : a reference to the integer to overwrite.
  //! \return A reference to the stream.
  inline Stream& operator>>(s16& val) {
    if(_mode == BINARY) {
      binaryRead(val);
    }
    else if(_mode == FORMATTED) {
      formattedRead(val);
    }
    return *this;
  }
  
  //! \brief Read an integer from the stream.
  //! \param val : a reference to the integer to overwrite.
  //! \return A reference to the stream.
  inline Stream& operator>>(s32& val) {
    if(_mode == BINARY) {
      binaryRead(val);
    }
    else if(_mode == FORMATTED) {
      formattedRead(val);
    }
    return *this;
  }
  
  //! \brief Read an integer from the stream.
  //! \param val : a reference to the integer to overwrite.
  //! \return A reference to the stream.
  inline Stream& operator>>(s64& val) {
    if(_mode == BINARY) {
      binaryRead(val);
    }
    else if(_mode == FORMATTED) {
      formattedRead(val);
    }
    return *this;
  }
  
  //! \brief Read an integer from the stream.
  //! \param val : a reference to the integer to overwrite.
  //! \return A reference to the stream.
  inline Stream& operator>>(u8& val) {
    if(_mode == BINARY) {
      binaryRead(val);
    }
    else if(_mode == FORMATTED) {
      formattedRead(val);
    }
    return *this;
  }
  
  //! \brief Read an integer from the stream.
  //! \param val : a reference to the integer to overwrite.
  //! \return A reference to the stream.
  inline Stream& operator>>(u16& val) {
    if(_mode == BINARY) {
      binaryRead(val);
    }
    else if(_mode == FORMATTED) {
      formattedRead(val);
    }
    return *this;
  }
  
  //! \brief Read an integer from the stream.
  //! \param val : a reference to the integer to overwrite.
  //! \return A reference to the stream.
  inline Stream& operator>>(u32& val) {
    if(_mode == BINARY) {
      binaryRead(val);
    }
    else if(_mode == FORMATTED) {
      formattedRead(val);
    }
    return *this;
  }
  
  //! \brief Read an integer from the stream.
  //! \param val : a reference to the integer to overwrite.
  //! \return A reference to the stream.
  inline Stream& operator>>(u64& val) {
    if(_mode == BINARY) {
      binaryRead(val);
    }
    else if(_mode == FORMATTED) {
      formattedRead(val);
    }
    return *this;
  }
  
  //! \brief Read a string from the stream.
  //! \param str : the buffer to write the read string into.
  //! \return A reference to the stream.
  inline Stream& operator>>(char* str) {
    binaryRead(str, _user_buffer_size);
    return *this;
  }
  
  //! \brief Read a char from the stream.
  //! \return The read char.
  virtual char getValue(void) = 0;
  
  //! \brief Return the next value to read from the stream without removing it from the head of the stream.
  //! \return The char at the head of the stream.
  inline char nextValue(void) {
    if(!_mini_buffer_used) {
      _mini_buffer = getValue();
      _mini_buffer_used = true;
    }
    return _mini_buffer;
  }
  
  //! \brief Write a char into the stream.
  //! \param c : the character to write.
  virtual void setValue(char c) = 0;
};

#endif//STREAM_HPP
