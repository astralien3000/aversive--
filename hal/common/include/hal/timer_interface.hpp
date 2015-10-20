#ifndef HAL_COMMON_TIMER_INTERFACE_HPP
#define HAL_COMMON_TIMER_INTERFACE_HPP

#include <base/integer.hpp>

//! \brief This define tells to the compiler (GNU) to warn the user when a marked funcionnality is used
//! \todo Replace by C++14 deprecated attribute
#define DEPRECATED __attribute__((deprecated))

namespace HAL {

  namespace Private {
  
    //! \brief TIMER Driver Interface
    struct TIMER_DriverInterface {

      //! \brief This is just an alias to build "deprecatable Enumerations"
#define MACRO_ENUM_ELEMENT(elem)				\
      static constexpr Type elem DEPRECATED = Type::elem

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
      static void setSettings(const Settings&)            DEPRECATED;
      static void getSettings(Settings&)                  DEPRECATED;
      template<typename Settings> static void setSettings(void) DEPRECATED;
      //! @}
	
      //! \name Counter Mode
      //! @{
      static void setCounterMode(CounterMode::Type)                DEPRECATED;
      template<CounterMode::Type> static void setCounterMode(void) DEPRECATED;
      static CounterMode::Type getCounterMode(void)                DEPRECATED;
      //! @}

      //! \name Clock Select
      //! @{
      static void setClockSelect(CounterMode::Type)                DEPRECATED;
      template<CounterMode::Type> static void setClockSelect(void) DEPRECATED;
      static CounterMode::Type getClockSelect(void)                DEPRECATED;
      //! @}

      //! \name Prescaler
      //! @{
      static void setPrescaler(Prescaler::Type)                DEPRECATED;
      template<Prescaler::Type> static void setPrescaler(void) DEPRECATED;
      static Prescaler::Type getPrescaler(void)                DEPRECATED;
      //! @}

      //! \name Overflow Handler
      //! @{
      static void setOverflowHandler(IRQ_Handler) DEPRECATED;
      static IRQ_Handler getOverflowHandler(void) DEPRECATED;
      //! @}

      //! \name OutputCompare Dynamic Functions
      //! @{
      static void setOutputCompareSettings(const OCSettings&, u8 channel) DEPRECATED;
      static void getOutputCompareSettings(OCSettings&, u8 channel)              DEPRECATED;

      static void setOutputCompareMode(OCMode::Type, u8 channel) DEPRECATED;
      static OCMode::Type getOutputCompareMode(u8 channel)       DEPRECATED;

      static void setOutputComparePolarity(OCPolarity::Type, u8 channel) DEPRECATED;
      static OCPolarity::Type getOutputComparePolarity(u8 channel)       DEPRECATED;

      static void setOutputComparePulseWidth(OCPulseWidth::Type, u8 channel) DEPRECATED;
      OCPulseWidth::Type getOutputComparePulseWidth(u8 channel)              DEPRECATED;

      static void setOutputCompareHandler(IRQ_Handler, u8 channel) DEPRECATED;
      static IRQ_Handler getOutputCompareHandler(u8 channel)       DEPRECATED;
      //! @}
      
      //! \brief Templated OutputCompare interface
      template<u8 CHANNEL>
      struct OutputCompare {
	//! \name Settings
	//! @{
	static void setSettings(const OCSettings&) DEPRECATED;
	template<typename Settings> static void setSettings(void)      DEPRECATED;
	static void getSettings(OCSettings&)        DEPRECATED;
	//! @}

	//! \name Mode
	//! @{
	static void setMode(OCMode::Type)                DEPRECATED;
	template<OCMode::Type> static void setMode(void) DEPRECATED;
	static OCMode::Type getMode(void)                DEPRECATED;
	//! @}

	//! \name Polarity
	//! @{
	static void setPolarity(OCPolarity::Type)                DEPRECATED;
	template<OCPolarity::Type> static void setPolarity(void) DEPRECATED;
	static OCPolarity::Type getPolarity(void)                DEPRECATED;
	//! @}

	//! \name Pulse Width
	//! @{
	static void setPulseWidth(OCPulseWidth::Type)                DEPRECATED;
	template<OCPulseWidth::Type> static void setPulseWidth(void) DEPRECATED;
	OCPulseWidth::Type getPulseWidth(void)                       DEPRECATED;
	//! @}

	//! \name Output Compare Handler
	//! @{
	static void setHandler(IRQ_Handler) DEPRECATED;
	static IRQ_Handler getHandler(void) DEPRECATED;
	//! @}
      };

      //! \brief Encoder interface
      struct Encoder {
	//! \name Settings
	//! @{
	static void setSettings(const EncoderSettings&)         DEPRECATED;
	template<typename Settings> static void setSettings(void) DEPRECATED;
	static void getSettings(EncoderSettings&)                DEPRECATED;
	//! @}

	//! \name Mode
	//! @{
	static void setMode(EncoderMode::Type)                DEPRECATED;
	template<EncoderMode::Type> static void setMode(void) DEPRECATED;
	static EncoderMode::Type getEncoderMode(void)         DEPRECATED;
	//! @}

	//! \name Channel Dynamic Functions
	//! @{
	static void setChannelPolarity(EncoderPolarity::Type, u8 channel) DEPRECATED;
	static EncoderPolarity::Type getChannelPolarity(u8 channel)       DEPRECATED;

	static void setChannelPrescaler(EncoderPolarity, u8 channel) DEPRECATED;
	static EncoderPolarity::Type getChannelPrescaler(u8 channel)       DEPRECATED;
	//! @}

	//! \brief Encoder Channel interface
	template<u8 CHANNEL>
	struct Channel {
	  //! \name Polarity
	  //! @{
	  static void setPolarity(EncoderPolarity::Type)                DEPRECATED;
	  template<EncoderPolarity::Type> static void setPolarity(void) DEPRECATED;
	  static EncoderPolarity::Type getPolarity(void)                DEPRECATED;
	  //! @}
	    
	  //! \name Prescaler
	  //! @{
	  static void setPrescaler(EncoderPrescaler::Type)                DEPRECATED;
	  template<EncoderPrescaler::Type> static void setPrescaler(void) DEPRECATED;
	  static EncoderPrescaler::Type getPrescaler(void)                DEPRECATED;
	  //! @}
	};
      };
    };

  }
}


#undef DEPRECATED

#endif//HAL_COMMON_TIMER_INTERFACE_HPP
