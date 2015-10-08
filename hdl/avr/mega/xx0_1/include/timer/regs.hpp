#ifndef HDL_AVR_MEGA_XX0_1_TIMER_REGS_HPP
#define HDL_AVR_MEGA_XX0_1_TIMER_REGS_HPP

#include <util/memory_mapping.hpp>
#include <util/dummy.hpp>

namespace HDL {
    
  namespace ATMegaxx0_1 {  

    /* Timer Modules */

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
	
      }
    }
  }
}

#endif//HDL_AVR_MEGA_XX0_1_TIMER_REGS_HPP
