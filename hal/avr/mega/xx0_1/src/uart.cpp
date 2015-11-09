#include "../include/uart.hpp"

namespace HAL {
  namespace ATMegaxx0_1 {
    template<> UART<0>::IRQ_Handler UART<0>::txc = 0;
    template<> UART<0>::IRQ_Handler UART<0>::rxc = 0;
  }
}
