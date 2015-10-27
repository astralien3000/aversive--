#ifndef HAL_AVR_MEGA_XX0_1_UART_HPP
#define HAL_AVR_MEGA_XX0_1_UART_HPP

#include <hal/uart_interface.hpp>

namespace HAL {

  namespace ATMegaxx0_1 {

    template<u8 ID>
    struct UART : ::HAL::Private::UART_DriverInterface {
      
      //! \brief This is just an alias to define an available enum value
#define MACRO_ENUM_ELEMENT(elem)				\
      static constexpr Type elem = Type::elem

      struct Parity : UART_DriverInterface::Parity {
	MACRO_ENUM_ELEMENT(UNDEFINED);
	MACRO_ENUM_ELEMENT(NONE);
	MACRO_ENUM_ELEMENT(EVEN);
	MACRO_ENUM_ELEMENT(ODD);
      };

      struct StopBit : UART_DriverInterface::StopBit {
	MACRO_ENUM_ELEMENT(UNDEFINED);
	MACRO_ENUM_ELEMENT(ONE_BIT);
	//MACRO_ENUM_ELEMENT(ONE_AND_HALF_BIT);
	MACRO_ENUM_ELEMENT(TWO_BIT);
      };

      struct FlowControl : UART_DriverInterface::FlowControl {
	//MACRO_ENUM_ELEMENT(UNDEFINED);
	MACRO_ENUM_ELEMENT(NONE);
	//MACRO_ENUM_ELEMENT(CTS);
	//MACRO_ENUM_ELEMENT(RTS);
      };

      struct Endianess : UART_DriverInterface::Endianess {
	MACRO_ENUM_ELEMENT(UNDEFINED);
	//MACRO_ENUM_ELEMENT(MSB);
	MACRO_ENUM_ELEMENT(LSB);
      };
      
#undef MACRO_ENUM_ELEMENT

      //static bool isModuleEnabled(void);
      //static void enableModule(void);
      //static void disableModule(void);

      //static bool isModuleSleepEnabled(void);
      //static void enableModuleSleep(void);
      //static void disableModuleSleep(void);

      static void setSettings(const Settings&);
      template<typename Settings> static void setSettings(void);
      static void getSettings(Settings&);
      
      static void setParity(typename Parity::Type parity) {
	// UNDEFINED Will not change parity
	if(parity == Parity::NONE) {
	  HDL::UART<ID>::Fields::PM = 0b00;
	}
	else if(parity == Parity::EVEN) {
	  HDL::UART<ID>::Fields::PM = 0b10;
	}
	else if(parity == Parity::ODD) {
	  HDL::UART<ID>::Fields::PM = 0b11;
	}
      }
      
      template<typename Parity::Type PARITY> static void setParity(void) {
	setParity(PARITY);
      }
      
      static typename Parity::Type getParity(void) {
	constexpr auto& PM = HDL::UART<ID>::Fields::PM;
	constexpr auto CFG_NONE = make_config(PM, 0b00);
	constexpr auto CFG_EVEN = make_config(PM, 0b10);
	constexpr auto CFG_ODD  = make_config(PM, 0b11);
	const u8 REGVAL = REG(PM) & MASK(PM);

	if(REGVAL == VAL(CFG_NONE)) {
	  return Parity::NONE;
	}
	else if(REGVAL == VAL(CFG_EVEN)) {
	  return Parity::EVEN;
	}
	else if(REGVAL == VAL(CFG_ODD)) {
	  return Parity::ODD;
	}
	else {
	  return Parity::UNDEFINED;
	}
      }
      
      static void setStopBit(typename StopBit::Type);
      template<typename StopBit::Type> static void setStopBit(void);
      static typename StopBit::Type getStopBit(void);

    private:
      template<u8 VAL>
      struct CSZ_CFG {
	static_assert(!(VAL & ~0b111), "Invalid CSZ Config");
	
	static constexpr auto config =
	  make_virtual_config(make_config(HDL::UART<ID>::Fields::CSZ_2, (VAL & 0b100) >> 2),
			      make_config(HDL::UART<ID>::Fields::CSZ_0_1, VAL & 0b011));
      };
      
    public:
      static void setWordSize(typename WordSize::Type word_size) {
	constexpr auto& CSZ = HDL::UART<ID>::Fields::CSZ;
	if(word_size == 5) {
	  CSZ = CSZ_CFG<0b000>::config;
	}
	else if(word_size == 6) {
	  CSZ = CSZ_CFG<0b001>::config;
	}
	else if(word_size == 7) {
	  CSZ = CSZ_CFG<0b010>::config;
	}
	else if(word_size == 8) {
	  CSZ = CSZ_CFG<0b011>::config;
	}
	else if(word_size == 9) {
	  CSZ = CSZ_CFG<0b111>::config;
	}
      }
      
      template<typename WordSize::Type WORD_SIZE> static void setWordSize(void) {
	static_assert(5 <= WORD_SIZE && WORD_SIZE <= 9, "Invalid Word Size");
	setWordSize(WORD_SIZE);
      }
      
      static typename WordSize::Type getWordSize(void) {
	
      }
      
      static void enableTx(void);
      static void disableTx(void);
      static bool isTxEnabled(void);
      
      static void enableRx(void);
      static void disableRx(void);
      static bool isRxEnabled(void);
      
      //static void setTxFifoSize(typename FifoSize::Type);
      //template<typename FifoSize::Type> static void setTxFifoSize(void);
      static typename FifoSize::Type getTxFifoSize(void);
      
      //static void setRxFifoSize(typename FifoSize::Type);
      //template<typename FifoSize::Type> static void setRxFifoSize(void);
      static typename FifoSize::Type getRxFifoSize(void);
      
      //static void setFlowControl(typename FlowControl::Type);
      //template<typename FlowControl::Type> static void setFlowControl(void);
      //static typename FlowControl::Type getFlowControl(void);
      
      //static void setEndianess(typename Endianess::Type);
      //template<typename Endianess::Type> static void setEndianess(void);
      static typename Endianess::Type getEndianess(void);
      
      static void setTxCompleteHandler(IRQ_Handler); 
      static void setRxCompleteHandler(IRQ_Handler); 
      
      static void putChar(u8); 
      static u8 getChar(void); 

      static u32 write(u8* data, u32 length); 
      static u32 read(u8* data, u32 length); 

      static u32 getTxFifoAvailableSpace(void);
      static u32 getRxFifoAvailableWords(void);
    };

    using UART_0 = UART<0>;
    using UART_1 = UART<1>;
    using UART_2 = UART<2>;
    using UART_3 = UART<3>;

    using UARTx = UART<-1>;
  }
}

#endif//HAL_AVR_MEGA_XX0_1_UART_HPP
