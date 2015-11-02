#ifndef HAL_COMMON_TIMER_INTERFACE_HPP
#define HAL_COMMON_TIMER_INTERFACE_HPP

#include <base/integer.hpp>

//! \brief This define tells to the compiler (GNU) to warn the user when a marked funcionnality is used
//! \todo Replace by C++14 deprecated attribute
#define UNAVAILABLE __attribute__((deprecated("This functionnality is not available for the microcontroller you are using")))

namespace HAL {

  namespace Private {
  
    //! \brief TIMER Driver Interface
    template<typename T>
    struct TIMER_DriverInterface {
      using IO_Type = T;
      
      //! \brief This is just an alias to build "deprecatable Enumerations"
#define MACRO_ENUM_ELEMENT(elem)				\
      static constexpr Type elem UNAVAILABLE = Type::elem

      //! \brief Interrupt Handler
      //! \todo May be gatered with others IRQ_Handlers
      using IRQ_Handler = void (*)(void);

      //! \brief The TIMER Counter Mode
      struct CounterMode {
	enum class Type : u8 { UNDEFINED, UP, DOWN, CENTER_ALIGNED };
	MACRO_ENUM_ELEMENT(UNDEFINED);
	MACRO_ENUM_ELEMENT(UP);
	MACRO_ENUM_ELEMENT(DOWN);
	MACRO_ENUM_ELEMENT(CENTER_ALIGNED);
      };

      //! \brief The TIMER Clock Selection
      struct ClockSelect {
	enum class Type : u8 { UNDEFINED, INTERNAL };
	MACRO_ENUM_ELEMENT(UNDEFINED);
	MACRO_ENUM_ELEMENT(INTERNAL);
      };

      //! \brief The TIMER Clock Prescaler
      struct Prescaler {
	using Type = IO_Type;
      };

      //! \brief The TIMER Counter Period
      struct Period {
	using Type = IO_Type;
      };

      //! \brief TIMER Settings
      struct Settings {
	typename CounterMode::Type counter_mode;
	typename ClockSelect::Type clock_select;
	typename Prescaler::Type prescaler;
	typename Period::Type period;
      };

      //! \brief The OutputCompare Mode
      struct OCMode {
	enum class Type : u8 { UNDEFINED, PWM };
	MACRO_ENUM_ELEMENT(UNDEFINED);
	MACRO_ENUM_ELEMENT(PWM);
      };

      //! \brief The OutputCompare Signal Polarity
      struct OCPolarity {
	enum class Type : u8 { UNDEFINED, HIGH, LOW };
	MACRO_ENUM_ELEMENT(UNDEFINED);
	MACRO_ENUM_ELEMENT(HIGH);
	MACRO_ENUM_ELEMENT(LOW);
      };

      //! \brief The OutputCompare Pulse Width
      struct OCPulseWidth {
	using Type = IO_Type;
      };
	
      //! \brief The OutputCompare Pulse Width
      struct OCSettings {
	typename OCMode::Type mode;
	typename OCPolarity::Type polarity;
	typename OCPulseWidth::Type pulse_width;
      };

      //! \brief The Encoder Mode
      struct EncoderMode {
	enum class Type : u8 { UNDEFINED, CHANNEL1_COUNT, CHANNEL2_COUNT, BOTH_COUNT };
	MACRO_ENUM_ELEMENT(UNDEFINED);
	MACRO_ENUM_ELEMENT(CHANNEL1_COUNT);
	MACRO_ENUM_ELEMENT(CHANNEL2_COUNT);
	MACRO_ENUM_ELEMENT(BOTH_COUNT);
      };

      //! \brief The Encoder Polarity
      struct EncoderPolarity {
	enum class Type : u8 { UNDEFINED, RISING, FALLING, BOTH };
	MACRO_ENUM_ELEMENT(UNDEFINED);
	MACRO_ENUM_ELEMENT(RISING);
	MACRO_ENUM_ELEMENT(FALLING);
	MACRO_ENUM_ELEMENT(BOTH);
      };
	
      //! \brief The Encoder Prescaler
      struct EncoderPrescaler {
	using Type = IO_Type;
      };
	
      //! \brief TIMER Encoder Channel Settings
      struct EncoderChannelSettings {
	typename EncoderPolarity::Type polarity;
	typename EncoderPrescaler::Type prescaler;
      }; 

      //! \brief TIMER Encoder Settings
      struct EncoderSettings {
	typename EncoderMode::Type mode;
	EncoderChannelSettings channel1;
	EncoderChannelSettings channel2;
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
      static void setSettings(const Settings&)            UNAVAILABLE;
      static void getSettings(Settings&)                  UNAVAILABLE;
      template<typename Settings> static void setSettings(void) UNAVAILABLE;
      //! @}
	
      //! \name Counter Mode
      //! @{
      static void setCounterMode(typename CounterMode::Type)                UNAVAILABLE;
      template<typename CounterMode::Type> static void setCounterMode(void) UNAVAILABLE;
      static typename CounterMode::Type getCounterMode(void)                UNAVAILABLE;
      //! @}

      //! \name Clock Select
      //! @{
      static void setClockSelect(typename ClockSelect::Type)                UNAVAILABLE;
      template<typename ClockSelect::Type> static void setClockSelect(void) UNAVAILABLE;
      static typename ClockSelect::Type getClockSelect(void)                UNAVAILABLE;
      //! @}

      //! \name Prescaler
      //! @{
      static void setPrescaler(typename Prescaler::Type)                UNAVAILABLE;
      template<typename Prescaler::Type> static void setPrescaler(void) UNAVAILABLE;
      static typename Prescaler::Type getPrescaler(void)                UNAVAILABLE;
      //! @}

      //! \name Overflow Handler
      //! @{
      static void setOverflowHandler(IRQ_Handler) UNAVAILABLE;
      static IRQ_Handler getOverflowHandler(void) UNAVAILABLE;
      //! @}

      //! \name OutputCompare Dynamic Functions
      //! @{
      static void setOutputCompareSettings(u8 channel, const OCSettings&) UNAVAILABLE;
      static void getOutputCompareSettings(u8 channel, OCSettings&)              UNAVAILABLE;

      static void setOutputCompareMode(u8 channel, typename OCMode::Type) UNAVAILABLE;
      static typename OCMode::Type getOutputCompareMode(u8 channel)       UNAVAILABLE;

      static void setOutputComparePolarity(u8 channel, typename OCPolarity::Type) UNAVAILABLE;
      static typename OCPolarity::Type getOutputComparePolarity(u8 channel)       UNAVAILABLE;

      static void setOutputComparePulseWidth(u8 channel, typename OCPulseWidth::Type) UNAVAILABLE;
      static typename OCPulseWidth::Type getOutputComparePulseWidth(u8 channel)              UNAVAILABLE;

      static void setOutputCompareHandler(u8 channel, IRQ_Handler) UNAVAILABLE;
      static IRQ_Handler getOutputCompareHandler(u8 channel)       UNAVAILABLE;
      //! @}
      
      //! \brief Templated OutputCompare interface
      template<u8 CHANNEL>
      struct OutputCompare {
	//! \name Settings
	//! @{
	static void setSettings(const OCSettings&) UNAVAILABLE;
	template<typename Settings> static void setSettings(void)      UNAVAILABLE;
	static void getSettings(OCSettings&)        UNAVAILABLE;
	//! @}

	//! \name Mode
	//! @{
	static void setMode(typename OCMode::Type)                UNAVAILABLE;
	template<typename OCMode::Type> static void setMode(void) UNAVAILABLE;
	static typename OCMode::Type getMode(void)                UNAVAILABLE;
	//! @}

	//! \name Polarity
	//! @{
	static void setPolarity(typename OCPolarity::Type)                UNAVAILABLE;
	template<typename OCPolarity::Type> static void setPolarity(void) UNAVAILABLE;
	static typename OCPolarity::Type getPolarity(void)                UNAVAILABLE;
	//! @}

	//! \name Pulse Width
	//! @{
	static void setPulseWidth(typename OCPulseWidth::Type)                UNAVAILABLE;
	template<typename OCPulseWidth::Type> static void setPulseWidth(void) UNAVAILABLE;
	static typename OCPulseWidth::Type getPulseWidth(void)                       UNAVAILABLE;
	//! @}

	//! \name Output Compare Handler
	//! @{
	static void setHandler(IRQ_Handler) UNAVAILABLE;
	static IRQ_Handler getHandler(void) UNAVAILABLE;
	//! @}
      };

      //! \brief Encoder interface
      struct Encoder {
	//! \name Settings
	//! @{
	static void setSettings(const EncoderSettings&)         UNAVAILABLE;
	template<typename Settings> static void setSettings(void) UNAVAILABLE;
	static void getSettings(EncoderSettings&)                UNAVAILABLE;
	//! @}

	//! \name Mode
	//! @{
	static void setMode(typename EncoderMode::Type)                UNAVAILABLE;
	template<typename EncoderMode::Type> static void setMode(void) UNAVAILABLE;
	static typename EncoderMode::Type getEncoderMode(void)         UNAVAILABLE;
	//! @}

	//! \name Channel Dynamic Functions
	//! @{
	static void setChannelPolarity(u8 channel, typename EncoderPolarity::Type) UNAVAILABLE;
	static typename EncoderPolarity::Type getChannelPolarity(u8 channel)       UNAVAILABLE;

	static void setChannelPrescaler(u8 channel, typename EncoderPrescaler::Type) UNAVAILABLE;
	static typename EncoderPrescaler::Type getChannelPrescaler(u8 channel)       UNAVAILABLE;
	//! @}

	//! \brief Encoder Channel interface
	template<u8 CHANNEL>
	struct Channel {
	  //! \name Polarity
	  //! @{
	  static void setPolarity(typename EncoderPolarity::Type)                UNAVAILABLE;
	  template<typename EncoderPolarity::Type> static void setPolarity(void) UNAVAILABLE;
	  static typename EncoderPolarity::Type getPolarity(void)                UNAVAILABLE;
	  //! @}
	    
	  //! \name Prescaler
	  //! @{
	  static void setPrescaler(typename EncoderPrescaler::Type)                UNAVAILABLE;
	  template<typename EncoderPrescaler::Type> static void setPrescaler(void) UNAVAILABLE;
	  static typename EncoderPrescaler::Type getPrescaler(void)                UNAVAILABLE;
	  //! @}
	};
      };
    };

  }
}


#undef UNAVAILABLE

#endif//HAL_COMMON_TIMER_INTERFACE_HPP
