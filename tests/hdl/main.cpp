//#include <memory_mapping.hpp>

//#define AVERSIVE

#if defined AVERSIVE
#include <hdl/reg.hpp>
using namespace HDL;

static constexpr auto CFG1 = make_config(TIMER_0::Fields::OCF_A, true);
static constexpr auto CFG2 = make_config(GPIO_A::Fields::PIN_0, false);

#else
#include <avr/io.h>

#endif


int main(int, char**) {
#if defined AVERSIVE
  
  //CFG1 & CFG2;
  //CFG1 & GPIO_A::PIN;
  
#else

#endif
  
  return 0;
}
