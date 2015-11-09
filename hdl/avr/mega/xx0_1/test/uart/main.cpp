#include <hdl/hdl.hpp>

using namespace HDL;

namespace HDL {
  namespace Interrupts {
    template<>
    void UART<0>::rx(void) {
      GPIO_B::Fields::PORT<7>::field = !GPIO_B::Fields::PORT<7>::field;
      UART_0::DR = UART_0::DR;
    }
  }
}

int main(int, char**) {
  GPIO_B::Fields::DDR<7>::field = true;
  GPIO_B::Fields::PORT<7>::field = true;

  UART_0::BRR = (16000000 / ((u32)16 * 9600)) - 1;
  UART_0::Fields::TXEN = true;
  UART_0::Fields::RXEN = true;
  UART_0::Fields::RXCIE = true;

  sei();
  
  while(1) {    
  }
  
  return 0;
}
