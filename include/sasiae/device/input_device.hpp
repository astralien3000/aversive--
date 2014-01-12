#ifndef SASIAE_INPUT_DEVICE_HPP
#define SASIAE_INPUT_DEVICE_HPP

template<typename T>
struct InputDevicePrivateData {
  T last_in;
};

#include "../../common/device/input_device.hpp"
#include "../client_thread.hpp"

template<typename T>
InputDevice<T>::InputDevice(const char* name) : Device(name) {
  ClientThread::instance().
    registerDevice(name,
		   std::function<void(char*)>([&] (char* msg) mutable -> void {
		       char cmd[32], msg2[1000];
		       sscanf(msg, "%s %s", cmd, msg2);

		       if(strcmp(cmd, "VALUE") == 0) {
			 long in;
			 sscanf(msg2, "%ld", &in);
			 _data.last_in = in;
		       }
		     }));
}

#endif//SASIAE_INPUT_DEVICE_HPP
