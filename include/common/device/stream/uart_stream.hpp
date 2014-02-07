#ifndef UART_STREAM_HPP
#define UART_STREAM_HPP

#include <base/integer.hpp>
#include <device/stream/stream.hpp>

//! \brief Uart stream which uses "thread-safe" Buffer implementation
//! \attention SIZE must be a power of 2
//! \param CHANNEL which Uart connection the stream must be bound to
//! \param SIZE the number of characters input and output buffers can both handle at any given time
template<int CHANNEL>
class UartStream : public Stream {
public:  
  UartStream(void);
  
  //! \brief Write a character into the stream
  Stream& operator<<(char);

  //! \brief Read a characte from the stream
  Stream& operator>>(char&);
};

#endif//UART_STREAM_HPP
