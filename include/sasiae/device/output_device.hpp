#ifndef SASIAE_OUTPUT_DEVICE_HPP
#define SASIAE_OUTPUT_DEVICE_HPP

template<typename T>
struct OutputDevicePrivateData {

};

#include "../../common/device/output_device.hpp"

#include <aversive.hpp>
#include <client_thread.hpp>

#include <sstream>

template<typename T>
OutputDevice<T>::OutputDevice(const char* name) : Device(name) {
  Aversive::init();

  ClientThread::instance().
    registerDevice(*this,
		   std::function<void(char*)>([&] (char*) mutable -> void {}));
}

template<typename T>
void OutputDevice<T>::setValue(T val) {
  std::ostringstream oss;
  oss << "VALUE " << val;

  ClientThread::instance().
    sendDeviceMessage(*this, 
		      oss.str().c_str());
}

#endif//SASIAE_OUTPUT_DEVICE_HPP
