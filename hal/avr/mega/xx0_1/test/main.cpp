#include "../include/gpio.hpp"

using namespace HAL;

extern void delay(void);

int main(int, char**) {
 
  GPIO_B::Pin<7>::setMode<GPIO_B::Mode::OUTPUT>();
  GPIO_G::getValue();
  GPIO_G::setValue(0x1ff);
  GPIO_G::setValue<0xFF>();

  GPIO_G::setPinValue(0, false);
  GPIO_B::togglePinGroup(0x11);

  GPIO_C::PinGroup<0b101>::setMode<GPIO_C::Mode::OUTPUT>();
  GPIO_B::PinGroup<0x11>::toggle();

  while(1) {
    delay();
    GPIO_B::Pin<7>::toggle();
  }
  
  return 0;
}
