#ifndef HAL_COMMON_GPIO_INTERFACE_HPP
#define HAL_COMMON_GPIO_INTERFACE_HPP

#include <base/integer.hpp>

#define DEPRECATED __attribute__((deprecated))

namespace HAL {

  namespace GPIO {
    
#define MACRO_ENUM_ELEMENT(elem)			\
    static constexpr Type elem DEPRECATED = Type::elem
    
    struct Mode {
      enum class Type : u8 { UNDEFINED = 0, INPUT, OUTPUT, ALTERNATE_FUNCTION };
      MACRO_ENUM_ELEMENT(UNDEFINED);
      MACRO_ENUM_ELEMENT(INPUT);
      MACRO_ENUM_ELEMENT(OUTPUT);
      MACRO_ENUM_ELEMENT(ALTERNATE_FUNCTION);
    };
    
    struct OutputMode {
      enum class Type : u8 { UNDEFINED = 0, PUSH_PULL, OPEN_DRAIN };
      MACRO_ENUM_ELEMENT(UNDEFINED);
      MACRO_ENUM_ELEMENT(PUSH_PULL);
      MACRO_ENUM_ELEMENT(OPEN_DRAIN);
    };

    struct Alternate {
      enum class Type : u8 { UNDEFINED = 0 };
      MACRO_ENUM_ELEMENT(UNDEFINED);
    };
    
    struct Pull {
      enum class Type : u8 { UNDEFINED = 0, UP, DOWN };
      MACRO_ENUM_ELEMENT(UNDEFINED);
      MACRO_ENUM_ELEMENT(UP);
      MACRO_ENUM_ELEMENT(DOWN);
    };

    struct Speed {
      enum class Type { UNDEFINED = 0 };
      MACRO_ENUM_ELEMENT(UNDEFINED);
    };

    struct TriggerDetection {
      enum class Type : u8 { UNDEFINED = 0, RISING, FALLING, BOTH };
      MACRO_ENUM_ELEMENT(UNDEFINED);
      MACRO_ENUM_ELEMENT(RISING);
      MACRO_ENUM_ELEMENT(FALLING);
      MACRO_ENUM_ELEMENT(BOTH);
    };

#undef MACRO_ENUM_ELEMENT
    
    using IRQ_Handler = void (*)(void);
    
    struct Settings {
      Mode::Type mode;
      OutputMode::Type output_mode;
      Alternate::Type alternate;
      Pull::Type pull;
      Speed::Type speed;
    };

    struct DriverInterface {
      static void getPinSettings(Settings&, u8 pinNumber)       DEPRECATED;
      static void setPinSettings(const Settings&, u8 pinNumber) DEPRECATED;
      static void init(const Settings&, u32 pinMask)            DEPRECATED;

      static bool isModuleEnabled(void) DEPRECATED;
      static void enableModule(void)    DEPRECATED;
      static void disableModule(void)   DEPRECATED;

      static bool isModuleSleepEnabled(void) DEPRECATED;
      static void enableModuleSleep(void)    DEPRECATED;
      static void disableModuleSleep(void)   DEPRECATED;

      static Mode::Type getPinMode(u8 pinNumber)       DEPRECATED;
      static void setPinMode(Mode::Type, u8 pinNumber) DEPRECATED;
      static void setMode(Mode::Type, u32 pinMask)     DEPRECATED;

      static OutputMode::Type getPinOutputMode(u8 pinNumber)       DEPRECATED;
      static void setPinOutputMode(OutputMode::Type, u8 pinNumber) DEPRECATED;
      static void setOutputMode(OutputMode::Type, u32 pinMask)     DEPRECATED;

      static Alternate::Type getPinAlternate(u8 pinNumber)       DEPRECATED;
      static void setPinAlternate(Alternate::Type, u8 pinNumber) DEPRECATED;
      static void setAlternate(Alternate::Type, u32 pinMask)     DEPRECATED;

      static Pull::Type getPinPull(u8 pinNumber)       DEPRECATED;
      static void setPinPull(Pull::Type, u8 pinNumber) DEPRECATED;
      static void setPull(Pull::Type, u32 pinMask)     DEPRECATED;

      static Speed::Type getPinSpeed(u8 pinNumber)       DEPRECATED;
      static void setPinSpeed(Speed::Type, u8 pinNumber) DEPRECATED;
      static void setSpeed(Speed::Type, u32 pinMask)     DEPRECATED;

      static IRQ_Handler getPinExtiHandler(u8 pinNumber)       DEPRECATED;
      static void setPinExtiHandler(IRQ_Handler, u8 pinNumber) DEPRECATED;

      static TriggerDetection::Type getPinTriggerDetection(u8 pinNumber)        DEPRECATED;
      static void setPinTriggerDectection(TriggerDetection::Type, u8 pinNumber) DEPRECATED;

      static bool getPinValue(u8 pinNumber)             DEPRECATED;
      static void setPinValue(bool value, u8 pinNumber) DEPRECATED;
      static void togglePin(u8 pinNumber)               DEPRECATED;

      static u32 getValue(void)                     DEPRECATED;
      static void setValue(bool value, u32 pinMask) DEPRECATED;
      static void toggle(u32 pinMask)               DEPRECATED;
    };
  }
}

#endif//HAL_COMMON_GPIO_INTERFACE_HPP
