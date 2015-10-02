//#include <memory_mapping.hpp>

#define AVERSIVE

#if defined AVERSIVE
#include "../../hdl/avr/mega/xx0_1/include/reg.hpp"
#else
#include <avr/io.h>
#endif

constexpr auto TEST = MemoryMapping::make_virtual_field(HDL::TIMER_0::Fields::COM_A, HDL::TIMER_0::Fields::COM_B);
constexpr auto TEST2 = MemoryMapping::make_virtual_field(HDL::TIMER_0::Fields::COM_A, HDL::TIMER_0::Fields::COM_B);


int main(int, char**) {
#if defined AVERSIVE
  using namespace HDL;
 
  TEST = TEST2;
  //GPIO_A::PIN = 0x02;

  // GPIO_A::Fields::DDR_0 = false;
  // GPIO_A::Fields::DDR<1>::field = false;
  // GPIO_A::Fields::PIN<6>::field = false;
  // GPIO_G::Fields::PIN<5>::field = true;

  //GPIO<7>::Fields::PIN<5>::Field = true; // should not compile

#else

  volatile u8 test = TCCR0A + 0b00010000;

  //TCNT2 = 11;
  
  // PINA &= ~(1 << 0);
  // PINA &= ~(1 << 1);
  // PINA &= ~(1 << 2);
  // PINA &= ~(1 << 3);
  
#endif
  
  return 0;
}
