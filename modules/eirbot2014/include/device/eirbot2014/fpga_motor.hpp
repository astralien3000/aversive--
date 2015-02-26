/*
    Aversive++                                                           
    Copyright (C) 2014 Eirbot                                            
                                                                         
    This program is free software: you can redistribute it and/or modify 
    it under the terms of the GNU General Public License as published by 
    the Free Software Foundation, either version 3 of the License, or    
    (at your option) any later version.                                  
                                                                         
    This program is distributed in the hope that it will be useful,      
    but WITHOUT ANY WARRANTY; without even the implied warranty of       
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the        
    GNU General Public License for more details.                         
                                                                         
    You should have received a copy of the GNU General Public License    
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef FPGA_MOTOR_HPP
#define FPGA_MOTOR_HPP

#include <device/eirbot2014/motor.hpp>

//! \brief A propulsion motor, used by Eirbot in 2014
//! \param ADDR : the address where to set the motor pwm
/*! 

  This actuator is actually connected to a FPGA, which is viewed as an
  external memory by the microcontroller. The address is set by the
  user, so I hope you know how your FPGA works ;) !

*/
template<typename T, int ADDR>
class FpgaMotor : public Motor<T> {
  static constexpr T _min = -127;
  static constexpr T _max =  127;

public:
  FpgaMotor(const char* name);

  void setValue(s32);
};

///////////////////////////////////////////////////////////////////

#include <math/saturate.hpp>

template<typename T, int ADDR>
inline FpgaMotor<T, ADDR>::FpgaMotor(const char* name)
  : Motor<T>(name) {
}

template<typename T, int ADDR>
inline void FpgaMotor<T, ADDR>::setValue(s32 val) {
  const s32 cmd = Math::saturate(val, _min, _max);
  if(Motor<T>::_inverse) {
    (*(T*)ADDR) = -cmd;
  }
  else {
    (*(T*)ADDR) = cmd;
  }
}



#endif//FPGA_MOTOR_HPP
