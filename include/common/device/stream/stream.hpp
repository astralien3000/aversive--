#ifndef STREAM_HPP
#define STREAM_HPP

#include <device/device.hpp>
#include <device/input.hpp>
#include <device/output.hpp>
#include <base/integer.hpp>

class Stream : public Device, public Input<char>, public Output<char> {
public:
    //! \brief Mode represents the different modes the stream can be in (default is FORMATTED)
  enum Mode { BINARY, FORMATTED };
  
  //! \brief StrMode represents the different modes the stream can read string (default is WORD)
  enum SepMode { WORD, LINE };
  
private:
  Mode _mode = FORMATTED;
  SepMode _sep = WORD;

private:
  // Write
  void binaryWrite(const char*, u16);

  //// Aversive Integers
  void binaryWrite(const s8&);
  void binaryWrite(const s16&);
  void binaryWrite(const s32&);
  void binaryWrite(const s64&);

  void binaryWrite(const u8&);
  void binaryWrite(const u16&);
  void binaryWrite(const u32&);
  void binaryWrite(const u64&);

  void formattedWrite(const s8&);
  void formattedWrite(const s16&);
  void formattedWrite(const s32&);
  void formattedWrite(const s64&);

  void formattedWrite(const u8&);
  void formattedWrite(const u16&);
  void formattedWrite(const u32&);
  void formattedWrite(const u64&);

  // Read
  void binaryRead(char*, u16);

  // Aversive Integers
  void binaryRead(s8&);
  void binaryRead(s16&);
  void binaryRead(s32&);
  void binaryRead(s64&);

  void binaryRead(u8&);
  void binaryRead(u16&);
  void binaryRead(u32&);
  void binaryRead(u64&);

  void formattedRead(s8&);
  void formattedRead(s16&);
  void formattedRead(s32&);
  void formattedRead(s64&);

  void formattedRead(u8&);
  void formattedRead(u16&);
  void formattedRead(u32&);
  void formattedRead(u64&);

public:
  //! \brief Default Constructor
  Stream(const char*);

  //! \brief Change the mode the stream is currently in
  inline void setMode(Mode m) {
    _mode = m;
  }

  //! \brief Change the string mode the stream is currently in
  inline void setSepMode(SepMode s) {
    _sep = s;
  }

  //! \brief Write a string into the stream (const version)
  inline Stream& operator<<(const char* str) {
    binaryWrite(str, 32);
    return *this;
  }

  /*
  //! \brief Write a string into the stream
  inline Stream& operator<<(char* str) {
    return *this << (const char*)str;
  }
  */

  //! \brief Write anything into the stream
  template<typename T>
  Stream& operator<<(const T& val) {
    if(_mode == BINARY) {
      binaryWrite(val);
    }
    else if(_mode == FORMATTED) {
      formattedWrite(val);
    }
    return *this;
  }

  //! \brief Read a string from the stream
  //! \attention Its behavior depends on the string mode the stream is currently in
  inline Stream& operator>>(char* str) {
    binaryRead(str, 32);
    return *this;
  }
  
  //! \brief Read anything from the stream
  //! \attention Its behavior depends on the mode (binary or formatted) the stream is currently in
  template<typename T>
  inline Stream& operator>>(T& val) {
    if(_mode == BINARY) {
      binaryRead(val);
    }
    else if(_mode == FORMATTED) {
      formattedRead(val);
    }
    return *this;
  }

  //! \brief Write a char in stream
  //! \warning virtual operation
  virtual char getValue(void) = 0;

  //! \brief Read a char from stream
  //! \warning virtual operation
  virtual void setValue(char) = 0;
};

#endif//STREAM_HPP
