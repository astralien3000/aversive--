#ifndef HAL_COMMON_UART_INTERFACE_HPP
#define HAL_COMMON_UART_INTERFACE_HPP

#include <base/integer.hpp>

//! \brief This define tells to the compiler (GNU) to warn the user when a marked funcionnality is used
//! \todo Replace by C++14 deprecated attribute
#define UNAVAILABLE __attribute__((deprecated("This functionnality is not available for the microcontroller you are using")))

namespace HAL {

  namespace Private {

    //! \brief UART Driver Interface
    struct UART_DriverInterface {
      
      //! \brief This is just an alias to build "deprecatable Enumerations"
#define MACRO_ENUM_ELEMENT(elem)				\
      static constexpr Type elem UNAVAILABLE = Type::elem

      //! \brief The UART Baudrate
      struct Baudrate {
	using Type = u32;
      };

      //! \brief The UART Parity Mode
      struct Parity {
	enum class Type : u8 { UNDEFINED = 0, NONE, EVEN, ODD };
	MACRO_ENUM_ELEMENT(UNDEFINED);
	MACRO_ENUM_ELEMENT(NONE);
	MACRO_ENUM_ELEMENT(EVEN);
	MACRO_ENUM_ELEMENT(ODD);
      };

      //! \brief The UART Stop Bit Length
      struct StopBit {
	enum class Type : u8 { UNDEFINED = 0, ONE_BIT, ONE_AND_HALF_BIT, TWO_BIT };
	MACRO_ENUM_ELEMENT(UNDEFINED);
	MACRO_ENUM_ELEMENT(ONE_BIT);
	MACRO_ENUM_ELEMENT(ONE_AND_HALF_BIT);
	MACRO_ENUM_ELEMENT(TWO_BIT);
      };

      //! \brief The UART Word Size
      struct WordSize {
	using Type = u8;
      };

      //! \brief The UART FIFO Size
      struct FifoSize {
	using Type = u8;
      };

      //! \brief The UART Flow Control Mode
      struct FlowControl {
	enum class Type : u8 { UNDEFINED = 0, NONE, CTS, RTS };
	MACRO_ENUM_ELEMENT(UNDEFINED);
	MACRO_ENUM_ELEMENT(NONE);
	MACRO_ENUM_ELEMENT(CTS);
	MACRO_ENUM_ELEMENT(RTS);
      };

      //! \brief The UART Endianess
      struct Endianess {
	enum class Type : u8 { UNDEFINED = 0, MSB, LSB };
	MACRO_ENUM_ELEMENT(UNDEFINED);
	MACRO_ENUM_ELEMENT(MSB);
	MACRO_ENUM_ELEMENT(LSB);
      };
      
      //! \brief Interrupt Handler
      //! \todo May be gatered with others IRQ_Handlers
      using IRQ_Handler = void (*)(void);

      //! \brief UART Settings
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

      //! \name Module Enable
      //! @{
      static bool isModuleEnabled(void) UNAVAILABLE;
      static void enableModule(void)    UNAVAILABLE;
      static void disableModule(void)   UNAVAILABLE;
      //! @}

      //! \name Module Sleep Enable
      //! @{
      static bool isModuleSleepEnabled(void) UNAVAILABLE;
      static void enableModuleSleep(void)    UNAVAILABLE;
      static void disableModuleSleep(void)   UNAVAILABLE;
      //! @}

      //! \name Settings
      //! @{
      static void setSettings(const Settings&)                  UNAVAILABLE;
      template<typename Settings> static void setSettings(void) UNAVAILABLE;
      static void getSettings(Settings&)                        UNAVAILABLE;
      //! @}
      
      //! \name Baudrate
      //! @{
      static void setBaudrate(Baudrate::Type)                UNAVAILABLE;
      template<Baudrate::Type> static void setBaudrate(void) UNAVAILABLE;
      static Baudrate::Type getBaudrate(void)                UNAVAILABLE;
      //! @}
      
      //! \name Partiy
      //! @{
      static void setParity(Parity::Type)                UNAVAILABLE;
      template<Parity::Type> static void setParity(void) UNAVAILABLE;
      static Parity::Type getParity(void)                UNAVAILABLE;
      //! @}
      
      //! \name Stop Bit
      //! @{
      static void setStopBit(StopBit::Type)                UNAVAILABLE;
      template<StopBit::Type> static void setStopBit(void) UNAVAILABLE;
      static StopBit::Type getStopBit(void)                UNAVAILABLE;
      //! @}
      
      //! \name Word Size
      //! @{
      static void setWordSize(WordSize::Type)                UNAVAILABLE;
      template<WordSize::Type> static void setWordSize(void) UNAVAILABLE;
      static WordSize::Type getWordSize(void)                UNAVAILABLE;
      //! @}
      
      //! \name TX Enable
      //! @{
      static void enableTx(void)    UNAVAILABLE;
      static void disableTx(void)   UNAVAILABLE;
      static bool isTxEnabled(void) UNAVAILABLE;
      //! @}
      
      //! \name RX Enable
      //! @{
      static void enableRx(void)    UNAVAILABLE;
      static void disableRx(void)   UNAVAILABLE;
      static bool isRxEnabled(void) UNAVAILABLE;
      //! @}
      
      //! \name TX FIFO Size
      //! @{
      static void setTxFifoSize(FifoSize::Type)                UNAVAILABLE;
      template<FifoSize::Type> static void setTxFifoSize(void) UNAVAILABLE;
      static FifoSize::Type getTxFifoSize(void)                UNAVAILABLE;
      //! @}
      
      //! \name RX FIFO Size
      //! @{
      static void setRxFifoSize(FifoSize::Type)                UNAVAILABLE;
      template<FifoSize::Type> static void setRxFifoSize(void) UNAVAILABLE;
      static FifoSize::Type getRxFifoSize(void)                UNAVAILABLE;
      //! @}
      
      //! \name Flow Control
      //! @{
      static void setFlowControl(FlowControl::Type)                UNAVAILABLE;
      template<FlowControl::Type> static void setFlowControl(void) UNAVAILABLE;
      static FlowControl::Type getFlowControl(void)                UNAVAILABLE;
      //! @}
      
      //! \name Endianess
      //! @{
      static void setEndianess(Endianess::Type)                UNAVAILABLE;
      template<Endianess::Type> static void setEndianess(void) UNAVAILABLE;
      static Endianess::Type getEndianess(void)                UNAVAILABLE;
      //! @}
      
      //! \name Handlers
      //! @{
      static void setTxCompleteHandler(IRQ_Handler) UNAVAILABLE; // Tx Fifo is Empty
      static void setRxCompleteHandler(IRQ_Handler) UNAVAILABLE; // Rx Fifo is Full
      //! @}
      
      //! \name Stream operations
      //! @{
      static void putChar(u8) UNAVAILABLE; // Blocking
      static u8 getChar(void) UNAVAILABLE; // Blocking

      static u32 write(u8* data, u32 length) UNAVAILABLE; // Blocking
      static u32 read(u8* data, u32 length)  UNAVAILABLE; // Blocking

      static u32 getTxFifoAvailableSpace(void) UNAVAILABLE;
      static u32 getRxFifoAvailableWords(void) UNAVAILABLE;
      //! @}
    };

  }
}

#undef UNAVAILABLE

#endif//HAL_COMMON_UART_INTERFACE_HPP
