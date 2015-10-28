#ifndef HDL_AVR_MEGA_XX0_1_UART_REGS_HPP
#define HDL_AVR_MEGA_XX0_1_UART_REGS_HPP

#include <memory_mapping/memory_mapping.hpp>
#include <base/dummy.hpp>


namespace HDL {
    
  namespace ATMegaxx0_1 {  

    namespace Private {
      using namespace ::MemoryMapping;
      
      namespace UART {

	//! \brief Here are defined UART module Registers, this class will be incorporated in the final UART Module
	template<typename ModuleDefs>
	struct UART_ModuleRegisters {
	  using Defs = ModuleDefs;

	  static constexpr Register8<typename Defs::Groups::CSR_A> CSR_A = Defs::CSR_A;
	  static constexpr Register8<typename Defs::Groups::CSR_B> CSR_B = Defs::CSR_B;
	  static constexpr Register8<typename Defs::Groups::CSR_C> CSR_C = Defs::CSR_C;

	  static constexpr Register16<typename Defs::Groups::BRR> BRR = Defs::BRR;
	  static constexpr Register8<typename Defs::Groups::BRR_L> BRR_L = Defs::BRR_L;
	  static constexpr Register8<typename Defs::Groups::BRR_H> BRR_H = Defs::BRR_H;

	  static constexpr Register8<typename Defs::Groups::DR> DR = Defs::DR;
	};

      }
    }
  }
}

#endif//HDL_AVR_MEGA_XX0_1_UART_REGS_HPP
