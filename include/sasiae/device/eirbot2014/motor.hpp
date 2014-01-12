#ifndef SASIAE_MOTOR_HPP
#define SASIAE_MOTOR_HPP

#include "../../../common/device/eirbot2014/motor.hpp"

template<s32* ADDR>
Motor<ADDR>::Motor(const char* name) : OutputDevice(name) {}

template<s32* ADDR>
void Motor<ADDR>::setValue(s32 val) {
  OutputDevice::setValue(*ADDR = val);
}


#endif//SASIAE_MOTOR_HPP
