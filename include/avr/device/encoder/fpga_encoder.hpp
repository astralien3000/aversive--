#ifndef AVR_FPGA_ENCODER_HPP
#define AVR_FPGA_ENCODER_HPP

#include "../../../common/device/encoder/fpga_encoder.hpp"

template<typename T, int ADDR>
inline FpgaEncoder<T, ADDR>::FpgaEncoder(const char* name)
  : Encoder(name) {
}

template<typename T, int ADDR>
inline s32 FpgaEncoder<T, ADDR>::getValue(void) {
  if(_inverse) {
    return -(*(T*)ADDR);
  }
  else {
    return *(T*)ADDR;
  }
}

#endif//AVR_FPGA_ENCODER_HPP
