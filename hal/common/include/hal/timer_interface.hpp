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
	
	struct OutputCompare_Settings {
	  Mode::Type mode;
	  Polarity::Type polarity;
	  bool fast;
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

      class DriverInterface {
	/*
	  void init(const Timer_Settings&);
	  Timer_Settings getSettings(void);

	  isModuleEnabled
	  enableModule
	  disableModule

	  setCounterMode
	  getCounterMode

	  setClockSelect
	  getClockSelect

	  setPrescaler
	  getPrescaler

	  setOverflowHandler
	  getOverflowHandler

	  void initOutputCompare(const Timer_OutputCompare_Settings&, u8 channel);
	  Timer_OutputCompare_Settings getOutputCompareSettings(u8 channel);

	  setOutputCompareMode
	  getOutputCompareMode

	  setOutputComparePolarity
	  getOutputComparePolarity

	  enableOuputCompareFastMode
	  disableOuputCompareFastMode
	  getOuputCompareFastMode

	  setOuputComparePulseWidth
	  getOuputComparePulseWidth

	  setOuputCompareHandler
	  getOuputCompareHandler

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
}

#undef DEPRECATED

#endif//HAL_COMMON_TIMER_INTERFACE_HPP
