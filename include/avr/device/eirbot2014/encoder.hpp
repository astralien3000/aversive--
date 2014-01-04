#ifndef AVR_ENCODER_HPP
#define AVR_ENCODER_HPP

#include "../../../common/device/eirbot2014/encoder.hpp"

template<u32* ADDR>
inline Encoder<ADDR>::Encoder(const char* name) : InputDevice<u32>(name) {}

template<u32* ADDR>
inline u32 Encoder<ADDR>::getValue(void) {
  return (*ADDR);
}


#endif//AVR_ENCODER_HPP
