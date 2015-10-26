#include "../include/gpio.hpp"

using namespace HAL;

extern void delay(void);

struct Test {
  static constexpr auto mode = GPIO_D::Mode::OUTPUT;
  static constexpr auto output_mode = GPIO_D::OutputMode::UNDEFINED;
  static constexpr auto alternate = GPIO_D::Alternate::UNDEFINED;
  static constexpr auto speed = GPIO_D::Speed::UNDEFINED;
  static constexpr auto pull = GPIO_D::Pull::UNDEFINED;
};


int main(int, char**) {
 
  GPIO_B::Pin<7>::setMode<GPIO_B::Mode::OUTPUT>();
  GPIO_G::getValue();
  GPIO_G::setValue(0x1ff);
  GPIO_G::setValue<0xFF>();

  GPIO_G::setPinValue(0, false);
  GPIO_B::togglePinGroup(0x11);

  GPIO_C::PinGroup<0b101>::setMode<GPIO_C::Mode::OUTPUT>();
  GPIO_B::PinGroup<0x11>::toggle();

  GPIO_D::Settings settings;
  GPIO_D::getPinSettings(0, settings);

  GPIO_D::PinGroup<0b11>::setSettings<Test>();
  GPIO_D::Pin<3>::setSettings<Test>();

  while(1) {
    delay();
    GPIO_B::Pin<7>::toggle();
  }
  
  return 0;
}
