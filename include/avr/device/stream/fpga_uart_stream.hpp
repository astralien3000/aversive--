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

#ifndef AVR_FPGA_UART_STREAM_HPP
#define AVR_FPGA_UART_STREAM_HPP

#include <base/integer.hpp>

struct FpgaUartStreamPrivateData {
  inline FpgaUartStreamPrivateData(volatile u8& _tx, volatile u8& _tx_occup, volatile u8& _rx, volatile u8& _rx_ava)
    : tx(_tx), tx_occup(_tx_occup),
      rx(_rx), rx_ava(_rx_ava) {
  }
  volatile u8& tx;
  volatile u8& tx_occup;
  volatile u8& rx;
  volatile u8& rx_ava;
};

#include "../../../common/device/stream/fpga_uart_stream.hpp"

inline FpgaUartStream::FpgaUartStream(const char* name, u8& tx, u8& tx_occup, u8& rx, u8& rx_ava)
  : Device(name),
    _data((volatile u8&) tx, (volatile u8&) tx_occup, (volatile u8&) rx, (volatile u8&) rx_ava) {
}

inline FpgaUartStream::FpgaUartStream(const char* name, volatile u8& tx, volatile u8& tx_occup, volatile u8& rx, volatile u8& rx_ava)
  : Device(name),
    _data(tx, tx_occup, rx, rx_ava) {
}

inline char FpgaUartStream::getValue(void) {
  if(_mini_buffer_used) {
    _mini_buffer_used = false;
    return _mini_buffer;
  }
  else {
    while(!_data.rx_ava) {
    }
    return _data.rx; 
  }
}

inline void FpgaUartStream::setValue(char val) {
  while(!(255 - _data.tx_occup)) {
  }
  _data.tx = val;
}

inline u16 FpgaUartStream::bufferSize(void) const {
  return 64;
}

inline u16 FpgaUartStream::outputFreeSpace(void) const {
  return bufferSize() - _data.tx_occup;
}

inline u16 FpgaUartStream::inputUsedSpace(void) const {
  return _data.rx_ava;
}

#endif//AVR_FPGA_UART_STREAM_HPP
