#ifndef SASIAE_UART_STREAM_HPP
#define SASIAE_UART_STREAM_HPP

#include "../../../common/device/stream/uart_stream.hpp"

#include <aversive.hpp>
#include <client_thread.hpp>
#include <sstream>

template<int CHANNEL>
UartStream<CHANNEL>::UartStream(const char* name) : Stream(name) {
  Aversive::init();

  ClientThread::instance().
    registerDevice(*this,
		   std::function<void(char*)>([&] (char* msg) mutable -> void {
		       (void) msg; //! \todo Write parser
		     }));

  ClientThread::instance().
    sendDeviceMessage(*this, "init");
}

template<int CHANNEL>
char UartStream<CHANNEL>::getValue(void) {
  return 0;
}

template<int CHANNEL>
void UartStream<CHANNEL>::setValue(char val) {
  std::ostringstream oss;
  oss << "value " << (unsigned int)val;

  ClientThread::instance().
    sendDeviceMessage(*this, 
		      oss.str().c_str());
}


#endif//SASIAE_UART_STREAM_HPP
