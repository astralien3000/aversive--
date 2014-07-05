
//#include <stdio.h>
//#include <stdlib.h>
//#include <stdint.h>

#include <base/integer.hpp>

namespace stm32 {

  // GPIO
  template<int ID>
  struct _gpio_mode_config {
  private:
    static const u32 OFFSET = ID * 2;
  public:
    static const u32 input = 0b00 << OFFSET;
    static const u32 output = 0b01 << OFFSET;
  };

  template<int ID>
  struct _gpio_bsr_config {
    static const u32 set = 0b1 << ID;
    static const u32 reset = 0b1 << (ID + 16);
  };

  template<u32 BASE_ADDR>
  struct _gpio {
    struct mode {
      static constexpr volatile u32& reg  = (*(volatile u32*)(BASE_ADDR + 0x00));

      template<int ID>
      struct pin : public _gpio_mode_config<ID> {};
    };

    struct bsr {
      static constexpr volatile u32& reg   = (*(volatile u32*)(BASE_ADDR + 0x18));

      template<int ID>
      struct pin : public _gpio_bsr_config<ID> {};
    };
  };

  template<int ID>
  struct gpio;

  template<>
  struct gpio<3> : public _gpio<0x40020C00> {};

  // RCC
  template<u32 BASE_ADDR>
  struct _rcc {
    struct ahb1 {
      struct enable {
        static constexpr volatile u32& reg = (*(volatile u32*)(BASE_ADDR + 0x30));

        static const u32 all = 0xFFFFFFFF;
      };
    };

    static constexpr volatile u32& ahb1enr = (*(volatile u32*)(BASE_ADDR + 0x30));
  };

  struct rcc : public _rcc<0x40023800> {};
}

#include <aversive.hpp>

volatile int test = 1;

void wait(u32 val) {
  for(volatile u32 i = 0 ; i < val && test ; i++) {}
}

int main(int argc, char* argv[]) {
  (void)argc;
  (void)argv;
  Aversive::init();

  stm32::rcc::ahb1::enable::reg = stm32::rcc::ahb1::enable::all;

  stm32::gpio<3>::mode::reg =
      stm32::gpio<3>::mode::pin<12>::output |
      stm32::gpio<3>::mode::pin<13>::output |
      stm32::gpio<3>::mode::pin<14>::output |
      stm32::gpio<3>::mode::pin<15>::output;

  u32 i = 0;
  u32 delta = 200;
  const u32 PERIOD = 10000;
  while(test) {
      i += delta;

      if(PERIOD < i) {
          delta = -delta;
          i += delta;
        }

      stm32::gpio<3>::bsr::reg =
          stm32::gpio<3>::bsr::pin<12>::set |
          stm32::gpio<3>::bsr::pin<13>::set |
          stm32::gpio<3>::bsr::pin<14>::set |
          stm32::gpio<3>::bsr::pin<15>::set;
      wait(i);
      stm32::gpio<3>::bsr::reg =
          stm32::gpio<3>::bsr::pin<12>::reset |
          stm32::gpio<3>::bsr::pin<13>::reset |
          stm32::gpio<3>::bsr::pin<14>::reset |
          stm32::gpio<3>::bsr::pin<15>::reset;
      wait(PERIOD - i);
    }
  return 0;
}
