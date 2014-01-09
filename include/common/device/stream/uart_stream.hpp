#ifndef UART_STREAM_HPP
#define UART_STREAM_HPP

#include "../output_device.hpp"
#include "../../hardware/uart.hpp"

#define DEFAULT_SIZE

template<int CHANNEL, int SIZE = DEFAULT_SIZE>
class UartStream {
protected:
  Array<SIZE, char> _s_buff;
  int _s_i;
  Array<SIZE, char> _r_buff;
  int _r_i;
  
public:
  UartStream(void);
  
  UartStream<CHANNEL, SIZE>& operator<<(const char* str);
  
  template<typename T>
  UartStream<CHANNEL, SIZE>& operator<<(T val);

  UartStream<CHANNEL, SIZE>& operator>>(const char* str);
  
  template<typename T>
  UartStream<CHANNEL, SIZE>& operator>>(T& val);
};

#endif//UART_STREAM_HPP
