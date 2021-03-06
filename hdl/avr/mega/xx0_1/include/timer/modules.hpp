#ifndef HDL_AVR_MEGA_XX0_1_TIMER_MODULES_HPP
#define HDL_AVR_MEGA_XX0_1_TIMER_MODULES_HPP

#include "regs.hpp"
#include "fields.hpp"
#include "defs.hpp"


namespace HDL {
    
  namespace ATMegaxx0_1 {  

    namespace Private {

      namespace TIMER {

	//! \brief This is the final TIMER module structure, which implements the HDL structure specification
	template<typename Defs>
	struct _TIMER : TIMER_ModuleRegisters<Defs>::Registers {
	  struct Fields : TIMER_ModuleFields<Defs>::Fields {};
	};

      }
    }

    //! \brief This is the final TIMER module structure, associated with an ID
    template<u8 ID> struct TIMER : Private::TIMER::_TIMER<Private::TIMER::_TIMER_Defs<ID>> {};

    using TIMER_0 = TIMER<0>;
    using TIMER_1 = TIMER<1>;
    using TIMER_2 = TIMER<2>;
    using TIMER_3 = TIMER<3>;
    using TIMER_4 = TIMER<4>;
    using TIMER_5 = TIMER<5>;

  }
}

#endif//HDL_AVR_MEGA_XX0_1_TIMER_MODULES_HPP
