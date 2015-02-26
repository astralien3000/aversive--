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

#ifndef SERVOMOTOR_FPGA_HPP
#define SERVOMOTOR_FPGA_HPP

#include <device/device.hpp>
#include <base/integer.hpp>

//! \brief A servomotor, used by Eirbot in 2014
//! \param ADDR : the address where to set the motor pwm

template<typename T, int ADDR>
class FpgaServomotor : Device {
public:
  FpgaServomotor(const char*);

  void setValue(u32);
};

////////////////////////////////////////////////////////////////////

template<typename T, int ADDR>
FpgaServomotor<T, ADDR>::FpgaServomotor(const char* name) : Device(name) {}

template<typename T, int ADDR>
void FpgaServomotor<T, ADDR>::setValue(u32 val) {
  *((T*)ADDR) = val;
}

#endif//SERVOMOTOR_FPGA_HPP
