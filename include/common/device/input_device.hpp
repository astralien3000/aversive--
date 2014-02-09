#ifndef SIMPLE_INPUT_DEVICE_HPP
#define SIMPLE_INPUT_DEVICE_HPP

#include <device/device.hpp>
#include <device/input.hpp>

template<typename T>
class SimpleInputDevice : public Input<T>, public Device {
public:
  SimpleInputDevice(const char* name);
  
  T getValue(void);

private:
  SimpleInputDevicePrivateData<T> _data;
};

#endif//SIMPLE_INPUT_DEVICE_HPP
