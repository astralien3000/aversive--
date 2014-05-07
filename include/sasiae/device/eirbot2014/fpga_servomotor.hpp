#ifndef SASIAE_SERVOMOTOR_FPGA_HPP
#define SASIAE_SERVOMOTOR_FPGA_HPP

#include "../../../common/device/eirbot2014/servomotor_fpga.hpp"

template<typename T, T* ADDR>
FpgaServomotor<T, ADDR>::FpgaServomotor(const char* name) : Servomotor(name) {}

template<typename T, T* ADDR>
void FpgaServomotor<T, ADDR>::setValue(u32 val) {
  Servomotor::setValue(*ADDR = val);
}

#endif//SASIAE_SERVOMOTOR_FPGA_HPP
