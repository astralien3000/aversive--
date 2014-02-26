#ifndef SASIAE_INPUT_DEVICE_HPP
#define SASIAE_INPUT_DEVICE_HPP

template<typename T>
struct SimpleInputDevicePrivateData {
  T last_in;
};

#include "../../common/device/input_device.hpp"

#include <aversive.hpp>
#include <client_thread.hpp>

template<typename T>
void get_value_from_msg(T* dest, const char* msg) {
  long long in;
  sscanf(msg, "%lld", &in);
  *dest = (T)in;
}

template<typename T>
SimpleInputDevice<T>::SimpleInputDevice(const char* name) : Device(name) {
  Aversive::init();
  _data.last_in = 0;

  ClientThread::instance().
    registerDevice(*this,
		   std::function<void(char*)>([&] (char* msg) mutable -> void {
		       char cmd[32], msg2[1000];
		       sscanf(msg, "%s %s", cmd, msg2);

		       if(strcmp(cmd, "value") == 0) {
			 get_value_from_msg(&_data.last_in, msg2);
		       }
		     }));

  ClientThread::instance().
    sendDeviceMessage(*this, "init");
}

template<typename T>
T SimpleInputDevice<T>::getValue(void) {
  return _data.last_in;
}

#endif//SASIAE_INPUT_DEVICE_HPP
