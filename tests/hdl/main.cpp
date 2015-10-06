//#include <memory_mapping.hpp>

//#define AVERSIVE

#if defined AVERSIVE
#include "../../hdl/avr/mega/xx0_1/include/reg.hpp"
using namespace HDL;
using namespace MemoryMapping;

constexpr auto TEST = make_virtual_field(TIMER_0::Fields::OCF_A, TIMER_0::Fields::COM_A);
constexpr auto TEST2 = make_virtual_field(TIMER_2::Fields::COM_A, TIMER_2::Fields::COM_A);
constexpr auto TEST3 = make_virtual_config(true, 0b01);

#else
#include <avr/io.h>

#endif

int main(int, char**) {
#if defined AVERSIVE

  TIMER_1::Fields::WGM = TIMER_5::Fields::WGM;
  
#else

#endif
  
  return 0;
}
