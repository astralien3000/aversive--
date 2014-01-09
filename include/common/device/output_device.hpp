#ifndef OUTPUT_DEVICE_HPP
#define OUTPUT_DEVICE_HPP

#include "device.hpp"
#include "output.hpp"

#ifndef OUTPUT_DEVICE_PRIVATE_DATA
#define OUTPUT_DEVICE_PRIVATE_DATA
#endif//OUTPUT_DEVICE_PRIVATE_DATA

template<typename T>
class OutputDevice : public Output<T>, public Device {
public:
  inline OutputDevice(const char* name) : Device(name) {}
  
  inline void setValue(T);

private:
  OUTPUT_DEVICE_PRIVATE_DATA
};

#undef  OUTPUT_DEVICE_PRIVATE_DATA

#endif//OUTPUT_DEVICE_HPP
