#ifndef UART_STREAM_HPP
#define UART_STREAM_HPP

#include <base/integer.hpp>
#include <device/stream/stream.hpp>
#include <device/device.hpp>

//! \class UartStream uart_stream.hpp <device/stream/uart_stream.hpp>
//! \brief Uart stream device.
//! \param _CHANNEL : the Uart connection the stream must be bound to.
template<u8 _CHANNEL>
class UartStream : public Device, public Stream {
public:
  //! \brief The UartStream's channel.
  static const u8 CHANNEL = _CHANNEL;
  
  //! \brief UartStream constructor.
  //! \param name : the device's name.
  UartStream(const char* name);
  
  //! \brief Read a character from the stream.
  //! \return The read character.
  char getValue(void);
  
  //! \brief Write a character into the stream.
  //! \param c : the character to write.
  void setValue(char c);
};

#endif//UART_STREAM_HPP
