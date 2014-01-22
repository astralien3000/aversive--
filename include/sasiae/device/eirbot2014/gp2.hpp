#ifndef SASIAE_GP2_HPP
#define SASIAE_GP2_HPP

#include "../../../common/device/eirbot2014/gp2.hpp"

template<u32* ADDR>
GP2<ADDR>::GP2(const char* name) : InputDevice(name) {
}

template<u32* ADDR>
u32 GP2<ADDR>::getValue(void) {
  return *ADDR = InputDevice::getValue();
}

#endif//SASIAE_GP2_HPP
