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

      struct OC {
	//! \brief The OutputCompare Mode
	struct Mode {
	  enum class Type : u8 { UNDEFINED, PWM };
	  MACRO_ENUM_ELEMENT(UNDEFINED);
	  MACRO_ENUM_ELEMENT(PWM);
	};

	//! \brief The OutputCompare Signal Polarity
	struct Polarity {
	  enum class Type : u8 { HIGH, LOW };
	  MACRO_ENUM_ELEMENT(HIGH);
	  MACRO_ENUM_ELEMENT(LOW);
	};

	//! \brief The OutputCompare Pulse Width
	struct PulseWidth {
	  using Type = u32;
	};
	
	//! \brief The OutputCompare Pulse Width
	struct Settings {
	  Mode::Type mode;
	  Polarity::Type polarity;
	  PulseWidth::Type pulse_width;
	};
      };
      
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
      static void setOutputCompareSettings(const OC::Settings&, u8 channel) DEPRECATED;
      static OC::Settings getOutputCompareSettings(u8 channel)              DEPRECATED;

      static void setOutputCompareMode(OC::Mode::Type, u8 channel) DEPRECATED;
      static OC::Mode::Type getOutputCompareMode(u8 channel)       DEPRECATED;

      static void setOutputComparePolarity(OC::Polarity::Type, u8 channel) DEPRECATED;
      static OC::Polarity::Type getOutputComparePolarity(u8 channel)       DEPRECATED;

      static void setOutputComparePulseWidth(OC::PulseWidth::Type, u8 channel) DEPRECATED;
      OC::PulseWidth::Type getOutputComparePulseWidth(u8 channel)              DEPRECATED;

      static void setOutputCompareHandler(IRQ_Handler, u8 channel) DEPRECATED;
      static IRQ_Handler getOutputCompareHandler(u8 channel)       DEPRECATED;
      //! @}
      
      //! \brief Templated OutputCompare interface
      template<u8 CHANNEL>
      struct OutputCompare {
	//! \name Settings
	//! @{
	static void setSettings(const OC::Settings&) DEPRECATED;
	template<typename Settings> static void setSettings(void)      DEPRECATED;
	static OC::Settings getSettings(void)        DEPRECATED;
	//! @}

	//! \name Mode
	//! @{
	static void setMode(OC::Mode::Type)                DEPRECATED;
	template<OC::Mode::Type> static void setMode(void) DEPRECATED;
	static OC::Mode::Type getMode(void)                DEPRECATED;
	//! @}

	//! \name Polarity
	//! @{
	static void setPolarity(OC::Polarity::Type)                DEPRECATED;
	template<OC::Polarity::Type> static void setPolarity(void) DEPRECATED;
	static OC::Polarity::Type getPolarity(void)                DEPRECATED;
	//! @}

	//! \name Pulse Width
	//! @{
	static void setPulseWidth(OC::PulseWidth::Type)                DEPRECATED;
	template<OC::PulseWidth::Type> static void setPulseWidth(void) DEPRECATED;
	OC::PulseWidth::Type getPulseWidth(void)                       DEPRECATED;
	//! @}

	//! \name Output Compare Handler
	//! @{
	static void setHandler(IRQ_Handler) DEPRECATED;
	static IRQ_Handler getHandler(void) DEPRECATED;
	//! @}
      };

      //! \brief Encoder interface
      struct Encoder {
	//! \brief The Encoder Mode
	struct Mode {
	  enum class Type : u8 { UNDEFINED, CHANNEL1_COUNT, CHANNEL2_COUNT, BOTH_COUNT };
	  MACRO_ENUM_ELEMENT(UNDEFINED);
	  MACRO_ENUM_ELEMENT(CHANNEL1_COUNT);
	  MACRO_ENUM_ELEMENT(CHANNEL2_COUNT);
	  MACRO_ENUM_ELEMENT(BOTH_COUNT);
	};

	//! \brief The Encoder Polarity
	struct Polarity {
	  enum class Type : u8 { UNDEFINED, RISING, FALLING, BOTH };
	  MACRO_ENUM_ELEMENT(UNDEFINED);
	  MACRO_ENUM_ELEMENT(RISING);
	  MACRO_ENUM_ELEMENT(FALLING);
	  MACRO_ENUM_ELEMENT(BOTH);
	};
	
	//! \brief The Encoder Prescaler
	struct Prescaler {
	  using Type = u32;
	};
	
	//! \brief TIMER Encoder Channel Settings
	struct ChannelSettings {
	  Polarity::Type polarity;
	  Prescaler::Type prescaler;
	}; 

	//! \brief TIMER Encoder Settings
	struct Settings {
	  Mode::Type mode;
	  ChannelSettings channel1;
	  ChannelSettings channel2;
	};

	//! \name Settings
	//! @{
	static void setSettings(const Settings&)         DEPRECATED;
	template<typename Settings> static void setSettings(void) DEPRECATED;
	static Settings getSettings(void)                DEPRECATED;
	//! @}

	//! \name Mode
	//! @{
	static void setMode(Mode::Type)                DEPRECATED;
	template<Mode::Type> static void setMode(void) DEPRECATED;
	static Mode::Type getEncoderMode(void)         DEPRECATED;
	//! @}

	//! \name Channel Dynamic Functions
	//! @{
	static void setChannelPolarity(Polarity, u8 channel) DEPRECATED;
	static Polarity getChannelPolarity(u8 channel)       DEPRECATED;

	static void setChannelPrescaler(Polarity, u8 channel) DEPRECATED;
	static Polarity getChannelPrescaler(u8 channel)       DEPRECATED;
	//! @}

	//! \brief Encoder Channel interface
	template<u8 CHANNEL>
	struct Channel {
	  //! \name Polarity
	  //! @{
	  static void setPolarity(Polarity) DEPRECATED;
	  static Polarity getPolarity(void) DEPRECATED;
	  //! @}
	    
	  //! \name Prescaler
	  //! @{
	  static void setPrescaler(Polarity) DEPRECATED;
	  static Polarity getPrescaler(void) DEPRECATED;
	  //! @}
	};
      };
    };

  }
}


#undef DEPRECATED

#endif//HAL_COMMON_TIMER_INTERFACE_HPP
