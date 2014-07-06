#include <base/integer.hpp>
#include <hardware/architecture.hpp>
#include <aversive.hpp>

int main(int argc, char* argv[]) {
  (void)argc;
  (void)argv;

  Aversive::init();

  stm32::rcc::ahb1::enable::reg |=
      stm32::rcc::ahb1::enable::gpio<3>::enable;
  Aversive::sleep(0);


  stm32::gpio<3>::bsr::reg =
      stm32::gpio<3>::bsr::pin<13>::set |
      stm32::gpio<3>::bsr::pin<14>::set |
      stm32::gpio<3>::bsr::pin<15>::set;

  stm32::gpio<3>::mode::reg =
      stm32::gpio<3>::mode::pin<12>::output |
      stm32::gpio<3>::mode::pin<13>::output |
      stm32::gpio<3>::mode::pin<14>::output |
      stm32::gpio<3>::mode::pin<15>::output;

  while(Aversive::sync()) {
    }

  return 0;
}
