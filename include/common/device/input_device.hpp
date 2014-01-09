#ifndef INPUT_DEVICE_HPP
#define INPUT_DEVICE_HPP

#include "device.hpp"
#include "input.hpp"

#ifndef INPUT_DEVICE_PRIVATE_DATA
#define INPUT_DEVICE_PRIVATE_DATA
#endif//INPUT_DEVICE_PRIVATE_DATA

template<typename T>
class InputDevice : public Input<T>, public Device {
public:
  inline InputDevice(const char* name) : Device(name) {}
  
  inline T getValue(void);

private:
  INPUT_DEVICE_PRIVATE_DATA
};

#undef  INPUT_DEVICE_PRIVATE_DATA

#endif//INPUT_DEVICE_HPP
