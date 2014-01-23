#ifndef AVR_OUTPUT_DEVICE_HPP
#define AVR_OUTPUT_DEVICE_HPP

#include "../../common/device/output_device.hpp"

template<typename T>
OutputDevice<T>::OutputDevice(const char* name) : Device(name) {
}

template<typename T>
void OutputDevice<T>::setValue(T val) {
  (void)val;
}

#endif//AVR_OUTPUT_DEVICE_HPP
