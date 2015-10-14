#ifndef HDL_AVR_MEGA_XX0_1_UART_MODULES_HPP
#define HDL_AVR_MEGA_XX0_1_UART_MODULES_HPP

#include "regs.hpp"
#include "fields.hpp"
#include "defs.hpp"

namespace HDL {
    
  namespace ATMegaxx0_1 {  

    namespace Private {

      namespace UART {

	//! \brief This is the final UART module structure, which implements the HDL structure specification
	template<typename Defs>
	struct _UART : UART_ModuleRegisters<Defs> {
	  struct Fields : UART_ModuleFields<Defs> {};
	};
      }
    }

    //! \brief This is the final UART module structure, associated with an ID
    template<u8 ID> struct UART : Private::UART::_UART<Private::UART::_UART_Defs<ID>> {};

    using UART_0 = UART<0>;
    using UART_1 = UART<1>;
    using UART_2 = UART<2>;
    
#if defined(__ATmegaxx0__)
    using UART_3 = UART<3>;
#endif   //(__ATmegaxx0__)
  }
}

#endif//HDL_AVR_MEGA_XX0_1_UART_MODULES_HPP
