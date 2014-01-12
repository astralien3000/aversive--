#ifndef MOTOR_HPP
#define MOTOR_HPP

#include <device/output_device.hpp>
#include "../../base/integer.hpp"

//! \brief A propulsion motor, used by Eirbot in 2014
//! \param ADDR : the address where to set the motor pwm
/*! 

  This actuator is actually connected to a FPGA, which is viewed as an
  external memory by the microcontroller. The address is set by the
  user, so I hope you know how your FPGA works ;) !

*/
template<s32* ADDR>
class Motor : public OutputDevice<s32> {
public:
  Motor(const char*);

  void setValue(s32);
};

#endif//MOTOR_HPP

