#ifndef SASIAE_UART_STREAM_HPP
#define SASIAE_UART_STREAM_HPP

#include "../../../common/device/stream/uart_stream.hpp"

#include <aversive.hpp>
#include <client_thread.hpp>
#include <sstream>

template<u8 _CHANNEL>
UartStream<_CHANNEL>::UartStream(const char* name) : Device(name) {
  Aversive::init();

  ClientThread::instance().
    registerDevice(*this,
		   std::function<void(char*)>([&] (char* msg) mutable -> void {
		       (void) msg; //! \todo Write parser
		     }));

  ClientThread::instance().
    sendDeviceMessage(*this, "init");
}

template<u8 _CHANNEL>
char UartStream<_CHANNEL>::getValue(void) {
  return 0;
}

template<u8 _CHANNEL>
void UartStream<_CHANNEL>::setValue(char val) {
  std::ostringstream oss;
  oss << "value " << (unsigned int)val;

  ClientThread::instance().
    sendDeviceMessage(*this, 
		      oss.str().c_str());
}


#endif//SASIAE_UART_STREAM_HPP
