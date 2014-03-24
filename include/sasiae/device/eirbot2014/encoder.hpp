#ifndef SASIAE_ENCODER_HPP
#define SASIAE_ENCODER_HPP

#include "../../../common/device/eirbot2014/encoder.hpp"

#include <aversive.hpp>
#include <client_thread.hpp>

#include <sstream>

template<typename T>
void get_value_from_msg(T* dest, const char* msg) {
  long long in;
  sscanf(msg, "%lld", &in);
  *dest = (T)in;
}

template<typename T>
Encoder<T>::Encoder(const char* name, T* addr)
  : Device(name), _addr(addr) {

  Aversive::init();
  *_addr = 0;

  ClientThread::instance().
    registerDevice(*this,
		   std::function<void(char*)>([&] (char* msg) mutable -> void {
		       char cmd[32], msg2[1000];
		       sscanf(msg, "%s %s", cmd, msg2);

		       if(strcmp(cmd, "value") == 0) {
			 get_value_from_msg(_addr, msg2);
		       }
		     }));

  ClientThread::instance().
    sendDeviceMessage(*this, "init");
}

template<typename T>
s32 Encoder<T>::getValue(void) {
  return *_addr;
}

template<typename T>
inline void Encoder<T>::inverse(void) {
  _inverse = !_inverse;
}

#endif//SASIAE_ENCODER_HPP
