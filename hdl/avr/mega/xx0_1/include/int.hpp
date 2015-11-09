#ifndef HDL_AVR_MEGA_XX0_1_INT_HPP
#define HDL_AVR_MEGA_XX0_1_INT_HPP

#include<base/integer.hpp>

#define INTERRUPT				\
  __attribute__((signal,section(".text.interrupt")))

namespace HDL {

  namespace Interrupts {

    template<u8 ID>
    struct External {
      static void interrupt(void) INTERRUPT;
    };

    template<u8 ID>
    struct PinChange {
      static void interrupt(void) INTERRUPT;
    };

    template<u8 ID>
    struct TIMER {
      template<u8 OC_ID>
      struct OC {
	static void comp(void) INTERRUPT;
      };
      static void ovf(void) INTERRUPT;
      static void capt(void) INTERRUPT;
    };

    template<u8 ID>
    struct UART {
      static void tx(void) INTERRUPT;
      static void rx(void) INTERRUPT;
      static void dre(void) INTERRUPT;
    };

  }
  
}

#undef INTERRUPT

#endif//HDL_AVR_MEGA_XX0_1_INT_HPP
