#ifndef AVR_FPGA_MOTOR_HPP
#define AVR_FPGA_MOTOR_HPP

#include "../../../common/device/motor/fpga_motor.hpp"

#include <math/saturate.hpp>

template<typename T, int ADDR>
inline FpgaMotor<T, ADDR>::FpgaMotor(const char* name)
  : Motor(name) {
}

template<typename T, int ADDR>
inline void FpgaMotor<T, ADDR>::setValue(s32 val) {
  const s32 cmd = Math::saturate(val, _min, _max);
  if(_inverse) {
    (*(T*)ADDR) = -cmd;
  }
  else {
    (*(T*)ADDR) = cmd;
  }
}


#endif//AVR_FPGA_MOTOR_HPP
