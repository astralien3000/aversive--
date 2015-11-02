#ifndef HAL_COMMON_UART_INTERFACE_HPP
#define HAL_COMMON_UART_INTERFACE_HPP

#include <base/integer.hpp>
#include <hal/macros_define.hpp>

namespace HAL {

  //! \brief UART Driver Interface
  //! \param T : The type of a standard UART Data Register
  template<typename T>
  struct UART_DriverInterface {
    using IO_Type = T;
      
    //! \brief The UART Baudrate
    struct Baudrate {
      using Type = u32;
    };

    //! \brief The UART Parity Mode
    struct Parity {
      enum class Type : u8 { UNDEFINED = 0, NONE, EVEN, ODD };
      _AVERSIVE_UNAVAILABLE_ELEMENT(UNDEFINED);
      _AVERSIVE_UNAVAILABLE_ELEMENT(NONE);
      _AVERSIVE_UNAVAILABLE_ELEMENT(EVEN);
      _AVERSIVE_UNAVAILABLE_ELEMENT(ODD);
    };

    //! \brief The UART Stop Bit Length
    struct StopBit {
      enum class Type : u8 { UNDEFINED = 0, ONE_BIT, ONE_AND_HALF_BIT, TWO_BIT };
      _AVERSIVE_UNAVAILABLE_ELEMENT(UNDEFINED);
      _AVERSIVE_UNAVAILABLE_ELEMENT(ONE_BIT);
      _AVERSIVE_UNAVAILABLE_ELEMENT(ONE_AND_HALF_BIT);
      _AVERSIVE_UNAVAILABLE_ELEMENT(TWO_BIT);
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
      _AVERSIVE_UNAVAILABLE_ELEMENT(UNDEFINED);
      _AVERSIVE_UNAVAILABLE_ELEMENT(NONE);
      _AVERSIVE_UNAVAILABLE_ELEMENT(CTS);
      _AVERSIVE_UNAVAILABLE_ELEMENT(RTS);
    };

    //! \brief The UART Endianess
    struct Endianess {
      enum class Type : u8 { UNDEFINED = 0, MSB, LSB };
      _AVERSIVE_UNAVAILABLE_ELEMENT(UNDEFINED);
      _AVERSIVE_UNAVAILABLE_ELEMENT(MSB);
      _AVERSIVE_UNAVAILABLE_ELEMENT(LSB);
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

    //! \name Module Enable
    //! @{
    static bool isModuleEnabled(void) _AVERSIVE_UNAVAILABLE;
    static void enableModule(void)    _AVERSIVE_UNAVAILABLE;
    static void disableModule(void)   _AVERSIVE_UNAVAILABLE;
    //! @}

    //! \name Module Sleep Enable
    //! @{
    static bool isModuleSleepEnabled(void) _AVERSIVE_UNAVAILABLE;
    static void enableModuleSleep(void)    _AVERSIVE_UNAVAILABLE;
    static void disableModuleSleep(void)   _AVERSIVE_UNAVAILABLE;
    //! @}

    //! \name Settings
    //! @{
    static void setSettings(const Settings&)                  _AVERSIVE_UNAVAILABLE;
    template<typename Settings> static void setSettings(void) _AVERSIVE_UNAVAILABLE;
    static void getSettings(Settings&)                        _AVERSIVE_UNAVAILABLE;
    //! @}
      
    //! \name Baudrate
    //! @{
    static void setBaudrate(typename Baudrate::Type)                _AVERSIVE_UNAVAILABLE;
    template<typename Baudrate::Type> static void setBaudrate(void) _AVERSIVE_UNAVAILABLE;
    static typename Baudrate::Type getBaudrate(void)                _AVERSIVE_UNAVAILABLE;
    //! @}
      
    //! \name Partiy
    //! @{
    static void setParity(typename Parity::Type)                _AVERSIVE_UNAVAILABLE;
    template<typename Parity::Type> static void setParity(void) _AVERSIVE_UNAVAILABLE;
    static typename Parity::Type getParity(void)                _AVERSIVE_UNAVAILABLE;
    //! @}
      
    //! \name Stop Bit
    //! @{
    static void setStopBit(typename StopBit::Type)                _AVERSIVE_UNAVAILABLE;
    template<typename StopBit::Type> static void setStopBit(void) _AVERSIVE_UNAVAILABLE;
    static typename StopBit::Type getStopBit(void)                _AVERSIVE_UNAVAILABLE;
    //! @}
      
    //! \name Word Size
    //! @{
    static void setWordSize(typename WordSize::Type)                _AVERSIVE_UNAVAILABLE;
    template<typename WordSize::Type> static void setWordSize(void) _AVERSIVE_UNAVAILABLE;
    static typename WordSize::Type getWordSize(void)                _AVERSIVE_UNAVAILABLE;
    //! @}
      
    //! \name TX Enable
    //! @{
    static void enableTx(void)    _AVERSIVE_UNAVAILABLE;
    static void disableTx(void)   _AVERSIVE_UNAVAILABLE;
    static bool isTxEnabled(void) _AVERSIVE_UNAVAILABLE;
    //! @}
      
    //! \name RX Enable
    //! @{
    static void enableRx(void)    _AVERSIVE_UNAVAILABLE;
    static void disableRx(void)   _AVERSIVE_UNAVAILABLE;
    static bool isRxEnabled(void) _AVERSIVE_UNAVAILABLE;
    //! @}
      
    //! \name TX FIFO Size
    //! @{
    static void setTxFifoSize(typename FifoSize::Type)                _AVERSIVE_UNAVAILABLE;
    template<typename FifoSize::Type> static void setTxFifoSize(void) _AVERSIVE_UNAVAILABLE;
    static typename FifoSize::Type getTxFifoSize(void)                _AVERSIVE_UNAVAILABLE;
    //! @}
      
    //! \name RX FIFO Size
    //! @{
    static void setRxFifoSize(typename FifoSize::Type)                _AVERSIVE_UNAVAILABLE;
    template<typename FifoSize::Type> static void setRxFifoSize(void) _AVERSIVE_UNAVAILABLE;
    static typename FifoSize::Type getRxFifoSize(void)                _AVERSIVE_UNAVAILABLE;
    //! @}
      
    //! \name Flow Control
    //! @{
    static void setFlowControl(typename FlowControl::Type)                _AVERSIVE_UNAVAILABLE;
    template<typename FlowControl::Type> static void setFlowControl(void) _AVERSIVE_UNAVAILABLE;
    static typename FlowControl::Type getFlowControl(void)                _AVERSIVE_UNAVAILABLE;
    //! @}
      
    //! \name Endianess
    //! @{
    static void setEndianess(typename Endianess::Type)                _AVERSIVE_UNAVAILABLE;
    template<typename Endianess::Type> static void setEndianess(void) _AVERSIVE_UNAVAILABLE;
    static typename Endianess::Type getEndianess(void)                _AVERSIVE_UNAVAILABLE;
    //! @}
      
    //! \name Handlers
    //! @{
    static void setTxCompleteHandler(IRQ_Handler) _AVERSIVE_UNAVAILABLE; // Tx Fifo is Empty
    static void setRxCompleteHandler(IRQ_Handler) _AVERSIVE_UNAVAILABLE; // Rx Fifo is Full
    //! @}
      
    //! \name Stream operations
    //! @{
    static void putChar(IO_Type) _AVERSIVE_UNAVAILABLE; // Blocking
    static IO_Type getChar(void) _AVERSIVE_UNAVAILABLE; // Blocking

    static u32 write(IO_Type* data, u32 length) _AVERSIVE_UNAVAILABLE; // Blocking
    static u32 read(IO_Type* data, u32 length)  _AVERSIVE_UNAVAILABLE; // Blocking

    static u32 getTxFifoAvailableSpace(void) _AVERSIVE_UNAVAILABLE;
    static u32 getRxFifoAvailableWords(void) _AVERSIVE_UNAVAILABLE;
    //! @}
  };

}

#include <hal/macros_undef.hpp>

#endif//HAL_COMMON_UART_INTERFACE_HPP
