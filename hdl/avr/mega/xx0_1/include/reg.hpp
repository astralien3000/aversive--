/* Definitions for ATmega640, Atmega1280, ATmega1281, ATmega2560 and ATmega2561. */

#ifndef HDL_AVR_MEGA_XX0_1_REG_HPP
#define HDL_AVR_MEGA_XX0_1_REG_HPP

#if defined(__AVR_ATmega640__) || defined(__AVR_ATmega1280__) || defined(__AVR_ATmega2560__)
# define __ATmegaxx0__
#elif defined(__AVR_ATmega1281__) || defined(__AVR_ATmega2561__)
# define __ATmegaxx1__
#endif

#include <util/memory_mapping.hpp>

namespace HDL {
  using namespace MemoryMapping;
  
  /* AVR_MACRO */
  namespace Private {
    static constexpr usys SFR(usys addr) {
      return (addr < 0x40)?(0x0020 +  addr):((addr >= 0x60)?(addr):0);
    }
    
    using DummyType = u8;
    constexpr u8 DUMMY_VALUE = 0;
  }

  
  /* GPIO Modules */
  
  namespace Private {

    /* Simple Defs */
  
    struct GPIO_Undef_ModuleDefs {
      static constexpr bool EXIST = false;
    };
    
    struct GPIO_Common_ModuleDefs {
      static constexpr bool EXIST = true;
    
      struct Groups {
	struct PIN;
	struct DDR;
	struct PORT;
      };

      static constexpr u8 PIN_MASK = 0b11111111;
    
      static constexpr u8 PIN_0 = 0;
      static constexpr u8 PIN_1 = 1;
      static constexpr u8 PIN_2 = 2;
      static constexpr u8 PIN_3 = 3;
      static constexpr u8 PIN_4 = 4;
      static constexpr u8 PIN_5 = 5;
      static constexpr u8 PIN_6 = 6;
      static constexpr u8 PIN_7 = 7;

      static constexpr u8 DDR_0 = 0;
      static constexpr u8 DDR_1 = 1;
      static constexpr u8 DDR_2 = 2;
      static constexpr u8 DDR_3 = 3;
      static constexpr u8 DDR_4 = 4;
      static constexpr u8 DDR_5 = 5;
      static constexpr u8 DDR_6 = 6;
      static constexpr u8 DDR_7 = 7;

      static constexpr u8 PORT_0 = 0;
      static constexpr u8 PORT_1 = 1;
      static constexpr u8 PORT_2 = 2;
      static constexpr u8 PORT_3 = 3;
      static constexpr u8 PORT_4 = 4;
      static constexpr u8 PORT_5 = 5;
      static constexpr u8 PORT_6 = 6;
      static constexpr u8 PORT_7 = 7;
    };

    struct GPIO_A_ModuleDefs : GPIO_Common_ModuleDefs {
      static constexpr usys PIN  = SFR(0x0000);
      static constexpr usys DDR  = SFR(0x0001);
      static constexpr usys PORT = SFR(0x0002);
    };

    struct GPIO_B_ModuleDefs : GPIO_Common_ModuleDefs {
      static constexpr usys PIN  = SFR(0x0003);
      static constexpr usys DDR  = SFR(0x0004);
      static constexpr usys PORT = SFR(0x0005);
    };

    struct GPIO_C_ModuleDefs : GPIO_Common_ModuleDefs {
      static constexpr usys PIN  = SFR(0x0006);
      static constexpr usys DDR  = SFR(0x0007);
      static constexpr usys PORT = SFR(0x0008);
    };

    struct GPIO_D_ModuleDefs : GPIO_Common_ModuleDefs {
      static constexpr usys PIN  = SFR(0x0009);
      static constexpr usys DDR  = SFR(0x000A);
      static constexpr usys PORT = SFR(0x000B);
    };

    struct GPIO_E_ModuleDefs : GPIO_Common_ModuleDefs {
      static constexpr usys PIN  = SFR(0x000C);
      static constexpr usys DDR  = SFR(0x000D);
      static constexpr usys PORT = SFR(0x000E);
    };

    struct GPIO_F_ModuleDefs : GPIO_Common_ModuleDefs {
      static constexpr usys PIN  = SFR(0x000F);
      static constexpr usys DDR  = SFR(0x0010);
      static constexpr usys PORT = SFR(0x0011);
    };

    // warning : This GPIO only contains 6 pins
    struct GPIO_G_ModuleDefs : GPIO_Common_ModuleDefs {
      struct Groups {
	struct PIN;
	struct DDR;
	struct PORT;
      };

      static constexpr u8 PIN_MASK = 0b00111111;
    
      static constexpr usys PIN  = SFR(0x0012);
      static constexpr usys DDR  = SFR(0x0013);
      static constexpr usys PORT = SFR(0x0014);
    };

#if defined(__ATmegaxx0__)
  
    struct GPIO_H_ModuleDefs : GPIO_Common_ModuleDefs {
      static constexpr usys PIN  = SFR(0x0100);
      static constexpr usys DDR  = SFR(0x0101);
      static constexpr usys PORT = SFR(0x0102);
    };

    struct GPIO_I_ModuleDefs : GPIO_Undef_ModuleDefs {};
    
    struct GPIO_J_ModuleDefs : GPIO_Common_ModuleDefs {
      static constexpr usys PIN  = SFR(0x0103);
      static constexpr usys DDR  = SFR(0x0104);
      static constexpr usys PORT = SFR(0x0105);
    };

    struct GPIO_K_ModuleDefs : GPIO_Common_ModuleDefs {
      static constexpr usys PIN  = SFR(0x0106);
      static constexpr usys DDR  = SFR(0x0107);
      static constexpr usys PORT = SFR(0x0108);
    };

    struct GPIO_L_ModuleDefs : GPIO_Common_ModuleDefs {
      static constexpr usys PIN  = SFR(0x0109);
      static constexpr usys DDR  = SFR(0x010A);
      static constexpr usys PORT = SFR(0x010B);
    };

#else

    struct GPIO_H_ModuleDefs : GPIO_Undef_ModuleDefs {};
    struct GPIO_I_ModuleDefs : GPIO_Undef_ModuleDefs {};
    struct GPIO_J_ModuleDefs : GPIO_Undef_ModuleDefs {};
    struct GPIO_K_ModuleDefs : GPIO_Undef_ModuleDefs {};
    struct GPIO_L_ModuleDefs : GPIO_Undef_ModuleDefs {};

#endif   //(__ATmegaxx0__)
  
    /* END Simple defs */
  }
  
  namespace Private {
    
    template<typename ModuleDefs>
    struct GPIO_ModuleRegisters {
      using Defs = ModuleDefs;

      static constexpr Register8<typename Defs::Groups::PIN>  PIN  = Defs::PIN;
      static constexpr Register8<typename Defs::Groups::DDR>  DDR  = Defs::DDR;
      static constexpr Register8<typename Defs::Groups::PORT> PORT = Defs::PORT;
    };
  
    template<typename ModuleDefs>
    struct GPIO_ModuleFields {
      using Defs = ModuleDefs;
      using Registers = GPIO_ModuleRegisters<Defs>;

      template<u8 PIN_NUM> struct Check {
	static_assert(Defs::PIN_MASK & (1 << PIN_NUM), "Invalid PIN_NUM");
      };
    
      template<u8 PIN_NUM>
      struct PIN : Check<PIN_NUM> {
	static constexpr BitField8<typename Defs::Groups::PIN, PIN_NUM> field = Registers::PIN;
      };
    
      template<u8 PIN_NUM>
      struct DDR : Check<PIN_NUM> {
	static constexpr BitField8<typename Defs::Groups::DDR, PIN_NUM> field = Registers::DDR;
      };
    
      template<u8 PIN_NUM>
      struct PORT : Check<PIN_NUM> {
	static constexpr BitField8<typename Defs::Groups::PORT, PIN_NUM> field = Registers::PORT;
      };
    };
  
    template<typename ModuleDefs>
    struct GPIO_ModuleAliases {
      using Defs = ModuleDefs;
      using Fields = GPIO_ModuleFields<Defs>;
    
      template<u8 MASK = Defs::PIN_MASK, DummyType DUMMY = DUMMY_VALUE> struct _PIN_Fields {};
      template<u8 MASK = Defs::PIN_MASK, DummyType DUMMY = DUMMY_VALUE> struct _DDR_Fields {};
      template<u8 MASK = Defs::PIN_MASK, DummyType DUMMY = DUMMY_VALUE> struct _PORT_Fields {};

      template<DummyType DUMMY>
      struct _PIN_Fields<0b00111111, DUMMY> {
	static constexpr auto& PIN_0 = Fields::template PIN<0>::field;
	static constexpr auto& PIN_1 = Fields::template PIN<1>::field;
	static constexpr auto& PIN_2 = Fields::template PIN<2>::field;
	static constexpr auto& PIN_3 = Fields::template PIN<3>::field;
	static constexpr auto& PIN_4 = Fields::template PIN<4>::field;
	static constexpr auto& PIN_5 = Fields::template PIN<5>::field;
      };

      template<DummyType DUMMY>
      struct _PIN_Fields<0b11111111, DUMMY> : _PIN_Fields<0b00111111, DUMMY> {
	static constexpr auto& PIN_6 = Fields::template PIN<6>::field;
	static constexpr auto& PIN_7 = Fields::template PIN<7>::field;
      };

      template<DummyType DUMMY>
      struct _DDR_Fields<0b00111111, DUMMY> {
	static constexpr auto& DDR_0 = Fields::template DDR<0>::field;
	static constexpr auto& DDR_1 = Fields::template DDR<1>::field;
	static constexpr auto& DDR_2 = Fields::template DDR<2>::field;
	static constexpr auto& DDR_3 = Fields::template DDR<3>::field;
	static constexpr auto& DDR_4 = Fields::template DDR<4>::field;
	static constexpr auto& DDR_5 = Fields::template DDR<5>::field;
      };

      template<DummyType DUMMY>
      struct _DDR_Fields<0b11111111, DUMMY> : _DDR_Fields<0b00111111, DUMMY> {
	static constexpr auto& DDR_6 = Fields::template DDR<6>::field;
	static constexpr auto& DDR_7 = Fields::template DDR<7>::field;
      };

      template<DummyType DUMMY>
      struct _PORT_Fields<0b00111111, DUMMY> {
	static constexpr auto& PORT_0 = Fields::template PORT<0>::field;
	static constexpr auto& PORT_1 = Fields::template PORT<1>::field;
	static constexpr auto& PORT_2 = Fields::template PORT<2>::field;
	static constexpr auto& PORT_3 = Fields::template PORT<3>::field;
	static constexpr auto& PORT_4 = Fields::template PORT<4>::field;
	static constexpr auto& PORT_5 = Fields::template PORT<5>::field;
      };

      template<DummyType DUMMY>
      struct _PORT_Fields<0b11111111, DUMMY> : _PORT_Fields<0b00111111, DUMMY> {
	static constexpr auto& PORT_6 = Fields::template PORT<6>::field;
	static constexpr auto& PORT_7 = Fields::template PORT<7>::field;
      };

      using PIN_Fields = _PIN_Fields<Defs::PIN_MASK>;
      using DDR_Fields = _DDR_Fields<Defs::PIN_MASK>;
      using PORT_Fields = _PORT_Fields<Defs::PIN_MASK>;
    };

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

    template<u8 ID> struct _GPIO_Defs : GPIO_Undef_ModuleDefs {};
    template<> struct _GPIO_Defs<0>  : GPIO_A_ModuleDefs {};
    template<> struct _GPIO_Defs<1>  : GPIO_B_ModuleDefs {};
    template<> struct _GPIO_Defs<2>  : GPIO_C_ModuleDefs {};
    template<> struct _GPIO_Defs<3>  : GPIO_D_ModuleDefs {};
    template<> struct _GPIO_Defs<4>  : GPIO_E_ModuleDefs {};
    template<> struct _GPIO_Defs<5>  : GPIO_F_ModuleDefs {};
    template<> struct _GPIO_Defs<6>  : GPIO_G_ModuleDefs {};
    template<> struct _GPIO_Defs<7>  : GPIO_H_ModuleDefs {};
    template<> struct _GPIO_Defs<8>  : GPIO_I_ModuleDefs {};
    template<> struct _GPIO_Defs<9>  : GPIO_J_ModuleDefs {};
    template<> struct _GPIO_Defs<10> : GPIO_K_ModuleDefs {};
    template<> struct _GPIO_Defs<11> : GPIO_L_ModuleDefs {};
  }
  
  template<u8 ID> struct GPIO : Private::_GPIO<Private::_GPIO_Defs<ID>>::Module {};  
  
  using GPIO_A = GPIO<0>;
  using GPIO_B = GPIO<1>;
  using GPIO_C = GPIO<2>;
  using GPIO_D = GPIO<3>;
  using GPIO_E = GPIO<4>;
  using GPIO_F = GPIO<5>;
  using GPIO_G = GPIO<6>;
  using GPIO_H = GPIO<7>;
  using GPIO_I = GPIO<8>;
  using GPIO_J = GPIO<9>;
  using GPIO_K = GPIO<10>;
  using GPIO_L = GPIO<11>;
  

  /* Timer Modules */
  
  namespace Private {
    
    /* Simple Defs */

    struct TIMER_8bits_ModuleDefs {
      static constexpr u8 BITS = 8;

      struct Groups {
	struct IMSK;

	struct CCR_A;
	struct CCR_B;

	struct CNT;
      };

      // IFR Register Bits
      static constexpr u8 TOV   = 0;
      static constexpr u8 OCF_A = 1;
      static constexpr u8 OCF_B = 2;

      // CCR_A Register Fields
      static constexpr u8 COM_A     = 0b11000000;
      static constexpr u8 COM_B     = 0b00110000;
      static constexpr u8 CCR_A_WGM = 0b00000011;
    
      // CCR_B Register Fields
      static constexpr u8 CS        = 0b00000111;
      static constexpr u8 CCR_B_WGM = 0b00001000;

      // CCR_B Register Bits
      static constexpr u8 FOC_A = 7;
      static constexpr u8 FOC_B = 6;

      // IMSK Register Bits
      static constexpr u8 TOIE   = 0;
      static constexpr u8 OCIE_A = 1;
      static constexpr u8 OCIE_B = 2;
    };

    struct TIMER_16bits_ModuleDefs {
      static constexpr u8 BITS = 16;

      struct Groups {
	struct IMSK;

	struct CCR_A;
	struct CCR_B;
	struct CCR_C;

	struct CNT16;
	struct CNT_L;
	struct CNT_H;
      };

      // IFR Register Bits
      static constexpr u8 TOV   = 0;
      static constexpr u8 OCF_A = 1;
      static constexpr u8 OCF_B = 2;
      static constexpr u8 OCF_C = 3;
      static constexpr u8 ICF   = 5;
    
      // IMSK Register Bits
      static constexpr u8 TOIE   = 0;
      static constexpr u8 OCIE_A = 1;
      static constexpr u8 OCIE_B = 2;
      static constexpr u8 OCIE_C = 3;
      static constexpr u8 ICIE   = 5;

      // CCR_A Register Fields
      static constexpr u8 COM_A     = 0b11000000;
      static constexpr u8 COM_B     = 0b00110000;
      static constexpr u8 COM_C     = 0b00001100;
      static constexpr u8 CCR_A_WGM = 0b00000011;
    
      // CCR_B Register Fields
      static constexpr u8 CS        = 0b00000111;
      static constexpr u8 CCR_B_WGM = 0b00011000;

      // CCR_B Register Bits
      static constexpr u8 ICNC = 7;
      static constexpr u8 ICES = 6;
    
      // CCR_C Register Bits
      static constexpr u8 FOC_A = 7;
      static constexpr u8 FOC_B = 6;
      static constexpr u8 FOC_C = 5;
    };

    struct TIMER_0_ModuleDefs : TIMER_8bits_ModuleDefs {
      static constexpr usys IFR   = SFR(0x15);
      static constexpr usys IMSK  = SFR(0x6E);

      static constexpr usys CCR_A = SFR(0x24);
      static constexpr usys CCR_B = SFR(0x25);

      static constexpr usys CNT   = SFR(0x26);
      static constexpr usys OCR_A = SFR(0x27);
      static constexpr usys OCR_B = SFR(0x28);
    };

    struct TIMER_1_ModuleDefs : TIMER_16bits_ModuleDefs {
      static constexpr usys IFR   = SFR(0x16);
      static constexpr usys IMSK  = SFR(0x6F);

      static constexpr usys CCR_A = SFR(0x80);
      static constexpr usys CCR_B = SFR(0x81);
      static constexpr usys CCR_C = SFR(0x82);

      static constexpr usys CNT   = SFR(0x84);
      static constexpr usys CNT_L = SFR(0x84);
      static constexpr usys CNT_H = SFR(0x85);

      static constexpr usys ICR   = SFR(0x86);
      static constexpr usys ICR_L = SFR(0x86);
      static constexpr usys ICR_H = SFR(0x87);
    
      static constexpr usys OCR_A   = SFR(0x88);
      static constexpr usys OCR_A_L = SFR(0x88);
      static constexpr usys OCR_A_H = SFR(0x89);
    
      static constexpr usys OCR_B   = SFR(0x8A);
      static constexpr usys OCR_B_L = SFR(0x8A);
      static constexpr usys OCR_B_H = SFR(0x8B);
    
      static constexpr usys OCR_C   = SFR(0x8C);
      static constexpr usys OCR_C_L = SFR(0x8C);
      static constexpr usys OCR_C_H = SFR(0x8D);
    };
  
    struct TIMER_2_ModuleDefs : TIMER_8bits_ModuleDefs {
      static constexpr usys IFR   = SFR(0x17);
      static constexpr usys IMSK  = SFR(0x70);

      static constexpr usys CCR_A = SFR(0xB0);
      static constexpr usys CCR_B = SFR(0xB1);

      static constexpr usys CNT   = SFR(0xB2);
      static constexpr usys OCR_A = SFR(0xB3);
      static constexpr usys OCR_B = SFR(0xB4);
    };
  
    struct TIMER_3_ModuleDefs : TIMER_16bits_ModuleDefs {
      static constexpr usys IFR   = SFR(0x18);
      static constexpr usys IMSK  = SFR(0x71);

      static constexpr usys CCR_A = SFR(0x90);
      static constexpr usys CCR_B = SFR(0x91);
      static constexpr usys CCR_C = SFR(0x92);

      static constexpr usys CNT   = SFR(0x94);
      static constexpr usys CNT_L = SFR(0x94);
      static constexpr usys CNT_H = SFR(0x95);

      static constexpr usys ICR   = SFR(0x96);
      static constexpr usys ICR_L = SFR(0x96);
      static constexpr usys ICR_H = SFR(0x97);
    
      static constexpr usys OCR_A   = SFR(0x98);
      static constexpr usys OCR_A_L = SFR(0x98);
      static constexpr usys OCR_A_H = SFR(0x99);
    
      static constexpr usys OCR_B   = SFR(0x9A);
      static constexpr usys OCR_B_L = SFR(0x9A);
      static constexpr usys OCR_B_H = SFR(0x9B);
    
      static constexpr usys OCR_C   = SFR(0x9C);
      static constexpr usys OCR_C_L = SFR(0x9C);
      static constexpr usys OCR_C_H = SFR(0x9D);
    };
  
    struct TIMER_4_ModuleDefs : TIMER_16bits_ModuleDefs {
      static constexpr usys IFR   = SFR(0x19);
      static constexpr usys IMSK  = SFR(0x72);

      static constexpr usys CCR_A = SFR(0xA0);
      static constexpr usys CCR_B = SFR(0xA1);
      static constexpr usys CCR_C = SFR(0xA2);

      static constexpr usys CNT   = SFR(0xA4);
      static constexpr usys CNT_L = SFR(0xA4);
      static constexpr usys CNT_H = SFR(0xA5);

      static constexpr usys ICR   = SFR(0xA6);
      static constexpr usys ICR_L = SFR(0xA6);
      static constexpr usys ICR_H = SFR(0xA7);
    
      static constexpr usys OCR_A   = SFR(0xA8);
      static constexpr usys OCR_A_L = SFR(0xA8);
      static constexpr usys OCR_A_H = SFR(0xA9);
    
      static constexpr usys OCR_B   = SFR(0xAA);
      static constexpr usys OCR_B_L = SFR(0xAA);
      static constexpr usys OCR_B_H = SFR(0xAB);
    
      static constexpr usys OCR_C   = SFR(0xAC);
      static constexpr usys OCR_C_L = SFR(0xAC);
      static constexpr usys OCR_C_H = SFR(0xAD);
    };
  
    struct TIMER_5_ModuleDefs : TIMER_16bits_ModuleDefs {
      static constexpr usys IFR   = SFR(0x1A);
      static constexpr usys IMSK  = SFR(0x73);

      static constexpr usys CCR_A = SFR(0x120);
      static constexpr usys CCR_B = SFR(0x121);
      static constexpr usys CCR_C = SFR(0x122);

      static constexpr usys CNT   = SFR(0x124);
      static constexpr usys CNT_L = SFR(0x124);
      static constexpr usys CNT_H = SFR(0x125);

      static constexpr usys ICR   = SFR(0x126);
      static constexpr usys ICR_L = SFR(0x126);
      static constexpr usys ICR_H = SFR(0x127);
    
      static constexpr usys OCR_A   = SFR(0x128);
      static constexpr usys OCR_A_L = SFR(0x128);
      static constexpr usys OCR_A_H = SFR(0x129);
    
      static constexpr usys OCR_B   = SFR(0x12A);
      static constexpr usys OCR_B_L = SFR(0x12A);
      static constexpr usys OCR_B_H = SFR(0x12B);
    
      static constexpr usys OCR_C   = SFR(0x12C);
      static constexpr usys OCR_C_L = SFR(0x12C);
      static constexpr usys OCR_C_H = SFR(0x12D);
    };
  
    /* END Simple defs */

  }

  namespace Private {

    template<typename ModuleDefs>
    struct TIMER_ModuleRegisters {
      using Defs = ModuleDefs;

      template<u8 BITS, DummyType DUMMY = DUMMY_VALUE> struct _Registers {};

      template<DummyType DUMMY>
      struct _Registers<8, DUMMY> {
	static constexpr Register8<typename Defs::Groups::IMSK> IFR  = Defs::IFR;
	static constexpr Register8<typename Defs::Groups::IMSK> IMSK = Defs::IMSK;
      
	static constexpr Register8<typename Defs::Groups::CCR_A> CCR_A = Defs::CCR_A;
	static constexpr Register8<typename Defs::Groups::CCR_B> CCR_B = Defs::CCR_B;
      
	static constexpr Register8<typename Defs::Groups::CNT> CNT   = Defs::CNT;
	static constexpr Register8<typename Defs::Groups::CNT> OCR_A = Defs::OCR_A;
	static constexpr Register8<typename Defs::Groups::CNT> OCR_B = Defs::OCR_B;

	template<u8 OC_ID, DummyType _DUMMY = DUMMY_VALUE> struct OCR { static_assert(!OC_ID && OC_ID, "Invalid OC_ID"); };

	template<DummyType _DUMMY> struct OCR<0, _DUMMY> {
	  static constexpr auto& reg = OCR_A;
	};

	template<DummyType _DUMMY> struct OCR<1, _DUMMY> {
	  static constexpr auto& reg = OCR_B;
	};
      };

      template<DummyType DUMMY>
      struct _Registers<16, DUMMY> {
	static constexpr Register8<typename Defs::Groups::IMSK> IFR  = Defs::IFR;
	static constexpr Register8<typename Defs::Groups::IMSK> IMSK = Defs::IMSK;
      
	static constexpr Register8<typename Defs::Groups::CCR_A> CCR_A = Defs::CCR_A;
	static constexpr Register8<typename Defs::Groups::CCR_B> CCR_B = Defs::CCR_B;
	static constexpr Register8<typename Defs::Groups::CCR_C> CCR_C = Defs::CCR_C;
      
	static constexpr Register8<typename Defs::Groups::CNT16> CNT   = Defs::CNT;
	static constexpr Register8<typename Defs::Groups::CNT_L> CNT_L = Defs::CNT_L;
	static constexpr Register8<typename Defs::Groups::CNT_H> CNT_H = Defs::CNT_H;
      
	static constexpr Register8<typename Defs::Groups::CNT16> ICR   = Defs::ICR;
	static constexpr Register8<typename Defs::Groups::CNT_L> ICR_L = Defs::ICR_L;
	static constexpr Register8<typename Defs::Groups::CNT_H> ICR_H = Defs::ICR_H;
      
	static constexpr Register8<typename Defs::Groups::CNT16> OCR_A   = Defs::OCR_A;
	static constexpr Register8<typename Defs::Groups::CNT_L> OCR_A_L = Defs::OCR_A_L;
	static constexpr Register8<typename Defs::Groups::CNT_H> OCR_A_H = Defs::OCR_A_H;

	static constexpr Register8<typename Defs::Groups::CNT16> OCR_B   = Defs::OCR_B;
	static constexpr Register8<typename Defs::Groups::CNT_L> OCR_B_L = Defs::OCR_B_L;
	static constexpr Register8<typename Defs::Groups::CNT_H> OCR_B_H = Defs::OCR_B_H;
      
	static constexpr Register8<typename Defs::Groups::CNT16> OCR_C   = Defs::OCR_C;
	static constexpr Register8<typename Defs::Groups::CNT_L> OCR_C_L = Defs::OCR_C_L;
	static constexpr Register8<typename Defs::Groups::CNT_H> OCR_C_H = Defs::OCR_C_H;

	template<u8 OC_ID, DummyType _DUMMY = DUMMY_VALUE> struct OCR { static_assert(!OC_ID && OC_ID, "Invalid OC_ID"); };

	template<DummyType _DUMMY> struct OCR<0, _DUMMY> {
	  static constexpr auto& reg = OCR_A;
	  static constexpr auto& reg_l = OCR_A_L;
	  static constexpr auto& reg_h = OCR_A_H;
	};

	template<DummyType _DUMMY> struct OCR<1, _DUMMY> {
	  static constexpr auto& reg = OCR_B;
	  static constexpr auto& reg_l = OCR_B_L;
	  static constexpr auto& reg_h = OCR_B_H;
	};

	template<DummyType _DUMMY> struct OCR<2, _DUMMY> {
	  static constexpr auto& reg = OCR_C;
	  static constexpr auto& reg_l = OCR_C_L;
	  static constexpr auto& reg_h = OCR_C_H;
	};

      };
    
      using Registers = _Registers<Defs::BITS>;
    };

    template<typename ModuleDefs>
    struct TIMER_ModuleFields {
      using Defs = ModuleDefs;
      using Registers = typename TIMER_ModuleRegisters<Defs>::Registers;
    
      template<u8 BITS, DummyType DUMMY = DUMMY_VALUE> struct _Fields {};

      template<DummyType DUMMY>
      struct _Fields<8, DUMMY> {
	// IFR Register Bits
	static constexpr BitField8<typename Defs::Groups::IMSK, Defs::TOV> TOV = Registers::IFR;
	static constexpr BitField8<typename Defs::Groups::IMSK, Defs::OCF_A> OCF_A = Registers::IFR;
	static constexpr BitField8<typename Defs::Groups::IMSK, Defs::OCF_B> OCF_B = Registers::IFR;

	template<u8 OC_ID, DummyType _DUMMY = DUMMY_VALUE> struct OCF {};

	template<DummyType _DUMMY> struct OCF<0, _DUMMY> {
	  static constexpr auto& field = OCF_A;
	};

	template<DummyType _DUMMY> struct OCF<1, _DUMMY> {
	  static constexpr auto& field = OCF_B;
	};

	// IMSK Register Bits
	static constexpr BitField8<typename Defs::Groups::IMSK, Defs::TOIE> TOIE = Registers::IMSK;
	static constexpr BitField8<typename Defs::Groups::IMSK, Defs::OCIE_A> OCIE_A = Registers::IMSK;
	static constexpr BitField8<typename Defs::Groups::IMSK, Defs::OCIE_B> OCIE_B = Registers::IMSK;

	template<u8 OC_ID, DummyType _DUMMY = DUMMY_VALUE> struct OCIE {};

	template<DummyType _DUMMY> struct OCIE<0, _DUMMY> {
	  static constexpr auto& field = OCIE_A;
	};

	template<DummyType _DUMMY> struct OCIE<1, _DUMMY> {
	  static constexpr auto& field = OCIE_B;
	};

	// CCR_A Register Fields
	static constexpr Field8<typename Defs::Groups::CCR_A, Defs::COM_A> COM_A = Registers::CCR_A;
	static constexpr Field8<typename Defs::Groups::CCR_A, Defs::COM_B> COM_B = Registers::CCR_A;

	template<u8 OC_ID, DummyType _DUMMY = DUMMY_VALUE> struct COM { static_assert(!OC_ID && OC_ID, "Invalid OC_ID"); };

	template<DummyType _DUMMY> struct COM<0, _DUMMY> {
	  static constexpr auto& field = COM_A;
	};
      
	template<DummyType _DUMMY> struct COM<1, _DUMMY> {
	  static constexpr auto& field = COM_B;
	};

	// CCR_B Register Fields
	static constexpr Field8<typename Defs::Groups::CCR_B, Defs::CS> CS = Registers::CCR_B;
	static constexpr BitField8<typename Defs::Groups::CCR_B, Defs::FOC_A> FOC_A = Registers::CCR_B;
	static constexpr BitField8<typename Defs::Groups::CCR_B, Defs::FOC_B> FOC_B = Registers::CCR_B;
      
	template<u8 OC_ID, DummyType _DUMMY = DUMMY_VALUE> struct FOC { static_assert(!OC_ID && OC_ID, "Invalid OC_ID"); };

	template<DummyType _DUMMY> struct FOC<0, _DUMMY> {
	  static constexpr auto& field = FOC_A;
	};
      
	template<DummyType _DUMMY> struct FOC<1, _DUMMY> {
	  static constexpr auto& field = FOC_B;
	};

	// CCR_A_B Register Fields
	static constexpr Field8<typename Defs::Groups::CCR_A, Defs::CCR_A_WGM> CCR_A_WGM = Registers::CCR_A;
	static constexpr Field8<typename Defs::Groups::CCR_B, Defs::CCR_B_WGM> CCR_B_WGM = Registers::CCR_B;
	static constexpr auto WGM = make_virtual_field(CCR_B_WGM, CCR_A_WGM);
      
      };
    
      template<DummyType DUMMY>
      struct _Fields<16, DUMMY> : _Fields<8, DUMMY> {
	// IFR Register Bits
	static constexpr BitField8<typename Defs::Groups::IMSK, Defs::OCF_C> OCF_C = Registers::IFR;
	static constexpr BitField8<typename Defs::Groups::IMSK, Defs::ICF> ICF = Registers::IFR;
      
	template<u8 OC_ID, DummyType _DUMMY = DUMMY_VALUE> struct OCF : _Fields<8, DUMMY>::template OCF<OC_ID, _DUMMY> {};
      
	template<DummyType _DUMMY> struct OCF<2, _DUMMY> {
	  static constexpr auto& field = OCF_C;
	};
      
	// IMSK Register Bits
	static constexpr BitField8<typename Defs::Groups::IMSK, Defs::OCIE_C> OCIE_C = Registers::IMSK;
	static constexpr BitField8<typename Defs::Groups::IMSK, Defs::ICIE> ICIE = Registers::IMSK;
      
	template<u8 OC_ID, DummyType _DUMMY = DUMMY_VALUE> struct OCIE : _Fields<8, DUMMY>::template OCIE<OC_ID, _DUMMY> {};
      
	template<DummyType _DUMMY> struct OCIE<2, _DUMMY> {
	  static constexpr auto& field = OCIE_C;
	};
      
	// CCR_A Register Fields
	static constexpr Field8<typename Defs::Groups::CCR_A, Defs::COM_C> COM_C = Registers::CCR_A;

	template<u8 OC_ID, DummyType _DUMMY = DUMMY_VALUE> struct COM : _Fields<8, DUMMY>::template COM<OC_ID, _DUMMY> {};
      
	template<DummyType _DUMMY> struct COM<2, _DUMMY> {
	  static constexpr auto& field = COM_C;
	};
      
	// CCR_B Register Fields
	static constexpr Field8<typename Defs::Groups::CCR_B, Defs::CS> CS = Registers::CCR_B;      
	static constexpr BitField8<typename Defs::Groups::CCR_B, Defs::ICNC> ICNC = Registers::CCR_B;
	static constexpr BitField8<typename Defs::Groups::CCR_B, Defs::ICES> ICES = Registers::CCR_B;

	// CCR_C Register Fields
	static constexpr BitField8<typename Defs::Groups::CCR_C, Defs::FOC_A> FOC_A = Registers::CCR_C;
	static constexpr BitField8<typename Defs::Groups::CCR_C, Defs::FOC_B> FOC_B = Registers::CCR_C;
	static constexpr BitField8<typename Defs::Groups::CCR_C, Defs::FOC_C> FOC_C = Registers::CCR_C;
      
	template<u8 OC_ID, DummyType _DUMMY = DUMMY_VALUE> struct FOC { static_assert(!OC_ID && OC_ID, "Invalid OC_ID"); };

	template<DummyType _DUMMY> struct FOC<0, _DUMMY> {
	  static constexpr auto& field = FOC_A;
	};
      
	template<DummyType _DUMMY> struct FOC<1, _DUMMY> {
	  static constexpr auto& field = FOC_B;
	};

	template<DummyType _DUMMY> struct FOC<2, _DUMMY> {
	  static constexpr auto& field = FOC_C;
	};
      };

      using Fields = _Fields<Defs::BITS>;
    };

    template<typename Defs>
    struct _TIMER : TIMER_ModuleRegisters<Defs>::Registers {
      struct Fields : TIMER_ModuleFields<Defs>::Fields {};
    };

    template<u8 ID> struct _TIMER_Defs { static_assert(!ID && ID, "Invalid TIMER"); };
    template<> struct _TIMER_Defs<0> : TIMER_0_ModuleDefs {};
    template<> struct _TIMER_Defs<1> : TIMER_1_ModuleDefs {};
    template<> struct _TIMER_Defs<2> : TIMER_2_ModuleDefs {};
    template<> struct _TIMER_Defs<3> : TIMER_3_ModuleDefs {};
    template<> struct _TIMER_Defs<4> : TIMER_4_ModuleDefs {};
    template<> struct _TIMER_Defs<5> : TIMER_5_ModuleDefs {};

  }
    
  template<u8 ID> struct TIMER : Private::_TIMER<Private::_TIMER_Defs<ID>> {};

  using TIMER_0 = TIMER<0>;
  using TIMER_1 = TIMER<1>;
  using TIMER_2 = TIMER<2>;
  using TIMER_3 = TIMER<3>;
  using TIMER_4 = TIMER<4>;
  using TIMER_5 = TIMER<5>;

  /* UART Modules */

  namespace Private {

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
      static constexpr usys CSR_A = SFR(0x00C0);
      static constexpr usys CSR_B = SFR(0x00C1);
      static constexpr usys CSR_C = SFR(0x00C2);

      static constexpr usys BRR   = SFR(0x00C4);
      static constexpr usys BRR_L = SFR(0x00C4);
      static constexpr usys BRR_H = SFR(0x00C5);

      static constexpr usys DR    = SFR(0x00C6);
    };

    struct UART_1_ModuleDefs : UART_Common_ModuleDefs {
      static constexpr usys CSR_A = SFR(0x00C8);
      static constexpr usys CSR_B = SFR(0x00C9);
      static constexpr usys CSR_C = SFR(0x00CA);

      static constexpr usys BRR   = SFR(0x00CC);
      static constexpr usys BRR_L = SFR(0x00CC);
      static constexpr usys BRR_H = SFR(0x00CD);

      static constexpr usys DR    = SFR(0x00CE);
    };

    struct UART_2_ModuleDefs : UART_Common_ModuleDefs {
      static constexpr usys CSR_A = SFR(0x00D0);
      static constexpr usys CSR_B = SFR(0x00D1);
      static constexpr usys CSR_C = SFR(0x00D2);

      static constexpr usys BRR   = SFR(0x00D4);
      static constexpr usys BRR_L = SFR(0x00D4);
      static constexpr usys BRR_H = SFR(0x00D5);

      static constexpr usys DR    = SFR(0x00D6);
    };

#if defined(__ATmegaxx0__)
    
    struct UART_3_ModuleDefs : UART_Common_ModuleDefs {
      static constexpr usys CSR_A = SFR(0x0130);
      static constexpr usys CSR_B = SFR(0x0131);
      static constexpr usys CSR_C = SFR(0x0132);

      static constexpr usys BRR   = SFR(0x0134);
      static constexpr usys BRR_L = SFR(0x0134);
      static constexpr usys BRR_H = SFR(0x0135);

      static constexpr usys DR    = SFR(0x0136);
    };

#endif   //(__ATmegaxx0__)

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

  template<u8 ID> struct UART : Private::_UART<Private::_UART_Defs<ID>> {};

  using UART_0 = UART<0>;
  using UART_1 = UART<1>;
  using UART_2 = UART<2>;
  using UART_3 = UART<3>;
}

#endif
