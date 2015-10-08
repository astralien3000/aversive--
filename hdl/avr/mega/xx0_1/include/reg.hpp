#ifndef HDL_AVR_MEGA_XX0_1_REG_HPP
#define HDL_AVR_MEGA_XX0_1_REG_HPP

#include <util/memory_mapping.hpp>
#include <util/dummy.hpp>
#include "../../../common/include/reg.hpp"


#if defined(__AVR_ATmega640__) || defined(__AVR_ATmega1280__) || defined(__AVR_ATmega2560__)
# define __ATmegaxx0__
#elif defined(__AVR_ATmega1281__) || defined(__AVR_ATmega2561__)
# define __ATmegaxx1__
#endif

#include "gpio/modules.hpp"

#include "timer/modules.hpp"

namespace HDL {
    
  namespace ATMegaxx0_1 {  

    namespace Private {

      namespace SimpleDefs {
	struct UART_Common_ModuleDefs {
	  struct Groups {
	    struct CSR_A;
	    struct CSR_B;
	    struct CSR_C;
	
	    struct BRR;
	    struct BRR_L;
	    struct BRR_H;

	    struct DR;
	  };
      
	  // CSR_A Register Bits
	  static constexpr u8 RXC  = 7;
	  static constexpr u8 TXC  = 6;
	  static constexpr u8 DRE  = 5;
	  static constexpr u8 FE   = 4;
	  static constexpr u8 DOR  = 3;
	  static constexpr u8 PE   = 2;
	  static constexpr u8 U2X  = 1;
	  static constexpr u8 MPCM = 0;
      
	  // CSR_B Register Bits
	  static constexpr u8 RXCIE = 7;
	  static constexpr u8 TXCIE = 6;
	  static constexpr u8 DRIE  = 5;
	  static constexpr u8 RXEN  = 4;
	  static constexpr u8 TXEN  = 3;
	  static constexpr u8 RXB8  = 1;
	  static constexpr u8 TXB8  = 0;

	  // CSR_B Register Fields
	  static constexpr u8 CSZ_2 = 0b00000100;
      
	  // CSR_C Register Bits
	  static constexpr u8 SBS  = 3;
	  static constexpr u8 CPOL = 0;

	  // CSR_C Register Fields
	  static constexpr u8 MSEL    = 0b11000000;
	  static constexpr u8 PM      = 0b00110000;
	  static constexpr u8 CSZ_0_1 = 0b00000110;
	};
    
	struct UART_0_ModuleDefs : UART_Common_ModuleDefs {
	  static constexpr usys CSR_A = SFR_MEM(0x00C0);
	  static constexpr usys CSR_B = SFR_MEM(0x00C1);
	  static constexpr usys CSR_C = SFR_MEM(0x00C2);

	  static constexpr usys BRR   = SFR_MEM(0x00C4);
	  static constexpr usys BRR_L = SFR_MEM(0x00C4);
	  static constexpr usys BRR_H = SFR_MEM(0x00C5);

	  static constexpr usys DR    = SFR_MEM(0x00C6);
	};

	struct UART_1_ModuleDefs : UART_Common_ModuleDefs {
	  static constexpr usys CSR_A = SFR_MEM(0x00C8);
	  static constexpr usys CSR_B = SFR_MEM(0x00C9);
	  static constexpr usys CSR_C = SFR_MEM(0x00CA);

	  static constexpr usys BRR   = SFR_MEM(0x00CC);
	  static constexpr usys BRR_L = SFR_MEM(0x00CC);
	  static constexpr usys BRR_H = SFR_MEM(0x00CD);

	  static constexpr usys DR    = SFR_MEM(0x00CE);
	};

	struct UART_2_ModuleDefs : UART_Common_ModuleDefs {
	  static constexpr usys CSR_A = SFR_MEM(0x00D0);
	  static constexpr usys CSR_B = SFR_MEM(0x00D1);
	  static constexpr usys CSR_C = SFR_MEM(0x00D2);

	  static constexpr usys BRR   = SFR_MEM(0x00D4);
	  static constexpr usys BRR_L = SFR_MEM(0x00D4);
	  static constexpr usys BRR_H = SFR_MEM(0x00D5);

	  static constexpr usys DR    = SFR_MEM(0x00D6);
	};

#if defined(__ATmegaxx0__)
    
	struct UART_3_ModuleDefs : UART_Common_ModuleDefs {
	  static constexpr usys CSR_A = SFR_MEM(0x0130);
	  static constexpr usys CSR_B = SFR_MEM(0x0131);
	  static constexpr usys CSR_C = SFR_MEM(0x0132);

	  static constexpr usys BRR   = SFR_MEM(0x0134);
	  static constexpr usys BRR_L = SFR_MEM(0x0134);
	  static constexpr usys BRR_H = SFR_MEM(0x0135);

	  static constexpr usys DR    = SFR_MEM(0x0136);
	};

#endif   //(__ATmegaxx0__)

      }

      namespace UART {
	template<u8 ID> struct _UART_Defs { static_assert(!ID && ID, "Invalid UART"); };
	template<> struct _UART_Defs<0> : UART_0_ModuleDefs {};
	template<> struct _UART_Defs<1> : UART_1_ModuleDefs {};
	template<> struct _UART_Defs<2> : UART_2_ModuleDefs {};
#if defined(__ATmegaxx0__)
	template<> struct _UART_Defs<3> : UART_3_ModuleDefs {};
#endif   //(__ATmegaxx0__)

	template<typename ModuleDefs>
	struct UART_ModuleRegisters {
	  using Defs = ModuleDefs;

	  static constexpr Register8<typename Defs::Groups::CSR_A> CSR_A = Defs::CSR_A;
	  static constexpr Register8<typename Defs::Groups::CSR_B> CSR_B = Defs::CSR_B;
	  static constexpr Register8<typename Defs::Groups::CSR_C> CSR_C = Defs::CSR_C;

	  static constexpr Register8<typename Defs::Groups::BRR> BRR = Defs::BRR;
	  static constexpr Register8<typename Defs::Groups::BRR_L> BRR_L = Defs::BRR_L;
	  static constexpr Register8<typename Defs::Groups::BRR_H> BRR_H = Defs::BRR_H;

	  static constexpr Register8<typename Defs::Groups::DR> DR = Defs::DR;
	};

	template<typename ModuleDefs>
	struct UART_ModuleFields {
	  using Defs = ModuleDefs;
	  using Registers = UART_ModuleRegisters<Defs>;

	  // CSR_A Register Bits
	  static constexpr BitField8<typename Defs::Groups::CSR_A, Defs::RXC>  RXC = Registers::CSR_A;
	  static constexpr BitField8<typename Defs::Groups::CSR_A, Defs::RXC>  TXC  = Registers::CSR_A;
	  static constexpr BitField8<typename Defs::Groups::CSR_A, Defs::DRE>  DRE  = Registers::CSR_A;
	  static constexpr BitField8<typename Defs::Groups::CSR_A, Defs::FE>   FE   = Registers::CSR_A;
	  static constexpr BitField8<typename Defs::Groups::CSR_A, Defs::DOR>  DOR  = Registers::CSR_A;
	  static constexpr BitField8<typename Defs::Groups::CSR_A, Defs::PE>   PE   = Registers::CSR_A;
	  static constexpr BitField8<typename Defs::Groups::CSR_A, Defs::U2X>  U2X  = Registers::CSR_A;
	  static constexpr BitField8<typename Defs::Groups::CSR_A, Defs::MPCM> MPCM = Registers::CSR_A;
      
	  // CSR_B Register Bits
	  static constexpr BitField8<typename Defs::Groups::CSR_B, Defs::RXCIE> RXCIE = Registers::CSR_B;
	  static constexpr BitField8<typename Defs::Groups::CSR_B, Defs::TXCIE> TXCIE = Registers::CSR_B;
	  static constexpr BitField8<typename Defs::Groups::CSR_B, Defs::DRIE>  DRIE  = Registers::CSR_B;
	  static constexpr BitField8<typename Defs::Groups::CSR_B, Defs::RXEN>  RXEN  = Registers::CSR_B;
	  static constexpr BitField8<typename Defs::Groups::CSR_B, Defs::TXEN>  TXEN  = Registers::CSR_B;
	  static constexpr BitField8<typename Defs::Groups::CSR_B, Defs::RXB8>  RXB8  = Registers::CSR_B;
	  static constexpr BitField8<typename Defs::Groups::CSR_B, Defs::TXB8>  TXB8  = Registers::CSR_B;
      
	  // CSR_C Register Bits
	  static constexpr BitField8<typename Defs::Groups::CSR_C, Defs::SBS>  SBS  = Registers::CSR_C;
	  static constexpr BitField8<typename Defs::Groups::CSR_C, Defs::CPOL> CPOL = Registers::CSR_C;

	  // CSR_C Register Fields
	  static constexpr Field8<typename Defs::Groups::CSR_C, Defs::MSEL> MSEL = Registers::CSR_C;
	  static constexpr Field8<typename Defs::Groups::CSR_C, Defs::PM>   PM   = Registers::CSR_C;

	  // CSR_B_C Register Fields
	  static constexpr Field8<typename Defs::Groups::CSR_B, Defs::CSZ_2>   CSZ_2   = Registers::CSR_B;
	  static constexpr Field8<typename Defs::Groups::CSR_C, Defs::CSZ_0_1> CSZ_0_1 = Registers::CSR_C;
	  static constexpr auto CSZ = make_virtual_field(CSZ_2, CSZ_0_1);
	};

	template<typename Defs>
	struct _UART : UART_ModuleRegisters<Defs> {
	  struct Fields : UART_ModuleFields<Defs> {};
	};
      }
    }

    template<u8 ID> struct UART : Private::UART::_UART<Private::UART::_UART_Defs<ID>> {};

    using UART_0 = UART<0>;
    using UART_1 = UART<1>;
    using UART_2 = UART<2>;
    using UART_3 = UART<3>;
  }

  using namespace ATMegaxx0_1;
}
  
#endif
