#ifndef AVR_UART_STREAM_HPP
#define AVR_UART_STREAM_HPP

#include "../../../common/device/stream/uart_stream.hpp"

#include <hardware/uart.hpp>

template<int CHANNEL>
UartStream<CHANNEL>::UartStream(void) {
  Uart<CHANNEL>& uart = Uart<CHANNEL>::instance();
  uart.init();
}

template<int CHANNEL>
Stream& UartStream<CHANNEL>::operator<<(char c) {
  Uart<CHANNEL>::instance().send(c);
  return *this;
}

template<int CHANNEL>
Stream& UartStream<CHANNEL>::operator>>(char& c) {
  Uart<CHANNEL>::instance().recv(c);
  return *this;
}

#endif//AVR_UART_STREAM_HPP
