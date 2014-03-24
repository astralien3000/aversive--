#ifndef AVR_MOTOR_HPP
#define AVR_MOTOR_HPP

#include "../../../common/device/eirbot2014/motor.hpp"

#include <math/saturate.hpp>

template<typename T>
inline Motor<T>::Motor(const char* name, T* addr)
  : Device(name), _addr(addr), _inverse(false) {

}

template<typename T>
inline void Motor<T>::setValue(s32 val) {  
  if(_inverse) {
    val = -val;
  }

  (*_addr) = Math::saturate<-127, 128>(val);
}

template<typename T>
inline void Motor<T>::inverse(void) {
  _inverse = !_inverse;
}


#endif//AVR_MOTOR_HPP
