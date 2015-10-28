#include "../include/uart.hpp"

namespace HAL {
  namespace ATMegaxx0_1 {

    template<> static IRQ_Handler UART<0>::txc = 0;
    template<> static IRQ_Handler UART<0>::rxc = 0;

    
  }
}
