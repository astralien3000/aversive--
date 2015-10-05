/* Definitions for ATmega640, Atmega1280, ATmega1281, ATmega2560 and ATmega2561. */

#ifndef HDL_AVR_MEGA_XX0_1_REG_HPP
#define HDL_AVR_MEGA_XX0_1_REG_HPP

#if defined(__AVR_ATmega640__) || defined(__AVR_ATmega1280__) || defined(__AVR_ATmega2560__)
# define __ATmegaxx0__
#elif defined(__AVR_ATmega1281__) || defined(__AVR_ATmega2561__)
# define __ATmegaxx1__
#endif

#include "../../../../common/include/memory_mapping.hpp"

namespace HDL {
  using namespace MemoryMapping;
  
  /* AVR_MACRO */
  static constexpr usys SFR(usys addr) {
    return 0x0020 +  addr;
  }

  using DummyType = u8;
  constexpr u8 DUMMY_VALUE = 0;

  /* GPIO Modules */

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

  //! warning : This GPIO only contains 6 pins
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

  template<u8 ID> struct GPIO : _GPIO<_GPIO_Defs<ID>>::Module {};  
  
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

  /* Simple Defs */

  struct TIMER_8bits_ModuleDefs {
    static constexpr u8 BITS = 8;

    struct Groups {
      struct IMSK;

      struct CCR_A;
      struct CCR_B;

      struct CNT;
    };

    //! IFR Register Bits
    static constexpr u8 TOV   = 0;
    static constexpr u8 OCF_A = 1;
    static constexpr u8 OCF_B = 2;

    //! CCR_A Register Fields
    static constexpr u8 COM_A   = 0b11000000;
    static constexpr u8 COM_B   = 0b00110000;
    static constexpr u8 WGM_0_1 = 0b00000011;
    
    //! CCR_B Register Fields
    static constexpr u8 CS    = 0b00000111;
    static constexpr u8 WGM_2 = 0b00001000;

    //! CCR_B Register Bits
    static constexpr u8 FOC_A = 7;
    static constexpr u8 FOC_B = 6;

    //! IMSK Register Bits
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

    //! IFR Register Bits
    static constexpr u8 TOV   = 0;
    static constexpr u8 OCF_A = 1;
    static constexpr u8 OCF_B = 2;
    static constexpr u8 OCF_C = 3;
    static constexpr u8 ICF   = 5;

    //! CCR_A Register Fields
    static constexpr u8 COM_A   = 0b11000000;
    static constexpr u8 COM_B   = 0b00110000;
    static constexpr u8 COM_C   = 0b00001100;
    static constexpr u8 WGM_0_1 = 0b00000011;
    
    //! CCR_B Register Fields
    static constexpr u8 CS      = 0b00000111;
    static constexpr u8 WGM_2_3 = 0b00011000;

    //! CCR_B Register Bits
    static constexpr u8 ICNC = 7;
    static constexpr u8 ICES = 6;
    
    //! CCR_C Register Bits
    static constexpr u8 FOC_A = 7;
    static constexpr u8 FOC_B = 6;
    static constexpr u8 FOC_C = 5;
    
    //! IMSK Register Bits
    static constexpr u8 TOIE   = 0;
    static constexpr u8 OCIE_A = 1;
    static constexpr u8 OCIE_B = 2;
    static constexpr u8 OCIE_C = 3;
    static constexpr u8 ICIE   = 5;
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
  
  /* END Simple defs */

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
      //! IFR Register Bits
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
    };
    
    template<DummyType DUMMY>
    struct _Fields<16, DUMMY> : _Fields<8, DUMMY> {
      //! IFR Register Bits
      static constexpr BitField8<typename Defs::Groups::IMSK, Defs::OCF_C> OCF_C = Registers::IFR;
      static constexpr BitField8<typename Defs::Groups::IMSK, Defs::ICF> ICF = Registers::IFR;
      
      template<u8 OC_ID, DummyType _DUMMY = DUMMY_VALUE> struct OCF : _Fields<8, DUMMY>::template OCF<OC_ID, _DUMMY> {};
      
      template<DummyType _DUMMY> struct OCF<2, _DUMMY> {
	static constexpr auto& field = OCF_C;
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
  
  template<u8 ID> struct TIMER : _TIMER<_TIMER_Defs<ID>> {};

  using TIMER_0 = TIMER<0>;
  using TIMER_1 = TIMER<1>;
  using TIMER_2 = TIMER<2>;
  
  /*
  struct TIMER_ModuleTraits {
    static constexpr u8 COUNT = 6;
  };

  template<u8 BITS>
  struct TIMER_ModuleGroups {
    struct IFR;
    struct CCR_A;
    struct CCR_B;
    struct CNT_OCR;
    struct IMSK;
  };

  template<u8 ID, DummyType DUMMY>
  struct _TIMER {
    static_assert(ID < TIMER_ModuleTraits::COUNT, "Invalid ID");
  };

  template<DummyType DUMMY>
  struct _TIMER<0, DUMMY> {
    using Groups = TIMER_ModuleGroups<8>;
    using Registers = _TIMER<0, DUMMY>;

    static constexpr MemoryMapping::Register8<Groups::IFR> IFR = SFR(0x15);
    
    static constexpr MemoryMapping::Register8<Groups::CCR_A> CCR_A = SFR(0x24);
    static constexpr MemoryMapping::Register8<Groups::CCR_B> CCR_B = SFR(0x25);

    static constexpr MemoryMapping::Register8<Groups::CNT_OCR> CNT = SFR(0x26);

    template<u8 OC_ID>
    struct OCR {
      static_assert(OC_ID < 2, "Invalid OC_ID");
      static constexpr MemoryMapping::Register8<TIMER_ModuleGroups<8>::CNT_OCR> reg = SFR(0x27+OC_ID);
    };
    
    static constexpr auto& OCR_A = OCR<0>::reg;
    static constexpr auto& OCR_B = OCR<1>::reg;

    static constexpr MemoryMapping::Register8<Groups::IMSK> IMSK = SFR(0x6E);

    struct Fields {

      //////////
      // IFR Register

      template<u8 BIT>
      struct IFR {
	static constexpr MemoryMapping::BitField8<TIMER_ModuleGroups<8>::IFR, BIT> field = Registers::IFR;
      };

      template<u8 OC_ID>
      struct OCF : IFR<1+OC_ID> {
	static_assert(OC_ID < 2, "Invalid OC_ID");
      };

      static constexpr auto& OCF_A = OCF<0>::field;
      static constexpr auto& OCF_B = OCF<1>::field;
      static constexpr auto&   TOV = IFR<0>::field;

      //////////
      // CCR_A Register

      template<u8 BIT>
      struct CCR_A {
	static constexpr MemoryMapping::BitField8<TIMER_ModuleGroups<8>::CCR_A, BIT> field = Registers::CCR_A;
      };

      template<u8 OC_ID, DummyType DUMMY1>
      struct _COM;

      template<DummyType DUMMY1>
      struct _COM<0, DUMMY1> {
	static constexpr MemoryMapping::Field8<TIMER_ModuleGroups<8>::CCR_A, 0b11000000> field = Registers::CCR_A;
      };

      template<DummyType DUMMY1>
      struct _COM<1, DUMMY1> {
	static constexpr MemoryMapping::Field8<TIMER_ModuleGroups<8>::CCR_A, 0b00110000> field = Registers::CCR_A;
      };

      template <u8 OC_ID> using COM = _COM<OC_ID, DUMMY_VALUE>;

      static constexpr auto& COM_A = COM<0>::field;
      static constexpr auto& COM_B = COM<1>::field;
      
    };
  };

  template<DummyType DUMMY>
  struct _TIMER<2, DUMMY> {
    using Groups = TIMER_ModuleGroups<8>;
    using Registers = _TIMER<2, DUMMY>;

      static constexpr MemoryMapping::Register8<Groups::IFR> IFR = SFR(0x17);
    
	static constexpr MemoryMapping::Register8<Groups::CCR_A> CCR_A = SFR(0xB0);
	static constexpr MemoryMapping::Register8<Groups::CCR_B> CCR_B = SFR(0xB1);

	static constexpr MemoryMapping::Register8<Groups::CNT_OCR> CNT = SFR(0xB2);

    template<u8 OC_ID>
    struct OCR {
      static_assert(OC_ID < 2, "Invalid OC_ID");
      static constexpr MemoryMapping::Register8<TIMER_ModuleGroups<8>::CNT_OCR> reg = SFR(0xB3+OC_ID);
    };
    
    static constexpr auto& OCR_A = OCR<0>::reg;
    static constexpr auto& OCR_B = OCR<1>::reg;

    static constexpr MemoryMapping::Register8<Groups::IMSK> IMSK = SFR(0x70);

    struct Fields {

      //////////
      // IFR Register

      template<u8 BIT>
      struct IFR {
	static constexpr MemoryMapping::BitField8<TIMER_ModuleGroups<8>::IFR, BIT> field = Registers::IFR;
      };

      template<u8 OC_ID>
      struct OCF : IFR<1+OC_ID> {
	static_assert(OC_ID < 2, "Invalid OC_ID");
      };

      static constexpr auto& OCF_A = OCF<0>::field;
      static constexpr auto& OCF_B = OCF<1>::field;
      static constexpr auto&   TOV = IFR<0>::field;

      //////////
      // CCR_A Register

      template<u8 BIT>
      struct CCR_A {
	static constexpr MemoryMapping::BitField8<TIMER_ModuleGroups<8>::CCR_A, BIT> field = Registers::CCR_A;
      };

      template<u8 OC_ID, DummyType DUMMY1>
      struct _COM;

      template<DummyType DUMMY1>
      struct _COM<0, DUMMY1> {
	static constexpr MemoryMapping::Field8<TIMER_ModuleGroups<8>::CCR_A, 0b11000000> field = Registers::CCR_A;
      };

      template<DummyType DUMMY1>
      struct _COM<1, DUMMY1> {
	static constexpr MemoryMapping::Field8<TIMER_ModuleGroups<8>::CCR_A, 0b00110000> field = Registers::CCR_A;
      };

      template <u8 OC_ID> using COM = _COM<OC_ID, DUMMY_VALUE>;

      static constexpr auto& COM_A = COM<0>::field;
      static constexpr auto& COM_B = COM<1>::field;
      
    };
  };

  template<u8 ID> using TIMER = _TIMER<ID, DUMMY_VALUE>;

  using TIMER_0 = TIMER<0>;
  using TIMER_2 = TIMER<2>;
  */
}

#endif
