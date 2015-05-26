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

/////////////////////////////////////////////////////////////

#include <math/saturate.hpp>

template<typename T>
inline Motor<T>::Motor(const char* name, T* addr)
  : Device(name), _addr(addr), _inverse(false) {

}

template<typename T>
inline void Motor<T>::setValue(s32 val) {
  if(_inverse) {
    val = -val;
  }

  (*_addr) = Math::saturate<-127, 127>(val);
}

template<typename T>
inline void Motor<T>::inverse(void) {
  _inverse = !_inverse;
}

#endif//MOTOR_HPP

