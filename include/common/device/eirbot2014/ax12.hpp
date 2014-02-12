#ifndef AX12_HPP
#define AX12_HPP

#include <device/input.hpp>
#include <device/output.hpp>
#include <device/device.hpp>

#include "../../base/integer.hpp"

//! \brief A digital servomotor, used by Eirbot in 2014
//! \param ADDR : the address where to set the motor pwm
/*! 

	This actuator is very specific because he works as an extern card
	so you can communicate with him. It is based on UART communication
	that's why you should read UartStream instructions.

*/

class Ax12: public Device, Input<u16>, Output<u16> {

	ax12PrivateData data;

	public:
		Ax12(char*);
		~Ax12();
		
		u16 getValue() const;
		void setValue(u16 );

		u16 getAngle();
		u16 getSpeed();
		u16 getTorque();

		void setAngle(u16 );
		void setSpeed(u16 );
		void setMode(const char* );
		void setAngleMax(u16, u16);
		void setTorqueMax(u16 );

};

#include "../../../common/device/eirbot2014/ax12.hpp"


#endif//AX12_HPP
