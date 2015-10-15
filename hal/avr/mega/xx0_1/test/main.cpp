#include "../include/gpio.hpp"

using namespace HAL;

extern void delay(void);

int main(int, char**) {
 
  GPIO_B::setPinMode<GPIO_B::Mode::OUTPUT, 7>();

  while(1) {
    delay();
    GPIO_B::togglePin<7>();
  }
  
  return 0;
}
