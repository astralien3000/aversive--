#include "timer.hpp"

using TIMER = HAL::Example::TIMER<0>;

void timer_test(void) {
  TIMER::isModuleEnabled();
  TIMER::enableModule();
  TIMER::disableModule();

  TIMER::isModuleSleepEnabled();
  TIMER::enableModuleSleep();
  TIMER::disableModuleSleep();

  {
    auto settings = TIMER::Settings();
    TIMER::setSettings(settings);
    TIMER::getSettings(settings);
    TIMER::setSettings<TIMER::Settings>();
  }
  
  TIMER::setCounterMode(TIMER::CounterMode::UNDEFINED);
  TIMER::setCounterMode<TIMER::CounterMode::UNDEFINED>();
  TIMER::getCounterMode();
  
  TIMER::setClockSelect(TIMER::ClockSelect::UNDEFINED);
  TIMER::setClockSelect<TIMER::ClockSelect::UNDEFINED>();
  TIMER::getClockSelect();
  
  TIMER::setPrescaler(0);
  TIMER::setPrescaler<0>();
  TIMER::getPrescaler();
  
  TIMER::setOverflowHandler(0);
  TIMER::getOverflowHandler();
  
  {
    auto settings = TIMER::OCSettings();
    TIMER::setOutputCompareSettings(0, settings);
    TIMER::getOutputCompareSettings(0, settings);
  }
  
  TIMER::setOutputCompareMode(0, TIMER::OCMode::UNDEFINED);
  TIMER::getOutputCompareMode(0);
  
  TIMER::setOutputComparePolarity(0, TIMER::OCPolarity::UNDEFINED);
  TIMER::getOutputComparePolarity(0);

  TIMER::setOutputComparePulseWidth(0, 0);
  TIMER::getOutputComparePulseWidth(0);

  TIMER::setOutputCompareHandler(0, 0);
  TIMER::getOutputCompareHandler(0);
  
  {
    auto settings = TIMER::OCSettings();
    TIMER::OutputCompare<0>::setSettings(settings);
    TIMER::OutputCompare<0>::setSettings<TIMER::OCSettings>();
    TIMER::OutputCompare<0>::getSettings(settings);
  }
  
  TIMER::OutputCompare<0>::setMode(TIMER::OCMode::UNDEFINED);
  TIMER::OutputCompare<0>::setMode<TIMER::OCMode::UNDEFINED>();
  TIMER::OutputCompare<0>::getMode();

  TIMER::OutputCompare<0>::setPolarity(TIMER::OCPolarity::UNDEFINED);
  TIMER::OutputCompare<0>::setPolarity<TIMER::OCPolarity::UNDEFINED>();
  TIMER::OutputCompare<0>::getPolarity();

  TIMER::OutputCompare<0>::setPulseWidth(0);
  TIMER::OutputCompare<0>::setPulseWidth<0>();
  TIMER::OutputCompare<0>::getPulseWidth();

  TIMER::OutputCompare<0>::setHandler(0);
  TIMER::OutputCompare<0>::getHandler();
  
  {
    auto settings = TIMER::EncoderSettings();
    TIMER::Encoder::setSettings(settings);
    TIMER::Encoder::setSettings<TIMER::EncoderSettings>();
    TIMER::Encoder::getSettings(settings);
  }
  
  TIMER::Encoder::setMode(TIMER::EncoderMode::UNDEFINED);
  TIMER::Encoder::setMode<TIMER::EncoderMode::UNDEFINED>();
  TIMER::Encoder::getEncoderMode();
  
  TIMER::Encoder::setChannelPolarity(0, TIMER::EncoderPolarity::UNDEFINED);
  TIMER::Encoder::getChannelPolarity(0);

  TIMER::Encoder::setChannelPrescaler(0, 0);
  TIMER::Encoder::getChannelPrescaler(0);
  
  TIMER::Encoder::Channel<0>::setPolarity(TIMER::EncoderPolarity::UNDEFINED);
  TIMER::Encoder::Channel<0>::setPolarity<TIMER::EncoderPolarity::UNDEFINED>();
  TIMER::Encoder::Channel<0>::getPolarity();
	    
  TIMER::Encoder::Channel<0>::setPrescaler(0);
  TIMER::Encoder::Channel<0>::setPrescaler<0>();
  TIMER::Encoder::Channel<0>::getPrescaler();
  
}
