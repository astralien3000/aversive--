#include <memory_mapping.hpp>

#define AVERSIVE

#if defined AVERSIVE
#include "../../hdl/avr/mega/xx0_1/include/reg.hpp"
#else
#include <avr/io.h>
#endif

int main(int, char**) {
#if defined AVERSIVE
  using namespace HDL;
  
  //GPIO_A::PIN = 0x02;

  GPIO_A::Fields::PIN<0>::Field = false;
  GPIO_A::Fields::DDR<1>::Field = false;
  GPIO_A::Fields::PIN<6>::Field = false;
  GPIO_G::Fields::PIN<5>::Field = true;

#else
  
  PINA &= ~(1 << 0);
  PINA &= ~(1 << 1);
  PINA &= ~(1 << 2);
  PINA &= ~(1 << 3);
  
#endif
  
  return 0;
}
