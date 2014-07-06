#ifndef GPIO_HPP
#define GPIO_HPP

#include "architecture.hpp"
#include <aversive.hpp>

template<int ID>
class Gpio {
public:
  static inline void init(void) {
    stm32::rcc::ahb1::enable::reg |=
        stm32::rcc::ahb1::enable::gpio<ID>::enable;
    Aversive::sleep(0);
  }

  template<int PID>
  class Pin {
  public:
    static inline void setModeOutput(void) {
      stm32::gpio<ID>::mode::reg =
          (stm32::gpio<ID>::mode::reg & ~stm32::gpio<ID>::mode::template pin<PID>::mask) |
          stm32::gpio<ID>::mode::template pin<PID>::output;
    }

    static inline void setModeInput(void) {
      stm32::gpio<ID>::mode::reg =
          (stm32::gpio<ID>::mode::reg & ~stm32::gpio<ID>::mode::template pin<PID>::mask) |
          stm32::gpio<ID>::mode::template pin<PID>::input;
    }

    static inline void set(void) {
      stm32::gpio<ID>::bsr::reg =
          (stm32::gpio<ID>::bsr::reg & ~stm32::gpio<ID>::bsr::template pin<PID>::mask) |
          stm32::gpio<ID>::bsr::template pin<PID>::set;
    }

    static inline void reset(void) {
      stm32::gpio<ID>::bsr::reg =
          (stm32::gpio<ID>::bsr::reg & ~stm32::gpio<ID>::bsr::template pin<PID>::mask) |
          stm32::gpio<ID>::bsr::template pin<PID>::reset;
    }
  };
};

#endif//GPIO_HPP
