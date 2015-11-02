/*
\brief This file is a template you can use to develop your driver
\todo 
 - Rename the security aganst include loops
 - Rename the Example namespace
 - Uncomment the functionalities that are available on your hardware
 - Implement it !
*/

#ifndef HAL_COMMON_TIMER_EXAMPLE_HPP
#define HAL_COMMON_TIMER_EXAMPLE_HPP

#include <hal/timer_interface.hpp>
#include <hal/macros_define.hpp>

namespace HAL {

  namespace Example {
  
    template<u8 ID>
    struct TIMER : ::HAL::Private::TIMER_DriverInterface<u16> {

      struct CounterMode : TIMER_DriverInterface::CounterMode {
	//_AVERSIVE_AVAILABLE_ELEMENT(UNDEFINED);
	//_AVERSIVE_AVAILABLE_ELEMENT(UP);
	//_AVERSIVE_AVAILABLE_ELEMENT(DOWN);
	//_AVERSIVE_AVAILABLE_ELEMENT(CENTER_ALIGNED);
      };

      struct ClockSelect : TIMER_DriverInterface::ClockSelect {
	//_AVERSIVE_AVAILABLE_ELEMENT(UNDEFINED);
	//_AVERSIVE_AVAILABLE_ELEMENT(INTERNAL);
      };

      struct OCMode : TIMER_DriverInterface::OCMode {
	//_AVERSIVE_AVAILABLE_ELEMENT(UNDEFINED);
	//_AVERSIVE_AVAILABLE_ELEMENT(PWM);
      };

      struct OCPolarity : TIMER_DriverInterface::OCPolarity {
	//_AVERSIVE_AVAILABLE_ELEMENT(UNDEFINED);
	//_AVERSIVE_AVAILABLE_ELEMENT(HIGH);
	//_AVERSIVE_AVAILABLE_ELEMENT(LOW);
      };

      struct EncoderMode : TIMER_DriverInterface::EncoderMode {
	//_AVERSIVE_AVAILABLE_ELEMENT(UNDEFINED);
	//_AVERSIVE_AVAILABLE_ELEMENT(CHANNEL1_COUNT);
	//_AVERSIVE_AVAILABLE_ELEMENT(CHANNEL2_COUNT);
	//_AVERSIVE_AVAILABLE_ELEMENT(BOTH_COUNT);
      };

      struct EncoderPolarity : TIMER_DriverInterface::EncoderPolarity {
	//_AVERSIVE_AVAILABLE_ELEMENT(UNDEFINED);
	//_AVERSIVE_AVAILABLE_ELEMENT(RISING);
	//_AVERSIVE_AVAILABLE_ELEMENT(FALLING);
	//_AVERSIVE_AVAILABLE_ELEMENT(BOTH);
      };
      
      //static bool isModuleEnabled(void) { return false; }
      //static void enableModule(void) {}
      //static void disableModule(void) {}

      //static bool isModuleSleepEnabled(void) { return false; }
      //static void enableModuleSleep(void) {}
      //static void disableModuleSleep(void) {}

      //static void setSettings(const Settings&) {}
      //static void getSettings(Settings&) {}
      //template<typename Settings> static void setSettings(void) {}
	
      //static void setCounterMode(typename CounterMode::Type) {}
      //template<typename CounterMode::Type> static void setCounterMode(void) {}
      //static typename CounterMode::Type getCounterMode(void) { return CounterMode::UNDEFINED; }

      //static void setClockSelect(typename ClockSelect::Type) {}
      //template<typename ClockSelect::Type> static void setClockSelect(void) {}
      //static typename ClockSelect::Type getClockSelect(void) { return ClockSelect::UNDEFINED; }

      //static void setPrescaler(typename Prescaler::Type) {}
      //template<typename Prescaler::Type> static void setPrescaler(void) {}
      //static typename Prescaler::Type getPrescaler(void) { return 0; }

      //static void setOverflowHandler(IRQ_Handler) {}
      //static IRQ_Handler getOverflowHandler(void) { return 0; }

      //static void setOutputCompareSettings(u8, const OCSettings&) {}
      //static void getOutputCompareSettings(u8, OCSettings&) {}

      //static void setOutputCompareMode(u8, typename OCMode::Type) {}
      //static typename OCMode::Type getOutputCompareMode(u8) { return OCMode::UNDEFINED; }

      //static void setOutputComparePolarity(u8, typename OCPolarity::Type) {}
      //static typename OCPolarity::Type getOutputComparePolarity(u8) { return OCPolarity::UNDEFINED; }

      //static void setOutputComparePulseWidth(u8, typename OCPulseWidth::Type) {}
      //static typename OCPulseWidth::Type getOutputComparePulseWidth(u8) { return 0; }

      //static void setOutputCompareHandler(u8, IRQ_Handler) {}
      //static IRQ_Handler getOutputCompareHandler(u8) { return 0; }
      
      template<u8 CHANNEL>
      struct OutputCompare : TIMER_DriverInterface::OutputCompare<CHANNEL> {
	//static void setSettings(const OCSettings&) {}
	//template<typename Settings> static void setSettings(void) {}
	//static void getSettings(OCSettings&) {}

	//static void setMode(typename OCMode::Type) {}
	//template<typename OCMode::Type> static void setMode(void) {}
	//static typename OCMode::Type getMode(void) { return OCMode::UNDEFINED; }

	//static void setPolarity(typename OCPolarity::Type) {}
	//template<typename OCPolarity::Type> static void setPolarity(void) {}
	//static typename OCPolarity::Type getPolarity(void) { return OCPolarity::UNDEFINED; }

	//static void setPulseWidth(typename OCPulseWidth::Type) {}
	//template<typename OCPulseWidth::Type> static void setPulseWidth(void) {}
	//static typename OCPulseWidth::Type getPulseWidth(void) { return 0; }

	//static void setHandler(IRQ_Handler) {}
	//static IRQ_Handler getHandler(void) { return 0; }
      };

      struct Encoder : TIMER_DriverInterface::Encoder {
	//static void setSettings(const EncoderSettings&) {}
	//template<typename Settings> static void setSettings(void) {}
	//static void getSettings(EncoderSettings&) {}

	//static void setMode(typename EncoderMode::Type) {}
	//template<typename EncoderMode::Type> static void setMode(void) {}
	//static typename EncoderMode::Type getEncoderMode(void) { return EncoderMode::UNDEFINED; }

	//static void setChannelPolarity(u8, typename EncoderPolarity::Type) {}
	//static typename EncoderPolarity::Type getChannelPolarity(u8) { return EncoderPolarity::UNDEFINED; }

	//static void setChannelPrescaler(u8, EncoderPrescaler::Type) {}
	//static typename EncoderPrescaler::Type getChannelPrescaler(u8) { return 0; }

	template<u8 CHANNEL>
	struct Channel : TIMER_DriverInterface::Encoder::template Channel<CHANNEL> {
	  //static void setPolarity(typename EncoderPolarity::Type) {}
	  //template<typename EncoderPolarity::Type> static void setPolarity(void) {}
	  //static typename EncoderPolarity::Type getPolarity(void) { return EncoderPolarity::UNDEFINED; }
	    
	  //static void setPrescaler(typename EncoderPrescaler::Type) {}
	  //template<typename EncoderPrescaler::Type> static void setPrescaler(void) {}
	  //static typename EncoderPrescaler::Type getPrescaler(void) { return 0; }
	};
      };
    };

  }
}

#include <hal/macros_undef.hpp>

#endif//HAL_COMMON_TIMER_EXAMPLE_HPP
