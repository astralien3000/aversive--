#ifndef AVR_SERVOMOTOR_FPGA_HPP
#define AVR_SERVOMOTOR_FPGA_HPP

#include "../../../common/device/servomotor/fpga_servomotor.hpp"

template<typename T, int ADDR>
FpgaServomotor<T, ADDR>::FpgaServomotor(const char* name) : Servomotor(name) {}

template<typename T, int ADDR>
void FpgaServomotor<T, ADDR>::setValue(u32 val) {
  *((T*)ADDR) = val;
}


#endif//AVR_SERVOMOTOR_FPGA_HPP
