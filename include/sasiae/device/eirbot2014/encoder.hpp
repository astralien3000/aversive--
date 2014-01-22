#ifndef SASIAE_ENCODER_HPP
#define SASIAE_ENCODER_HPP

#include "../../../common/device/eirbot2014/encoder.hpp"

template<u32* ADDR>
Encoder<ADDR>::Encoder(const char* name) : InputDevice(name) {
}

template<u32* ADDR>
u32 Encoder<ADDR>::getValue(void) {
  return *ADDR = InputDevice::getValue();
}

#endif//SASIAE_ENCODER_HPP
