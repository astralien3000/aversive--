#ifndef HDL_AVR_MEGA_XX0_1_EXT_FIELDS_HPP
#define HDL_AVR_MEGA_XX0_1_EXT_FIELDS_HPP

#include "regs.hpp"
#include <memory_mapping/memory_mapping.hpp>
#include <base/dummy.hpp>

namespace HDL {
    
  namespace ATMegaxx0_1 {  

    namespace Private {

      namespace EXT {

	template<DummyType DUMMY = DUMMY_VALUE>
	struct EXT_ModuleFields {
	  using Defs = SimpleDefs::EXT_ModuleDefs;
	  using Registers = EXT_ModuleRegisters<>;
	  
	  //! name PCIFR Register Bits
	  //! @{
#if defined(__ATmegaxx0__)
	  static constexpr BitField8<typename Defs::Groups::PCIFR, Defs::PCIF_2 > PCIF_2  = Registers::PCIFR;
#endif // __ATmegaxx0__
	  static constexpr BitField8<typename Defs::Groups::PCIFR, Defs::PCIF_1 > PCIF_1  = Registers::PCIFR;
	  static constexpr BitField8<typename Defs::Groups::PCIFR, Defs::PCIF_0 > PCIF_0  = Registers::PCIFR;
	  //! @}

	  //! name EIFR Register Bits
	  //! @{
	  static constexpr BitField8<typename Defs::Groups::EIMSK, Defs::INTF_7 > INTF_7  = Registers::EIFR;
	  static constexpr BitField8<typename Defs::Groups::EIMSK, Defs::INTF_6 > INTF_6  = Registers::EIFR;
	  static constexpr BitField8<typename Defs::Groups::EIMSK, Defs::INTF_5 > INTF_5  = Registers::EIFR;
	  static constexpr BitField8<typename Defs::Groups::EIMSK, Defs::INTF_4 > INTF_4  = Registers::EIFR;
	  static constexpr BitField8<typename Defs::Groups::EIMSK, Defs::INTF_3 > INTF_3  = Registers::EIFR;
	  static constexpr BitField8<typename Defs::Groups::EIMSK, Defs::INTF_2 > INTF_2  = Registers::EIFR;
	  static constexpr BitField8<typename Defs::Groups::EIMSK, Defs::INTF_1 > INTF_1  = Registers::EIFR;
	  static constexpr BitField8<typename Defs::Groups::EIMSK, Defs::INTF_0 > INTF_0  = Registers::EIFR;
	  //! @}

	  //! name EIMSK Register Bits
	  //! @{
	  static constexpr BitField8<typename Defs::Groups::EIMSK, Defs::INT_7 > INT_7  = Registers::EIMSK;
	  static constexpr BitField8<typename Defs::Groups::EIMSK, Defs::INT_6 > INT_6  = Registers::EIMSK;
	  static constexpr BitField8<typename Defs::Groups::EIMSK, Defs::INT_5 > INT_5  = Registers::EIMSK;
	  static constexpr BitField8<typename Defs::Groups::EIMSK, Defs::INT_4 > INT_4  = Registers::EIMSK;
	  static constexpr BitField8<typename Defs::Groups::EIMSK, Defs::INT_3 > INT_3  = Registers::EIMSK;
	  static constexpr BitField8<typename Defs::Groups::EIMSK, Defs::INT_2 > INT_2  = Registers::EIMSK;
	  static constexpr BitField8<typename Defs::Groups::EIMSK, Defs::INT_1 > INT_1  = Registers::EIMSK;
	  static constexpr BitField8<typename Defs::Groups::EIMSK, Defs::INT_0 > INT_0  = Registers::EIMSK;
	  //! @}

	  //! name PCICR Register Bits
	  //! @{
#if defined(__ATmegaxx0__)
	  static constexpr BitField8<typename Defs::Groups::PCICR, Defs::PCIE_2 > PCIE_2  = Registers::PCICR;
#endif // __ATmegaxx0__
	  static constexpr BitField8<typename Defs::Groups::PCICR, Defs::PCIE_1 > PCIE_1  = Registers::PCICR;
	  static constexpr BitField8<typename Defs::Groups::PCICR, Defs::PCIE_0 > PCIE_0  = Registers::PCICR;
	  //! @}
	  
	  //! \name EICR_A Register Bits
	  //! @{
	  static constexpr Field8<typename Defs::Groups::EICR_A, Defs::ISC_3 > ISC_3  = Registers::EICR_A;
	  static constexpr Field8<typename Defs::Groups::EICR_A, Defs::ISC_2 > ISC_2  = Registers::EICR_A;
	  static constexpr Field8<typename Defs::Groups::EICR_A, Defs::ISC_1 > ISC_1  = Registers::EICR_A;
	  static constexpr Field8<typename Defs::Groups::EICR_A, Defs::ISC_0 > ISC_0  = Registers::EICR_A;
	  //! @}

	  //! \name EICR_B Register Bits
	  //! @{
	  static constexpr Field8<typename Defs::Groups::EICR_B, Defs::ISC_7 > ISC_7  = Registers::EICR_B;
	  static constexpr Field8<typename Defs::Groups::EICR_B, Defs::ISC_6 > ISC_6  = Registers::EICR_B;
	  static constexpr Field8<typename Defs::Groups::EICR_B, Defs::ISC_5 > ISC_5  = Registers::EICR_B;
	  static constexpr Field8<typename Defs::Groups::EICR_B, Defs::ISC_4 > ISC_4  = Registers::EICR_B;
	  //! @}

	  //! name PCMSK_0 Register Bits
	  //! @{
	  static constexpr BitField8<typename Defs::Groups::PCMSK_0, Defs::PCINT_7 > PCINT_7  = Registers::PCMSK_0;
	  static constexpr BitField8<typename Defs::Groups::PCMSK_0, Defs::PCINT_6 > PCINT_6  = Registers::PCMSK_0;
	  static constexpr BitField8<typename Defs::Groups::PCMSK_0, Defs::PCINT_5 > PCINT_5  = Registers::PCMSK_0;
	  static constexpr BitField8<typename Defs::Groups::PCMSK_0, Defs::PCINT_4 > PCINT_4  = Registers::PCMSK_0;
	  static constexpr BitField8<typename Defs::Groups::PCMSK_0, Defs::PCINT_3 > PCINT_3  = Registers::PCMSK_0;
	  static constexpr BitField8<typename Defs::Groups::PCMSK_0, Defs::PCINT_2 > PCINT_2  = Registers::PCMSK_0;
	  static constexpr BitField8<typename Defs::Groups::PCMSK_0, Defs::PCINT_1 > PCINT_1  = Registers::PCMSK_0;
	  static constexpr BitField8<typename Defs::Groups::PCMSK_0, Defs::PCINT_0 > PCINT_0  = Registers::PCMSK_0;
	  //! @}

	  //! name PCMSK_1 Register Bits
	  //! @{
	  static constexpr BitField8<typename Defs::Groups::PCMSK_1, Defs::PCINT_15 > PCINT_15  = Registers::PCMSK_1;
	  static constexpr BitField8<typename Defs::Groups::PCMSK_1, Defs::PCINT_14 > PCINT_14  = Registers::PCMSK_1;
	  static constexpr BitField8<typename Defs::Groups::PCMSK_1, Defs::PCINT_13 > PCINT_13  = Registers::PCMSK_1;
	  static constexpr BitField8<typename Defs::Groups::PCMSK_1, Defs::PCINT_12 > PCINT_12  = Registers::PCMSK_1;
	  static constexpr BitField8<typename Defs::Groups::PCMSK_1, Defs::PCINT_11 > PCINT_11  = Registers::PCMSK_1;
	  static constexpr BitField8<typename Defs::Groups::PCMSK_1, Defs::PCINT_10 > PCINT_10  = Registers::PCMSK_1;
	  static constexpr BitField8<typename Defs::Groups::PCMSK_1, Defs::PCINT_9 > PCINT_9  = Registers::PCMSK_1;
	  static constexpr BitField8<typename Defs::Groups::PCMSK_1, Defs::PCINT_8 > PCINT_8  = Registers::PCMSK_1;
	  //! @}

#if defined(__ATmegaxx0__) 
	  //! name PCMSK_2 Register Bits
	  //! @{
	  static constexpr BitField8<typename Defs::Groups::PCMSK_2, Defs::PCINT_23 > PCINT_23  = Registers::PCMSK_2;
	  static constexpr BitField8<typename Defs::Groups::PCMSK_2, Defs::PCINT_22 > PCINT_22  = Registers::PCMSK_2;
	  static constexpr BitField8<typename Defs::Groups::PCMSK_2, Defs::PCINT_21 > PCINT_21  = Registers::PCMSK_2;
	  static constexpr BitField8<typename Defs::Groups::PCMSK_2, Defs::PCINT_20 > PCINT_20  = Registers::PCMSK_2;
	  static constexpr BitField8<typename Defs::Groups::PCMSK_2, Defs::PCINT_19 > PCINT_19  = Registers::PCMSK_2;
	  static constexpr BitField8<typename Defs::Groups::PCMSK_2, Defs::PCINT_18 > PCINT_18  = Registers::PCMSK_2;
	  static constexpr BitField8<typename Defs::Groups::PCMSK_2, Defs::PCINT_17 > PCINT_17  = Registers::PCMSK_2;
	  static constexpr BitField8<typename Defs::Groups::PCMSK_2, Defs::PCINT_16 > PCINT_16  = Registers::PCMSK_2;
#endif // __ATmegaxx0__
	  //! @}
	};
	
      }
    }
  }
}

#endif//HDL_AVR_MEGA_XX0_1_EXT_FIELDS_HPP
