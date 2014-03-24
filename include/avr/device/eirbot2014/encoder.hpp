#ifndef AVR_ENCODER_HPP
#define AVR_ENCODER_HPP

#include "../../../common/device/eirbot2014/encoder.hpp"

template<typename T>
inline Encoder<T>::Encoder(const char* name, T* addr)
  : Device(name), _addr(addr), _inverse(false) {

}

template<typename T>
inline s32 Encoder<T>::getValue(void) {
  if(_inverse) {
    return -(*_addr);
  }
  else {
    return *_addr;
  }
}

template<typename T>
inline void Encoder<T>::inverse(void) {
  _inverse = !_inverse;
}

#endif//AVR_ENCODER_HPP
