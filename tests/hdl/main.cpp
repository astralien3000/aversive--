//#include <memory_mapping.hpp>

#define AVERSIVE

#if defined AVERSIVE
#include "../../hdl/avr/mega/xx0_1/include/reg.hpp"
#else
#include <avr/io.h>
#endif

constexpr auto TEST = MemoryMapping::make_virtual_field(HDL::TIMER_0::Fields::COM_A, HDL::TIMER_0::Fields::COM_B);
constexpr auto TEST2 = MemoryMapping::make_virtual_field(HDL::TIMER_0::Fields::COM_A, HDL::TIMER_0::Fields::COM_B);

constexpr auto TEST3 = static_list_fusion(TEST.FIELDS, TEST2.FIELDS);

u8 a, b;
constexpr auto T1 = make_static_list<u8&, u8&>(a, b);
constexpr auto T2 = make_static_list(1, 2);

int main(int, char**) {
#if defined AVERSIVE
  using namespace HDL;

  TEST = TEST2;

#else

  
#endif
  
  return 0;
}
