//#include <memory_mapping.hpp>

//#define AVERSIVE

#if defined AVERSIVE
#include "../../hdl/avr/mega/xx0_1/include/reg.hpp"

constexpr auto TEST = MemoryMapping::make_virtual_field(HDL::TIMER_0::Fields::TOV, HDL::TIMER_0::Fields::OCF_A, HDL::TIMER_0::Fields::COM_A);
constexpr auto TEST2 = MemoryMapping::make_virtual_field(HDL::TIMER_2::Fields::TOV, HDL::TIMER_2::Fields::OCF_A, HDL::TIMER_2::Fields::COM_A);
constexpr auto TEST3 = MemoryMapping::make_virtual_config(true, true, 0b01);

#else
#include <avr/io.h>

#endif

int main(int, char**) {
#if defined AVERSIVE
  using namespace HDL;

  GPIO_A::Fields::PIN_0 = true;
  GPIO_A::Fields::PORT_7 = true;

  GPIO_G::Fields::DDR_0 = true;
  //GPIO_G::Fields::PIN_7 = true;

  GPIO_C::Fields::PORT<5>::field = false;
  
  GPIO_A::PIN = GPIO<11>::PIN;
  //GPIO_ModuleFields<GPIO_G_ModuleDefs>::Fields::PIN<7>::field = true;
  //GPIO_A::PIN = 0;
  //GPIO_A::Fields::PIN_0 = true;
  
  //TEST = TEST2;
  //TEST = TEST3;
  
#else

  TIFR0 = (TIFR0 & ~(1 << TOV0)) | (TIFR2 & (1 << TOV2));
  TIFR0 = (TIFR0 & ~(1 << OCF0A)) | (TIFR2 & (1 << OCF2A));
  TCCR0A = (TCCR0A & ~0b11000000) | (TCCR2A & 0b11000000);

  TIFR0 |= 1 << TOV2;
  TIFR0 |= 1 << OCF2A;
  TCCR0A = (TCCR0A & ~0b11000000) | 0b01000000;

#endif
  
  return 0;
}
