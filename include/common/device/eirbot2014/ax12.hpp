#ifndef AX12_HPP
#define AX12_HPP

#include <device/output_device.hpp>
#include "../../base/integer.hpp"

//! \brief A digital servomotor, used by Eirbot in 2014
//! \param ADDR : the address where to set the motor pwm
/*! 

	This actuator is very specific because he works as an extern card
	so you can communicate with him. It is based on UART communication
	that's why you should read UartStream instructions.

*/

class Ax12: public IODevice<u16,u16> {

	ax12PrivateData data;

	public:
		Ax12(char*);
		~Ax12();

		u16 getAngle() const;
		u16 getSpeed() const;
		u16 getTorque() const;

		void setAngle(u16 );
		void setSpeed(u16 );
		void setMode(char* );
		void setAngleMax(u16, u16);
		void setTorqueMax(u16 );

};


#endif//AX12_HPP
