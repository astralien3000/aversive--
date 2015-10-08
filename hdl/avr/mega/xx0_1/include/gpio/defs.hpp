#ifndef HDL_AVR_MEGA_XX0_1_GPIO_DEFS_HPP
#define HDL_AVR_MEGA_XX0_1_GPIO_DEFS_HPP

namespace HDL {
  
  namespace ATMegaxx0_1 {
      
    namespace Private {
      using namespace HDL::AVR::Private;

      namespace SimpleDefs {
  
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
	  static constexpr usys PIN  = SFR_IO(0x0000);
	  static constexpr usys DDR  = SFR_IO(0x0001);
	  static constexpr usys PORT = SFR_IO(0x0002);
	};

	struct GPIO_B_ModuleDefs : GPIO_Common_ModuleDefs {
	  static constexpr usys PIN  = SFR_IO(0x0003);
	  static constexpr usys DDR  = SFR_IO(0x0004);
	  static constexpr usys PORT = SFR_IO(0x0005);
	};

	struct GPIO_C_ModuleDefs : GPIO_Common_ModuleDefs {
	  static constexpr usys PIN  = SFR_IO(0x0006);
	  static constexpr usys DDR  = SFR_IO(0x0007);
	  static constexpr usys PORT = SFR_IO(0x0008);
	};

	struct GPIO_D_ModuleDefs : GPIO_Common_ModuleDefs {
	  static constexpr usys PIN  = SFR_IO(0x0009);
	  static constexpr usys DDR  = SFR_IO(0x000A);
	  static constexpr usys PORT = SFR_IO(0x000B);
	};

	struct GPIO_E_ModuleDefs : GPIO_Common_ModuleDefs {
	  static constexpr usys PIN  = SFR_IO(0x000C);
	  static constexpr usys DDR  = SFR_IO(0x000D);
	  static constexpr usys PORT = SFR_IO(0x000E);
	};

	struct GPIO_F_ModuleDefs : GPIO_Common_ModuleDefs {
	  static constexpr usys PIN  = SFR_IO(0x000F);
	  static constexpr usys DDR  = SFR_IO(0x0010);
	  static constexpr usys PORT = SFR_IO(0x0011);
	};

	// warning : This GPIO only contains 6 pins
	struct GPIO_G_ModuleDefs : GPIO_Common_ModuleDefs {
	  struct Groups {
	    struct PIN;
	    struct DDR;
	    struct PORT;
	  };

	  static constexpr u8 PIN_MASK = 0b00111111;
    
	  static constexpr usys PIN  = SFR_IO(0x0012);
	  static constexpr usys DDR  = SFR_IO(0x0013);
	  static constexpr usys PORT = SFR_IO(0x0014);
	};

#if defined(__ATmegaxx0__)
  
	struct GPIO_H_ModuleDefs : GPIO_Common_ModuleDefs {
	  static constexpr usys PIN  = SFR_MEM(0x0100);
	  static constexpr usys DDR  = SFR_MEM(0x0101);
	  static constexpr usys PORT = SFR_MEM(0x0102);
	};
    
	struct GPIO_J_ModuleDefs : GPIO_Common_ModuleDefs {
	  static constexpr usys PIN  = SFR_MEM(0x0103);
	  static constexpr usys DDR  = SFR_MEM(0x0104);
	  static constexpr usys PORT = SFR_MEM(0x0105);
	};

	struct GPIO_K_ModuleDefs : GPIO_Common_ModuleDefs {
	  static constexpr usys PIN  = SFR_MEM(0x0106);
	  static constexpr usys DDR  = SFR_MEM(0x0107);
	  static constexpr usys PORT = SFR_MEM(0x0108);
	};

	struct GPIO_L_ModuleDefs : GPIO_Common_ModuleDefs {
	  static constexpr usys PIN  = SFR_MEM(0x0109);
	  static constexpr usys DDR  = SFR_MEM(0x010A);
	  static constexpr usys PORT = SFR_MEM(0x010B);
	};

#endif   //(__ATmegaxx0__)
  
      }
    }
  }
}

namespace HDL {
  namespace ATMegaxx0_1 {
    
    namespace Private {
      using namespace SimpleDefs;
      
      namespace GPIO {
	
	template<u8 ID> struct _GPIO_Defs : GPIO_Undef_ModuleDefs {};
	template<> struct _GPIO_Defs<0>  : GPIO_A_ModuleDefs {};
	template<> struct _GPIO_Defs<1>  : GPIO_B_ModuleDefs {};
	template<> struct _GPIO_Defs<2>  : GPIO_C_ModuleDefs {};
	template<> struct _GPIO_Defs<3>  : GPIO_D_ModuleDefs {};
	template<> struct _GPIO_Defs<4>  : GPIO_E_ModuleDefs {};
	template<> struct _GPIO_Defs<5>  : GPIO_F_ModuleDefs {};
	template<> struct _GPIO_Defs<6>  : GPIO_G_ModuleDefs {};

#if defined(__ATmegaxx0__)
	template<> struct _GPIO_Defs<7>  : GPIO_H_ModuleDefs {};
	
	template<> struct _GPIO_Defs<9>  : GPIO_J_ModuleDefs {};
	template<> struct _GPIO_Defs<10> : GPIO_K_ModuleDefs {};
	template<> struct _GPIO_Defs<11> : GPIO_L_ModuleDefs {};
#endif   //(__ATmegaxx0__)
      }
    }
  }
}


#endif//HDL_AVR_MEGA_XX0_1_GPIO_DEFS_HPP
