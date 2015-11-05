#include <hdl/hdl.hpp>

using namespace HDL;

namespace HDL {
  namespace Interrupts {
    template<>
    void External<0>::interrupt(void) {
      GPIO_B::Fields::PORT<7>::field = !GPIO_B::Fields::PORT<7>::field;
    }
  }
}

int main(int, char**) {
  GPIO_B::Fields::DDR<7>::field = true;
  GPIO_B::Fields::PORT<7>::field = true;

  GPIO_D::Fields::DDR<0>::field = false;
  GPIO_D::Fields::PORT<0>::field = true; // pull up
  
  EXT::Fields::ISC_0 = 0b01;
  EXT::Fields::INT_0 = true;
	   
  sei();
  
  while(1) {    
  }
  
  return 0;
}
