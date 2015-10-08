//#include <memory_mapping.hpp>

//#define AVERSIVE

#if defined AVERSIVE
#include <hdl/reg.hpp>
using namespace HDL;

#else
#include <avr/io.h>

#endif


int main(int, char**) {
#if defined AVERSIVE

  bool test = TIMER_2::Fields::OCF_A && TIMER_5::Fields::OCF_B;
  if(GPIO_A::Fields::DDR_0) {
    GPIO_A::Fields::PORT_0 = test;
  }
  
#else

  UCSR0A |= (1 << RXC0);
  TIFR0 = 0x10;

#endif
  
  return 0;
}
