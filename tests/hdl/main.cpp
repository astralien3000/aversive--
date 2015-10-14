//#include <memory_mapping.hpp>

#define AVERSIVE

#if defined AVERSIVE
#include <hdl/reg.hpp>
using namespace HDL;

#else
#include <avr/io.h>

#endif


int main(int, char**) {
#if defined AVERSIVE

  GPIO_A::PIN = 0x00;
  GPIO<2>::Fields::PORT_2 = true;
  TIMER_0::CCR_A = 0x00;
  TIMER_1::Fields::TOV = false;
  UART_0::DR = 'a';
  UART_1::Fields::RXC = true;
  GPIO_L::Fields::PORT_2 = true;
  
#else

#endif
  
  return 0;
}
