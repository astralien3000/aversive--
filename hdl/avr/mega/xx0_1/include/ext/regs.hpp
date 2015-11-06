#ifndef HDL_AVR_MEGA_XX0_1_EXT_REGS_HPP
#define HDL_AVR_MEGA_XX0_1_EXT_REGS_HPP

#include <memory_mapping/memory_mapping.hpp>
#include <base/dummy.hpp>
#include "defs.hpp"

namespace HDL {
    
  namespace ATMegaxx0_1 {
    
    namespace Private {
      using namespace ::MemoryMapping;
      
      namespace EXT {
	
	template<DummyType DUMMY = DUMMY_VALUE>
	struct EXT_ModuleRegisters {
	  using Defs = SimpleDefs::EXT_ModuleDefs;

	  static constexpr Register8<typename Defs::Groups::PCIFR> PCIFR = Defs::PCIFR;
	  static constexpr Register8<typename Defs::Groups::EIMSK> EIFR = Defs::EIFR;
	  static constexpr Register8<typename Defs::Groups::EIMSK> EIMSK = Defs::EIMSK;
	  
	  static constexpr Register8<typename Defs::Groups::PCICR> PCICR = Defs::PCICR;
	  static constexpr Register8<typename Defs::Groups::EICR_A > EICR_A  = Defs::EICR_A ;
	  static constexpr Register8<typename Defs::Groups::EICR_B > EICR_B  = Defs::EICR_B ;

	  static constexpr Register8<typename Defs::Groups::PCMSK_0 > PCMSK_0  = Defs::PCMSK_0 ;
	  static constexpr Register8<typename Defs::Groups::PCMSK_1 > PCMSK_1  = Defs::PCMSK_1 ;
#if defined(__ATmegaxx0__)
	  static constexpr Register8<typename Defs::Groups::PCMSK_2 > PCMSK_2  = Defs::PCMSK_2 ;
#endif /* __ATmegaxx0__ */
	};
	
      }
    }
  }
}

#endif//HDL_AVR_MEGA_XX0_1_EXT_REGS_HPP
