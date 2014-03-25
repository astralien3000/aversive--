#ifndef AVR_UART_STREAM_HPP
#define AVR_UART_STREAM_HPP

#include "../../../common/device/stream/uart_stream.hpp"

#include <hardware/uart.hpp>

template<u8 _CHANNEL>
UartStream<_CHANNEL>::UartStream(const char* name) : Device(name) {
  Uart<_CHANNEL>& uart = Uart<CHANNEL>::instance();
  uart.init();
}

template<u8 _CHANNEL>
void UartStream<_CHANNEL>::setValue(char c) {
  Uart<_CHANNEL>::instance().send(c);
}

template<u8 _CHANNEL>
char UartStream<_CHANNEL>::getValue(void) {
  if(_mini_buffer_used) {
    _mini_buffer_used = false;
    return _mini_buffer;
  }
  else {
    char ret;
    Uart<_CHANNEL>::instance().recv(ret);
    return ret;
  }
}

#endif//AVR_UART_STREAM_HPP
