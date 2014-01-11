#ifndef AVR_UART_STREAM_HPP
#define AVR_UART_STREAM_HPP

#include "../../../common/device/stream/uart_stream.hpp"

#include <hardware/uart.hpp>
#include <ctype.h>
#include <stdio.h>

template<int CHANNEL, buffer_t SIZE>
UartStream<CHANNEL, SIZE>::UartStream(void) :
_out_buff(), _in_buff(), _m(FORMATTED) {
  Uart<CHANNEL>::instance().init();
}

template<int CHANNEL, buffer_t SIZE>
inline UartStream<CHANNEL, SIZE>::~UartStream(void) {
}

template<int CHANNEL, buffer_t SIZE>
inline typename UartStream<CHANNEL, SIZE>::Mode UartStream<CHANNEL, SIZE>::mode() const {
  return _m;
}

template<int CHANNEL, buffer_t SIZE>
inline void UartStream<CHANNEL, SIZE>::setMode(UartStream<CHANNEL, SIZE>::Mode m) {
  _m = m;
}

template<int CHANNEL, buffer_t SIZE>
bool UartStream<CHANNEL, SIZE>::binaryWrite(uint8_t data) {
  return _out_buff.enqueue(data);
}

template<int CHANNEL, buffer_t SIZE>
bool UartStream<CHANNEL, SIZE>::binaryRead(uint8_t& data) {
  if(_in_buff.isEmpty()) {
    return false;
  }
  data = _in_buff.head();
  return _in_buff.dequeue();
}

template<int CHANNEL, buffer_t SIZE>
bool UartStream<CHANNEL, SIZE>::complexBinaryWrite(const char* str) {
  const uint8_t* ptr = reinterpret_cast<const uint8_t*>(str);
  for(; (*ptr) != '\0' && binaryWrite(*ptr); ptr++) { }
  return (*ptr) == '\0';
}

template<int CHANNEL, buffer_t SIZE>
bool UartStream<CHANNEL, SIZE>::complexBinaryRead(char* str) {
  uint8_t* ptr = reinterpret_cast<uint8_t*>(str);
  for(;binaryRead(*ptr) && !isspace(*ptr); ptr++) { }
  if(isspace(*ptr)) {
    *ptr = '\0';
    return true;
  }
  else {
    *(++ptr) = '\0';
    return false;
  }
}

template<int CHANNEL, buffer_t SIZE>
template<typename T>
bool UartStream<CHANNEL, SIZE>::complexBinaryWrite(const T& val) {
  const uint8_t* ptr = reinterpret_cast<const uint8_t*>(&val);
  int i;
  for(i = 0; i < sizeof(T) && binaryWrite(*ptr); i++, ptr++) { }
  return i == sizeof(T);
}

template<int CHANNEL, buffer_t SIZE>
template<typename T>
bool UartStream<CHANNEL, SIZE>::complexBinaryRead(T& val) {
  uint8_t* ptr = reinterpret_cast<uint8_t*>(&val);
  int i;
  for(i = 0; i < sizeof(T) && binaryRead(*ptr); i++, ptr++) { }
  return i == sizeof(T);
}

template<int CHANNEL, buffer_t SIZE>
bool UartStream<CHANNEL, SIZE>::formattedWrite(const char& val) {
  return binaryWrite(*reinterpret_cast<uint8_t*>(&val));
}

template<int CHANNEL, buffer_t SIZE>
bool UartStream<CHANNEL, SIZE>::formattedWrite(const unsigned char& val) {
  return binaryWrite(*reinterpret_cast<uint8_t*>(&val));
}

template<int CHANNEL, buffer_t SIZE>
bool UartStream<CHANNEL, SIZE>::formattedWrite(const short& val) {
  char str[7];
  snprintf(str, 7, "%hd", val);
  return complexBinaryWrite(str);
}

template<int CHANNEL, buffer_t SIZE>
bool UartStream<CHANNEL, SIZE>::formattedWrite(const unsigned short& val) {
  char str[7];
  snprintf(str, 7, "%hu", val);
  return complexBinaryWrite(str);
}

template<int CHANNEL, buffer_t SIZE>
bool UartStream<CHANNEL, SIZE>::formattedWrite(const long int& val) {
  char str[12];
  snprintf(str, 12, "%ld", val);
  return complexBinaryWrite(str);
}

template<int CHANNEL, buffer_t SIZE>
bool UartStream<CHANNEL, SIZE>::formattedWrite(const unsigned long int& val) {
  char str[12];
  snprintf(str, 12, "%lu", val);
  return complexBinaryWrite(str);
}

template<int CHANNEL, buffer_t SIZE>
bool UartStream<CHANNEL, SIZE>::formattedWrite(const long long int& val) {
  char str[22];
  snprintf(str, 22, "%lld", val);
  return complexBinaryWrite(str);
}

template<int CHANNEL, buffer_t SIZE>
bool UartStream<CHANNEL, SIZE>::formattedWrite(const unsigned long long int& val) {
  char str[22];
  snprintf(str, 22, "%llu", val);
  return complexBinaryWrite(str);
}

template<int CHANNEL, buffer_t SIZE>
bool UartStream<CHANNEL, SIZE>::formattedWrite(const float& val) {
  char str[25];
  snprintf(str, 25, "%E", val);
  return complexBinaryWrite(str);
}

template<int CHANNEL, buffer_t SIZE>
bool UartStream<CHANNEL, SIZE>::formattedWrite(const double& val) {
  char str[25];
  snprintf(str, 25, "%E", val);
  return complexBinaryWrite(str);
}

template<int CHANNEL, buffer_t SIZE>
inline UartStream<CHANNEL, SIZE>& UartStream<CHANNEL, SIZE>::operator<<(const char* str) {
  complexBinaryWrite(str);
  return (*this);
}

template<int CHANNEL, buffer_t SIZE>
template<typename T>
inline UartStream<CHANNEL, SIZE>& UartStream<CHANNEL, SIZE>::operator<<(const T& val) {
  if(_m == BINARY) {
    complexBinaryWrite(val);
  }
  else {
    formattedWrite(val);
  }
  return (*this);
}

template<int CHANNEL, buffer_t SIZE>
UartStream<CHANNEL, SIZE>& UartStream<CHANNEL, SIZE>::operator>>(char* str) {
  complexBinaryRead(str);
  return (*this);
}

template<int CHANNEL, buffer_t SIZE>
template<typename T>
UartStream<CHANNEL, SIZE>& UartStream<CHANNEL, SIZE>::operator>>(T& val) {
  if(_m == BINARY) {
    complexBinaryRead(val);
  }
  else {
    // TODO here
  }
  return (*this);
}

#endif//AVR_UART_STREAM_HPP
