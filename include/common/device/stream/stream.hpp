#ifndef STREAM_HPP
#define STREAM_HPP

#include <device/stream/formatted_stream.hpp>

//! \class Stream stream.hpp <device/stream/stream.hpp>
//! \brief Abstract two-way stream with formatted and binary read and write.
//! \todo Change SeparatorMode into Separatorarator (or StringSeparatorarator).
class Stream : public FormattedStream {
public:
  //! \brief Represents the different ways a stream can read and write data.
  //! \details Defaut is formatted.
  enum Mode {
    BINARY,   //!< Read and write data as binary.
    FORMATTED //!< Read and write formatted data.
  };
  
private:
  //! \brief The current mode of the stream.
  Mode _mode = FORMATTED;
  
public:
  //! \brief Default constructor.
  inline Stream(void)
    : FormattedStream() {
  }
  
  //! \brief Copy constructor.
  //! \param s : the stream to copy.
  inline Stream(const Stream& s)
    : FormattedStream(s) {
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
    if(_mode == BINARY) {
      binaryRead(str, _user_buffer_size);
    }
    else if(_mode == FORMATTED) {
      formattedRead(str, _user_buffer_size);
    }
    return *this;
  }
};

#endif//STREAM_HPP
