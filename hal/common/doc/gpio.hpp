/*!
\page HAL GPIO Example
\brief This file is a template you can use to develop your driver
\todo 
 - Rename the security aganst include loops
 - Rename the Example namespace
 - Uncomment the functionalities that are available on your hardware
 - Implement it !
*/

#ifndef HAL_COMMON_GPIO_EXAMPLE_HPP
#define HAL_COMMON_GPIO_EXAMPLE_HPP

#include <hal/gpio_interface.hpp>

namespace HAL {
  
  namespace Example {
  
    template<u8 ID>
    struct GPIO : ::HAL::Private::GPIO_DriverInterface {
      
      //! \brief This is just an alias to define an available enum value
#define MACRO_ENUM_ELEMENT(elem)				\
      static constexpr Type elem = Type::elem

      struct Mode : GPIO_DriverInterface::Mode {
	//MACRO_ENUM_ELEMENT(UNDEFINED);
	//MACRO_ENUM_ELEMENT(INPUT);
	//MACRO_ENUM_ELEMENT(OUTPUT);
	//MACRO_ENUM_ELEMENT(ALTERNATE_FUNCTION);
      };
    
      struct OutputMode : GPIO_DriverInterface::OutputMode {
	//MACRO_ENUM_ELEMENT(UNDEFINED);
	//MACRO_ENUM_ELEMENT(PUSH_PULL);
	//MACRO_ENUM_ELEMENT(OPEN_DRAIN);
      };

      struct Alternate : GPIO_DriverInterface::Alternate {
	//MACRO_ENUM_ELEMENT(UNDEFINED);
      };

      struct Pull : GPIO_DriverInterface::Pull {
	//MACRO_ENUM_ELEMENT(UNDEFINED);
	//MACRO_ENUM_ELEMENT(UP);
	//MACRO_ENUM_ELEMENT(DOWN);
      };

      struct Speed : GPIO_DriverInterface::Speed {
	//MACRO_ENUM_ELEMENT(UNDEFINED);
      };

      struct TriggerDetection : GPIO_DriverInterface::TriggerDetection {
	//MACRO_ENUM_ELEMENT(UNDEFINED);
	//MACRO_ENUM_ELEMENT(RISING);
	//MACRO_ENUM_ELEMENT(FALLING);
	//MACRO_ENUM_ELEMENT(BOTH);
      };

#undef MACRO_ENUM_ELEMENT

      //static bool isModuleEnabled(void) {}
      //static void enableModule(void) {}
      //static void disableModule(void) {}
      
      //static bool isModuleSleepEnabled(void) {}
      //static void enableModuleSleep(void) {}
      //static void disableModuleSleep(void) {}
      
      //static void getPinSettings(u8 pin_number, Settings&) {}
      //static void setPinSettings(u8 pin_number, const Settings&) {}
      //static void setPinGroupSettings(u32 pin_mask, const Settings&) {}
      
      //static Mode::Type getPinMode(u8 pin_number) {}
      //static void setPinMode(u8 pin_number, Mode::Type) {}
      //static void setPinGroupMode(u32 pin_mask, Mode::Type) {}
      
      //static OutputMode::Type getPinOutputMode(u8 pin_number) {}
      //static void setPinOutputMode(u8 pin_number, OutputMode::Type) {}
      //static void setPinGroupOutputMode(u32 pin_mask, OutputMode::Type) {}
      
      //static Alternate::Type getPinAlternate(u8 pin_number) {}
      //static void setPinAlternate(u8 pin_number, Alternate::Type) {}
      //static void setPinGroupAlternate(u32 pin_mask, Alternate::Type) {}
      
      //static Pull::Type getPinPull(u8 pin_number) {}
      //static void setPinPull(u8 pin_number, Pull::Type) {}
      //static void setPinGroupPull(u32 pin_mask, Pull::Type) {}
      
      //static Speed::Type getPinSpeed(u8 pin_number) {}
      //static void setPinSpeed(u8 pin_number, Speed::Type) {}
      //static void setPinGroupSpeed(u32 pin_mask, Speed::Type) {}
      
      //static IRQ_Handler getPinExtiHandler(u8 pin_number) {}
      //static void setPinExtiHandler(u8 pin_number, IRQ_Handler) {}
      
      //static TriggerDetection::Type getPinTriggerDetection(u8 pin_number) {}
      //static void setPinTriggerDectection(u8 pin_number, TriggerDetection::Type) {}
      
      //static u32 getValue(void) {}
      //static void setValue(u32 value) {}
      //template<u32 VALUE> static void setValue(void) {}

      //static bool getPinValue(u8 pin_number) {}
      //static void setPinValue(u8 pin_number, bool value) {}
      //static void togglePin(u8 pin_number) {}

      //static void setPinGroupValue(u32 pin_mask, bool value) {}
      //static void togglePinGroup(u32 pin_mask) {}

      template<u32 PIN_MASK>
      struct PinGroup : GPIO_DriverInterface::PinGroup<PIN_MASK> {
	//static void setSettings(const Settings&) {}
	//template<typename Settings> static void setSettings(void) {}
	
	//static void setMode(Mode::Type) {}
	//template<Mode::Type> static void setMode(void) {}
	
	//static void setOutputMode(OutputMode::Type) {}
	//template<OutputMode::Type> static void setOutputMode(void) {}
	
	//static void setAlternate(Alternate::Type) {}
	//template<Alternate::Type> static void setAlternate(void) {}
	
	//static void setPull(Pull::Type) {}
	//template<Pull::Type> static void setPull(void) {}
	
	//static void setSpeed(Speed::Type) {}
	//template<Speed::Type> static void setSpeed(void) {}
	
	//static void setValue(bool value) {}
	//template<bool VALUE> static void setValue(void) {}
	//static void toggle(void) {}
      };

      template<u8 PIN_NUMBER>
      struct Pin : GPIO_DriverInterface::Pin<PIN_NUMBER> {
	//static void getSettings(Settings&) {}
	//static void setSettings(const Settings&) {}
	//template<typename Settings> static void setSettings(void) {}
	
	//static Mode::Type getMode(void) {}
	//static void setMode(Mode::Type) {}
	//template<Mode::Type> static void setMode(void) {}
	
	//static OutputMode::Type getOutputMode(void) {}
	//static void setOutputMode(OutputMode::Type) {}
	//template<OutputMode::Type> static void setOutputMode(void) {}
	
	//static Alternate::Type getAlternate(void) {}
	//static void setAlternate(Alternate::Type) {}
	//template<Alternate::Type> static void setAlternate(void) {}
	
	//static Pull::Type getPull(void) {}
	//static void setPull(Pull::Type) {}
	//template<Pull::Type> static void setPull(void) {}
	
	//static Speed::Type getSpeed(void) {}
	//static void setSpeed(Speed::Type) {}
	//template<Speed::Type> static void setSpeed(void) {}
	
	//static IRQ_Handler getExtiHandler(void) {}
	//static void setExtiHandler(IRQ_Handler) {}
	
	//static TriggerDetection::Type getTriggerDetection(void) {}
	//static void setTriggerDectection(TriggerDetection::Type) {}
	//template<TriggerDetection::Type> static void setTriggerDectection(void) {}
	
	//static bool getValue(void) {}
	//static void setValue(bool value) {}
	//static void toggle(void) {}
	//template<bool VALUE> static void setValue(void) {}

      };
    };
    
  }  
}

#endif//HAL_COMMON_GPIO_EXAMPLE_HPP
