#ifndef AVR_INPUT_DEVICE_HPP
#define AVR_INPUT_DEVICE_HPP

template<typename T>
struct SimpleInputDevicePrivateData {

};

#include "../../common/device/input_device.hpp"

template<typename T>
SimpleInputDevice<T>::SimpleInputDevice(const char* name) : Device(name) {
}

template<typename T>
T SimpleInputDevice<T>::getValue(void) {
  return 0;
}


#endif//AVR_INPUT_DEVICE_HPP
