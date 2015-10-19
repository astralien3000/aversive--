#ifndef HAL_COMMON_TIMER_INTERFACE_HPP
#define HAL_COMMON_TIMER_INTERFACE_HPP

#include <base/integer.hpp>

//! \brief This define tells to the compiler (GNU) to warn the user when a marked funcionnality is used
//! \todo Replace by C++14 deprecated attribute
#define DEPRECATED __attribute__((deprecated))

namespace HAL {

  namespace Private {
  
    namespace TIMER {
      
      //! \brief This is just an alias to build "deprecatable Enumerations"
#define MACRO_ENUM_ELEMENT(elem)				\
      static constexpr Type elem DEPRECATED = Type::elem

      //! \brief Interrupt Handler
      //! \todo May be gatered with others IRQ_Handlers
      using IRQ_Handler = void (*)(void);

      //! \brief Contains all the TIMER Settings Types
      struct Base {
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
      };

      //! \brief Contains all the TIMER OutputCompare Settings Types
      struct OutputCompare {
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

      //! \brief Contains all the TIMER Settings Settings Types
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
	struct Channel {
	  Polarity::Type polarity;
	  Prescaler::Type prescaler;
	}; 

	//! \brief TIMER Encoder Settings
	struct Settings {
	  Mode::Type mode;
	  Channel channel1;
	  Channel channel2;
	};
      };

      //! \brief TIMER Driver Interface
      struct DriverInterface {
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
	static void setSettings(const Base::Settings&)            DEPRECATED;
	static void getSettings(Base::Settings&)                  DEPRECATED;
	template<typename Settings> static void setSettings(void) DEPRECATED;
	//! @}
	
	//! \name Counter Mode
	//! @{
	static void setCounterMode(Base::CounterMode::Type)                DEPRECATED;
	template<Base::CounterMode::Type> static void setCounterMode(void) DEPRECATED;
	static Base::CounterMode::Type getCounterMode(void)                DEPRECATED;
	//! @}

	//! \name Clock Select
	//! @{
	static void setClockSelect(Base::CounterMode::Type)                DEPRECATED;
	template<Base::CounterMode::Type> static void setClockSelect(void) DEPRECATED;
	static Base::CounterMode::Type getClockSelect(void)                DEPRECATED;
	//! @}

	//! \name Prescaler
	//! @{
	static void setPrescaler(Base::Prescaler::Type)                DEPRECATED;
	template<Base::Prescaler::Type> static void setPrescaler(void) DEPRECATED;
	static Base::Prescaler::Type getPrescaler(void)                DEPRECATED;
	//! @}

	//! \name Overflow Handler
	//! @{
	static void setOverflowHandler(IRQ_Handler) DEPRECATED;
	static IRQ_Handler getOverflowHandler(void) DEPRECATED;
	//! @}

	//! \name OutputCompare Dynamic Functions
	//! @{
	static void setOutputCompareSettings(const TIMER::OutputCompare::Settings&, u8 channel) DEPRECATED;
	static TIMER::OutputCompare::Settings getOutputCompareSettings(u8 channel)              DEPRECATED;

	static void setOutputCompareMode(TIMER::OutputCompare::Mode::Type, u8 channel) DEPRECATED;
	static TIMER::OutputCompare::Mode::Type getOutputCompareMode(u8 channel)       DEPRECATED;

	static void setOutputComparePolarity(TIMER::OutputCompare::Polarity::Type, u8 channel) DEPRECATED;
	static TIMER::OutputCompare::Polarity::Type getOutputComparePolarity(u8 channel)       DEPRECATED;

	static void setOutputComparePulseWidth(TIMER::OutputCompare::PulseWidth::Type, u8 channel) DEPRECATED;
	TIMER::OutputCompare::PulseWidth::Type getOutputComparePulseWidth(u8 channel)              DEPRECATED;

	static void setOutputCompareHandler(IRQ_Handler, u8 channel) DEPRECATED;
	static IRQ_Handler getOutputCompareHandler(u8 channel)       DEPRECATED;
	//! @}

	//! \brief Templated OutputCompare interface
	template<u8 CHANNEL>
	struct OutputCompare {
	  //! \name Settings
	  //! @{
	  static void setSettings(const TIMER::OutputCompare::Settings&) DEPRECATED;
	  template<typename Settings> static void setSettings(void)      DEPRECATED;
	  static TIMER::OutputCompare::Settings getSettings(void)        DEPRECATED;
	  //! @}

	  //! \name Mode
	  //! @{
	  static void setMode(TIMER::OutputCompare::Mode::Type)                DEPRECATED;
	  template<TIMER::OutputCompare::Mode::Type> static void setMode(void) DEPRECATED;
	  static TIMER::OutputCompare::Mode::Type getMode(void)                DEPRECATED;
	  //! @}

	  //! \name Polarity
	  //! @{
	  static void setPolarity(TIMER::OutputCompare::Polarity::Type)                DEPRECATED;
	  template<TIMER::OutputCompare::Polarity::Type> static void setPolarity(void) DEPRECATED;
	  static TIMER::OutputCompare::Polarity::Type getPolarity(void)                DEPRECATED;
	  //! @}

	  //! \name Pulse Width
	  //! @{
	  static void setPulseWidth(TIMER::OutputCompare::PulseWidth::Type)                DEPRECATED;
	  template<TIMER::OutputCompare::PulseWidth::Type> static void setPulseWidth(void) DEPRECATED;
	  TIMER::OutputCompare::PulseWidth::Type getPulseWidth(void)                       DEPRECATED;
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
	  static void setSettings(const TIMER::Encoder::Settings&)         DEPRECATED;
	  template<typename Settings> static void setSettings(void) DEPRECATED;
	  static TIMER::Encoder::Settings getSettings(void)                DEPRECATED;
	  //! @}

	  //! \name Mode
	  //! @{
	  static void setMode(TIMER::Encoder::Mode::Type)                DEPRECATED;
	  template<TIMER::Encoder::Mode::Type> static void setMode(void) DEPRECATED;
	  static TIMER::Encoder::Mode::Type getEncoderMode(void)         DEPRECATED;
	  //! @}

	  //! \name Channel Dynamic Functions
	  //! @{
	  static void setChannelPolarity(TIMER::Encoder::Polarity, u8 channel) DEPRECATED;
	  static TIMER::Encoder::Polarity getChannelPolarity(u8 channel)       DEPRECATED;

	  static void setChannelPrescaler(TIMER::Encoder::Polarity, u8 channel) DEPRECATED;
	  static TIMER::Encoder::Polarity getChannelPrescaler(u8 channel)       DEPRECATED;
	  //! @}

	  //! \brief Encoder Channel interface
	  template<u8 CHANNEL>
	  struct Channel {
	    //! \name Polarity
	    //! @{
	    static void setPolarity(TIMER::Encoder::Polarity) DEPRECATED;
	    static TIMER::Encoder::Polarity getPolarity(void) DEPRECATED;
	    //! @}
	    
	    //! \name Prescaler
	    //! @{
	    static void setPrescaler(TIMER::Encoder::Polarity) DEPRECATED;
	    static TIMER::Encoder::Polarity getPrescaler(void) DEPRECATED;
	    //! @}
	  };
	};
      };

    }
  }
}


#undef DEPRECATED

#endif//HAL_COMMON_TIMER_INTERFACE_HPP
