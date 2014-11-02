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
