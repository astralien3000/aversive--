/*
\brief This file is a template you can use to develop your driver
\todo 
 - Rename the security aganst include loops
 - Rename the Example namespace
 - Uncomment the functionalities that are available on your hardware
 - Implement it !
*/

#ifndef HAL_COMMON_UART_EXAMPLE_HPP
#define HAL_COMMON_UART_EXAMPLE_HPP

#include <hal/uart_interface.hpp>

namespace HAL {

  namespace Example {

    template<u8 ID>
    struct UART : ::HAL::Private::UART_DriverInterface<u8> {
      
      //! \brief This is just an alias to define an available enum value
#define MACRO_ENUM_ELEMENT(elem)				\
      static constexpr Type elem = Type::elem

      struct Parity : UART_DriverInterface::Parity {
	//MACRO_ENUM_ELEMENT(UNDEFINED);
	//MACRO_ENUM_ELEMENT(NONE);
	//MACRO_ENUM_ELEMENT(EVEN);
	//MACRO_ENUM_ELEMENT(ODD);
      };

      struct StopBit : UART_DriverInterface::StopBit {
	//MACRO_ENUM_ELEMENT(UNDEFINED);
	//MACRO_ENUM_ELEMENT(ONE_BIT);
	//MACRO_ENUM_ELEMENT(ONE_AND_HALF_BIT);
	//MACRO_ENUM_ELEMENT(TWO_BIT);
      };

      struct FlowControl : UART_DriverInterface::FlowControl {
	//MACRO_ENUM_ELEMENT(UNDEFINED);
	//MACRO_ENUM_ELEMENT(NONE);
	//MACRO_ENUM_ELEMENT(CTS);
	//MACRO_ENUM_ELEMENT(RTS);
      };

      struct Endianess : UART_DriverInterface::Endianess {
	//MACRO_ENUM_ELEMENT(UNDEFINED);
	//MACRO_ENUM_ELEMENT(MSB);
	//MACRO_ENUM_ELEMENT(LSB);
      };
      
#undef MACRO_ENUM_ELEMENT

      //static bool isModuleEnabled(void) { return false; }
      //static void enableModule(void) {}
      //static void disableModule(void) {}

      //static bool isModuleSleepEnabled(void) { return false; }
      //static void enableModuleSleep(void) {}
      //static void disableModuleSleep(void) {}

      //static void setSettings(const Settings&) {}
      //template<typename Settings> static void setSettings(void) {}
      //static void getSettings(Settings&) {}
      
      //static void setBaudrate(typename Baudrate::Type) {}
      //template<typename Baudrate::Type> static void setBaudrate(void) {}
      //static typename Baudrate::Type getBaudrate(void) { return 0; }
      
      //static void setParity(typename Parity::Type) {}
      //template<typename Parity::Type> static void setParity(void) {}
      //static typename Parity::Type getParity(void) { return Parity::UNDEFINED; }
      
      //static void setStopBit(typename StopBit::Type) {}
      //template<typename StopBit::Type> static void setStopBit(void) {}
      //static typename StopBit::Type getStopBit(void) { return StopBit::UNDEFINED; }
      
      //static void setWordSize(typename WordSize::Type) {}
      //template<typename WordSize::Type> static void setWordSize(void) {}
      //static typename WordSize::Type getWordSize(void) { return 0; }
      
      //static void enableTx(void) {}
      //static void disableTx(void) {}
      //static bool isTxEnabled(void) { return false; }
      
      //static void enableRx(void) {}
      //static void disableRx(void) {}
      //static bool isRxEnabled(void) { return false; }
      
      //static void setTxFifoSize(typename FifoSize::Type) {}
      //template<typename FifoSize::Type> static void setTxFifoSize(void) {}
      //static typename FifoSize::Type getTxFifoSize(void) { return 0; }
      
      //static void setRxFifoSize(typename FifoSize::Type) {}
      //template<typename FifoSize::Type> static void setRxFifoSize(void) {}
      //static typename FifoSize::Type getRxFifoSize(void) { return 0; }
      
      //static void setFlowControl(typename FlowControl::Type) {}
      //template<typename FlowControl::Type> static void setFlowControl(void) {}
      //static typename FlowControl::Type getFlowControl(void) { return FlowControl::UNDEFINED; }
      
      //static void setEndianess(typename Endianess::Type) {}
      //template<typename Endianess::Type> static void setEndianess(void) {}
      //static typename Endianess::Type getEndianess(void) { return Endianess::UNDEFINED; }
      
      //static void setTxCompleteHandler(IRQ_Handler) {} 
      //static void setRxCompleteHandler(IRQ_Handler) {} 
      
      //static void putChar(u8) {}
      //static u8 getChar(void) { return 0; }

      //static u32 write(u8*, u32) { return 0; }
      //static u32 read(u8*, u32) { return 0; }

      //static u32 getTxFifoAvailableSpace(void) { return 0; }
      //static u32 getRxFifoAvailableWords(void) { return 0; }
    };

  }
}

#endif//HAL_COMMON_UART_EXAMPLE_HPP
