#ifndef AX12_HPP
#define AX12_HPP

#include <device/device.hpp>
#include <device/output.hpp>
#include <base/integer.hpp>

//! \brief A digital servomotor, used by Eirbot in 2014
//! \param ADDR : the address where to set the motor pwm
/*! 

	This actuator is very specific because he works as an extern card
	so you can communicate with him. It is based on UART communication
	that's why you should read UartStream instructions.

*/
template<s32* ADDR>
class Motor : public Device, public Output<s32> {
public:
  Motor(const char*);

  void setValue(s32);
};

#endif//AX12_HPP
