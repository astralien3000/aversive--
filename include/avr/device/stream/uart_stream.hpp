#ifndef AVR_UART_STREAM_HPP
#define AVR_UART_STREAM_HPP

#include "../../../common/device/stream/uart_stream.hpp"

#include <hardware/uart.hpp>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

static const uint8_t SHORT_STR_LENGTH = 7;
static const uint8_t LONG_STR_LENGTH = 12;
static const uint8_t DOUBLE_STR_LENGTH = 25;

template<int CHANNEL>
UartStream<CHANNEL>::UartStream(void) :
_out_buff(), _in_buff() {
  Uart<CHANNEL>& uart = Uart<CHANNEL>::instance();
  uart.init();
  
  uart.recvEvent().setFunction(UartStream<CHANNEL>::read);
  uart.sendEvent().setFunction(UartStream<CHANNEL>::write);
  
  uart.recvEvent().start();
  uart.sendEvent().start();
}

template<int CHANNEL>
void UartStream<CHANNEL>::read(void) {
  UartStream<CHANNEL>& stream = UartStream<CHANNEL>::instance();
  char c = Uart<CHANNEL>::instance().template recv<uint8_t>();
  Uart<CHANNEL>::instance().send(c);
  stream._in_buff.enqueue(c);
}

#include <hardware/interrupts.hpp>

template<int CHANNEL>
void UartStream<CHANNEL>::write(void) {
  UartStream<CHANNEL>& stream = UartStream<CHANNEL>::instance();
  if(stream._out_buff.usedSpace()) {
    stream._sending = true;
    u8 c = stream._out_buff.head();
    stream._out_buff.dequeue();
    Uart<CHANNEL>::instance().send(c);
  }
  else {
    stream._sending = false;
  }
}

#define tryFlush()				\
  Interrupts::clear();				\
  if(!_sending) {				\
    _sending = true;				\
    UartStream<CHANNEL>::write();		\
  }						\
  Interrupts::set();

template<int CHANNEL>
inline typename UartStream<CHANNEL>::Mode UartStream<CHANNEL>::mode() const {
  return _m;
}

template<int CHANNEL>
inline void UartStream<CHANNEL>::setMode(UartStream<CHANNEL>::Mode m) {
  _m = m;
}

template<int CHANNEL>
inline typename UartStream<CHANNEL>::StrMode UartStream<CHANNEL>::strMode() const {
  return _s;
}

template<int CHANNEL>
inline void UartStream<CHANNEL>::setStrMode(UartStream<CHANNEL>::StrMode s) {
  _s = s;
}

template<int CHANNEL>
bool UartStream<CHANNEL>::binaryWrite(uint8_t data) {
  while(_out_buff.isFull()) {
    tryFlush();
  }
  return _out_buff.enqueue(data);
}

template<int CHANNEL>
bool UartStream<CHANNEL>::binaryRead(uint8_t& data) {
  if(_in_buff.isEmpty()) {
    return false;
  }
  data = _in_buff.head();
  return _in_buff.dequeue();
}

template<int CHANNEL>
bool UartStream<CHANNEL>::complexBinaryWrite(const char* str) {
  const uint8_t* ptr = reinterpret_cast<const uint8_t*>(str);
  for(; (*ptr) != '\0' && binaryWrite(*ptr); ptr++) { }
  return (*ptr) == '\0';
}

template<int CHANNEL>
template<typename T>
bool UartStream<CHANNEL>::complexBinaryWrite(const T& val) {
  const uint8_t* ptr = reinterpret_cast<const uint8_t*>(&val);
  int i;
  for(i = 0; i < (int)sizeof(T) && binaryWrite(*ptr); i++, ptr++) { }
  return i == sizeof(T);
}

template<int CHANNEL>
bool UartStream<CHANNEL>::complexBinaryRead(char* str, uint_fast16_t limit) {
  if(limit == 1) {
    *str = '\0';
    return true;
  }
  
  uint8_t* ptr = reinterpret_cast<uint8_t*>(str);
  bool hasLimit = (limit != 0);
  if(!hasLimit) {
    for(;binaryRead(*ptr) && !((_s == WORD) ? isspace(*ptr) : *ptr == '\n') && *ptr != '\0'; ptr++) { }
  }
  else {
    for(;binaryRead(*ptr) && !((_s == WORD) ? isspace(*ptr) : *ptr == '\n') && *ptr != '\0' && limit > 2; ptr++, limit--) { }
  }
  
  if(*ptr == '\0') { }
  else if(isspace(*ptr)) {
    *ptr = '\0';
  }
  else {
    *(++ptr) = '\0';
  }
  return true;
}

template<int CHANNEL>
template<typename T>
bool UartStream<CHANNEL>::complexBinaryRead(T& val) {
  uint8_t* ptr = reinterpret_cast<uint8_t*>(&val);
  int i;
  for(i = 0; i < sizeof(T) && binaryRead(*ptr); i++, ptr++) { }
  return i == sizeof(T);
}

template<int CHANNEL>
inline bool UartStream<CHANNEL>::formattedWrite(const char& val) {
  return binaryWrite(*reinterpret_cast<const uint8_t*>(&val));
}

template<int CHANNEL>
inline bool UartStream<CHANNEL>::formattedWrite(const unsigned char& val) {
  return binaryWrite(*reinterpret_cast<const uint8_t*>(&val));
}

template<int CHANNEL>
bool UartStream<CHANNEL>::formattedWrite(const short& val) {
  char str[SHORT_STR_LENGTH] = {0};
  snprintf(str, SHORT_STR_LENGTH, "%hd", val);
  return complexBinaryWrite(str);
}

template<int CHANNEL>
bool UartStream<CHANNEL>::formattedWrite(const unsigned short& val) {
  char str[SHORT_STR_LENGTH] = {0};
  snprintf(str, SHORT_STR_LENGTH, "%hu", val);
  return complexBinaryWrite(str);
}

template<int CHANNEL>
bool UartStream<CHANNEL>::formattedWrite(const long int& val) {
  char str[LONG_STR_LENGTH] = {0};
  snprintf(str, LONG_STR_LENGTH, "%ld", val);
  return complexBinaryWrite(str);
}

template<int CHANNEL>
bool UartStream<CHANNEL>::formattedWrite(const unsigned long int& val) {
  char str[LONG_STR_LENGTH] = {0};
  snprintf(str, LONG_STR_LENGTH, "%lu", val);
  return complexBinaryWrite(str);
}

template<int CHANNEL>
bool UartStream<CHANNEL>::formattedWrite(const float& val) {
  char str[DOUBLE_STR_LENGTH] = {0};
  snprintf(str, DOUBLE_STR_LENGTH, "%E", (double)val);
  return complexBinaryWrite(str);
}

template<int CHANNEL>
bool UartStream<CHANNEL>::formattedWrite(const double& val) {
  char str[DOUBLE_STR_LENGTH] = {0};
  snprintf(str, DOUBLE_STR_LENGTH, "%E", val);
  return complexBinaryWrite(str);
}

template<int CHANNEL>
inline bool UartStream<CHANNEL>::formattedRead(char& val) {
  return binaryRead(*reinterpret_cast<uint8_t*>(&val));
}

template<int CHANNEL>
inline bool UartStream<CHANNEL>::formattedRead(unsigned char& val) {
  return binaryRead(*reinterpret_cast<uint8_t*>(&val));
}

template<int CHANNEL>
bool UartStream<CHANNEL>::formattedRead(short& val) {
  long int val2;
  bool res = formattedRead(val2);
  val = static_cast<short>(val2);
  return res;
}

template<int CHANNEL>
bool UartStream<CHANNEL>::formattedRead(unsigned short& val) {
  unsigned long int val2;
  bool res = formattedRead(val2);
  val = static_cast<unsigned short>(val2);
  return res;
}

template<int CHANNEL>
bool UartStream<CHANNEL>::formattedRead(long int& val) {
  char str[LONG_STR_LENGTH];
  complexBinaryRead(str, LONG_STR_LENGTH);
  val = strtol(str, NULL, 10);
  return true;
}

template<int CHANNEL>
bool UartStream<CHANNEL>::formattedRead(unsigned long int& val) {
  char str[LONG_STR_LENGTH];
  complexBinaryRead(str, LONG_STR_LENGTH);
  val = strtoul(str, NULL, 10);
  return true;
}

template<int CHANNEL>
bool UartStream<CHANNEL>::formattedRead(float& val) {
  double val2;
  bool res = formattedRead(val2);
  val = static_cast<float>(val2);
  return res;
}

template<int CHANNEL>
bool UartStream<CHANNEL>::formattedRead(double& val) {
  char str[DOUBLE_STR_LENGTH];
  complexBinaryRead(str, DOUBLE_STR_LENGTH);
  val = strtod(str, NULL);
  return true;
}

template<int CHANNEL>
inline UartStream<CHANNEL>& UartStream<CHANNEL>::operator<<(const char* str) {

  complexBinaryWrite(str);

  tryFlush();
  return (*this);
}

template<int CHANNEL>
template<typename T>
UartStream<CHANNEL>& UartStream<CHANNEL>::operator<<(const T& val) {

  if(_m == BINARY) {
    complexBinaryWrite(val);
  }
  else {
    formattedWrite(val);
  }
  
  tryFlush();
  return (*this);
}

template<int CHANNEL>
inline UartStream<CHANNEL>& UartStream<CHANNEL>::operator>>(char* str) {
  complexBinaryRead(str);
  return (*this);
}

template<int CHANNEL>
template<typename T>
UartStream<CHANNEL>& UartStream<CHANNEL>::operator>>(T& val) {
  if(_m == BINARY) {
    complexBinaryRead(val);
  }
  else {
    formattedRead(val);
  }
  return (*this);
}

#endif//AVR_UART_STREAM_HPP
