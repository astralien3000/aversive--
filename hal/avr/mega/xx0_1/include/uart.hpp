#ifndef HAL_AVR_MEGA_XX0_1_UART_HPP
#define HAL_AVR_MEGA_XX0_1_UART_HPP

#include <hal/uart_interface.hpp>

namespace HAL {

  namespace ATMegaxx0_1 {

    template<u8 ID>
    struct UART : ::HAL::UART_DriverInterface<u8> {
    private:
      
      //! \brief This function has to be User-defined
      inline static u32 getSystemClockFrequency(void); // DEFINE ME

      //! \brief The TX Complete Event handler
      static IRQ_Handler txc;
      
      //! \brief The RX Complete Event handler
      static IRQ_Handler rxc;

    public:
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
	MACRO_ENUM_ELEMENT(UNDEFINED);
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
      
      //inline static bool isModuleEnabled(void);
      //inline static void enableModule(void);
      //inline static void disableModule(void);

      //inline static bool isModuleSleepEnabled(void);
      //inline static void enableModuleSleep(void);
      //inline static void disableModuleSleep(void);

      inline static void setSettings(const Settings& settings) {
	setBaudrate(settings.baudrate);
	setParity(settings.parity);
	setStopBit(settings.stop_bit);
	setWordSize(settings.word_size);
	
	if(settings.tx_enabled) {
	  enableTx();
	}
	else {
	  disableTx();
	}
	
	if(settings.rx_enabled) {
	  enableRx();
	}
	else {
	  disableRx();
	}
      }
      
      template<typename Settings> inline static void setSettings(void) {
	static_assert(Settings::flow_control == FlowControl::UNDEFINED ||
		      Settings::flow_control == FlowControl::NONE,
		      "Invalid Flow Control");
	static_assert(Settings::endianess == Endianess::UNDEFINED ||
		      Settings::endianess == Endianess::LSB,
		      "Invalid Endianess");
	static_assert(Settings::tx_fifo_size == 1,
		      "Invalid TX FIFO Size");
	static_assert(Settings::rx_fifo_size == 1,
		      "Invalid RX FIFO Size");
	
	setBaudrate(Settings::baudrate);
	setParity(Settings::parity);
	setStopBit(Settings::stop_bit);
	setWordSize(Settings::word_size);
	
	if(Settings::tx_enabled) {
	  enableTx();
	}
	else {
	  disableTx();
	}
	
	if(Settings::rx_enabled) {
	  enableRx();
	}
	else {
	  disableRx();
	}	
      }
      
      inline static void getSettings(Settings& settings) {
	settings.baudrate = getBaudrate();
	settings.parity = getParity();
	settings.stop_bit = getStopBit();
	settings.word_size = getWordSize();
      
	settings.tx_enabled = isTxEnabled();
	settings.rx_enabled = isRxEnabled();

	settings.tx_fifo_size = getTxFifoSize();
	settings.rx_fifo_size = getRxFifoSize();

	settings.flow_control = FlowControl::NONE;

	settings.endianess = Endianess::LSB;
      }
      
      inline static void setBaudrate(Baudrate::Type baudrate) {
	HDL::UART<ID>::BRR = (getSystemClockFrequency() / (16 * baudrate)) - 1;
      }
      
      template<Baudrate::Type BAUDRATE> inline static void setBaudrate(void) {
	static_assert(!(BAUDRATE & ~0xFFFF), "Invalid Baudrate");
	setBaudrate(BAUDRATE);
      }
      
      inline static Baudrate::Type getBaudrate(void) {
	return getSystemClockFrequency() / (16 * (VAL(HDL::UART<ID>::BRR) + 1));
      }
      
      inline static void setParity(typename Parity::Type parity) {
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
      
      template<typename Parity::Type PARITY> inline static void setParity(void) {
	setParity(PARITY);
      }
      
      //! \todo This function is not optimized
      inline static typename Parity::Type getParity(void) {
	constexpr auto& PM = HDL::UART<ID>::Fields::PM;
	constexpr auto CFG_NONE = make_config(PM, 0b00);
	constexpr auto CFG_EVEN = make_config(PM, 0b10);
	constexpr auto CFG_ODD  = make_config(PM, 0b11);

	if(PM == CFG_NONE) {
	  return Parity::NONE;
	}
	else if(PM == CFG_EVEN) {
	  return Parity::EVEN;
	}
	else if(PM == CFG_ODD) {
	  return Parity::ODD;
	}
	else {
	  return Parity::UNDEFINED;
	}
      }
      
      inline static void setStopBit(typename StopBit::Type sb) {
	if(sb == StopBit::ONE_BIT) {
	  HDL::UART<ID>::Fields::SBS = false;
	}
	else if(sb == StopBit::TWO_BIT) {
	  HDL::UART<ID>::Fields::SBS = true;
	}
      }
      
      template<typename StopBit::Type SB> inline static void setStopBit(void) {
	setStopBit(SB);
      }
      
      inline static typename StopBit::Type getStopBit(void) {
	if(HDL::UART<ID>::Fields::SBS) {
	  return StopBit::ONE_BIT;
	}
	else {
	  return StopBit::TWO_BIT;
	}
      }

    private:
      template<u8 VAL>
      struct CSZ_CFG {
	static_assert(!(VAL & ~0b111), "Invalid CSZ Config");
	
	static constexpr auto config =
	  make_virtual_config(make_config(HDL::UART<ID>::Fields::CSZ_2, (VAL & 0b100) >> 2),
			      make_config(HDL::UART<ID>::Fields::CSZ_0_1, VAL & 0b011));
      };
      
    public:
      inline static void setWordSize(typename WordSize::Type word_size) {
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
      
      template<typename WordSize::Type WORD_SIZE> inline static void setWordSize(void) {
	static_assert(5 <= WORD_SIZE && WORD_SIZE <= 9, "Invalid Word Size");
	setWordSize(WORD_SIZE);
      }

      //! \todo This function is not optimized
      inline static typename WordSize::Type getWordSize(void) {
	constexpr auto& CSZ = HDL::UART<ID>::Fields::CSZ;
	if(CSZ == CSZ_CFG<0b000>::config) {
	  return 5;
	}
	else if(CSZ == CSZ_CFG<0b001>::config) {
	  return 6;
	}
	else if(CSZ == CSZ_CFG<0b010>::config) {
	  return 7;
	}
	else if(CSZ == CSZ_CFG<0b011>::config) {
	  return 8;
	}
	else if(CSZ == CSZ_CFG<0b111>::config) {
	  return 9;
	}
	return 0;
      }
      
      inline static void enableTx(void) {
	HDL::UART<ID>::Fields::TXEN = true;
      }
      
      inline static void disableTx(void) {
	HDL::UART<ID>::Fields::TXEN = false;
      }
      
      inline static bool isTxEnabled(void) {
	return HDL::UART<ID>::Fields::TXEN;
      }
      
      inline static void enableRx(void) {
	HDL::UART<ID>::Fields::RXEN = true;
      }
      
      inline static void disableRx(void) {
	HDL::UART<ID>::Fields::RXEN = false;
      }
      
      inline static bool isRxEnabled(void) {
	return HDL::UART<ID>::Fields::RXEN;
      }
      
      //inline static void setTxFifoSize(typename FifoSize::Type);
      //template<typename FifoSize::Type> inline static void setTxFifoSize(void);
      inline static typename FifoSize::Type getTxFifoSize(void) {
	return 1;
      }
      
      //inline static void setRxFifoSize(typename FifoSize::Type);
      //template<typename FifoSize::Type> inline static void setRxFifoSize(void);
      inline static typename FifoSize::Type getRxFifoSize(void) {
	return 1;
      }
      
      //inline static void setFlowControl(typename FlowControl::Type);
      //template<typename FlowControl::Type> inline static void setFlowControl(void);
      //inline static typename FlowControl::Type getFlowControl(void);
      
      //inline static void setEndianess(typename Endianess::Type);
      //template<typename Endianess::Type> inline static void setEndianess(void);
      inline static typename Endianess::Type getEndianess(void) {
	return Endianess::LSB;
      }
      
      static void setTxCompleteHandler(IRQ_Handler);
      static void setRxCompleteHandler(IRQ_Handler);
      
      inline static void putChar(u8 val) {
	while(!HDL::UART<ID>::Fields::DRE);
	HDL::UART<ID>::DR = val;
      }
      
      inline static u8 getChar(void) {
	while(!HDL::UART<ID>::Fields::RXC);
	return VAL(HDL::UART<ID>::DR);
      }

      inline static u32 write(u8* data, u32 length) {
	const u32 res = length;
	while(length) {
	  putChar(data);
	  data++;
	  length--;
	}
	return res;
      }
      
      inline static u32 read(u8* data, u32 length) {
	const u32 res = length;
	while(length) {
	  *data = getChar();
	  data++;
	  length--;
	}
	return res;
      }

      inline static u32 getTxFifoAvailableSpace(void) {
	if(HDL::UART<ID>::Fields::DRE) {
	  return 1;
	}
	return 0;
      }
      
      inline static u32 getRxFifoAvailableWords(void) {
	if(HDL::UART<ID>::Fields::RXC) {
	  return 1;
	}
	return 0;
      }
    };

    using UART_0 = UART<0>;
    using UART_1 = UART<1>;
    using UART_2 = UART<2>;
    using UART_3 = UART<3>;

    using UARTx = UART<-1>;
  }
}

#endif//HAL_AVR_MEGA_XX0_1_UART_HPP
