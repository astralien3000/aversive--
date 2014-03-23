#ifndef AVR_UART_STREAM_HPP
#define AVR_UART_STREAM_HPP

#include "../../../common/device/stream/uart_stream.hpp"

#include <hardware/uart.hpp>

template<int CHANNEL>
UartStream<CHANNEL>::UartStream(const char* name) : Device(name) {
  Uart<CHANNEL>& uart = Uart<CHANNEL>::instance();
  uart.init();
}

template<int CHANNEL>
void UartStream<CHANNEL>::setValue(char c) {
  Uart<CHANNEL>::instance().send(c);
}

template<int CHANNEL>
char UartStream<CHANNEL>::getValue(void) {
  if(_mini_buffer_used) {
    _mini_buffer_used = false;
    return _mini_buffer;
  }
  else {
    char ret;
    Uart<CHANNEL>::instance().recv(ret);
    return ret;
  }
}

#endif//AVR_UART_STREAM_HPP
