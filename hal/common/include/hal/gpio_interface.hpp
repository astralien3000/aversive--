#ifndef HAL_COMMON_GPIO_INTERFACE_HPP
#define HAL_COMMON_GPIO_INTERFACE_HPP

#include <base/integer.hpp>

//! \brief This define tells to the compiler (GNU) to warn the user when a marked funcionnality is used
//! \todo Replace by C++14 deprecated attribute
#define DEPRECATED __attribute__((deprecated))

namespace HAL {

  namespace GPIO {

    //! \brief This is just an alias to build "deprecatable Enumerations"
#define MACRO_ENUM_ELEMENT(elem)			\
    static constexpr Type elem DEPRECATED = Type::elem

    //! \brief The GPIO Pin Mode
    struct Mode {
      enum class Type : u8 { UNDEFINED = 0, INPUT, OUTPUT, ALTERNATE_FUNCTION };
      MACRO_ENUM_ELEMENT(UNDEFINED);
      MACRO_ENUM_ELEMENT(INPUT);
      MACRO_ENUM_ELEMENT(OUTPUT);
      MACRO_ENUM_ELEMENT(ALTERNATE_FUNCTION);
    };
    
    //! \brief The GPIO Pin Output Mode
    struct OutputMode {
      enum class Type : u8 { UNDEFINED = 0, PUSH_PULL, OPEN_DRAIN };
      MACRO_ENUM_ELEMENT(UNDEFINED);
      MACRO_ENUM_ELEMENT(PUSH_PULL);
      MACRO_ENUM_ELEMENT(OPEN_DRAIN);
    };

    //! \brief The GPIO Pin Alterate Function
    struct Alternate {
      enum class Type : u8 { UNDEFINED = 0 };
      MACRO_ENUM_ELEMENT(UNDEFINED);
    };

    //! \brief The GPIO Pin Pull Policy
    struct Pull {
      enum class Type : u8 { UNDEFINED = 0, UP, DOWN };
      MACRO_ENUM_ELEMENT(UNDEFINED);
      MACRO_ENUM_ELEMENT(UP);
      MACRO_ENUM_ELEMENT(DOWN);
    };

    //! \brief The GPIO Pin Maximum Speed
    struct Speed {
      enum class Type { UNDEFINED = 0 };
      MACRO_ENUM_ELEMENT(UNDEFINED);
    };

    //! \brief The GPIO Pin Trigger Detection Mode
    struct TriggerDetection {
      enum class Type : u8 { UNDEFINED = 0, RISING, FALLING, BOTH };
      MACRO_ENUM_ELEMENT(UNDEFINED);
      MACRO_ENUM_ELEMENT(RISING);
      MACRO_ENUM_ELEMENT(FALLING);
      MACRO_ENUM_ELEMENT(BOTH);
    };

#undef MACRO_ENUM_ELEMENT

    //! \brief Interrupt Handler
    //! \todo May be gatered with others IRQ_Handlers
    using IRQ_Handler = void (*)(void);

    //! \brief GPIO Pin Settings
    struct Settings {
      Mode::Type mode;
      OutputMode::Type output_mode;
      Alternate::Type alternate;
      Pull::Type pull;
      Speed::Type speed;
    };

    //! \brief GPIO Griver Interface
    /*!
     * This interface exists to show the develloper what can be implemented.
     * But the developper may not implement everything, since not every mirocontroller has as much functionnalities.
     * If a microcontroller provides a service that does not fit this interface, please, contact the main developpers of this project.
     */
    struct DriverInterface {
      //! \name Settings
      //! @{
      static void getPinSettings(Settings&, u8 pinNumber)       DEPRECATED;
      static void setPinSettings(const Settings&, u8 pinNumber) DEPRECATED;
      static void init(const Settings&, u32 pinMask)            DEPRECATED;

      template<typename Settings, u8 PIN_NUMBER> static void setPinSettings(void) DEPRECATED;
      template<typename Settings> static void init(void)                          DEPRECATED;
      //! @}

      //! \name Module Enable
      //! @{
      static bool isModuleEnabled(void) DEPRECATED;
      static void enableModule(void)    DEPRECATED;
      static void disableModule(void)   DEPRECATED;
      //! @}

      //! \name Module Sleep Enable
      //! @{
      static bool isModuleSleepEnabled(void) DEPRECATED;
      static void enableModuleSleep(void)    DEPRECATED;
      static void disableModuleSleep(void)   DEPRECATED;
      //! @}

      //! \name Mode
      //! @{
      static Mode::Type getPinMode(u8 pinNumber)       DEPRECATED;
      static void setPinMode(Mode::Type, u8 pinNumber) DEPRECATED;
      static void setMode(Mode::Type, u32 pinMask)     DEPRECATED;

      template<u8 PIN_NUMBER> static Mode::Type getPinMode(void)       DEPRECATED;
      template<Mode::Type, u8 PIN_NUMBER> static void setPinMode(void) DEPRECATED;
      template<Mode::Type, u32 PIN_MASK> static void setMode(void)     DEPRECATED;
      //! @}

      //! \name Output Mode
      //! @{
      static OutputMode::Type getPinOutputMode(u8 pinNumber)       DEPRECATED;
      static void setPinOutputMode(OutputMode::Type, u8 pinNumber) DEPRECATED;
      static void setOutputMode(OutputMode::Type, u32 pinMask)     DEPRECATED;

      template<u8 PIN_NUMBER> static OutputMode::Type getPinOutputMode(void)       DEPRECATED;
      template<OutputMode::Type, u8 PIN_NUMBER> static void setPinOutputMode(void) DEPRECATED;
      template<OutputMode::Type, u32 PIN_MASK> static void setOutputMode(void)     DEPRECATED;
      //! @}

      //! \name Alternate Function
      //! @{
      static Alternate::Type getPinAlternate(u8 pinNumber)       DEPRECATED;
      static void setPinAlternate(Alternate::Type, u8 pinNumber) DEPRECATED;
      static void setAlternate(Alternate::Type, u32 pinMask)     DEPRECATED;

      template<u8 PIN_NUMBER> static Alternate::Type getPinAlternate(void)       DEPRECATED;
      template<Alternate::Type, u8 PIN_NUMBER> static void setPinAlternate(void) DEPRECATED;
      template<Alternate::Type, u32 PIN_MASK> static void setAlternate(void)     DEPRECATED;
      //! @}

      //! \name Pull policy
      //! @{
      static Pull::Type getPinPull(u8 pinNumber)       DEPRECATED;
      static void setPinPull(Pull::Type, u8 pinNumber) DEPRECATED;
      static void setPull(Pull::Type, u32 pinMask)     DEPRECATED;
      
      template<u8 PIN_NUMBER> static Pull::Type getPinPull(void)       DEPRECATED;
      template<Pull::Type, u8 PIN_NUMBER> static void setPinPull(void) DEPRECATED;
      template<Pull::Type, u32 PIN_MASK> static void setPull(void)     DEPRECATED;
      //! @}

      //! \name Speed
      //! @{
      static Speed::Type getPinSpeed(u8 pinNumber)       DEPRECATED;
      static void setPinSpeed(Speed::Type, u8 pinNumber) DEPRECATED;
      static void setSpeed(Speed::Type, u32 pinMask)     DEPRECATED;

      template<u8 PIN_NUMBER> static Speed::Type getPinSpeed(void)       DEPRECATED;
      template<Speed::Type, u8 PIN_NUMBER> static void setPinSpeed(void) DEPRECATED;
      template<Speed::Type, u32 PIN_MASK> static void setSpeed(void)     DEPRECATED;
      //! @}

      //! \name External Interrupt Handler
      //! @{
      static IRQ_Handler getPinExtiHandler(u8 pinNumber)       DEPRECATED;
      static void setPinExtiHandler(IRQ_Handler, u8 pinNumber) DEPRECATED;
      //! @}

      //! \name Trigger Detection
      //! @{
      static TriggerDetection::Type getPinTriggerDetection(u8 pinNumber)        DEPRECATED;
      static void setPinTriggerDectection(TriggerDetection::Type, u8 pinNumber) DEPRECATED;

      template<u8 PIN_NUMBER> static TriggerDetection::Type getPinTriggerDetection(void)        DEPRECATED;
      template<TriggerDetection::Type, u8 PIN_NUMBER> static void setPinTriggerDectection(void) DEPRECATED;
      //! @}

      //! \name Value
      //! @{
      static bool getPinValue(u8 pinNumber)             DEPRECATED;
      static void setPinValue(bool value, u8 pinNumber) DEPRECATED;
      static void togglePin(u8 pinNumber)               DEPRECATED;

      static u32 getValue(void)                     DEPRECATED;
      static void setValue(u32 value)               DEPRECATED;
      static void setValue(bool value, u32 pinMask) DEPRECATED;
      static void toggle(u32 pinMask)               DEPRECATED;

      template<u8 PIN_NUMBER> static bool getPinValue(void)             DEPRECATED;
      template<bool VALUE, u8 PIN_NUMBER> static void setPinValue(void) DEPRECATED;
      template<u8 PIN_NUMBER> static void togglePin(void)               DEPRECATED;

      template<u32 VALUE> static void setValue(void)                DEPRECATED;
      template<bool VALUE, u32 PIN_MASK> static void setValue(void) DEPRECATED;
      template<u32 PIN_MASK> static void toggle(void)               DEPRECATED;
      //! @}
    };
  }
}

#endif//HAL_COMMON_GPIO_INTERFACE_HPP
