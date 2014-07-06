#ifndef STM32F4_HPP
#define STM32F4_HPP

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
  template<int ID>
  struct _rcc_ahb1_enable_gpio {
    static const u32 enable = (1 << ID);
  };

  template<u32 BASE_ADDR>
  struct _rcc {
    struct ahb1 {
      struct enable {
        static constexpr volatile u32& reg = (*(volatile u32*)(BASE_ADDR + 0x30));

        static const u32 all = 0xFFFFFFFF;

        template<int ID>
        struct gpio : public _rcc_ahb1_enable_gpio<ID> {};
      };
    };

    static constexpr volatile u32& ahb1enr = (*(volatile u32*)(BASE_ADDR + 0x30));
  };

  struct rcc : public _rcc<0x40023800> {};
}

#endif//STM32F4_HPP
