#ifndef SASIAE_OUTPUT_DEVICE_HPP
#define SASIAE_OUTPUT_DEVICE_HPP

template<typename T>
struct SimpleOutputDevicePrivateData {

};

#include "../../common/device/output_device.hpp"

#include <client_thread.hpp>

#include <sstream>

template<typename T>
SimpleOutputDevice<T>::SimpleOutputDevice(const char* name) : Device(name) {
  (void)AversiveInitializer::instance();

  ClientThread::instance().
    registerDevice(*this,
		   std::function<void(char*)>([&] (char*) mutable -> void {}));
}

template<typename T>
void SimpleOutputDevice<T>::setValue(T val) {
  std::ostringstream oss;
  oss << "VALUE " << val;

  ClientThread::instance().
    sendDeviceMessage(*this, 
		      oss.str().c_str());
}

#endif//SASIAE_OUTPUT_DEVICE_HPP
