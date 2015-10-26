#include "../include/gpio.hpp"

using namespace HAL;

extern void delay(void);

struct LedSettings {
  static constexpr auto mode = GPIOx::Mode::OUTPUT;
  static constexpr auto output_mode = GPIOx::OutputMode::UNDEFINED;
  static constexpr auto alternate = GPIOx::Alternate::UNDEFINED;
  static constexpr auto speed = GPIOx::Speed::UNDEFINED;
  static constexpr auto pull = GPIOx::Pull::UNDEFINED;
};


int main(int, char**) {

  /*
  GPIO_B::Pin<7>::setSettings<LedSettings>();
  
  while(1) {
    delay();
    GPIO_B::Pin<7>::setValue<true>();
    delay();
    GPIO_B::Pin<7>::setValue<false>();
  }
  */

  GPIO_B::Pin<7>::setMode(GPIOx::Mode::OUTPUT);

  while(1) {
    delay();
    GPIO_B::Pin<7>::toggle();
    //GPIO_B::togglePin(7);
  }
  
  return 0;
}
