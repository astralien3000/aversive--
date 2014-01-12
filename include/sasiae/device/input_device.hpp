#ifndef SASIAE_INPUT_DEVICE_HPP
#define SASIAE_INPUT_DEVICE_HPP

template<typename T>
struct InputDevicePrivateData {
  T last_in;
};

#include "../../common/device/input_device.hpp"
#include "../client_thread.hpp"

template<typename T>
void get_value_from_msg(T* dest, const char* msg) {
  long long in;
  sscanf(msg, "%lld", &in);
  *dest = (T)in;
}

template<typename T>
InputDevice<T>::InputDevice(const char* name) : Device(name) {
  _data.last_in = 0;

  ClientThread::instance().
    registerDevice(name,
		   std::function<void(char*)>([&] (char* msg) mutable -> void {
		       char cmd[32], msg2[1000];
		       sscanf(msg, "%s %s", cmd, msg2);

		       if(strcmp(cmd, "VALUE") == 0) {
			 get_value_from_msg(&_data.last_in, msg2);
		       }
		     }));

  ClientThread::instance().
    sendDeviceMessage(*this, "CALLME");
}

template<typename T>
T InputDevice<T>::getValue(void) {
  return _data.last_in;
}

#endif//SASIAE_INPUT_DEVICE_HPP
