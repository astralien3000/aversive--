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

      //static bool isModuleEnabled(void);
      //static void enableModule(void);
      //static void disableModule(void);

      //static bool isModuleSleepEnabled(void);
      //static void enableModuleSleep(void);
      //static void disableModuleSleep(void);

      //static void setSettings(const Settings&);
      //template<typename Settings> static void setSettings(void);
      //static void getSettings(Settings&);
      
      //static void setParity(Parity::Type);
      //template<Parity::Type> static void setParity(void);
      //static Parity::Type getParity(void);
      
      //static void setStopBit(StopBit::Type);
      //template<StopBit::Type> static void setStopBit(void);
      //static StopBit::Type getStopBit(void);
      
      //static void setWordSize(WordSize::Type);
      //template<WordSize::Type> static void setWordSize(void);
      //static WordSize::Type getWordSize(void);
      
      //static void enableTx(void);
      //static void disableTx(void);
      //static bool isTxEnabled(void);
      
      //static void enableRx(void);
      //static void disableRx(void);
      //static bool isRxEnabled(void);
      
      //static void setTxFifoSize(FifoSize::Type);
      //template<FifoSize::Type> static void setTxFifoSize(void);
      //static FifoSize::Type getTxFifoSize(void);
      
      //static void setRxFifoSize(FifoSize::Type);
      //template<FifoSize::Type> static void setRxFifoSize(void);
      //static FifoSize::Type getRxFifoSize(void);
      
      //static void setFlowControl(FlowControl::Type);
      //template<FlowControl::Type> static void setFlowControl(void);
      //static FlowControl::Type getFlowControl(void);
      
      //static void setEndianess(Endianess::Type);
      //template<Endianess::Type> static void setEndianess(void);
      //static Endianess::Type getEndianess(void);
      
      //static void setTxCompleteHandler(IRQ_Handler); 
      //static void setRxCompleteHandler(IRQ_Handler); 
      
      //static void putChar(u8); 
      //static u8 getChar(void); 

      //static u32 write(u8* data, u32 length); 
      //static u32 read(u8* data, u32 length); 

      //static u32 getTxFifoAvailableSpace(void);
      //static u32 getRxFifoAvailableWords(void);
    };

  }
}

#endif//HAL_AVR_MEGA_XX0_1_UART_HPP
