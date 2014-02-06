#ifndef AVR_ENCODER_HPP
#define AVR_ENCODER_HPP

#include "../../../common/device/eirbot2014/encoder.hpp"

template<typename T>
inline Encoder<T>::Encoder(const char* name, T* addr) : InputDevice<T>(name), _addr(addr) {}

template<typename T>
inline T Encoder<T>::getValue(void) {
  return *_addr;
}


#endif//AVR_ENCODER_HPP
