#ifndef OUTPUT_DEVICE_HPP
#define OUTPUT_DEVICE_HPP

#include "device.hpp"
#include "output.hpp"

template<typename T>
class OutputDevice : public Output<T>, public Device {
public:
  OutputDevice(const char* name);
  
  void setValue(T);
};

#endif//OUTPUT_DEVICE_HPP
