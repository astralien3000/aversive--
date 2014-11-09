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

#ifndef FPGA_TIMER_HPP
#define FPGA_TIMER_HPP

#include <device/device.hpp>
#include <device/input.hpp>
#include <base/integer.hpp>

class FpgaTimer : public Device, public Input<s32> {
public:
  enum Mode {
    TIME_US,
    TIME_MS,
    TIME_S
  };

private:
  Mode _mod;
  
  volatile u16* const _us;
  volatile u16* const _ms;
  volatile u16* const _s;
  
public:

  FpgaTimer(const char* name, u16* s, u16* ms, u16* us)
    : Device(name),
      _s(s), _ms(ms), _us(us), 
      _mod(TIME_S) {
    
  }

  void setMode(Mode m) {
    _mod = m;
  }

  inline s32 seconds(void) {
    return (s32)(*_s);
  }

  inline s32 milliseconds(void) {
    return seconds() * 1000 + (s32)(*_ms);
  }
  
  inline s32 microseconds(void) {
    return milliseconds() * 1000 + (s32)(*_us);
  }

  s32 getValue(void) {
    if(_mod == TIME_S) {
      return seconds();
    }
    else if(_mod == TIME_MS) {
      return milliseconds();
    }
    else if(_mod == TIME_US) {
      return microseconds();
    }
  }
};

#endif//FPGA_TIMER_HPP
