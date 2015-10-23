#ifndef HAL_COMMON_TIMER_INTERFACE_HPP
#define HAL_COMMON_TIMER_INTERFACE_HPP

#include <base/integer.hpp>

//! \brief This define tells to the compiler (GNU) to warn the user when a marked funcionnality is used
//! \todo Replace by C++14 deprecated attribute
#define UNAVAILABLE __attribute__((deprecated("This functionnality is not available for the microcontroller you are using")))

namespace HAL {

  namespace Private {
  
    //! \brief TIMER Driver Interface
    struct TIMER_DriverInterface {

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
	using Type = u32;
      };

      //! \brief The TIMER Counter Period
      struct Period {
	using Type = u32;
      };

      //! \brief TIMER Settings
      struct Settings {
	CounterMode::Type counter_mode;
	ClockSelect::Type clock_select;
	Prescaler::Type prescaler;
	Period::Type period;
      };

      //! \brief The OutputCompare Mode
      struct OCMode {
	enum class Type : u8 { UNDEFINED, PWM };
	MACRO_ENUM_ELEMENT(UNDEFINED);
	MACRO_ENUM_ELEMENT(PWM);
      };

      //! \brief The OutputCompare Signal Polarity
      struct OCPolarity {
	enum class Type : u8 { HIGH, LOW };
	MACRO_ENUM_ELEMENT(HIGH);
	MACRO_ENUM_ELEMENT(LOW);
      };

      //! \brief The OutputCompare Pulse Width
      struct OCPulseWidth {
	using Type = u32;
      };
	
      //! \brief The OutputCompare Pulse Width
      struct OCSettings {
	OCMode::Type mode;
	OCPolarity::Type polarity;
	OCPulseWidth::Type pulse_width;
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
	using Type = u32;
      };
	
      //! \brief TIMER Encoder Channel Settings
      struct EncoderChannelSettings {
	EncoderPolarity::Type polarity;
	EncoderPrescaler::Type prescaler;
      }; 

      //! \brief TIMER Encoder Settings
      struct EncoderSettings {
	EncoderMode::Type mode;
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
      static void setCounterMode(CounterMode::Type)                UNAVAILABLE;
      template<CounterMode::Type> static void setCounterMode(void) UNAVAILABLE;
      static CounterMode::Type getCounterMode(void)                UNAVAILABLE;
      //! @}

      //! \name Clock Select
      //! @{
      static void setClockSelect(CounterMode::Type)                UNAVAILABLE;
      template<CounterMode::Type> static void setClockSelect(void) UNAVAILABLE;
      static CounterMode::Type getClockSelect(void)                UNAVAILABLE;
      //! @}

      //! \name Prescaler
      //! @{
      static void setPrescaler(Prescaler::Type)                UNAVAILABLE;
      template<Prescaler::Type> static void setPrescaler(void) UNAVAILABLE;
      static Prescaler::Type getPrescaler(void)                UNAVAILABLE;
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

      static void setOutputCompareMode(u8 channel, OCMode::Type) UNAVAILABLE;
      static OCMode::Type getOutputCompareMode(u8 channel)       UNAVAILABLE;

      static void setOutputComparePolarity(u8 channel, OCPolarity::Type) UNAVAILABLE;
      static OCPolarity::Type getOutputComparePolarity(u8 channel)       UNAVAILABLE;

      static void setOutputComparePulseWidth(u8 channel, OCPulseWidth::Type) UNAVAILABLE;
      OCPulseWidth::Type getOutputComparePulseWidth(u8 channel)              UNAVAILABLE;

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
	static void setMode(OCMode::Type)                UNAVAILABLE;
	template<OCMode::Type> static void setMode(void) UNAVAILABLE;
	static OCMode::Type getMode(void)                UNAVAILABLE;
	//! @}

	//! \name Polarity
	//! @{
	static void setPolarity(OCPolarity::Type)                UNAVAILABLE;
	template<OCPolarity::Type> static void setPolarity(void) UNAVAILABLE;
	static OCPolarity::Type getPolarity(void)                UNAVAILABLE;
	//! @}

	//! \name Pulse Width
	//! @{
	static void setPulseWidth(OCPulseWidth::Type)                UNAVAILABLE;
	template<OCPulseWidth::Type> static void setPulseWidth(void) UNAVAILABLE;
	OCPulseWidth::Type getPulseWidth(void)                       UNAVAILABLE;
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
	static void setMode(EncoderMode::Type)                UNAVAILABLE;
	template<EncoderMode::Type> static void setMode(void) UNAVAILABLE;
	static EncoderMode::Type getEncoderMode(void)         UNAVAILABLE;
	//! @}

	//! \name Channel Dynamic Functions
	//! @{
	static void setChannelPolarity(u8 channel, EncoderPolarity::Type) UNAVAILABLE;
	static EncoderPolarity::Type getChannelPolarity(u8 channel)       UNAVAILABLE;

	static void setChannelPrescaler(u8 channel, EncoderPolarity) UNAVAILABLE;
	static EncoderPolarity::Type getChannelPrescaler(u8 channel)       UNAVAILABLE;
	//! @}

	//! \brief Encoder Channel interface
	template<u8 CHANNEL>
	struct Channel {
	  //! \name Polarity
	  //! @{
	  static void setPolarity(EncoderPolarity::Type)                UNAVAILABLE;
	  template<EncoderPolarity::Type> static void setPolarity(void) UNAVAILABLE;
	  static EncoderPolarity::Type getPolarity(void)                UNAVAILABLE;
	  //! @}
	    
	  //! \name Prescaler
	  //! @{
	  static void setPrescaler(EncoderPrescaler::Type)                UNAVAILABLE;
	  template<EncoderPrescaler::Type> static void setPrescaler(void) UNAVAILABLE;
	  static EncoderPrescaler::Type getPrescaler(void)                UNAVAILABLE;
	  //! @}
	};
      };
    };

  }
}


#undef UNAVAILABLE

#endif//HAL_COMMON_TIMER_INTERFACE_HPP
