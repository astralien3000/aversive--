#ifndef HAL_COMMON_GPIO_INTERFACE_HPP
#define HAL_COMMON_GPIO_INTERFACE_HPP

#include <base/integer.hpp>

//! \brief This define tells to the compiler (GNU) to warn the user when a marked funcionnality is used
//! \todo Replace by C++14 deprecated attribute
#define DEPRECATED __attribute__((deprecated))

namespace HAL {

  namespace Private {
  
    //! \brief GPIO Driver Interface
    /*!
     * This interface exists to show the develloper what can be implemented.
     * But the developper may not implement everything, since not every mirocontroller has as much functionnalities.
     * If a microcontroller provides a service that does not fit this interface, please, contact the main developpers of this project.
     */
    struct GPIO_DriverInterface {
      
      //! \brief This is just an alias to build "deprecatable Enumerations"
#define MACRO_ENUM_ELEMENT(elem)				\
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

#undef MACRO_ENUM_ELEMENT

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
	
      //! \name Settings
      //! @{
      static void getPinSettings(Settings&, u8 pin_number)         DEPRECATED;
      static void setPinSettings(const Settings&, u8 pin_number)   DEPRECATED;
      static void setPinGroupSettings(const Settings&, u32 pin_mask) DEPRECATED;
      //! @}

      //! \name Mode
      //! @{
      static Mode::Type getPinMode(u8 pin_number)         DEPRECATED;
      static void setPinMode(Mode::Type, u8 pin_number)   DEPRECATED;
      static void setPinGroupMode(Mode::Type, u32 pin_mask) DEPRECATED;
      //! @}

      //! \name Output Mode
      //! @{
      static OutputMode::Type getPinOutputMode(u8 pin_number)         DEPRECATED;
      static void setPinOutputMode(OutputMode::Type, u8 pin_number)   DEPRECATED;
      static void setPinGroupOutputMode(OutputMode::Type, u32 pin_mask) DEPRECATED;
      //! @}

      //! \name Alternate Function
      //! @{
      static Alternate::Type getPinAlternate(u8 pin_number)         DEPRECATED;
      static void setPinAlternate(Alternate::Type, u8 pin_number)   DEPRECATED;
      static void setPinGroupAlternate(Alternate::Type, u32 pin_mask) DEPRECATED;
      //! @}

      //! \name Pull policy
      //! @{
      static Pull::Type getPinPull(u8 pin_number)       DEPRECATED;
      static void setPinPull(Pull::Type, u8 pin_number) DEPRECATED;
      static void setPinGroupPull(Pull::Type, u32 pin_mask)     DEPRECATED;
      //! @}

      //! \name Speed
      //! @{
      static Speed::Type getPinSpeed(u8 pin_number)         DEPRECATED;
      static void setPinSpeed(Speed::Type, u8 pin_number)   DEPRECATED;
      static void setPinGroupSpeed(Speed::Type, u32 pin_mask) DEPRECATED;
      //! @}

      //! \name External Interrupt Handler
      //! @{
      static IRQ_Handler getPinExtiHandler(u8 pin_number)       DEPRECATED;
      static void setPinExtiHandler(IRQ_Handler, u8 pin_number) DEPRECATED;
      //! @}

      //! \name Trigger Detection
      //! @{
      static TriggerDetection::Type getPinTriggerDetection(u8 pin_number)        DEPRECATED;
      static void setPinTriggerDectection(TriggerDetection::Type, u8 pin_number) DEPRECATED;
      //! @}

      //! \name Value
      //! @{
      static u32 getValue(void)                      DEPRECATED;
      static void setValue(u32 value)                DEPRECATED;
      template<u32 VALUE> static void setValue(void) DEPRECATED;

      static bool getPinValue(u8 pin_number)             DEPRECATED;
      static void setPinValue(bool value, u8 pin_number) DEPRECATED;
      static void togglePin(u8 pin_number)               DEPRECATED;

      static void setPinGroupValue(bool value, u32 pin_mask) DEPRECATED;
      static void togglePinGroup(u32 pin_mask)               DEPRECATED;
      //! @}

      //! \brief Templated PinGroup interface
      template<u32 PIN_MASK>
      struct PinGroup {
	//! \name Settings
	//! @{
	static void setSettings(const Settings&)                  DEPRECATED;
	template<typename Settings> static void setSettings(void) DEPRECATED;
	//! @}

	//! \name Mode
	//! @{
	static void setMode(Mode::Type)                DEPRECATED;
	template<Mode::Type> static void setMode(void) DEPRECATED;
	//! @}

	//! \name Output Mode
	//! @{
	static void setOutputMode(OutputMode::Type)                DEPRECATED;
	template<OutputMode::Type> static void setOutputMode(void) DEPRECATED;
	//! @}

	//! \name Alternate Function
	//! @{
	static void setAlternate(Alternate::Type)                DEPRECATED;
	template<Alternate::Type> static void setAlternate(void) DEPRECATED;
	//! @}

	//! \name Pull policy
	//! @{
	static void setPull(Pull::Type)                DEPRECATED;
	template<Pull::Type> static void setPull(void) DEPRECATED;
	//! @}

	//! \name Speed
	//! @{
	static void setSpeed(Speed::Type)                DEPRECATED;
	template<Speed::Type> static void setSpeed(void) DEPRECATED;
	//! @}

	//! \name Value
	//! @{
	static void setValue(bool value)                DEPRECATED;
	template<bool VALUE> static void setValue(void) DEPRECATED;
	static void toggle(void)                        DEPRECATED;
	//! @}
      };

      //! \brief Templated Pin interface
      template<u8 PIN_NUMBER>
      struct Pin {
	//! \name Settings
	//! @{
	static void getSettings(Settings&)       DEPRECATED;
	static void setSettings(const Settings&) DEPRECATED;
	  
	template<typename Settings> static void setSettings(void) DEPRECATED;
	//! @}

	//! \name Mode
	//! @{
	static Mode::Type getMode(void) DEPRECATED;
	static void setMode(Mode::Type)    DEPRECATED;
	  
	template<Mode::Type> static void setMode(void) DEPRECATED;
	//! @}

	//! \name Output Mode
	//! @{
	static OutputMode::Type getOutputMode(void) DEPRECATED;
	static void setOutputMode(OutputMode::Type) DEPRECATED;

	template<OutputMode::Type> static void setOutputMode(void) DEPRECATED;
	//! @}

	//! \name Alternate Function
	//! @{
	static Alternate::Type getAlternate(void) DEPRECATED;
	static void setAlternate(Alternate::Type) DEPRECATED;

	template<Alternate::Type> static void setAlternate(void) DEPRECATED;
	//! @}

	//! \name Pull policy
	//! @{
	static Pull::Type getPull(void) DEPRECATED;
	static void setPull(Pull::Type) DEPRECATED;

	template<Pull::Type> static void setPull(void) DEPRECATED;
	//! @}

	//! \name Speed
	//! @{
	static Speed::Type getSpeed(void) DEPRECATED;
	static void setSpeed(Speed::Type) DEPRECATED;

	template<Speed::Type> static void setSpeed(void) DEPRECATED;
	//! @}

	//! \name External Interrupt Handler
	//! @{
	static IRQ_Handler getExtiHandler(void) DEPRECATED;
	static void setExtiHandler(IRQ_Handler) DEPRECATED;
	//! @}

	//! \name Trigger Detection
	//! @{
	static TriggerDetection::Type getTriggerDetection(void)  DEPRECATED;
	static void setTriggerDectection(TriggerDetection::Type) DEPRECATED;

	template<TriggerDetection::Type> static void setTriggerDectection(void) DEPRECATED;
	//! @}

	//! \name Value
	//! @{
	static bool getValue(void)       DEPRECATED;
	static void setValue(bool value) DEPRECATED;
	static void toggle(void)         DEPRECATED;

	template<bool VALUE> static void setValue(void) DEPRECATED;
	//! @}

      };
    };
    
  }
}

#undef DEPRECATED

#endif//HAL_COMMON_GPIO_INTERFACE_HPP
