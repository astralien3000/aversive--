#include <hal/hal.hpp>

namespace HDL {
  namespace Interrupts {
    template<u8 ID>
    void UART<ID>::tx(void) {
      ::HAL::UART<ID>::txc();
    }
    
    template<u8 ID>
    void UART<ID>::rx(void) {
      ::HAL::UART<ID>::rxc();
    }
  }
}

namespace HAL {
  namespace ATMegaxx0_1 {
    template<u8 ID> void UART<ID>::setTxCompleteHandler(IRQ_Handler h) {
      if(h) {
	txc = h;
	::HDL::UART<ID>::Fields::TXCIE = true;
      }
      else {
	::HDL::UART<ID>::Fields::TXCIE = false;
	txc = h;
      }
    }
    
    template<u8 ID> void UART<ID>::setRxCompleteHandler(IRQ_Handler h) {
      if(h) {
	rxc = h;
	::HDL::UART<ID>::Fields::RXCIE = true;
      }
      else {
	::HDL::UART<ID>::Fields::RXCIE = false;
	rxc = h;
      }
    }
  }
}

#define _AVERSIVE_DEFINE_INTERRUPT_HANDLER(id)				\
  namespace HAL {							\
    namespace ATMegaxx0_1 {						\
      template<> UART<id>::IRQ_Handler UART<id>::txc = 0;		\
      template<> UART<id>::IRQ_Handler UART<id>::rxc = 0;		\
    }									\
  }									\
  template void HDL::Interrupts::UART<id>::tx(void);			\
  template void HDL::Interrupts::UART<id>::rx(void);			\
  template void HAL::ATMegaxx0_1::UART<id>::setTxCompleteHandler(IRQ_Handler); \
  template void HAL::ATMegaxx0_1::UART<id>::setRxCompleteHandler(IRQ_Handler); \

