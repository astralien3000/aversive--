#ifndef HDL_AVR_MEGA_XX0_1_TIMER_FIELDS_HPP
#define HDL_AVR_MEGA_XX0_1_TIMER_FIELDS_HPP

#include "regs.hpp"
#include <memory_mapping/memory_mapping.hpp>
#include <base/dummy.hpp>

namespace HDL {
    
  namespace ATMegaxx0_1 {  

    namespace Private {

      namespace TIMER {

	//! \brief Here are defined TIMER module Fields, this class will be incorporated in the final TIMER Module
	/*!
	 * The fields are splitted into 2 cases : 8-bits and 16-bits
	 */
	template<typename ModuleDefs>
	struct TIMER_ModuleFields {
	  using Defs = ModuleDefs;
	  using Registers = typename TIMER_ModuleRegisters<Defs>::Registers;
    
	  template<u8 BITS, DummyType DUMMY = DUMMY_VALUE> struct _Fields {};

	  //! \brief 8-bits specisalization
	  template<DummyType DUMMY>
	  struct _Fields<8, DUMMY> {
	    //! \name IFR Register Bits
	    //! @{
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
	    //! @}

	    //! \name IMSK Register Bits
	    //! @{
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
	    //! @}

	    //! \name CCR_A Register Fields
	    //! @{
	    static constexpr Field8<typename Defs::Groups::CCR_A, Defs::COM_A> COM_A = Registers::CCR_A;
	    static constexpr Field8<typename Defs::Groups::CCR_A, Defs::COM_B> COM_B = Registers::CCR_A;

	    template<u8 OC_ID, DummyType _DUMMY = DUMMY_VALUE> struct COM { static_assert(!OC_ID && OC_ID, "Invalid OC_ID"); };

	    template<DummyType _DUMMY> struct COM<0, _DUMMY> {
	      static constexpr auto& field = COM_A;
	    };
      
	    template<DummyType _DUMMY> struct COM<1, _DUMMY> {
	      static constexpr auto& field = COM_B;
	    };
	    //! @}

	    //! \name CCR_B Register Fields
	    //! @{
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
	    //! @}

	    //! \name CCR_A_B Register Fields
	    //! @{
	    static constexpr Field8<typename Defs::Groups::CCR_A, Defs::CCR_A_WGM> CCR_A_WGM = Registers::CCR_A;
	    static constexpr Field8<typename Defs::Groups::CCR_B, Defs::CCR_B_WGM> CCR_B_WGM = Registers::CCR_B;
	    static constexpr auto WGM = make_virtual_field(CCR_B_WGM, CCR_A_WGM);
      
	  };
    
	  //! \brief 8-bits specisalization
	  template<DummyType DUMMY>
	  struct _Fields<16, DUMMY> : _Fields<8, DUMMY> {
	    //! \name IFR Register Bits
	    //! @{
	    static constexpr BitField8<typename Defs::Groups::IMSK, Defs::OCF_C> OCF_C = Registers::IFR;
	    static constexpr BitField8<typename Defs::Groups::IMSK, Defs::ICF> ICF = Registers::IFR;
      
	    template<u8 OC_ID, DummyType _DUMMY = DUMMY_VALUE> struct OCF : _Fields<8, DUMMY>::template OCF<OC_ID, _DUMMY> {};
      
	    template<DummyType _DUMMY> struct OCF<2, _DUMMY> {
	      static constexpr auto& field = OCF_C;
	    };
	    //! @}
      
	    //! \name IMSK Register Bits
	    //! @{
	    static constexpr BitField8<typename Defs::Groups::IMSK, Defs::OCIE_C> OCIE_C = Registers::IMSK;
	    static constexpr BitField8<typename Defs::Groups::IMSK, Defs::ICIE> ICIE = Registers::IMSK;
      
	    template<u8 OC_ID, DummyType _DUMMY = DUMMY_VALUE> struct OCIE : _Fields<8, DUMMY>::template OCIE<OC_ID, _DUMMY> {};
      
	    template<DummyType _DUMMY> struct OCIE<2, _DUMMY> {
	      static constexpr auto& field = OCIE_C;
	    };
	    //! @}
      
	    //! \name CCR_A Register Fields
	    //! @{
	    static constexpr Field8<typename Defs::Groups::CCR_A, Defs::COM_C> COM_C = Registers::CCR_A;

	    template<u8 OC_ID, DummyType _DUMMY = DUMMY_VALUE> struct COM : _Fields<8, DUMMY>::template COM<OC_ID, _DUMMY> {};
      
	    template<DummyType _DUMMY> struct COM<2, _DUMMY> {
	      static constexpr auto& field = COM_C;
	    };
	    //! @}
      
	    //! \name CCR_B Register Fields
	    //! @{
	    static constexpr Field8<typename Defs::Groups::CCR_B, Defs::CS> CS = Registers::CCR_B;      
	    static constexpr BitField8<typename Defs::Groups::CCR_B, Defs::ICNC> ICNC = Registers::CCR_B;
	    static constexpr BitField8<typename Defs::Groups::CCR_B, Defs::ICES> ICES = Registers::CCR_B;
	    //! @}

	    //! \name CCR_C Register Fields
	    //! @{
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
	    //! @}
	  };

	  using Fields = _Fields<Defs::BITS>;
	};

      }
    }
  }
}

#endif//HDL_AVR_MEGA_XX0_1_TIMER_FIELDS_HPP
