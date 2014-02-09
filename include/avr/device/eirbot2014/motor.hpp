#ifndef AVR_MOTOR_HPP
#define AVR_MOTOR_HPP

#include "../../../common/device/eirbot2014/motor.hpp"

#include <math/saturate.hpp>

template<typename T>
inline Motor<T>::Motor(const char* name, T* addr) : SimpleOutputDevice<T>(name), _addr(addr) {}

template<typename T>
inline void Motor<T>::setValue(T val) {
  *_addr = val;
}

#endif//AVR_MOTOR_HPP
