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

namespace HDL {
  using namespace MemoryMapping;
    
  namespace ATMegaxx0_1 {  

    /* Timer Modules */
  
    namespace Private {
    
      namespace SimpleDefs {

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
	  static constexpr usys IFR   = SFR_IO(0x0015);
	  static constexpr usys IMSK  = SFR_MEM(0x006E);

	  static constexpr usys CCR_A = SFR_IO(0x0024);
	  static constexpr usys CCR_B = SFR_IO(0x0025);

	  static constexpr usys CNT   = SFR_IO(0x0026);
	  static constexpr usys OCR_A = SFR_IO(0x0027);
	  static constexpr usys OCR_B = SFR_IO(0x0028);
	};

	struct TIMER_1_ModuleDefs : TIMER_16bits_ModuleDefs {
	  static constexpr usys IFR   = SFR_IO(0x0016);
	  static constexpr usys IMSK  = SFR_MEM(0x006F);

	  static constexpr usys CCR_A = SFR_MEM(0x0080);
	  static constexpr usys CCR_B = SFR_MEM(0x0081);
	  static constexpr usys CCR_C = SFR_MEM(0x0082);

	  static constexpr usys CNT   = SFR_MEM(0x0084);
	  static constexpr usys CNT_L = SFR_MEM(0x0084);
	  static constexpr usys CNT_H = SFR_MEM(0x0085);

	  static constexpr usys ICR   = SFR_MEM(0x0086);
	  static constexpr usys ICR_L = SFR_MEM(0x0086);
	  static constexpr usys ICR_H = SFR_MEM(0x0087);
    
	  static constexpr usys OCR_A   = SFR_MEM(0x0088);
	  static constexpr usys OCR_A_L = SFR_MEM(0x0088);
	  static constexpr usys OCR_A_H = SFR_MEM(0x0089);
    
	  static constexpr usys OCR_B   = SFR_MEM(0x008A);
	  static constexpr usys OCR_B_L = SFR_MEM(0x008A);
	  static constexpr usys OCR_B_H = SFR_MEM(0x008B);
    
	  static constexpr usys OCR_C   = SFR_MEM(0x008C);
	  static constexpr usys OCR_C_L = SFR_MEM(0x008C);
	  static constexpr usys OCR_C_H = SFR_MEM(0x008D);
	};
  
	struct TIMER_2_ModuleDefs : TIMER_8bits_ModuleDefs {
	  static constexpr usys IFR   = SFR_IO(0x0017);
	  static constexpr usys IMSK  = SFR_MEM(0x0070);

	  static constexpr usys CCR_A = SFR_MEM(0x00B0);
	  static constexpr usys CCR_B = SFR_MEM(0x00B1);

	  static constexpr usys CNT   = SFR_MEM(0x00B2);
	  static constexpr usys OCR_A = SFR_MEM(0x00B3);
	  static constexpr usys OCR_B = SFR_MEM(0x00B4);
	};
  
	struct TIMER_3_ModuleDefs : TIMER_16bits_ModuleDefs {
	  static constexpr usys IFR   = SFR_IO(0x0018);
	  static constexpr usys IMSK  = SFR_MEM(0x0071);

	  static constexpr usys CCR_A = SFR_MEM(0x0090);
	  static constexpr usys CCR_B = SFR_MEM(0x0091);
	  static constexpr usys CCR_C = SFR_MEM(0x0092);

	  static constexpr usys CNT   = SFR_MEM(0x0094);
	  static constexpr usys CNT_L = SFR_MEM(0x0094);
	  static constexpr usys CNT_H = SFR_MEM(0x0095);

	  static constexpr usys ICR   = SFR_MEM(0x0096);
	  static constexpr usys ICR_L = SFR_MEM(0x0096);
	  static constexpr usys ICR_H = SFR_MEM(0x0097);
    
	  static constexpr usys OCR_A   = SFR_MEM(0x0098);
	  static constexpr usys OCR_A_L = SFR_MEM(0x0098);
	  static constexpr usys OCR_A_H = SFR_MEM(0x0099);
    
	  static constexpr usys OCR_B   = SFR_MEM(0x009A);
	  static constexpr usys OCR_B_L = SFR_MEM(0x009A);
	  static constexpr usys OCR_B_H = SFR_MEM(0x009B);
    
	  static constexpr usys OCR_C   = SFR_MEM(0x009C);
	  static constexpr usys OCR_C_L = SFR_MEM(0x009C);
	  static constexpr usys OCR_C_H = SFR_MEM(0x009D);
	};
  
	struct TIMER_4_ModuleDefs : TIMER_16bits_ModuleDefs {
	  static constexpr usys IFR   = SFR_IO(0x0019);
	  static constexpr usys IMSK  = SFR_MEM(0x0072);

	  static constexpr usys CCR_A = SFR_MEM(0x00A0);
	  static constexpr usys CCR_B = SFR_MEM(0x00A1);
	  static constexpr usys CCR_C = SFR_MEM(0x00A2);

	  static constexpr usys CNT   = SFR_MEM(0x00A4);
	  static constexpr usys CNT_L = SFR_MEM(0x00A4);
	  static constexpr usys CNT_H = SFR_MEM(0x00A5);

	  static constexpr usys ICR   = SFR_MEM(0x00A6);
	  static constexpr usys ICR_L = SFR_MEM(0x00A6);
	  static constexpr usys ICR_H = SFR_MEM(0x00A7);
    
	  static constexpr usys OCR_A   = SFR_MEM(0x00A8);
	  static constexpr usys OCR_A_L = SFR_MEM(0x00A8);
	  static constexpr usys OCR_A_H = SFR_MEM(0x00A9);
    
	  static constexpr usys OCR_B   = SFR_MEM(0x00AA);
	  static constexpr usys OCR_B_L = SFR_MEM(0x00AA);
	  static constexpr usys OCR_B_H = SFR_MEM(0x00AB);
    
	  static constexpr usys OCR_C   = SFR_MEM(0x00AC);
	  static constexpr usys OCR_C_L = SFR_MEM(0x00AC);
	  static constexpr usys OCR_C_H = SFR_MEM(0x00AD);
	};
  
	struct TIMER_5_ModuleDefs : TIMER_16bits_ModuleDefs {
	  static constexpr usys IFR   = SFR_IO(0x001A);
	  static constexpr usys IMSK  = SFR_MEM(0x0073);

	  static constexpr usys CCR_A = SFR_MEM(0x0120);
	  static constexpr usys CCR_B = SFR_MEM(0x0121);
	  static constexpr usys CCR_C = SFR_MEM(0x0122);

	  static constexpr usys CNT   = SFR_MEM(0x0124);
	  static constexpr usys CNT_L = SFR_MEM(0x0124);
	  static constexpr usys CNT_H = SFR_MEM(0x0125);

	  static constexpr usys ICR   = SFR_MEM(0x0126);
	  static constexpr usys ICR_L = SFR_MEM(0x0126);
	  static constexpr usys ICR_H = SFR_MEM(0x0127);
    
	  static constexpr usys OCR_A   = SFR_MEM(0x0128);
	  static constexpr usys OCR_A_L = SFR_MEM(0x0128);
	  static constexpr usys OCR_A_H = SFR_MEM(0x0129);
    
	  static constexpr usys OCR_B   = SFR_MEM(0x012A);
	  static constexpr usys OCR_B_L = SFR_MEM(0x012A);
	  static constexpr usys OCR_B_H = SFR_MEM(0x012B);
    
	  static constexpr usys OCR_C   = SFR_MEM(0x012C);
	  static constexpr usys OCR_C_L = SFR_MEM(0x012C);
	  static constexpr usys OCR_C_H = SFR_MEM(0x012D);
	};
  
      }

    }

    namespace Private {

      namespace TIMER {
	
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
      
	    static constexpr Register16<typename Defs::Groups::CNT16> CNT   = Defs::CNT;
	    static constexpr Register8<typename Defs::Groups::CNT_L> CNT_L = Defs::CNT_L;
	    static constexpr Register8<typename Defs::Groups::CNT_H> CNT_H = Defs::CNT_H;
      
	    static constexpr Register16<typename Defs::Groups::CNT16> ICR   = Defs::ICR;
	    static constexpr Register8<typename Defs::Groups::CNT_L> ICR_L = Defs::ICR_L;
	    static constexpr Register8<typename Defs::Groups::CNT_H> ICR_H = Defs::ICR_H;
      
	    static constexpr Register16<typename Defs::Groups::CNT16> OCR_A   = Defs::OCR_A;
	    static constexpr Register8<typename Defs::Groups::CNT_L> OCR_A_L = Defs::OCR_A_L;
	    static constexpr Register8<typename Defs::Groups::CNT_H> OCR_A_H = Defs::OCR_A_H;

	    static constexpr Register16<typename Defs::Groups::CNT16> OCR_B   = Defs::OCR_B;
	    static constexpr Register8<typename Defs::Groups::CNT_L> OCR_B_L = Defs::OCR_B_L;
	    static constexpr Register8<typename Defs::Groups::CNT_H> OCR_B_H = Defs::OCR_B_H;
      
	    static constexpr Register16<typename Defs::Groups::CNT16> OCR_C   = Defs::OCR_C;
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
    }
    
    template<u8 ID> struct TIMER : Private::TIMER::_TIMER<Private::TIMER::_TIMER_Defs<ID>> {};

    using TIMER_0 = TIMER<0>;
    using TIMER_1 = TIMER<1>;
    using TIMER_2 = TIMER<2>;
    using TIMER_3 = TIMER<3>;
    using TIMER_4 = TIMER<4>;
    using TIMER_5 = TIMER<5>;

    /* UART Modules */

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
