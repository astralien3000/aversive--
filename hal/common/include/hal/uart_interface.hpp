#ifndef HAL_COMMON_UART_INTERFACE_HPP
#define HAL_COMMON_UART_INTERFACE_HPP

#include <base/integer.hpp>

//! \brief This define tells to the compiler (GNU) to warn the user when a marked funcionnality is used
//! \todo Replace by C++14 deprecated attribute
#define UNAVAILABLE __attribute__((deprecated("This functionnality is not available for the microcontroller you are using")))

namespace HAL {

  //! \brief UART Driver Interface
  //! \param T : The type of a standard UART Data Register
  template<typename T>
  struct UART_DriverInterface {
    using IO_Type = T;
      
    //! \brief This is just an alias to build "deprecatable Enumerations"
#define MACRO_ENUM_ELEMENT(elem)                        \
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
      typename Baudrate::Type baudrate;
      typename Parity::Type parity;
      typename StopBit::Type stop_bit;
      typename WordSize::Type word_size;
      
      bool tx_enabled;
      bool rx_enabled;

      typename FifoSize::Type tx_fifo_size;
      typename FifoSize::Type rx_fifo_size;

      typename FlowControl::Type flow_control;

      typename Endianess::Type endianess;
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
    static void setBaudrate(typename Baudrate::Type)                UNAVAILABLE;
    template<typename Baudrate::Type> static void setBaudrate(void) UNAVAILABLE;
    static typename Baudrate::Type getBaudrate(void)                UNAVAILABLE;
    //! @}
      
    //! \name Partiy
    //! @{
    static void setParity(typename Parity::Type)                UNAVAILABLE;
    template<typename Parity::Type> static void setParity(void) UNAVAILABLE;
    static typename Parity::Type getParity(void)                UNAVAILABLE;
    //! @}
      
    //! \name Stop Bit
    //! @{
    static void setStopBit(typename StopBit::Type)                UNAVAILABLE;
    template<typename StopBit::Type> static void setStopBit(void) UNAVAILABLE;
    static typename StopBit::Type getStopBit(void)                UNAVAILABLE;
    //! @}
      
    //! \name Word Size
    //! @{
    static void setWordSize(typename WordSize::Type)                UNAVAILABLE;
    template<typename WordSize::Type> static void setWordSize(void) UNAVAILABLE;
    static typename WordSize::Type getWordSize(void)                UNAVAILABLE;
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
    static void setTxFifoSize(typename FifoSize::Type)                UNAVAILABLE;
    template<typename FifoSize::Type> static void setTxFifoSize(void) UNAVAILABLE;
    static typename FifoSize::Type getTxFifoSize(void)                UNAVAILABLE;
    //! @}
      
    //! \name RX FIFO Size
    //! @{
    static void setRxFifoSize(typename FifoSize::Type)                UNAVAILABLE;
    template<typename FifoSize::Type> static void setRxFifoSize(void) UNAVAILABLE;
    static typename FifoSize::Type getRxFifoSize(void)                UNAVAILABLE;
    //! @}
      
    //! \name Flow Control
    //! @{
    static void setFlowControl(typename FlowControl::Type)                UNAVAILABLE;
    template<typename FlowControl::Type> static void setFlowControl(void) UNAVAILABLE;
    static typename FlowControl::Type getFlowControl(void)                UNAVAILABLE;
    //! @}
      
    //! \name Endianess
    //! @{
    static void setEndianess(typename Endianess::Type)                UNAVAILABLE;
    template<typename Endianess::Type> static void setEndianess(void) UNAVAILABLE;
    static typename Endianess::Type getEndianess(void)                UNAVAILABLE;
    //! @}
      
    //! \name Handlers
    //! @{
    static void setTxCompleteHandler(IRQ_Handler) UNAVAILABLE; // Tx Fifo is Empty
    static void setRxCompleteHandler(IRQ_Handler) UNAVAILABLE; // Rx Fifo is Full
    //! @}
      
    //! \name Stream operations
    //! @{
    static void putChar(IO_Type) UNAVAILABLE; // Blocking
    static IO_Type getChar(void) UNAVAILABLE; // Blocking

    static u32 write(IO_Type* data, u32 length) UNAVAILABLE; // Blocking
    static u32 read(IO_Type* data, u32 length)  UNAVAILABLE; // Blocking

    static u32 getTxFifoAvailableSpace(void) UNAVAILABLE;
    static u32 getRxFifoAvailableWords(void) UNAVAILABLE;
    //! @}
  };

}

#undef UNAVAILABLE

#endif//HAL_COMMON_UART_INTERFACE_HPP
