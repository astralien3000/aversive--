#ifndef AVR_UART_STREAM_HPP
#define AVR_UART_STREAM_HPP

#include "../../../common/device/stream/uart_stream.hpp"

template<int CHANNEL, int SIZE>
inline UartStream<CHANNEL, SIZE>::UartStream(void) :
_s_buff('\0'), _s_i(0), _r_buff('\0'), _r_i(0) {
  Uart<CHANNEL>::instance().init();
}

template<int CHANNEL, int SIZE>
UartStream<CHANNEL, SIZE>& UartStream<CHANNEL, SIZE>::operator<<(const char* str) {
  while((*str) != '\0') {
    // If the buffer is full (we need to keep a \0)
    if(_s_buff[(_s_i + 1) % SIZE] != '\0') {
      break;
    }
    _s_buff[_s_i++] = *str;
    str++;
  }
  return (*this);
}

template<int CHANNEL, int SIZE>
template<typename T>
UartStream<CHANNEL, SIZE>& UartStream<CHANNEL, SIZE>::operator<<(T val) {
  for(int i = 0; i < sizeof(T); i++, val <<= 8) {
    // If the buffer is full (we need to keep a \0)
    if(_s_buff[(_s_i + 1) % SIZE] != '\0') {
      break;
    }
    _s_buff[_s_i++] = (char) (val & 0xff);
  }
  return (*this);
}

#endif//AVR_UART_STREAM_HPP
