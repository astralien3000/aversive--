#ifndef HAL_AVR_MEGA_XX0_1_GPIO_HPP
#define HAL_AVR_MEGA_XX0_1_GPIO_HPP

#include <hal/gpio_interface.hpp>
#include <hdl/reg.hpp>

namespace HAL {

  namespace ATMegaxx0_1 {

    template<u8 ID>
    struct GPIO : ::HAL::Private::GPIO_DriverInterface {

#define MACRO_ENUM_ELEMENT(elem)                \
      static constexpr Type elem = Type::elem
      
      struct Mode : GPIO_DriverInterface::Mode {
        MACRO_ENUM_ELEMENT(INPUT);
        MACRO_ENUM_ELEMENT(OUTPUT);
      };

      struct OutputMode : GPIO_DriverInterface::OutputMode {
	MACRO_ENUM_ELEMENT(UNDEFINED);
	//MACRO_ENUM_ELEMENT(PUSH_PULL);
	//MACRO_ENUM_ELEMENT(OPEN_DRAIN);
      };

      struct Alternate : GPIO_DriverInterface::Alternate {
	MACRO_ENUM_ELEMENT(UNDEFINED);
      };

      struct Pull : GPIO_DriverInterface::Pull {
	MACRO_ENUM_ELEMENT(UNDEFINED);
	//MACRO_ENUM_ELEMENT(UP);
	//MACRO_ENUM_ELEMENT(DOWN);
      };

      struct Speed : GPIO_DriverInterface::Speed {
	MACRO_ENUM_ELEMENT(UNDEFINED);
      };

      struct TriggerDetection : GPIO_DriverInterface::TriggerDetection {
	MACRO_ENUM_ELEMENT(UNDEFINED);
	//MACRO_ENUM_ELEMENT(RISING);
	//MACRO_ENUM_ELEMENT(FALLING);
	//MACRO_ENUM_ELEMENT(BOTH);
      };

#undef MACRO_ENUM_ELEMENT

      //! \name Module Enable
      //! @{
      inline static bool isModuleEnabled(void) {
        return true;
      }
      
      //inline static void enableModule(void);
      //inline static void disableModule(void);
      //! @}

      //! \name Module Sleep Enable
      //! @{
      //inline static bool isModuleSleepEnabled(void);
      //inline static void enableModuleSleep(void);
      //inline static void disableModuleSleep(void);
      //! @}
        
      //! \name Settings
      //! @{
      inline static void getPinSettings(u8 pin_number, Settings& settings) {
	settings.mode = getPinMode(pin_number);
	settings.output_mode = OutputMode::UNDEFINED;
	settings.alternate = Alternate::UNDEFINED;
	settings.pull = Pull::UNDEFINED;
	settings.speed = Speed::UNDEFINED;
      }
      
      inline static void setPinSettings(u8 pin_number, const Settings& settings) {
	setPinMode(pin_number, settings.mode);
      }
      
      inline static void setPinGroupSettings(u32 pin_mask, const Settings& settings) {
	setPinGroupMode(pin_mask, settings);
      }
      //! @}

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

      inline static void setPinGroupMode(u32 pin_mask, typename Mode::Type mode) {
	if(mode == Mode::OUTPUT) {
	  HDL::GPIO<ID>::DDR |= pin_mask;
	}
	else {
	  HDL::GPIO<ID>::DDR &= ~pin_mask;
	}
      }
      
      inline static void setPinMode(u8 pin_number, typename Mode::Type mode) {
	setPinGroupMode(mode, (1 << pin_number));
      }
      //! @}

      //! \name Output Mode
      //! @{
      //inline static typename OutputMode::Type getPinOutputMode(u8 pin_number);
      //inline static void setPinOutputMode(u8 pin_number, typename OutputMode::Type);
      //inline static void setPinGroupOutputMode(u32 pin_mask, typename OutputMode::Type);
      //! @}

      //! \name Alternate Function
      //! @{
      //inline static typename Alternate::Type getPinAlternate(u8 pin_number);
      //inline static void setPinAlternate(u8 pin_number, typename Alternate::Type);
      //inline static void setPinGroupAlternate(u32 pin_mask, typename Alternate::Type);
      //! @}

      //! \name Pull policy
      //! @{
      //inline static typename Pull::Type getPinPull(u8 pin_number);
      //inline static void setPinPull(u8 pin_number, typename Pull::Type);
      //inline static void setPinGroupPull(u32 pin_mask, typename Pull::Type);
      //! @}

      //! \name Speed
      //! @{
      //inline static typename Speed::Type getPinSpeed(u8 pin_number);
      //inline static void setPinSpeed(u8 pin_number, typename Speed::Type);
      //inline static void setPinGroupSpeed(u32 pin_mask, typename Speed::Type);
      //! @}

      //! \name External Interrupt Handler
      //! @{
      //inline static IRQ_Handler getPinExtiHandler(u8 pin_number);
      //inline static void setPinExtiHandler(u8 pin_number, IRQ_Handler);
      //! @}

      //! \name Trigger Detection
      //! @{
      //inline static typename TriggerDetection::Type getPinTriggerDetection(u8 pin_number);
      //inline static void setPinTriggerDectection(u8 pin_number, typename TriggerDetection::Type);
      //! @}

      //! \name Value
      //! @{
      inline static u32 getValue(void) {
	return VAL(HDL::GPIO<ID>::PIN);
      }
      
      inline static void setValue(u32 value) {
	HDL::GPIO<ID>::PORT = value;
      }
      
      template<u32 VALUE> inline static void setValue(void) {
	static_assert(!(VALUE & ~0xFF), "Invalid value");
	HDL::GPIO<ID>::PORT = VALUE;
      }

      inline static void setPinGroupValue(u32 pin_mask, bool value) {
	if(value) {
	  HDL::GPIO<ID>::PORT |= pin_mask;
	}
	else {
	  HDL::GPIO<ID>::PORT &= ~pin_mask;
	}
      }
      
      inline static void togglePinGroup(u32 pin_mask) {
	HDL::GPIO<ID>::PORT = 
	  (HDL::GPIO<ID>::PORT & (u8)~pin_mask) |
	  (~VAL(HDL::GPIO<ID>::PIN) & pin_mask);
      }

      inline static bool getPinValue(u8 pin_number) {
	if(HDL::GPIO<ID>::PIN & (1 << pin_number)) {
	  return true;
	}
	else {
	  return false;
	}
      }
      
      inline static void setPinValue(u8 pin_number, bool value) {
	setPinGroupValue(1 << pin_number, value);
      }
      
      inline static void togglePin(u8 pin_number) {
	togglePinGroup(1 << pin_number);
      }
      //! @}

      //! \brief Templated PinGroup interface
      template<u32 PIN_MASK>
      struct PinGroup {
	static_assert(!(~0xFF & PIN_MASK), "Invalid PinGroup");
	
        //! \name Settings
        //! @{
        inline static void setSettings(const Settings& settings) {
	  setPinGroupSettings(PIN_MASK, settings);
	}
	
        template<typename Settings> inline static void setSettings(void) {
	  static_assert(Settings::mode == Mode::OUTPUT || Settings::mode == Mode::INPUT, "Not a valid GPIO Mode for this microcontroller");
	  static_assert(Settings::output_mode == OutputMode::UNDEFINED, "Pin OutputMode must be UNDEFINED");
	  static_assert(Settings::alternate == Alternate::UNDEFINED, "Pin Alternate Function must be UNDEFINED");
	  static_assert(Settings::pull == Pull::UNDEFINED, "Pin Pull Mode must be UNDEFINED");
	  static_assert(Settings::speed == Speed::UNDEFINED, "Pin Speed must be UNDEFINED");

	  setMode(Settings::mode);
	}
        //! @}

        //! \name Mode
        //! @{
        inline static void setMode(typename Mode::Type mode) {
	  setPinGroupMode(PIN_MASK, mode);
	}
	
        template<typename Mode::Type MODE> inline static void setMode(void) {
	  setMode(MODE);
	}
        //! @}

        //! \name Output Mode
        //! @{
        //inline static void setOutputMode(typename OutputMode::Type);
        //template<typename OutputMode::Type> inline static void setOutputMode(void);
        //! @}

        //! \name Alternate Function
        //! @{
        //inline static void setAlternate(typename Alternate::Type);
        //template<typename Alternate::Type> inline static void setAlternate(void);
        //! @}

        //! \name Pull policy
        //! @{
        //inline static void setPull(typename Pull::Type);
        //template<typename Pull::Type> inline static void setPull(void);
        //! @}

        //! \name Speed
        //! @{
        //inline static void setSpeed(typename Speed::Type);
        //template<typename Speed::Type> inline static void setSpeed(void);
        //! @}

        //! \name Value
        //! @{
        inline static void setValue(bool value) {
	  setPinGroupValue(PIN_MASK, value);
	}
	
        template<bool VALUE> inline static void setValue(void) {
	  setValue(VALUE);
	}
	
        inline static void toggle(void) {
	  togglePinGroup(PIN_MASK);
	}
        //! @}
      };

      //! \brief Templated Pin interface
      template<u8 PIN_NUMBER>
      struct Pin {	
        //! \name Settings
        //! @{
        inline static void getSettings(Settings& settings) {
	  getPinSettings(PIN_NUMBER, settings);
	}
	
        inline static void setSettings(const Settings& settings) {
	  setMode(settings.mode);
	}
	
        template<typename Settings> inline static void setSettings(void) {
	  static_assert(Settings::mode == Mode::OUTPUT || Settings::mode == Mode::INPUT, "Not a valid GPIO Mode for this microcontroller");
	  static_assert(Settings::output_mode == OutputMode::UNDEFINED, "Pin OutputMode must be UNDEFINED");
	  static_assert(Settings::alternate == Alternate::UNDEFINED, "Pin Alternate Function must be UNDEFINED");
	  static_assert(Settings::pull == Pull::UNDEFINED, "Pin Pull Mode must be UNDEFINED");
	  static_assert(Settings::speed == Speed::UNDEFINED, "Pin Speed must be UNDEFINED");

	  setMode(Settings::mode);
	}
        //! @}

        //! \name Mode
        //! @{
        inline static typename Mode::Type getMode(void) {
	  if(HDL::GPIO<ID>::Fields::template DDR<PIN_NUMBER>::field) {
	    return Mode::OUTPUT;
	  }
	  else {
	    return Mode::INPUT;
	  }
	}
	
        inline static void setMode(typename Mode::Type mode) {
	  HDL::GPIO<ID>::Fields::template DDR<PIN_NUMBER>::field = (mode == Mode::OUTPUT);
	}
	
        template<typename Mode::Type MODE> inline static void setMode(void) {
	  HDL::GPIO<ID>::Fields::template DDR<PIN_NUMBER>::field = (MODE == Mode::OUTPUT);
	}
        //! @}

        //! \name Output Mode
        //! @{
        //inline static typename OutputMode::Type getOutputMode(void);
        //inline static void setOutputMode(typename OutputMode::Type);
        //template<typename OutputMode::Type> inline static void setOutputMode(void);
        //! @}

        //! \name Alternate Function
        //! @{
        //inline static typename Alternate::Type getAlternate(void);
        //inline static void setAlternate(typename Alternate::Type);
        //template<typename Alternate::Type> inline static void setAlternate(void);
        //! @}

        //! \name Pull policy
        //! @{
        //inline static typename Pull::Type getPull(void);
        //inline static void setPull(typename Pull::Type);
        //template<typename Pull::Type> inline static void setPull(void);
        //! @}

        //! \name Speed
        //! @{
        //inline static typename Speed::Type getSpeed(void);
        //inline static void setSpeed(typename Speed::Type);
        //template<typename Speed::Type> inline static void setSpeed(void);
        //! @}

        //! \name External Interrupt Handler
        //! @{
        //inline static IRQ_Handler getExtiHandler(void);
        //inline static void setExtiHandler(IRQ_Handler);
        //! @}

        //! \name Trigger Detection
        //! @{
        //inline static typename TriggerDetection::Type getTriggerDetection(void);
        //inline static void setTriggerDectection(typename TriggerDetection::Type);
        //template<typename TriggerDetection::Type> inline static void setTriggerDectection(void);
        //! @}

        //! \name Value
        //! @{
        inline static bool getValue(void) {
	  return HDL::GPIO<ID>::Fields::template PIN<PIN_NUMBER>::field;
	}
	
        inline static void setValue(bool value) {
	  HDL::GPIO<ID>::Fields::template PORT<PIN_NUMBER>::field = value;
	}
	
        inline static void toggle(void) {
	  // Check if the pin exist
	  (void) HDL::GPIO<ID>::Fields::template PORT<PIN_NUMBER>::field;
	  togglePin(PIN_NUMBER);
	}
	
        template<bool VALUE> inline static void setValue(void) {
	  HDL::GPIO<ID>::Fields::template PORT<PIN_NUMBER>::field = VALUE;
	}
        //! @}

      };
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

    // \brief This is used to specify settings that can be on any GPIO
    using GPIOx = GPIO<-1>;
  }
}

namespace HAL {
  using namespace ATMegaxx0_1;
}

#endif//HAL_AVR_MEGA_XX0_1_GPIO_HPP
