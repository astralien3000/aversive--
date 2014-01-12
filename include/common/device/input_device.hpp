#ifndef INPUT_DEVICE_HPP
#define INPUT_DEVICE_HPP

#include "device.hpp"
#include "input.hpp"

template<typename T>
class InputDevice : public Input<T>, public Device {
public:
  InputDevice(const char* name);
  
  T getValue(void);

private:
  InputDevicePrivateData<T> _data;
};

#endif//INPUT_DEVICE_HPP
