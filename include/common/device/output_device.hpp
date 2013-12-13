#ifndef OUTPUT_DEVICE_HPP
#define OUTPUT_DEVICE_HPP

#include "device.hpp"
#include "output.hpp"

template<typename T>
class OutputDevice : public Output<T>, public Device {
public:
  inline OutputDevice(const char* name) : Device(name) {}
  
  inline void setOutput(T&);

private:
  struct PrivateData;
  PrivateData _data;
};


#endif//OUTPUT_DEVICE_HPP
