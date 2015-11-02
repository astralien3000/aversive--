#include "gpio.hpp"

using GPIO = HAL::Example::GPIO<0>;

void gpio_test(void) {
  GPIO::isModuleEnabled();
  GPIO::enableModule();
  GPIO::disableModule();
  
  GPIO::isModuleSleepEnabled();
  GPIO::enableModuleSleep();
  GPIO::disableModuleSleep();

  {
    auto settings = GPIO::Settings();
    GPIO::getPinSettings(0, settings);
    GPIO::setPinSettings(0, settings);
    GPIO::setPinGroupSettings(1, settings);
  }
    
  GPIO::getPinMode(0);
  GPIO::setPinMode(0, GPIO::Mode::UNDEFINED);
  GPIO::setPinGroupMode(1, GPIO::Mode::UNDEFINED);
  
  GPIO::getPinOutputMode(0);
  GPIO::setPinOutputMode(0, GPIO::OutputMode::UNDEFINED);
  GPIO::setPinGroupOutputMode(1, GPIO::OutputMode::UNDEFINED);
  
  GPIO::getPinAlternate(0);
  GPIO::setPinAlternate(0, GPIO::Alternate::UNDEFINED);
  GPIO::setPinGroupAlternate(1, GPIO::Alternate::UNDEFINED);
  
  GPIO::getPinPull(0);
  GPIO::setPinPull(0, GPIO::Pull::UNDEFINED);
  GPIO::setPinGroupPull(1, GPIO::Pull::UNDEFINED);
      
  GPIO::getPinSpeed(0);
  GPIO::setPinSpeed(0, GPIO::Speed::UNDEFINED);
  GPIO::setPinGroupSpeed(1, GPIO::Speed::UNDEFINED);
      
  GPIO::getPinExtiHandler(0);
  GPIO::setPinExtiHandler(0, (GPIO::IRQ_Handler)0);
      
  GPIO::getPinTriggerDetection(0);
  GPIO::setPinTriggerDectection(0, GPIO::TriggerDetection::UNDEFINED);
  
  GPIO::getValue();
  GPIO::setValue(0);
  GPIO::setValue<0>();

  GPIO::getPinValue(0);
  GPIO::setPinValue(0,false);
  GPIO::togglePin(0);

  GPIO::setPinGroupValue(1,false);
  GPIO::togglePinGroup(1);

  {
    auto settings = GPIO::Settings();
    GPIO::PinGroup<1>::setSettings(settings);
    GPIO::PinGroup<1>::setSettings<GPIO::Settings>();
  }
  
  GPIO::PinGroup<1>::setMode(GPIO::Mode::UNDEFINED);
  GPIO::PinGroup<1>::setMode<GPIO::Mode::UNDEFINED>();
	
  GPIO::PinGroup<1>::setOutputMode(GPIO::OutputMode::UNDEFINED);
  GPIO::PinGroup<1>::setOutputMode<GPIO::OutputMode::UNDEFINED>();
	
  GPIO::PinGroup<1>::setAlternate(GPIO::Alternate::UNDEFINED);
  GPIO::PinGroup<1>::setAlternate<GPIO::Alternate::UNDEFINED>();
	
  GPIO::PinGroup<1>::setPull(GPIO::Pull::UNDEFINED);
  GPIO::PinGroup<1>::setPull<GPIO::Pull::UNDEFINED>();
	
  GPIO::PinGroup<1>::setSpeed(GPIO::Speed::UNDEFINED);
  GPIO::PinGroup<1>::setSpeed<GPIO::Speed::UNDEFINED>();
	
  GPIO::PinGroup<1>::setValue(false);
  GPIO::PinGroup<1>::setValue<false>();
  GPIO::PinGroup<1>::toggle();
  
  {
    auto settings = GPIO::Settings();
    GPIO::Pin<0>::getSettings(settings);
    GPIO::Pin<0>::setSettings(settings);
    GPIO::Pin<0>::setSettings<GPIO::Settings>();
  }
  
  GPIO::Pin<0>::getMode();
  GPIO::Pin<0>::setMode(GPIO::Mode::UNDEFINED);
  GPIO::Pin<0>::setMode<GPIO::Mode::UNDEFINED>();
  
  GPIO::Pin<0>::getOutputMode();
  GPIO::Pin<0>::setOutputMode(GPIO::OutputMode::UNDEFINED);
  GPIO::Pin<0>::setOutputMode<GPIO::OutputMode::UNDEFINED>();
	
  GPIO::Pin<0>::getAlternate();
  GPIO::Pin<0>::setAlternate(GPIO::Alternate::UNDEFINED);
  GPIO::Pin<0>::setAlternate<GPIO::Alternate::UNDEFINED>();
	
  GPIO::Pin<0>::getPull();
  GPIO::Pin<0>::setPull(GPIO::Pull::UNDEFINED);
  GPIO::Pin<0>::setPull<GPIO::Pull::UNDEFINED>();
	
  GPIO::Pin<0>::getSpeed();
  GPIO::Pin<0>::setSpeed(GPIO::Speed::UNDEFINED);
  GPIO::Pin<0>::setSpeed<GPIO::Speed::UNDEFINED>();
	
  GPIO::Pin<0>::getExtiHandler();
  GPIO::Pin<0>::setExtiHandler((GPIO::IRQ_Handler)0);
	
  GPIO::Pin<0>::getTriggerDetection();
  GPIO::Pin<0>::setTriggerDectection(GPIO::TriggerDetection::UNDEFINED);
  GPIO::Pin<0>::setTriggerDectection<GPIO::TriggerDetection::UNDEFINED>();
	
  GPIO::Pin<0>::getValue();
  GPIO::Pin<0>::setValue(false);
  GPIO::Pin<0>::toggle();
  GPIO::Pin<0>::setValue<false>();
}
