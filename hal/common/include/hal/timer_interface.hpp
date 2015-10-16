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

      struct Base {
	struct CounterMode {
	  enum class Type : u8 { UNDEFINED, UP, DOWN, CENTER_ALIGNED };
	  MACRO_ENUM_ELEMENT(UNDEFINED);
	  MACRO_ENUM_ELEMENT(UP);
	  MACRO_ENUM_ELEMENT(DOWN);
	  MACRO_ENUM_ELEMENT(CENTER_ALIGNED);
	};
	
	struct ClockSelect {
	  enum class Type : u8 { UNDEFINED, INTERNAL };
	  MACRO_ENUM_ELEMENT(UNDEFINED);
	  MACRO_ENUM_ELEMENT(INTERNAL);
	};

	struct Prescaler {
	  using Type = u32;
	};

	struct Period {
	  using Type = u32;
	};

	struct Settings {
	  CounterMode::Type counter_mode;
	  ClockSelect::Type clock_select;
	  Prescaler::Type prescaler;
	  Period::Type period;
	};
      };

      struct OutputCompare {
	struct Mode {
	  enum class Type : u8 { UNDEFINED, PWM };
	  MACRO_ENUM_ELEMENT(UNDEFINED);
	  MACRO_ENUM_ELEMENT(PWM);
	};

	struct Polarity {
	  enum class Type : u8 { HIGH, LOW };
	  MACRO_ENUM_ELEMENT(HIGH);
	  MACRO_ENUM_ELEMENT(LOW);
	};

	struct PulseWidth {
	  using Type = u32;
	};
	
	struct Settings {
	  Mode::Type mode;
	  Polarity::Type polarity;
	  PulseWidth::Type pulse_width;
	};
      };

      struct Encoder {
	struct Mode {
	  enum class Type : u8 { UNDEFINED, CHANNEL1_COUNT, CHANNEL2_COUNT, BOTH_COUNT };
	  MACRO_ENUM_ELEMENT(UNDEFINED);
	  MACRO_ENUM_ELEMENT(CHANNEL1_COUNT);
	  MACRO_ENUM_ELEMENT(CHANNEL2_COUNT);
	  MACRO_ENUM_ELEMENT(BOTH_COUNT);
	};

	struct Polarity {
	  enum class Type : u8 { UNDEFINED, RISING, FALLING, BOTH };
	  MACRO_ENUM_ELEMENT(UNDEFINED);
	  MACRO_ENUM_ELEMENT(RISING);
	  MACRO_ENUM_ELEMENT(FALLING);
	  MACRO_ENUM_ELEMENT(BOTH);
	};
	
	struct Prescaler {
	  using Type = u32;
	};
	
	struct Channel {
	  Polarity::Type polarity;
	  Prescaler::Type prescaler;
	}; 

	struct Settings {
	  Mode::Type mode;
	  Channel channel1;
	  Channel channel2;
	};
      };

      struct DriverInterface {

	static bool isModuleEnabled(void) DEPRECATED;
	static void enableModule(void)    DEPRECATED;
	static void disableModule(void)   DEPRECATED;

	static bool isModuleSleepEnabled(void) DEPRECATED;
	static void enableModuleSleep(void)    DEPRECATED;
	static void disableModuleSleep(void)   DEPRECATED;

	static void init(const Base::Settings&)            DEPRECATED;
	static void getSettings(Base::Settings&)           DEPRECATED;
	template<typename Settings> static void init(void) DEPRECATED;
	
	static void setCounterMode(Base::CounterMode::Type)                DEPRECATED;
	template<Base::CounterMode::Type> static void setCounterMode(void) DEPRECATED;
	static Base::CounterMode::Type getCounterMode(void)                DEPRECATED;

	static void setClockSelect(Base::CounterMode::Type)                DEPRECATED;
	template<Base::CounterMode::Type> static void setClockSelect(void) DEPRECATED;
	static Base::CounterMode::Type getClockSelect(void)                DEPRECATED;

	static void setPrescaler(Base::Prescaler::Type)                DEPRECATED;
	template<Base::Prescaler::Type> static void setPrescaler(void) DEPRECATED;
	static Base::Prescaler::Type getPrescaler(void)                DEPRECATED;

	static void setOverflowHandler(IRQ_Handler);
	static IRQ_Handler getOverflowHandler(void);

	template<u8 CHANNEL>
	struct OutputCompare {
	  static void init(const TIMER::OutputCompare::Settings&);
	  template<typename Settings> static void init(void);
	  static TIMER::OutputCompare::Settings getSettings(void);

	  static void setMode(TIMER::OutputCompare::Mode::Type);
	  template<TIMER::OutputCompare::Mode::Type> static void setMode(void);
	  static TIMER::OutputCompare::Mode::Type getMode(void);

	  static void setPolarity(TIMER::OutputCompare::Polarity::Type);
	  template<TIMER::OutputCompare::Polarity::Type> static void setPolarity(void);
	  static TIMER::OutputCompare::Polarity::Type getPolarity(void);

	  static void setPulseWidth(TIMER::OutputCompare::PulseWidth::Type);
	  template<TIMER::OutputCompare::PulseWidth::Type> static void setPulseWidth(void);
	  TIMER::OutputCompare::PulseWidth::Type getPulseWidth(void);

	  static void setHandler(IRQ_Handler);
	  static IRQ_Handler getHandler(void);
	};
      };
	
      /*
	void initEncoder(const Timer_Encoder_Settings&);
	Timer_Encoder_Settings getEncoderSettings(void);

	setEncoderMode
	getEncoderMode

	setEncoderChannelPolarity
	getEncoderChannelPolarity

	setEncoderChannelPrescaler
	getEncoderChannelPrescaler
      */
    };


  }
}


#undef DEPRECATED

#endif//HAL_COMMON_TIMER_INTERFACE_HPP
