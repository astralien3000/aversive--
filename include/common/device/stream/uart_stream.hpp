#ifndef UART_STREAM_HPP
#define UART_STREAM_HPP

#include <base/integer.hpp>
#include <device/stream/stream.hpp>
#include <device/device.hpp>

//! \brief Uart stream which uses "thread-safe" Buffer implementation
//! \attention SIZE must be a power of 2
//! \param CHANNEL which Uart connection the stream must be bound to
//! \param SIZE the number of characters input and output buffers can both handle at any given time
template<int CHANNEL>
class UartStream : public Device, public Stream {
public:  
  UartStream(const char*);
  
  //! \brief Write a char in stream
  char getValue(void);

  //! \brief Read a char from stream
  void setValue(char);
};

#endif//UART_STREAM_HPP
