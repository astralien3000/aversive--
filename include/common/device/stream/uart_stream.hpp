#ifndef UART_STREAM_HPP
#define UART_STREAM_HPP

#include <base/singleton.hpp>
#include <base/integer.hpp>
#include <container/buffer.hpp>
#include <stdint.h>

//! \brief Uart stream which uses "thread-safe" Buffer implementation
//! \attention SIZE must be a power of 2
//! \param CHANNEL which Uart connection the stream must be bound to
//! \param SIZE the number of characters input and output buffers can both handle at any given time
template<int CHANNEL>
class UartStream {
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
  UartStream(void);
  
  //! \brief Change the mode the stream is currently in
  void setMode(Mode m);

  //! \brief Change the string mode the stream is currently in
  void setSepMode(SepMode s);
  
  //! \brief Write a string into the stream
  UartStream<CHANNEL>& operator<<(const char*);

  //! \brief Write a string into the stream
  UartStream<CHANNEL>& operator<<(char*);

  //! \brief Write anything into the stream
  template<typename T>
  UartStream<CHANNEL>& operator<<(const T&);
  
  //! \brief Read a string from the stream
  //! \attention Its behavior depends on the string mode the stream is currently in
  UartStream<CHANNEL>& operator>>(char*);
  
  //! \brief Read anything from the stream
  //! \attention Its behavior depends on the mode (binary or formatted) the stream is currently in
  template<typename T>
  UartStream<CHANNEL>& operator>>(T&);
};

#endif//UART_STREAM_HPP
