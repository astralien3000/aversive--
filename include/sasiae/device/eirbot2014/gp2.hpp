#ifndef SASIAE_GP2_HPP
#define SASIAE_GP2_HPP

#include "../../../common/device/eirbot2014/gp2.hpp"

template<u8 PIN>
GP2<PIN>::GP2(const char* name) : InputDevice(name) {
}

template<u8 PIN>
u8 GP2<PIN>::getValue(void) {
  return InputDevice::getValue();
}

#endif//SASIAE_GP2_HPP
