#ifndef AVR_SERVOMOTOR_FPGA_HPP
#define AVR_SERVOMOTOR_FPGA_HPP

#include "../../../common/device/eirbot2014/fpga_servomotor.hpp"

//! \todo implement !!!!

template<typename T, T* ADDR>
FpgaServomotor<T, ADDR>::FpgaServomotor(const char* name) : Servomotor(name) {}

template<typename T, T* ADDR>
void FpgaServomotor<T, ADDR>::setValue(u32 val) {
  *ADDR = val;
}


#endif//AVR_SERVOMOTOR_FPGA_HPP
