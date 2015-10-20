#ifndef HAL_COMMON_UART_INTERFACE_HPP
#define HAL_COMMON_UART_INTERFACE_HPP

#include <base/integer.hpp>

//! \brief This define tells to the compiler (GNU) to warn the user when a marked funcionnality is used
//! \todo Replace by C++14 deprecated attribute
#define DEPRECATED __attribute__((deprecated))

namespace HAL {

  namespace Private {

    struct UART_DriverInterface {
      
      //! \brief This is just an alias to build "deprecatable Enumerations"
#define MACRO_ENUM_ELEMENT(elem)				\
      static constexpr Type elem DEPRECATED = Type::elem

      struct Baudrate {
	using Type = u32;
      };

      struct Parity {
	enum class Type : u8 { UNDEFINED = 0, NONE, EVEN, ODD };
	MACRO_ENUM_ELEMENT(UNDEFINED);
	MACRO_ENUM_ELEMENT(NONE);
	MACRO_ENUM_ELEMENT(EVEN);
	MACRO_ENUM_ELEMENT(ODD);
      };

      struct StopBit {
	enum class Type : u8 { UNDEFINED = 0, ONE_BIT, ONE_AND_HALF_BIT, TWO_BIT };
	MACRO_ENUM_ELEMENT(UNDEFINED);
	MACRO_ENUM_ELEMENT(ONE_BIT);
	MACRO_ENUM_ELEMENT(ONE_AND_HALF_BIT);
	MACRO_ENUM_ELEMENT(TWO_BIT);
      };

      struct WordSize {
	using Type = u8;
      };

      struct FifoSize {
	using Type = u8;
      };

      struct FlowControl {
	enum class Type : u8 { UNDEFINED = 0, NONE, CTS, RTS };
	MACRO_ENUM_ELEMENT(UNDEFINED);
	MACRO_ENUM_ELEMENT(NONE);
	MACRO_ENUM_ELEMENT(CTS);
	MACRO_ENUM_ELEMENT(RTS);
      };

      struct Endianess {
	enum class Type : u8 { UNDEFINED = 0, MSB, LSB };
	MACRO_ENUM_ELEMENT(UNDEFINED);
	MACRO_ENUM_ELEMENT(MSB);
	MACRO_ENUM_ELEMENT(LSB);
      };

      using IRQ_Handler = void (*)(void);
    
      struct Settings {
	Baudrate::Type baudrate;
	Parity::Type parity;
	StopBit::Type stop_bit;
	WordSize::Type word_size;
      
	bool tx_enabled;
	bool rx_enabled;

	FifoSize::Type tx_fifo_size;
	FifoSize::Type rx_fifo_size;

	FlowControl::Type flow_control;

	Endianess::Type endianess;
      };

#undef MACRO_ENUM_ELEMENT

      static void setSettings(const Settings&)                  DEPRECATED;
      template<typename Settings> static void setSettings(void) DEPRECATED;
      static void getSettings(Settings&)                        DEPRECATED;
    
      static void setParity(Parity::Type)                DEPRECATED;
      template<Parity::Type> static void setParity(void) DEPRECATED;
      static Parity::Type getParity(void)                DEPRECATED;
    
      static void setStopBit(StopBit::Type)                DEPRECATED;
      template<StopBit::Type> static void setStopBit(void) DEPRECATED;
      static StopBit::Type getStopBit(void)                DEPRECATED;

      static void setWordSize(WordSize::Type)                DEPRECATED;
      template<WordSize::Type> static void setWordSize(void) DEPRECATED;
      static WordSize::Type getWordSize(void)                DEPRECATED;

      static void enableTx(void)    DEPRECATED;
      static void disableTx(void)   DEPRECATED;
      static bool isTxEnabled(void) DEPRECATED;

      static void enableRx(void)    DEPRECATED;
      static void disableRx(void)   DEPRECATED;
      static bool isRxEnabled(void) DEPRECATED;

      static void setTxFifoSize(FifoSize::Type)                DEPRECATED;
      template<FifoSize::Type> static void setTxFifoSize(void) DEPRECATED;
      static FifoSize::Type getTxFifoSize(void)                DEPRECATED;

      static void setRxFifoSize(FifoSize::Type)                DEPRECATED;
      template<FifoSize::Type> static void setRxFifoSize(void) DEPRECATED;
      static FifoSize::Type getRxFifoSize(void)                DEPRECATED;

      static void setFlowControl(FlowControl::Type)                DEPRECATED;
      template<FlowControl::Type> static void setFlowControl(void) DEPRECATED;
      static FlowControl::Type getFlowControl(void)                DEPRECATED;

      static void setEndianess(Endianess::Type)                DEPRECATED;
      template<Endianess::Type> static void setEndianess(void) DEPRECATED;
      static Endianess::Type getEndianess(void)                DEPRECATED;

      static void setTxCompleteHandler(IRQ_Handler) DEPRECATED; // Tx Fifo is Empty
      static void setRxCompleteHandler(IRQ_Handler) DEPRECATED; // Rx Fifo is Full

      static void putChar(u8) DEPRECATED; // Blocking
      static u8 getChar(void) DEPRECATED; // Blocking

      static u32 write(u8* data, u32 length) DEPRECATED; // Blocking
      static u32 read(u8* data, u32 length)  DEPRECATED; // Blocking

      static u32 getTxFifoAvailableSpace(void) DEPRECATED;
      static u32 getRxFifoAvailableWords(void) DEPRECATED;
    };

  }
}

#undef DEPRECATED

#endif//HAL_COMMON_UART_INTERFACE_HPP
