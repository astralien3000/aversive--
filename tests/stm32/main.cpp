
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
/* #include <FreeRTOS.h> */
/* #include <list.h> */
/* #include <queue.h> */
/* #include <task.h> */
/* #include <semphr.h> */
/* #include <platform.h> */

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

static const u32 GPIOD_BASE_ADDR = 0x40020C00;
static volatile u32& GPIOD_MODER  = (*(volatile u32*)(GPIOD_BASE_ADDR + 0x00));
static volatile u32& GPIOD_OTYPER = (*(volatile u32*)(GPIOD_BASE_ADDR + 0x04));

static const u32 MODER0_0 = 0;
static const u32 MODER0_1 = 1;

static const u32 MODER1_0 = 2;
static const u32 MODER1_1 = 3;

static const u32 MODER2_0 = 4;
static const u32 MODER2_1 = 5;

static const u32 MODER12_0 = 24;
static const u32 MODER12_1 = 25;

static const u32 MODER13_0 = 26;
static const u32 MODER13_1 = 27;

static const u32 MODER14_0 = 28;
static const u32 MODER14_1 = 29;

static const u32 MODER15_0 = 30;
static const u32 MODER15_1 = 31;

static volatile u32& GPIOD_ODR = (*(volatile u32*)(GPIOD_BASE_ADDR + 0x14));

static volatile u32& GPIOD_BSRR = (*(volatile u32*)(GPIOD_BASE_ADDR + 0x18));

static const u32 BS12 = 12;
static const u32 BS13 = 13;
static const u32 BS14 = 14;
static const u32 BS15 = 15;

static const u32 BR12 = 28;
static const u32 BR13 = 29;
static const u32 BR14 = 30;
static const u32 BR15 = 31;

static const u32 RCC_BASE_ADDR = 0x40023800;

static volatile u32& RCC_AHB1ENR = (*(volatile u32*)(RCC_BASE_ADDR + 0x30));

static const u32 GPIODEN = 3;

extern "C" volatile void* Default_Handler;

extern "C" void __aeabi_unwind_cpp_pr0(void) {
  return;
}

volatile int test = 1;

void wait(u32 val) {
  for(volatile u32 i = 0 ; i < val && test ; i++) {}
}

int main(int argc, char* argv[]) {
  (void)argc;
  (void)argv;

  volatile void* test = Default_Handler;

  stm32::rcc::ahb1::enable::reg = stm32::rcc::ahb1::enable::all;

  stm32::gpio<3>::mode::reg = stm32::gpio<3>::mode::pin<12>::output |
      stm32::gpio<3>::mode::pin<13>::output |
      stm32::gpio<3>::mode::pin<14>::output |
      stm32::gpio<3>::mode::pin<15>::output;

  u32 i = 0;
  const u32 PERIOD = 10000;
  while(test) {
      i = (i-100) % PERIOD;
      stm32::gpio<3>::bsr::reg = stm32::gpio<3>::bsr::pin<12>::set |
          stm32::gpio<3>::bsr::pin<13>::set |
          stm32::gpio<3>::bsr::pin<14>::set |
          stm32::gpio<3>::bsr::pin<15>::set;
      wait(i);
      stm32::gpio<3>::bsr::reg = stm32::gpio<3>::bsr::pin<12>::reset |
          stm32::gpio<3>::bsr::pin<13>::reset |
          stm32::gpio<3>::bsr::pin<14>::reset |
          stm32::gpio<3>::bsr::pin<15>::reset;
      wait(PERIOD - i);
    }
  return 0;
}
