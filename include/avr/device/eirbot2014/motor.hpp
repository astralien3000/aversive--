#ifndef AVR_MOTOR_HPP
#define AVR_MOTOR_HPP

#include "../../../common/device/eirbot2014/motor.hpp"

template<s32* ADDR>
inline Motor<ADDR>::Motor(const char* name) : OutputDevice<s32>(name) {}

template<s32* ADDR>
inline void Motor<ADDR>::setValue(s32 val) {
  (*ADDR) = val;
}

#endif//AVR_MOTOR_HPP
