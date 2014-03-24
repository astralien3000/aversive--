#ifndef MOTOR_HPP
#define MOTOR_HPP

#include <device/device.hpp>
#include <device/output.hpp>
#include <base/integer.hpp>

//! \brief A propulsion motor, used by Eirbot in 2014
//! \param ADDR : the address where to set the motor pwm
/*! 

  This actuator is actually connected to a FPGA, which is viewed as an
  external memory by the microcontroller. The address is set by the
  user, so I hope you know how your FPGA works ;) !

*/
template<typename T>
class Motor : public Device, public Output<s32> {
public:
  //! \brief Create a named motor
  //! \param name : the name of the device (used with sasiae)
  //! \param addr : the fpga register address
  Motor(const char* name, T* addr);

  //! \brief Send an command to the motor
  //! \warning The value is saturated if not in a valid interval
  void setValue(s32);

  //! \brief Switch positive and negative command
  void inverse(void);

private:
  volatile T* const _addr;
  bool _inverse;
};

#endif//MOTOR_HPP

