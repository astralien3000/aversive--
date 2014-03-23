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
class Motor : public Device, public Output<T> {
public:
  Motor(const char*, T*);

  void setValue(T);

private:
  T* _addr;
};

#endif//MOTOR_HPP

