#ifndef HDL_AVR_MEGA_XX0_1_GPIO_MODULES_HPP
#define HDL_AVR_MEGA_XX0_1_GPIO_MODULES_HPP

#include "regs.hpp"
#include "fields.hpp"
#include "defs.hpp"

namespace HDL {
    
  namespace ATMegaxx0_1 {
    
    namespace Private {
      
      namespace GPIO {

	//! \brief This is the final GPIO module structure, which implements the HDL structure specification
	template<typename Defs>
	struct _GPIO {
	  static_assert(Defs::EXIST, "GPIO does not exists");
	  struct Module
	    : GPIO_ModuleRegisters<Defs> {
	    struct Fields
	      : GPIO_ModuleFields<Defs>,
		GPIO_ModuleAliases<Defs>::PIN_Fields,
		GPIO_ModuleAliases<Defs>::DDR_Fields,
		GPIO_ModuleAliases<Defs>::PORT_Fields {
	    };
	  };
	};
	
      }
    }

    //! \brief This is the final GPIO module structure, associated with an ID
    template<u8 ID> struct GPIO : Private::GPIO::_GPIO<Private::GPIO::_GPIO_Defs<ID>>::Module {};  
  
    using GPIO_A = GPIO<0>;
    using GPIO_B = GPIO<1>;
    using GPIO_C = GPIO<2>;
    using GPIO_D = GPIO<3>;
    using GPIO_E = GPIO<4>;
    using GPIO_F = GPIO<5>;
    using GPIO_G = GPIO<6>;

#if defined(__ATmegaxx0__)
    using GPIO_H = GPIO<7>;

    using GPIO_J = GPIO<9>;
    using GPIO_K = GPIO<10>;
    using GPIO_L = GPIO<11>;
#endif   //(__ATmegaxx0__)
  }
}

#endif//HDL_AVR_MEGA_XX0_1_GPIO_MODULES_HPP
