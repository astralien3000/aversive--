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
