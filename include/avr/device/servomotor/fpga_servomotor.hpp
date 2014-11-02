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

#ifndef AVR_SERVOMOTOR_FPGA_HPP
#define AVR_SERVOMOTOR_FPGA_HPP

#include "../../../common/device/servomotor/fpga_servomotor.hpp"

template<typename T, int ADDR>
FpgaServomotor<T, ADDR>::FpgaServomotor(const char* name) : Servomotor(name) {}

template<typename T, int ADDR>
void FpgaServomotor<T, ADDR>::setValue(u32 val) {
  *((T*)ADDR) = val;
}


#endif//AVR_SERVOMOTOR_FPGA_HPP
