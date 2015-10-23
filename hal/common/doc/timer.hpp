#ifndef HAL_COMMON_TIMER_EXAMPLE_HPP
#define HAL_COMMON_TIMER_EXAMPLE_HPP

#include <hal/timer_interface.hpp>

namespace HAL {

  namespace Example {
  
    template<u8 ID>
    struct TIMER : ::HAL::Private::TIMER_DriverInterface {

#define MACRO_ENUM_ELEMENT(elem)				\
      static constexpr Type elem = Type::elem

      struct CounterMode : TIMER_DriverInterface::CounterMode {
	//MACRO_ENUM_ELEMENT(UNDEFINED);
	//MACRO_ENUM_ELEMENT(UP);
	//MACRO_ENUM_ELEMENT(DOWN);
	//MACRO_ENUM_ELEMENT(CENTER_ALIGNED);
      };

      struct ClockSelect : TIMER_DriverInterface::ClockSelect {
	//MACRO_ENUM_ELEMENT(UNDEFINED);
	//MACRO_ENUM_ELEMENT(INTERNAL);
      };

      struct OCMode : TIMER_DriverInterface::OCMode {
	//MACRO_ENUM_ELEMENT(UNDEFINED);
	//MACRO_ENUM_ELEMENT(PWM);
      };

      struct OCPolarity : TIMER_DriverInterface::OCPolarity {
	//MACRO_ENUM_ELEMENT(HIGH);
	//MACRO_ENUM_ELEMENT(LOW);
      };

      struct EncoderMode : TIMER_DriverInterface::EncoderMode {
	//MACRO_ENUM_ELEMENT(UNDEFINED);
	//MACRO_ENUM_ELEMENT(CHANNEL1_COUNT);
	//MACRO_ENUM_ELEMENT(CHANNEL2_COUNT);
	//MACRO_ENUM_ELEMENT(BOTH_COUNT);
      };

      struct EncoderPolarity : TIMER_DriverInterface::EncoderPolarity {
	//MACRO_ENUM_ELEMENT(UNDEFINED);
	//MACRO_ENUM_ELEMENT(RISING);
	//MACRO_ENUM_ELEMENT(FALLING);
	//MACRO_ENUM_ELEMENT(BOTH);
      };

#undef MACRO_ENUM_ELEMENT
      
      //static bool isModuleEnabled(void) {}
      //static void enableModule(void) {}
      //static void disableModule(void) {}

      //static bool isModuleSleepEnabled(void) {}
      //static void enableModuleSleep(void) {}
      //static void disableModuleSleep(void) {}

      //static void setSettings(const Settings&) {}
      //static void getSettings(Settings&) {}
      //template<typename Settings> static void setSettings(void) {}
	
      //static void setCounterMode(CounterMode::Type) {}
      //template<CounterMode::Type> static void setCounterMode(void) {}
      //static CounterMode::Type getCounterMode(void) {}

      //static void setClockSelect(CounterMode::Type) {}
      //template<CounterMode::Type> static void setClockSelect(void) {}
      //static CounterMode::Type getClockSelect(void) {}

      //static void setPrescaler(Prescaler::Type) {}
      //template<Prescaler::Type> static void setPrescaler(void) {}
      //static Prescaler::Type getPrescaler(void) {}

      //static void setOverflowHandler(IRQ_Handler) {}
      //static IRQ_Handler getOverflowHandler(void) {}

      //static void setOutputCompareSettings(u8 channel, const OCSettings&) {}
      //static void getOutputCompareSettings(u8 channel, OCSettings&) {}

      //static void setOutputCompareMode(u8 channel, OCMode::Type) {}
      //static OCMode::Type getOutputCompareMode(u8 channel) {}

      //static void setOutputComparePolarity(u8 channel, OCPolarity::Type) {}
      //static OCPolarity::Type getOutputComparePolarity(u8 channel) {}

      //static void setOutputComparePulseWidth(u8 channel, OCPulseWidth::Type) {}
      //static OCPulseWidth::Type getOutputComparePulseWidth(u8 channel) {}

      //static void setOutputCompareHandler(u8 channel, IRQ_Handler) {}
      //static IRQ_Handler getOutputCompareHandler(u8 channel) {}
      
      template<u8 CHANNEL>
      struct OutputCompare : TIMER_DriverInterface::OutputCompare<CHANNEL> {
	//static void setSettings(const OCSettings&) {}
	//template<typename Settings> static void setSettings(void) {}
	//static void getSettings(OCSettings&) {}

	//static void setMode(OCMode::Type) {}
	//template<OCMode::Type> static void setMode(void) {}
	//static OCMode::Type getMode(void) {}

	//static void setPolarity(OCPolarity::Type) {}
	//template<OCPolarity::Type> static void setPolarity(void) {}
	//static OCPolarity::Type getPolarity(void) {}

	//static void setPulseWidth(OCPulseWidth::Type) {}
	//template<OCPulseWidth::Type> static void setPulseWidth(void) {}
	//static OCPulseWidth::Type getPulseWidth(void) {}

	//static void setHandler(IRQ_Handler) {}
	//static IRQ_Handler getHandler(void) {}
      };

      struct Encoder : TIMER_DriverInterface::Encoder {
	//static void setSettings(const EncoderSettings&) {}
	//template<typename Settings> static void setSettings(void) {}
	//static void getSettings(EncoderSettings&) {}

	//static void setMode(EncoderMode::Type) {}
	//template<EncoderMode::Type> static void setMode(void) {}
	//static EncoderMode::Type getEncoderMode(void) {}

	//static void setChannelPolarity(u8 channel, EncoderPolarity::Type) {}
	//static EncoderPolarity::Type getChannelPolarity(u8 channel) {}

	//static void setChannelPrescaler(u8 channel, EncoderPolarity) {}
	//static EncoderPolarity::Type getChannelPrescaler(u8 channel) {}

	template<u8 CHANNEL>
	struct Channel : TIMER_DriverInterface::Encoder::template Channel<CHANNEL> {
	  //static void setPolarity(EncoderPolarity::Type) {}
	  //template<EncoderPolarity::Type> static void setPolarity(void) {}
	  //static EncoderPolarity::Type getPolarity(void) {}
	    
	  //static void setPrescaler(EncoderPrescaler::Type) {}
	  //template<EncoderPrescaler::Type> static void setPrescaler(void) {}
	  //static EncoderPrescaler::Type getPrescaler(void) {}
	};
      };
    };

  }
}

#endif//HAL_COMMON_TIMER_EXAMPLE_HPP
