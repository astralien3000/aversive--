#ifndef HDL_AVR_MEGA_XX0_1_GPIO_REGS_HPP
#define HDL_AVR_MEGA_XX0_1_GPIO_REGS_HPP

#include <util/memory_mapping.hpp>
#include <util/dummy.hpp>

namespace HDL {
    
  namespace ATMegaxx0_1 {
    
    namespace Private {
      using namespace HDL::Private;
      using namespace MemoryMapping;
      
      namespace GPIO {
	template<typename ModuleDefs>
	struct GPIO_ModuleRegisters {
	  using Defs = ModuleDefs;

	  static constexpr Register8<typename Defs::Groups::PIN>  PIN  = Defs::PIN;
	  static constexpr Register8<typename Defs::Groups::DDR>  DDR  = Defs::DDR;
	  static constexpr Register8<typename Defs::Groups::PORT> PORT = Defs::PORT;
	};
      }
    }
  }
}

#endif//HDL_AVR_MEGA_XX0_1_GPIO_REGS_HPP