#ifndef HDL_AVR_MEGA_XX0_1_GPIO_MODULES_HPP
#define HDL_AVR_MEGA_XX0_1_GPIO_MODULES_HPP

#include "regs.hpp"
#include "fields.hpp"

namespace HDL {
  using namespace MemoryMapping;
    
  namespace ATMegaxx0_1 {
    
    namespace Private {
      
      namespace GPIO {

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
  }
}

#endif//HDL_AVR_MEGA_XX0_1_GPIO_MODULES_HPP
