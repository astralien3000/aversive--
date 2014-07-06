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

    static const u32 mask = 0b11 << OFFSET;
  };

  template<int ID>
  struct _gpio_bsr_config {
    static const u32 set = 0b1 << ID;
    static const u32 reset = 0b1 << (ID + 16);

    static const u32 mask = set | reset;
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
  struct gpio<0> : public _gpio<0x40020000> {};

  template<>
  struct gpio<1> : public _gpio<0x40020400> {};

  template<>
  struct gpio<2> : public _gpio<0x40020800> {};

  template<>
  struct gpio<3> : public _gpio<0x40020C00> {};

  template<>
  struct gpio<4> : public _gpio<0x40021000> {};

  template<>
  struct gpio<5> : public _gpio<0x40021400> {};

  template<>
  struct gpio<6> : public _gpio<0x40021800> {};

  template<>
  struct gpio<7> : public _gpio<0x40021C00> {};

  template<>
  struct gpio<8> : public _gpio<0x40022000> {};

  template<>
  struct gpio<9> : public _gpio<0x40022400> {};

  template<>
  struct gpio<10> : public _gpio<0x40022800> {};

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
