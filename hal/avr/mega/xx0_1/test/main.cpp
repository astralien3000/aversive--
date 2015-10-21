#include "../include/gpio.hpp"

using namespace HAL;

extern void delay(void);

int main(int, char**) {
 
  GPIO_B::Pin<7>::setMode<GPIO_B::Mode::OUTPUT>();

  while(1) {
    delay();
    GPIO_B::Pin<7>::toggle();
  }
  
  return 0;
}
