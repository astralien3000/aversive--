#ifndef HAL_COMMON_GPIO_INTERFACE_HPP
#define HAL_COMMON_GPIO_INTERFACE_HPP

#include <base/integer.hpp>

//! \brief This define tells to the compiler (GNU) to warn the user when a marked funcionnality is used
//! \todo Replace by C++14 deprecated attribute
#define UNAVAILABLE __attribute__((deprecated("This functionnality is not available for the microcontroller you are using")))

namespace HAL {

  namespace Private {
  
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
      
      //! \brief This is just an alias to build "deprecatable Enumerations"
#define MACRO_ENUM_ELEMENT(elem)				\
      static constexpr Type elem UNAVAILABLE = Type::elem

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

#undef MACRO_ENUM_ELEMENT

      //! \name Module Enable
      //! @{
      static bool isModuleEnabled(void) UNAVAILABLE;
      static void enableModule(void)    UNAVAILABLE;
      static void disableModule(void)   UNAVAILABLE;
      //! @}

      //! \name Module Sleep Enable
      //! @{
      static bool isModuleSleepEnabled(void) UNAVAILABLE;
      static void enableModuleSleep(void)    UNAVAILABLE;
      static void disableModuleSleep(void)   UNAVAILABLE;
      //! @}
	
      //! \name Settings
      //! @{
      static void getPinSettings(u8 pin_number, Settings&)           UNAVAILABLE;
      static void setPinSettings(u8 pin_number, const Settings&)     UNAVAILABLE;
      static void setPinGroupSettings(IO_Type pin_mask, const Settings&) UNAVAILABLE;
      //! @}

      //! \name Mode
      //! @{
      static typename Mode::Type getPinMode(u8 pin_number)           UNAVAILABLE;
      static void setPinMode(u8 pin_number, typename Mode::Type)     UNAVAILABLE;
      static void setPinGroupMode(IO_Type pin_mask, typename Mode::Type) UNAVAILABLE;
      //! @}

      //! \name Output Mode
      //! @{
      static typename OutputMode::Type getPinOutputMode(u8 pin_number)           UNAVAILABLE;
      static void setPinOutputMode(u8 pin_number, typename OutputMode::Type)     UNAVAILABLE;
      static void setPinGroupOutputMode(IO_Type pin_mask, typename OutputMode::Type) UNAVAILABLE;
      //! @}

      //! \name Alternate Function
      //! @{
      static typename Alternate::Type getPinAlternate(u8 pin_number)           UNAVAILABLE;
      static void setPinAlternate(u8 pin_number, typename Alternate::Type)     UNAVAILABLE;
      static void setPinGroupAlternate(IO_Type pin_mask, typename Alternate::Type) UNAVAILABLE;
      //! @}

      //! \name Pull policy
      //! @{
      static typename Pull::Type getPinPull(u8 pin_number)               UNAVAILABLE;
      static void setPinPull(u8 pin_number, typename Pull::Type)         UNAVAILABLE;
      static void setPinGroupPull(IO_Type pin_mask, typename Pull::Type)     UNAVAILABLE;
      //! @}

      //! \name Speed
      //! @{
      static typename Speed::Type getPinSpeed(u8 pin_number)           UNAVAILABLE;
      static void setPinSpeed(u8 pin_number, typename Speed::Type)     UNAVAILABLE;
      static void setPinGroupSpeed(IO_Type pin_mask, typename Speed::Type) UNAVAILABLE;
      //! @}

      //! \name External Interrupt Handler
      //! @{
      static IRQ_Handler getPinExtiHandler(u8 pin_number)       UNAVAILABLE;
      static void setPinExtiHandler(u8 pin_number, IRQ_Handler) UNAVAILABLE;
      //! @}

      //! \name Trigger Detection
      //! @{
      static typename TriggerDetection::Type getPinTriggerDetection(u8 pin_number)        UNAVAILABLE;
      static void setPinTriggerDectection(u8 pin_number, typename TriggerDetection::Type) UNAVAILABLE;
      //! @}

      //! \name Value
      //! @{
      static IO_Type getValue(void)                      UNAVAILABLE;
      static void setValue(IO_Type value)                UNAVAILABLE;
      template<IO_Type VALUE> static void setValue(void) UNAVAILABLE;

      static bool getPinValue(u8 pin_number)             UNAVAILABLE;
      static void setPinValue(u8 pin_number, bool value) UNAVAILABLE;
      static void togglePin(u8 pin_number)               UNAVAILABLE;

      static void setPinGroupValue(IO_Type pin_mask, bool value) UNAVAILABLE;
      static void togglePinGroup(IO_Type pin_mask)               UNAVAILABLE;
      //! @}

      //! \brief Templated PinGroup interface
      template<IO_Type PIN_MASK>
      struct PinGroup {
	//! \name Settings
	//! @{
	static void setSettings(const Settings&)                  UNAVAILABLE;
	template<typename Settings> static void setSettings(void) UNAVAILABLE;
	//! @}

	//! \name Mode
	//! @{
	static void setMode(typename Mode::Type)                UNAVAILABLE;
	template<typename Mode::Type> static void setMode(void) UNAVAILABLE;
	//! @}

	//! \name Output Mode
	//! @{
	static void setOutputMode(typename OutputMode::Type)                UNAVAILABLE;
	template<typename OutputMode::Type> static void setOutputMode(void) UNAVAILABLE;
	//! @}

	//! \name Alternate Function
	//! @{
	static void setAlternate(typename Alternate::Type)                UNAVAILABLE;
	template<typename Alternate::Type> static void setAlternate(void) UNAVAILABLE;
	//! @}

	//! \name Pull policy
	//! @{
	static void setPull(typename Pull::Type)                UNAVAILABLE;
	template<typename Pull::Type> static void setPull(void) UNAVAILABLE;
	//! @}

	//! \name Speed
	//! @{
	static void setSpeed(typename Speed::Type)                UNAVAILABLE;
	template<typename Speed::Type> static void setSpeed(void) UNAVAILABLE;
	//! @}

	//! \name Value
	//! @{
	static void setValue(bool value)                UNAVAILABLE;
	template<bool VALUE> static void setValue(void) UNAVAILABLE;
	static void toggle(void)                        UNAVAILABLE;
	//! @}
      };

      //! \brief Templated Pin interface
      template<u8 PIN_NUMBER>
      struct Pin {
	//! \name Settings
	//! @{
	static void getSettings(Settings&)       UNAVAILABLE;
	static void setSettings(const Settings&) UNAVAILABLE;
	  
	template<typename Settings> static void setSettings(void) UNAVAILABLE;
	//! @}

	//! \name Mode
	//! @{
	static typename Mode::Type getMode(void) UNAVAILABLE;
	static void setMode(typename Mode::Type)    UNAVAILABLE;
	  
	template<typename Mode::Type> static void setMode(void) UNAVAILABLE;
	//! @}

	//! \name Output Mode
	//! @{
	static typename OutputMode::Type getOutputMode(void) UNAVAILABLE;
	static void setOutputMode(typename OutputMode::Type) UNAVAILABLE;

	template<typename OutputMode::Type> static void setOutputMode(void) UNAVAILABLE;
	//! @}

	//! \name Alternate Function
	//! @{
	static typename Alternate::Type getAlternate(void) UNAVAILABLE;
	static void setAlternate(typename Alternate::Type) UNAVAILABLE;

	template<typename Alternate::Type> static void setAlternate(void) UNAVAILABLE;
	//! @}

	//! \name Pull policy
	//! @{
	static typename Pull::Type getPull(void) UNAVAILABLE;
	static void setPull(typename Pull::Type) UNAVAILABLE;

	template<typename Pull::Type> static void setPull(void) UNAVAILABLE;
	//! @}

	//! \name Speed
	//! @{
	static typename Speed::Type getSpeed(void) UNAVAILABLE;
	static void setSpeed(typename Speed::Type) UNAVAILABLE;

	template<typename Speed::Type> static void setSpeed(void) UNAVAILABLE;
	//! @}

	//! \name External Interrupt Handler
	//! @{
	static IRQ_Handler getExtiHandler(void) UNAVAILABLE;
	static void setExtiHandler(IRQ_Handler) UNAVAILABLE;
	//! @}

	//! \name Trigger Detection
	//! @{
	static typename TriggerDetection::Type getTriggerDetection(void)  UNAVAILABLE;
	static void setTriggerDectection(typename TriggerDetection::Type) UNAVAILABLE;

	template<typename TriggerDetection::Type> static void setTriggerDectection(void) UNAVAILABLE;
	//! @}

	//! \name Value
	//! @{
	static bool getValue(void)       UNAVAILABLE;
	static void setValue(bool value) UNAVAILABLE;
	static void toggle(void)         UNAVAILABLE;

	template<bool VALUE> static void setValue(void) UNAVAILABLE;
	//! @}

      };
    };
    
  }
}

#undef UNAVAILABLE

#endif//HAL_COMMON_GPIO_INTERFACE_HPP
