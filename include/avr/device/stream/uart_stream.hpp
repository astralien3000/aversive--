#ifndef AVR_UART_STREAM_HPP
#define AVR_UART_STREAM_HPP

#include "../../../common/device/stream/uart_stream.hpp"

#include <aversive.hpp>
#include <hardware/uart.hpp>

template<int CHANNEL>
UartStream<CHANNEL>::UartStream(void) {
  Aversive::init();
  Uart<CHANNEL>& uart = Uart<CHANNEL>::instance();
  uart.init();
}

template<int CHANNEL>
UartStream<CHANNEL>& UartStream<CHANNEL>::operator<<(const char* str) {
  for( ; *str != '\0' ; str++) {
    Uart<CHANNEL>::instance().send(*str);
  }
  return *this;
}

template<int CHANNEL>
UartStream<CHANNEL>& UartStream<CHANNEL>::operator<<(char* str) {
  return *this << (const char*)str;
}

template<int CHANNEL> template<typename T>
UartStream<CHANNEL>& UartStream<CHANNEL>::operator<<(const T& val) {
  char str[32] = {0};

  if(_mode == BINARY) {
    for(u16 i = 0 ; i < sizeof(val) ; i++) {
      str[i] = val >> (i * 8) % 256;
    }
  }
  else if(_mode == FORMATTED) {
    T tmp = val;
    
    u16 beg = 0;
    if(val == 0) {
      str[beg++] = '0';
    }
    else if(val < 0) {
      str[beg++] = '-';
      tmp = -val;
    }
    
    u16 i = beg;
    while(0 < tmp && i < 32) {
      str[i] = '0' + tmp % 10;
      tmp /= 10;
      i++;
    }
    
    i--;
    while(beg < i) {
      char aux = str[i];
      str[i] = str[beg];
      str[beg] = aux;
      i--;
      beg++;
    }
  }

  return *this << (const char*)str;
}

template<int CHANNEL>
UartStream<CHANNEL>& UartStream<CHANNEL>::operator>>(char* str) {
  bool keep = true;
  char* beg = str;
  while(keep && (str-beg) < 32) {
    char c;
    Uart<CHANNEL>::instance().recv(c);
    *str = c;
    if(_mode == FORMATTED) {
      if(_sep == WORD && c == ' ') {
	keep = false;
      }
      else if(c == '\r' || c == '\n') {
	*str = '\n';
	keep = false;
      }
      Uart<CHANNEL>::instance().send(*str);
    }
    str++;	
  }
  *(str-1) = '\0';
  return *this;
}

template<int CHANNEL> template<typename T>
UartStream<CHANNEL>& UartStream<CHANNEL>::operator>>(T& val) {
  char str[32] = {0};
  *this >> str;

  val = 0;
  
  if(_mode == BINARY) {
    for(u16 i = 0 ; i < sizeof(val) ; i++) {
      val += str[i] << (i * 8);
    }
  }
  else if(_mode == FORMATTED) {
    u16 beg = 0;
    if(str[0] == '-') {
      beg = 1;
    }
    
    for(u16 i = beg ; str[i] ; i++) {
      if('0' <= str[i] && str[i] <= '9') {
	val *= 10;
	val += (T)(str[i] - '0');
      }
      else {
	str[i+1] = '\0';
      }
    }

    if(beg == 1) {
      val = -val;
    }
  }
  return *this;
}

#endif//AVR_UART_STREAM_HPP
