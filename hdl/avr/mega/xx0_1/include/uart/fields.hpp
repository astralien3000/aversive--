#ifndef HDL_AVR_MEGA_XX0_1_UART_FIELDS_HPP
#define HDL_AVR_MEGA_XX0_1_UART_FIELDS_HPP

#include "regs.hpp"
#include <memory_mapping/memory_mapping.hpp>
#include <base/dummy.hpp>

namespace HDL {
    
  namespace ATMegaxx0_1 {  

    namespace Private {

      namespace UART {

	//! \brief Here are defined UART module Fields, this class will be incorporated in the final UART Module
	template<typename ModuleDefs>
	struct UART_ModuleFields {
	  using Defs = ModuleDefs;
	  using Registers = UART_ModuleRegisters<Defs>;

	  //! \name CSR_A Register Bits
	  //! @{
	  static constexpr BitField8<typename Defs::Groups::CSR_A, Defs::RXC>  RXC = Registers::CSR_A;
	  static constexpr BitField8<typename Defs::Groups::CSR_A, Defs::RXC>  TXC  = Registers::CSR_A;
	  static constexpr BitField8<typename Defs::Groups::CSR_A, Defs::DRE>  DRE  = Registers::CSR_A;
	  static constexpr BitField8<typename Defs::Groups::CSR_A, Defs::FE>   FE   = Registers::CSR_A;
	  static constexpr BitField8<typename Defs::Groups::CSR_A, Defs::DOR>  DOR  = Registers::CSR_A;
	  static constexpr BitField8<typename Defs::Groups::CSR_A, Defs::PE>   PE   = Registers::CSR_A;
	  static constexpr BitField8<typename Defs::Groups::CSR_A, Defs::U2X>  U2X  = Registers::CSR_A;
	  static constexpr BitField8<typename Defs::Groups::CSR_A, Defs::MPCM> MPCM = Registers::CSR_A;
	  //! @}

	  //! \name CSR_B Register Bits
	  //! @{
	  static constexpr BitField8<typename Defs::Groups::CSR_B, Defs::RXCIE> RXCIE = Registers::CSR_B;
	  static constexpr BitField8<typename Defs::Groups::CSR_B, Defs::TXCIE> TXCIE = Registers::CSR_B;
	  static constexpr BitField8<typename Defs::Groups::CSR_B, Defs::DRIE>  DRIE  = Registers::CSR_B;
	  static constexpr BitField8<typename Defs::Groups::CSR_B, Defs::RXEN>  RXEN  = Registers::CSR_B;
	  static constexpr BitField8<typename Defs::Groups::CSR_B, Defs::TXEN>  TXEN  = Registers::CSR_B;
	  static constexpr BitField8<typename Defs::Groups::CSR_B, Defs::RXB8>  RXB8  = Registers::CSR_B;
	  static constexpr BitField8<typename Defs::Groups::CSR_B, Defs::TXB8>  TXB8  = Registers::CSR_B;
	  //! @}

	  //! \name CSR_C Register Bits
	  //! @{
	  static constexpr BitField8<typename Defs::Groups::CSR_C, Defs::SBS>  SBS  = Registers::CSR_C;
	  static constexpr BitField8<typename Defs::Groups::CSR_C, Defs::CPOL> CPOL = Registers::CSR_C;
	  //! @}

	  //! \name CSR_C Register Fields
	  //! @{
	  static constexpr Field8<typename Defs::Groups::CSR_C, Defs::MSEL> MSEL = Registers::CSR_C;
	  static constexpr Field8<typename Defs::Groups::CSR_C, Defs::PM>   PM   = Registers::CSR_C;
	  //! @}

	  //! \name CSR_B_C Register Fields
	  //! @{
	  static constexpr Field8<typename Defs::Groups::CSR_B, Defs::CSZ_2>   CSZ_2   = Registers::CSR_B;
	  static constexpr Field8<typename Defs::Groups::CSR_C, Defs::CSZ_0_1> CSZ_0_1 = Registers::CSR_C;
	  static constexpr auto CSZ = make_virtual_field(CSZ_2, CSZ_0_1);
	  //! @}
	};

      }
    }
  }
}

#endif//HDL_AVR_MEGA_XX0_1_UART_FIELDS_HPP
