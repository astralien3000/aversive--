#include <base/integer.hpp>
#include <hardware/architecture.hpp>
#include <aversive.hpp>

int main(int argc, char* argv[]) {
  (void)argc;
  (void)argv;

  stm32::rcc::ahb1::enable::reg = stm32::rcc::ahb1::enable::all;

  Aversive::init();

  stm32::gpio<3>::mode::reg =
      stm32::gpio<3>::mode::pin<12>::output |
      stm32::gpio<3>::mode::pin<13>::output |
      stm32::gpio<3>::mode::pin<14>::output |
      stm32::gpio<3>::mode::pin<15>::output;


  stm32::gpio<3>::bsr::reg =
      stm32::gpio<3>::bsr::pin<13>::set |
      stm32::gpio<3>::bsr::pin<14>::set |
      stm32::gpio<3>::bsr::pin<15>::set;


  u32 i = 0;
  u32 delta = 200;
  const u32 PERIOD = 10000;
  while(Aversive::sync()) {
      i += delta;

      if(PERIOD < i) {
          delta = -delta;
          i += delta;
        }

      stm32::gpio<3>::bsr::reg =
          stm32::gpio<3>::bsr::pin<12>::set;
    }

  return 0;
}
