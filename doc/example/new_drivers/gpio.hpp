/*
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
#include <hal/macros_define.hpp>

namespace HAL {
  
  namespace Example {
  
    template<u8 ID>
    struct GPIO : ::HAL::GPIO_DriverInterface<u8> {

      struct Mode : GPIO_DriverInterface::Mode {
        //_AVERSIVE_AVAILABLE_ELEMENT(UNDEFINED);
        //_AVERSIVE_AVAILABLE_ELEMENT(INPUT);
        //_AVERSIVE_AVAILABLE_ELEMENT(OUTPUT);
        //_AVERSIVE_AVAILABLE_ELEMENT(ALTERNATE_FUNCTION);
      };
    
      struct OutputMode : GPIO_DriverInterface::OutputMode {
        //_AVERSIVE_AVAILABLE_ELEMENT(UNDEFINED);
        //_AVERSIVE_AVAILABLE_ELEMENT(PUSH_PULL);
        //_AVERSIVE_AVAILABLE_ELEMENT(OPEN_DRAIN);
      };

      struct Alternate : GPIO_DriverInterface::Alternate {
        //_AVERSIVE_AVAILABLE_ELEMENT(UNDEFINED);
      };

      struct Pull : GPIO_DriverInterface::Pull {
        //_AVERSIVE_AVAILABLE_ELEMENT(UNDEFINED);
        //_AVERSIVE_AVAILABLE_ELEMENT(UP);
        //_AVERSIVE_AVAILABLE_ELEMENT(DOWN);
      };

      struct Speed : GPIO_DriverInterface::Speed {
        //_AVERSIVE_AVAILABLE_ELEMENT(UNDEFINED);
      };

      struct TriggerDetection : GPIO_DriverInterface::TriggerDetection {
        //_AVERSIVE_AVAILABLE_ELEMENT(UNDEFINED);
        //_AVERSIVE_AVAILABLE_ELEMENT(RISING);
        //_AVERSIVE_AVAILABLE_ELEMENT(FALLING);
        //_AVERSIVE_AVAILABLE_ELEMENT(BOTH);
      };

      //static bool isModuleEnabled(void) { return 0; }
      //static void enableModule(void) {}
      //static void disableModule(void) {}
      
      //static bool isModuleSleepEnabled(void) { return 0; }
      //static void enableModuleSleep(void) {}
      //static void disableModuleSleep(void) {}
      
      //static void getPinSettings(u8, Settings&) {}
      //static void setPinSettings(u8, const Settings&) {}
      //static void setPinGroupSettings(IO_Type, const Settings&) {}
      
      //static typename Mode::Type getPinMode(u8) { return Mode::UNDEFINED; }
      //static void setPinMode(u8, typename Mode::Type) {}
      //static void setPinGroupMode(IO_Type, typename Mode::Type) {}
      
      //static typename OutputMode::Type getPinOutputMode(u8) { return OutputMode::UNDEFINED; }
      //static void setPinOutputMode(u8, typename OutputMode::Type) {}
      //static void setPinGroupOutputMode(IO_Type, typename OutputMode::Type) {}
      
      //static typename Alternate::Type getPinAlternate(u8) { return Alternate::UNDEFINED; }
      //static void setPinAlternate(u8, typename Alternate::Type) {}
      //static void setPinGroupAlternate(IO_Type, typename Alternate::Type) {}
      
      //static typename Pull::Type getPinPull(u8) { return Pull::UNDEFINED; }
      //static void setPinPull(u8, typename Pull::Type) {}
      //static void setPinGroupPull(IO_Type, typename Pull::Type) {}
      
      //static typename Speed::Type getPinSpeed(u8) { return Speed::UNDEFINED; }
      //static void setPinSpeed(u8, typename Speed::Type) {}
      //static void setPinGroupSpeed(IO_Type, typename Speed::Type) {}
      
      //static IRQ_Handler getPinExtiHandler(u8) { return 0; }
      //static void setPinExtiHandler(u8, IRQ_Handler) {}
      
      //static typename TriggerDetection::Type getPinTriggerDetection(u8) { return TriggerDetection::UNDEFINED; }
      //static void setPinTriggerDectection(u8, typename TriggerDetection::Type) {}
      
      //static IO_Type getValue(void) { return 0; }
      //static void setValue(IO_Type) {}
      //template<IO_Type VALUE> static void setValue(void) {}

      //static bool getPinValue(u8) { return false; }
      //static void setPinValue(u8, bool) {}
      //static void togglePin(u8) {}

      //static void setPinGroupValue(IO_Type, bool) {}
      //static void togglePinGroup(IO_Type) {}

      template<IO_Type PIN_MASK>
      struct PinGroup : GPIO_DriverInterface::PinGroup<PIN_MASK> {
        //static void setSettings(const Settings&) {}
        //template<typename Settings> static void setSettings(void) {}
        
        //static void setMode(typename Mode::Type) {}
        //template<typename Mode::Type> static void setMode(void) {}
        
        //static void setOutputMode(typename OutputMode::Type) {}
        //template<typename OutputMode::Type> static void setOutputMode(void) {}
        
        //static void setAlternate(typename Alternate::Type) {}
        //template<typename Alternate::Type> static void setAlternate(void) {}
        
        //static void setPull(typename Pull::Type) {}
        //template<typename Pull::Type> static void setPull(void) {}
        
        //static void setSpeed(typename Speed::Type) {}
        //template<typename Speed::Type> static void setSpeed(void) {}
        
        //static void setValue(bool) {}
        //template<bool VALUE> static void setValue(void) {}
        //static void toggle(void) {}
      };

      template<u8 PIN_NUMBER>
      struct Pin : GPIO_DriverInterface::Pin<PIN_NUMBER> {
        //static void getSettings(Settings&) {}
        //static void setSettings(const Settings&) {}
        //template<typename Settings> static void setSettings(void) {}
        
        //static typename Mode::Type getMode(void) { return Mode::UNDEFINED; }
        //static void setMode(typename Mode::Type) {}
        //template<typename Mode::Type> static void setMode(void) {}
        
        //static typename OutputMode::Type getOutputMode(void) { return OutputMode::UNDEFINED; }
        //static void setOutputMode(typename OutputMode::Type) {}
        //template<typename OutputMode::Type> static void setOutputMode(void) {}
        
        //static typename Alternate::Type getAlternate(void) { return Alternate::UNDEFINED; }
        //static void setAlternate(typename Alternate::Type) {}
        //template<typename Alternate::Type> static void setAlternate(void) {}
        
        //static typename Pull::Type getPull(void) { return Pull::UNDEFINED; }
        //static void setPull(typename Pull::Type) {}
        //template<typename Pull::Type> static void setPull(void) {}
        
        //static typename Speed::Type getSpeed(void) { return Speed::UNDEFINED; }
        //static void setSpeed(typename Speed::Type) {}
        //template<typename Speed::Type> static void setSpeed(void) {}
        
        //static IRQ_Handler getExtiHandler(void) { return 0; }
        //static void setExtiHandler(IRQ_Handler) {}
        
        //static typename TriggerDetection::Type getTriggerDetection(void) { return TriggerDetection::UNDEFINED; }
        //static void setTriggerDectection(typename TriggerDetection::Type) {}
        //template<typename TriggerDetection::Type> static void setTriggerDectection(void) {}
        
        //static bool getValue(void) { return 0; }
        //static void setValue(bool) {}
        //static void toggle(void) {}
        //template<bool VALUE> static void setValue(void) {}

      };
    };
    
  }  
}

#include <hal/macros_undef.hpp>

#endif//HAL_COMMON_GPIO_EXAMPLE_HPP
