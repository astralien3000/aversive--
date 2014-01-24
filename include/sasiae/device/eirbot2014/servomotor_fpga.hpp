#ifndef SASIAE_SERVOMOTOR_FPGA_HPP
#define SASIAE_SERVOMOTOR_FPGA_HPP

#include "../../../common/device/eirbot2014/servomotor_fpga.hpp"

template<s32* ADDR>
ServomotorFpga<ADDR>::ServomotorFpga(const char* name) : Servomotor(name) {}

template<s32* ADDR>
void ServomotorFpga<ADDR>::setValue(u32 val) {
  Servomotor::setValue(*ADDR = val);
}

#endif//SASIAE_SERVOMOTOR_FPGA_HPP
