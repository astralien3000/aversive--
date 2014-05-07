#ifndef FPGA_MOTOR_HPP
#define FPGA_MOTOR_HPP

#include <device/motor/motor.hpp>

//! \brief A propulsion motor, used by Eirbot in 2014
//! \param ADDR : the address where to set the motor pwm
/*! 

  This actuator is actually connected to a FPGA, which is viewed as an
  external memory by the microcontroller. The address is set by the
  user, so I hope you know how your FPGA works ;) !

*/
template<typename T, int ADDR>
class FpgaMotor : public Motor {
public:
  FpgaMotor(const char* name);

  void setValue(s32);
};

#endif//FPGA_MOTOR_HPP
