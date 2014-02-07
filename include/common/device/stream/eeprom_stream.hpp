#ifndef EEPROM_STREAM_HPP
#define EEPROM_STREAM_HPP

#include <base/singleton.hpp>
#include <base/integer.hpp>
#include <container/buffer.hpp>
#include <stdint.h>

//! \brief Eeprom stream which uses "thread-safe" Buffer implementation
//! \attention SIZE must be a power of 2
//! \param CHANNEL which Eeprom connection the stream must be bound to
//! \param SIZE the number of characters input and output buffers can both handle at any given time
template<int CHANNEL>
class EepromStream {
public:
  //! \brief Mode represents the different modes the stream can be in (default is FORMATTED)
  enum Mode { BINARY, FORMATTED };
  
  //! \brief StrMode represents the different modes the stream can read string (default is WORD)
  enum SepMode { WORD, LINE };
  
protected:
  Mode _mode = FORMATTED;
  SepMode _sep = WORD;
  u16 _max_size = 32;

public:  
  EepromStream(void);
  
  //! \brief Change the mode the stream is currently in
  void setMode(Mode m);

  //! \brief Change the string mode the stream is currently in
  void setSepMode(SepMode s);
  
  //! \brief Write a string into the stream
  EepromStream<CHANNEL>& operator<<(const char*);

  //! \brief Write a string into the stream
  EepromStream<CHANNEL>& operator<<(char*);

  //! \brief Write anything into the stream
  template<typename T>
  EepromStream<CHANNEL>& operator<<(const T&);
  
  //! \brief Read a string from the stream
  //! \attention Its behavior depends on the string mode the stream is currently in
  EepromStream<CHANNEL>& operator>>(char*);
  
  //! \brief Read anything from the stream
  //! \attention Its behavior depends on the mode (binary or formatted) the stream is currently in
  template<typename T>
  EepromStream<CHANNEL>& operator>>(T&);
};

#endif//EEPROM_STREAM_HPP
