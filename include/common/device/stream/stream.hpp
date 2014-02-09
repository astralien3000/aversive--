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
  u16 _max_size = 32;

protected:

public:
  //! \brief Default Constructor
  Stream(const char*);

  //! \brief Change the mode the stream is currently in
  void setMode(Mode m);

  //! \brief Change the string mode the stream is currently in
  void setSepMode(SepMode s);

  //! \brief Write a string into the stream (const version)
  Stream& operator<<(const char*);

  //! \brief Write a string into the stream
  Stream& operator<<(char*);

  //! \brief Write anything into the stream
  template<typename T>
  Stream& operator<<(const T&);

  //! \brief Read a string from the stream
  //! \attention Its behavior depends on the string mode the stream is currently in
  Stream& operator>>(char*);
  
  //! \brief Read anything from the stream
  //! \attention Its behavior depends on the mode (binary or formatted) the stream is currently in
  template<typename T>
  Stream& operator>>(T&);

  //! \brief Write a char in stream
  //! \warning virtual operation
  virtual char getValue(void) = 0;

  //! \brief Read a char from stream
  //! \warning virtual operation
  virtual void setValue(char) = 0;
};

#endif//STREAM_HPP
