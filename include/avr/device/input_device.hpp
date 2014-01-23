#ifndef AVR_INPUT_DEVICE_HPP
#define AVR_INPUT_DEVICE_HPP

template<typename T>
struct InputDevicePrivateData {

};

#include "../../common/device/input_device.hpp"

template<typename T>
InputDevice<T>::InputDevice(const char* name) : Device(name) {
}

template<typename T>
T InputDevice<T>::getValue(void) {
  return 0;
}


#endif//AVR_INPUT_DEVICE_HPP
