#ifndef SASIAE_ENCODER_HPP
#define SASIAE_ENCODER_HPP

#include "../../../common/device/eirbot2014/encoder.hpp"

template<typename T>
Encoder<T>::Encoder(const char* name, T* addr) : InputDevice<T>(name), _addr(addr) {
}

template<typename T>
T Encoder<T>::getValue(void) {
  return *_addr = InputDevice<T>::getValue();
}

#endif//SASIAE_ENCODER_HPP
