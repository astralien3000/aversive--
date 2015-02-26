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

#ifndef SASIAE_SERVOMOTOR_FPGA_HPP
#define SASIAE_SERVOMOTOR_FPGA_HPP

#include <device/eirbot2014/fpga_servomotor.hpp>

template<typename T, int ADDR>
FpgaServomotor<T, ADDR>::FpgaServomotor(const char* name) : Servomotor(name) {}

template<typename T, int ADDR>
void FpgaServomotor<T, ADDR>::setValue(u32 val) {
  Servomotor::setValue(*(T*)ADDR = val);
}

#endif//SASIAE_SERVOMOTOR_FPGA_HPP
