#include <hdl/hdl.hpp>

using namespace HDL;

u32 count = 0;

namespace HDL {
  namespace Interrupts {
    template<>
    void TIMER<0>::ovf(void) {
      if(count > 10) {
	GPIO_B::Fields::PORT<7>::field = !GPIO_B::Fields::PORT<7>::field;
	count = 0;
      }
      count++;
    }
  }
}

int main(int, char**) {
  GPIO_B::Fields::DDR<7>::field = true;
  GPIO_B::Fields::PORT<7>::field = true;

  TIMER_0::Fields::CS = 0b101;
  TIMER_0::Fields::CCR_A_WGM = 0b00;
  TIMER_0::Fields::CCR_B_WGM = 0b0;
  TIMER<0>::Fields::TOIE = true;
  
  sei();
  
  while(1) {    
  }
  
  return 0;
}
