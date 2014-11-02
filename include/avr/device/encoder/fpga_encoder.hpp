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

#ifndef AVR_FPGA_ENCODER_HPP
#define AVR_FPGA_ENCODER_HPP

#include "../../../common/device/encoder/fpga_encoder.hpp"

template<typename T, int ADDR>
inline FpgaEncoder<T, ADDR>::FpgaEncoder(const char* name)
  : Encoder(name) {
}

template<typename T, int ADDR>
inline s32 FpgaEncoder<T, ADDR>::getValue(void) {
  if(_inverse) {
    return -(*(T*)ADDR);
  }
  else {
    return *(T*)ADDR;
  }
}

#endif//AVR_FPGA_ENCODER_HPP
