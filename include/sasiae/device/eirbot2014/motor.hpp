#ifndef SASIAE_MOTOR_HPP
#define SASIAE_MOTOR_HPP

#include "../../../common/device/eirbot2014/motor.hpp"

template<typename T>
Motor<T>::Motor(const char* name, T* addr) : SimpleOutputDevice<T>(name), _addr(addr) {}

template<typename T>
void Motor<T>::setValue(T val) {
  SimpleOutputDevice<T>::setValue(*_addr = val);
}


#endif//SASIAE_MOTOR_HPP
