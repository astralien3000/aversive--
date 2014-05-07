#ifndef SERVOMOTOR_FPGA_HPP
#define SERVOMOTOR_FPGA_HPP

#include <device/eirbot2014/servomotor.hpp>

//! \brief A servomotor, used by Eirbot in 2014
//! \param ADDR : the address where to set the motor pwm

template<typename T, T* ADDR>
class FpgaServomotor : public Servomotor {
public:
  FpgaServomotor(const char*);

  void setValue(u32);
};



#endif//SERVOMOTOR_FPGA_HPP
