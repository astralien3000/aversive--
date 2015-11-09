#ifndef HAL_COMMON_GPIO_INTERFACE_HPP
#define HAL_COMMON_GPIO_INTERFACE_HPP

#include <base/integer.hpp>
#include <hal/macros_define.hpp>

namespace HAL {

  //! \brief GPIO Driver Interface
  //! \param T : The type of a standard GPIO I/O Register
  /*!
   * This interface exists to show the develloper what can be implemented.
   * But the developper may not implement everything, since not every mirocontroller has as much functionnalities.
   * If a microcontroller provides a service that does not fit this interface, please, contact the main developpers of this project.
   */
  template<typename T>
  struct GPIO_DriverInterface {
    using IO_Type = T;
      
    //! \brief The GPIO Pin Mode
    struct Mode {
      enum class Type : u8 { UNDEFINED = 0, INPUT, OUTPUT, ALTERNATE_FUNCTION };
      _AVERSIVE_UNAVAILABLE_ELEMENT(UNDEFINED);
      _AVERSIVE_UNAVAILABLE_ELEMENT(INPUT);
      _AVERSIVE_UNAVAILABLE_ELEMENT(OUTPUT);
      _AVERSIVE_UNAVAILABLE_ELEMENT(ALTERNATE_FUNCTION);
    };
    
    //! \brief The GPIO Pin Output Mode
    struct OutputMode {
      enum class Type : u8 { UNDEFINED = 0, PUSH_PULL, OPEN_DRAIN };
      _AVERSIVE_UNAVAILABLE_ELEMENT(UNDEFINED);
      _AVERSIVE_UNAVAILABLE_ELEMENT(PUSH_PULL);
      _AVERSIVE_UNAVAILABLE_ELEMENT(OPEN_DRAIN);
    };

    //! \brief The GPIO Pin Alterate Function
    struct Alternate {
      enum class Type : u8 { UNDEFINED = 0 };
      _AVERSIVE_UNAVAILABLE_ELEMENT(UNDEFINED);
    };

    //! \brief The GPIO Pin Pull Policy
    struct Pull {
      enum class Type : u8 { UNDEFINED = 0, UP, DOWN };
      _AVERSIVE_UNAVAILABLE_ELEMENT(UNDEFINED);
      _AVERSIVE_UNAVAILABLE_ELEMENT(UP);
      _AVERSIVE_UNAVAILABLE_ELEMENT(DOWN);
    };

    //! \brief The GPIO Pin Maximum Speed
    struct Speed {
      enum class Type { UNDEFINED = 0 };
      _AVERSIVE_UNAVAILABLE_ELEMENT(UNDEFINED);
    };

    //! \brief The GPIO Pin Trigger Detection Mode
    struct TriggerDetection {
      enum class Type : u8 { UNDEFINED = 0, RISING, FALLING, BOTH };
      _AVERSIVE_UNAVAILABLE_ELEMENT(UNDEFINED);
      _AVERSIVE_UNAVAILABLE_ELEMENT(RISING);
      _AVERSIVE_UNAVAILABLE_ELEMENT(FALLING);
      _AVERSIVE_UNAVAILABLE_ELEMENT(BOTH);
    };

    //! \brief Interrupt Handler
    //! \todo May be gatered with others IRQ_Handlers
    using IRQ_Handler = void (*)(void);

    //! \brief GPIO Pin Settings
    struct Settings {
      typename Mode::Type mode;
      typename OutputMode::Type output_mode;
      typename Alternate::Type alternate;
      typename Pull::Type pull;
      typename Speed::Type speed;
    };

    //! \name Module Enable
    //! @{
    static bool isModuleEnabled(void) _AVERSIVE_UNAVAILABLE;
    static void enableModule(void)    _AVERSIVE_UNAVAILABLE;
    static void disableModule(void)   _AVERSIVE_UNAVAILABLE;
    //! @}

    //! \name Module Sleep Enable
    //! @{
    static bool isModuleSleepEnabled(void) _AVERSIVE_UNAVAILABLE;
    static void enableModuleSleep(void)    _AVERSIVE_UNAVAILABLE;
    static void disableModuleSleep(void)   _AVERSIVE_UNAVAILABLE;
    //! @}
        
    //! \name Settings
    //! @{
    static void getPinSettings(u8 pin_number, Settings&)           _AVERSIVE_UNAVAILABLE;
    static void setPinSettings(u8 pin_number, const Settings&)     _AVERSIVE_UNAVAILABLE;
    static void setPinGroupSettings(IO_Type pin_mask, const Settings&) _AVERSIVE_UNAVAILABLE;
    //! @}

    //! \name Mode
    //! @{
    static typename Mode::Type getPinMode(u8 pin_number)           _AVERSIVE_UNAVAILABLE;
    static void setPinMode(u8 pin_number, typename Mode::Type)     _AVERSIVE_UNAVAILABLE;
    static void setPinGroupMode(IO_Type pin_mask, typename Mode::Type) _AVERSIVE_UNAVAILABLE;
    //! @}

    //! \name Output Mode
    //! @{
    static typename OutputMode::Type getPinOutputMode(u8 pin_number)           _AVERSIVE_UNAVAILABLE;
    static void setPinOutputMode(u8 pin_number, typename OutputMode::Type)     _AVERSIVE_UNAVAILABLE;
    static void setPinGroupOutputMode(IO_Type pin_mask, typename OutputMode::Type) _AVERSIVE_UNAVAILABLE;
    //! @}

    //! \name Alternate Function
    //! @{
    static typename Alternate::Type getPinAlternate(u8 pin_number)           _AVERSIVE_UNAVAILABLE;
    static void setPinAlternate(u8 pin_number, typename Alternate::Type)     _AVERSIVE_UNAVAILABLE;
    static void setPinGroupAlternate(IO_Type pin_mask, typename Alternate::Type) _AVERSIVE_UNAVAILABLE;
    //! @}

    //! \name Pull policy
    //! @{
    static typename Pull::Type getPinPull(u8 pin_number)               _AVERSIVE_UNAVAILABLE;
    static void setPinPull(u8 pin_number, typename Pull::Type)         _AVERSIVE_UNAVAILABLE;
    static void setPinGroupPull(IO_Type pin_mask, typename Pull::Type)     _AVERSIVE_UNAVAILABLE;
    //! @}

    //! \name Speed
    //! @{
    static typename Speed::Type getPinSpeed(u8 pin_number)           _AVERSIVE_UNAVAILABLE;
    static void setPinSpeed(u8 pin_number, typename Speed::Type)     _AVERSIVE_UNAVAILABLE;
    static void setPinGroupSpeed(IO_Type pin_mask, typename Speed::Type) _AVERSIVE_UNAVAILABLE;
    //! @}

    //! \name External Interrupt Handler
    //! @{
    static IRQ_Handler getPinExtiHandler(u8 pin_number)       _AVERSIVE_UNAVAILABLE;
    static void setPinExtiHandler(u8 pin_number, IRQ_Handler) _AVERSIVE_UNAVAILABLE;
    //! @}

    //! \name Trigger Detection
    //! @{
    static typename TriggerDetection::Type getPinTriggerDetection(u8 pin_number)        _AVERSIVE_UNAVAILABLE;
    static void setPinTriggerDectection(u8 pin_number, typename TriggerDetection::Type) _AVERSIVE_UNAVAILABLE;
    //! @}

    //! \name Value
    //! @{
    static IO_Type getValue(void)                      _AVERSIVE_UNAVAILABLE;
    static void setValue(IO_Type value)                _AVERSIVE_UNAVAILABLE;
    template<IO_Type VALUE> static void setValue(void) _AVERSIVE_UNAVAILABLE;

    static bool getPinValue(u8 pin_number)             _AVERSIVE_UNAVAILABLE;
    static void setPinValue(u8 pin_number, bool value) _AVERSIVE_UNAVAILABLE;
    static void togglePin(u8 pin_number)               _AVERSIVE_UNAVAILABLE;

    static void setPinGroupValue(IO_Type pin_mask, bool value) _AVERSIVE_UNAVAILABLE;
    static void togglePinGroup(IO_Type pin_mask)               _AVERSIVE_UNAVAILABLE;
    //! @}

    //! \brief Templated PinGroup interface
    template<IO_Type PIN_MASK>
    struct PinGroup {
      //! \name Settings
      //! @{
      static void setSettings(const Settings&)                  _AVERSIVE_UNAVAILABLE;
      template<typename Settings> static void setSettings(void) _AVERSIVE_UNAVAILABLE;
      //! @}

      //! \name Mode
      //! @{
      static void setMode(typename Mode::Type)                _AVERSIVE_UNAVAILABLE;
      template<typename Mode::Type> static void setMode(void) _AVERSIVE_UNAVAILABLE;
      //! @}

      //! \name Output Mode
      //! @{
      static void setOutputMode(typename OutputMode::Type)                _AVERSIVE_UNAVAILABLE;
      template<typename OutputMode::Type> static void setOutputMode(void) _AVERSIVE_UNAVAILABLE;
      //! @}

      //! \name Alternate Function
      //! @{
      static void setAlternate(typename Alternate::Type)                _AVERSIVE_UNAVAILABLE;
      template<typename Alternate::Type> static void setAlternate(void) _AVERSIVE_UNAVAILABLE;
      //! @}

      //! \name Pull policy
      //! @{
      static void setPull(typename Pull::Type)                _AVERSIVE_UNAVAILABLE;
      template<typename Pull::Type> static void setPull(void) _AVERSIVE_UNAVAILABLE;
      //! @}

      //! \name Speed
      //! @{
      static void setSpeed(typename Speed::Type)                _AVERSIVE_UNAVAILABLE;
      template<typename Speed::Type> static void setSpeed(void) _AVERSIVE_UNAVAILABLE;
      //! @}

      //! \name Value
      //! @{
      static void setValue(bool value)                _AVERSIVE_UNAVAILABLE;
      template<bool VALUE> static void setValue(void) _AVERSIVE_UNAVAILABLE;
      static void toggle(void)                        _AVERSIVE_UNAVAILABLE;
      //! @}
    };

    //! \brief Templated Pin interface
    template<u8 PIN_NUMBER>
    struct Pin {
      //! \name Settings
      //! @{
      static void getSettings(Settings&)       _AVERSIVE_UNAVAILABLE;
      static void setSettings(const Settings&) _AVERSIVE_UNAVAILABLE;
          
      template<typename Settings> static void setSettings(void) _AVERSIVE_UNAVAILABLE;
      //! @}

      //! \name Mode
      //! @{
      static typename Mode::Type getMode(void) _AVERSIVE_UNAVAILABLE;
      static void setMode(typename Mode::Type)    _AVERSIVE_UNAVAILABLE;
          
      template<typename Mode::Type> static void setMode(void) _AVERSIVE_UNAVAILABLE;
      //! @}

      //! \name Output Mode
      //! @{
      static typename OutputMode::Type getOutputMode(void) _AVERSIVE_UNAVAILABLE;
      static void setOutputMode(typename OutputMode::Type) _AVERSIVE_UNAVAILABLE;

      template<typename OutputMode::Type> static void setOutputMode(void) _AVERSIVE_UNAVAILABLE;
      //! @}

      //! \name Alternate Function
      //! @{
      static typename Alternate::Type getAlternate(void) _AVERSIVE_UNAVAILABLE;
      static void setAlternate(typename Alternate::Type) _AVERSIVE_UNAVAILABLE;

      template<typename Alternate::Type> static void setAlternate(void) _AVERSIVE_UNAVAILABLE;
      //! @}

      //! \name Pull policy
      //! @{
      static typename Pull::Type getPull(void) _AVERSIVE_UNAVAILABLE;
      static void setPull(typename Pull::Type) _AVERSIVE_UNAVAILABLE;

      template<typename Pull::Type> static void setPull(void) _AVERSIVE_UNAVAILABLE;
      //! @}

      //! \name Speed
      //! @{
      static typename Speed::Type getSpeed(void) _AVERSIVE_UNAVAILABLE;
      static void setSpeed(typename Speed::Type) _AVERSIVE_UNAVAILABLE;

      template<typename Speed::Type> static void setSpeed(void) _AVERSIVE_UNAVAILABLE;
      //! @}

      //! \name External Interrupt Handler
      //! @{
      static IRQ_Handler getExtiHandler(void) _AVERSIVE_UNAVAILABLE;
      static void setExtiHandler(IRQ_Handler) _AVERSIVE_UNAVAILABLE;
      //! @}

      //! \name Trigger Detection
      //! @{
      static typename TriggerDetection::Type getTriggerDetection(void)  _AVERSIVE_UNAVAILABLE;
      static void setTriggerDectection(typename TriggerDetection::Type) _AVERSIVE_UNAVAILABLE;

      template<typename TriggerDetection::Type> static void setTriggerDectection(void) _AVERSIVE_UNAVAILABLE;
      //! @}

      //! \name Value
      //! @{
      static bool getValue(void)       _AVERSIVE_UNAVAILABLE;
      static void setValue(bool value) _AVERSIVE_UNAVAILABLE;
      static void toggle(void)         _AVERSIVE_UNAVAILABLE;

      template<bool VALUE> static void setValue(void) _AVERSIVE_UNAVAILABLE;
      //! @}

    };
  };
    
}

#include <hal/macros_undef.hpp>

#endif//HAL_COMMON_GPIO_INTERFACE_HPP
