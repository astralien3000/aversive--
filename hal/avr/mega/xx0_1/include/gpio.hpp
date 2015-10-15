#ifndef HAL_AVR_MEGA_XX0_1_GPIO_HPP
#define HAL_AVR_MEGA_XX0_1_GPIO_HPP

#include <hal/gpio_interface.hpp>
#include <hdl/reg.hpp>

namespace HAL {

  namespace ATMegaxx0_1 {

    template<u8 ID>
    struct GPIO : ::HAL::Private::GPIO::DriverInterface {

#define MACRO_ENUM_ELEMENT(elem)		\
      static constexpr Type elem = Type::elem
      
      struct Mode : ::HAL::Private::GPIO::Mode {
	MACRO_ENUM_ELEMENT(UNDEFINED);
	MACRO_ENUM_ELEMENT(INPUT);
	MACRO_ENUM_ELEMENT(OUTPUT);
      };

#undef MACRO_ENUM_ELEMENT

      //! \brief the module is always enabled
      inline static constexpr bool isModuleEnabled(void) {
	return true;
      }

      //! \name Mode
      //! @{
      inline static typename Mode::Type getPinMode(u8 pin_number) {
	if(HDL::GPIO<ID>::DDR & (1 << pin_number)) {
	  return Mode::OUTPUT;
	}
	else {
	  return Mode::INPUT;
	}
      }
      
      inline static void setPinMode(typename Mode::Type type, u8 pin_number) {
	setMode(type, (1 << pin_number));
      }
      
      inline static void setMode(typename Mode::Type type, u32 pin_mask) {
	if(type == Mode::INPUT) {
	  HDL::GPIO<ID>::DDR &= (u8)~pin_mask;
	}
	else if(type == Mode::OUTPUT) {
	  HDL::GPIO<ID>::DDR |= (u8)pin_mask;
	}
      }
      
      template<u8 PIN_NUMBER>
      inline static typename Mode::Type getPinMode(void) {
	if(HDL::GPIO<ID>::Fields::template DDR<PIN_NUMBER>::field) {
	  return Mode::OUTPUT;
	}
	else {
	  return Mode::INPUT;
	}
      }
	
      template<typename Mode::Type TYPE, u8 PIN_NUMBER>
      inline static void setPinMode(void) {
	static_assert((TYPE == Mode::INPUT) || (TYPE == Mode::OUTPUT),
		      "This mode is not supported for this microcontroller");
	
	if(TYPE == Mode::INPUT) {
	  HDL::GPIO<ID>::Fields::template DDR<PIN_NUMBER>::field = false;
	}
	else if(TYPE == Mode::OUTPUT) {
	  HDL::GPIO<ID>::Fields::template DDR<PIN_NUMBER>::field = true;
	}
      }
      
      template<typename Mode::Type TYPE, u32 PIN_MASK>
      inline static void setMode(void) {
	static_assert((TYPE == Mode::INPUT) || (TYPE == Mode::OUTPUT),
		      "This mode is not supported for this microcontroller");
	static_assert((PIN_MASK & 0xFF) == PIN_MASK,
		      "Invalid PIN MASK");

      	if(TYPE == Mode::INPUT) {
	  HDL::GPIO<ID>::DDR &= (u8)~PIN_MASK;
	}
	else if(TYPE == Mode::OUTPUT) {
	  HDL::GPIO<ID>::DDR |= (u8)PIN_MASK;
	}
      }
      //! @}

      //! \name Value
      //! @{
      inline static bool getPinValue(u8 pin_number) {
	return (HDL::GPIO<ID>::PIN & (1 << pin_number)) == (1 << pin_number);
      }
      
      inline static void setPinValue(bool value, u8 pin_number) {
	if(value) {
	  HDL::GPIO<ID>::PORT |= 1 << pin_number;
	}
	else {
	  HDL::GPIO<ID>::PORT &= ~(1 << pin_number);
	}
      }
      
      //! \todo TEST
      inline static void togglePin(u8 pin_number) {
	const u8 msk = 1 << pin_number;
	if(HDL::GPIO<ID>::PORT & msk) {
	  HDL::GPIO<ID>::PORT &= ~msk;
	}
	else {
	  HDL::GPIO<ID>::PORT |= msk;
	}
      }
      
      inline static u32 getValue(void) {
	return HDL::GPIO<ID>::PIN;
      }
      
      inline static void setValue(u32 value) {
	HDL::GPIO<ID>::PORT = value;
      }
      
      inline static void setValue(bool value, u32 pin_mask) {
	if(value) {
	  HDL::GPIO<ID>::PORT &= (u8)~pin_mask;
	}
	else {
	  HDL::GPIO<ID>::PORT |= (u8)pin_mask;
	}
      }

      //! \todo TEST
      inline static void toggle(u32 pin_mask) {
	HDL::GPIO<ID>::PORT =
	  (HDL::GPIO<ID>::PORT & (u8)~pin_mask) |
	  ((~VAL(HDL::GPIO<ID>::PORT)) & (u8)pin_mask);
      }
      
      template<u8 PIN_NUMBER>
      inline static bool getPinValue(void) {
	return HDL::GPIO<ID>::Fields::template PIN<PIN_NUMBER>::field;
      }
      
      template<bool VALUE, u8 PIN_NUMBER>
      inline static void setPinValue(void) {
	HDL::GPIO<ID>::Fields::template PORT<PIN_NUMBER>::field = VALUE;
      }
      
      //! \todo TEST
      template<u8 PIN_NUMBER>
      static void togglePin(void) {
	using PORTField = typename HDL::GPIO<ID>::Fields::template PORT<PIN_NUMBER>;
	PORTField::field = !PORTField::field;
      }

      template<u32 VALUE> static void setValue(void) {
	HDL::GPIO<ID>::PORT = (u8)VALUE;
      }
      
      template<bool VALUE, u32 PIN_MASK> static void setValue(void) {
	if(VALUE) {
	  HDL::GPIO<ID>::PORT |= (u8)PIN_MASK;
	}
	else {
	  HDL::GPIO<ID>::PORT &= (u8)~PIN_MASK;
	}
      }
      
      //! \todo TEST
      template<u32 PIN_MASK> static void toggle(void) {
	HDL::GPIO<ID>::PORT =
	  (HDL::GPIO<ID>::PORT & (u8)~PIN_MASK) |
	  ((~VAL(HDL::GPIO<ID>::PORT)) & (u8)PIN_MASK);
      }
      //! @}
    };

    using GPIO_A = GPIO<0>;
    using GPIO_B = GPIO<1>;
    using GPIO_C = GPIO<2>;
    using GPIO_D = GPIO<3>;
    using GPIO_E = GPIO<4>;
    using GPIO_F = GPIO<5>;
    using GPIO_G = GPIO<6>;
    using GPIO_H = GPIO<7>;
    using GPIO_I = GPIO<8>;
    using GPIO_J = GPIO<9>;
    using GPIO_K = GPIO<10>;
    using GPIO_L = GPIO<11>;
  }
}

namespace HAL {
  using namespace ATMegaxx0_1;
}

#endif//HAL_AVR_MEGA_XX0_1_GPIO_HPP
