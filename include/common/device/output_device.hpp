#ifndef SIMPLE_OUTPUT_DEVICE_HPP
#define SIMPLE_OUTPUT_DEVICE_HPP

#include "device.hpp"
#include "output.hpp"

template<typename T>
class SimpleOutputDevice : public Output<T>, public Device {
public:
  SimpleOutputDevice(const char* name);
  
  void setValue(T);
};

#endif//SIMPLE_OUTPUT_DEVICE_HPP
