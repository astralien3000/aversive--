#ifndef HAL_UART_INTERFACE_HPP
#define HAL_UART_INTERFACE_HPP

#include <base/compil.hpp>
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
      AVERSIVE_UNAVAILABLE_ELEMENT(UNDEFINED);
      AVERSIVE_UNAVAILABLE_ELEMENT(NONE);
      AVERSIVE_UNAVAILABLE_ELEMENT(EVEN);
      AVERSIVE_UNAVAILABLE_ELEMENT(ODD);
    };

    //! \brief The UART Stop Bit Length
    struct StopBit {
      enum class Type : u8 { UNDEFINED = 0, ONE_BIT, ONE_AND_HALF_BIT, TWO_BIT };
      AVERSIVE_UNAVAILABLE_ELEMENT(UNDEFINED);
      AVERSIVE_UNAVAILABLE_ELEMENT(ONE_BIT);
      AVERSIVE_UNAVAILABLE_ELEMENT(ONE_AND_HALF_BIT);
      AVERSIVE_UNAVAILABLE_ELEMENT(TWO_BIT);
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
      AVERSIVE_UNAVAILABLE_ELEMENT(UNDEFINED);
      AVERSIVE_UNAVAILABLE_ELEMENT(NONE);
      AVERSIVE_UNAVAILABLE_ELEMENT(CTS);
      AVERSIVE_UNAVAILABLE_ELEMENT(RTS);
    };

    //! \brief The UART Endianess
    struct Endianess {
      enum class Type : u8 { UNDEFINED = 0, MSB, LSB };
      AVERSIVE_UNAVAILABLE_ELEMENT(UNDEFINED);
      AVERSIVE_UNAVAILABLE_ELEMENT(MSB);
      AVERSIVE_UNAVAILABLE_ELEMENT(LSB);
    };

    //! \brief The UART Events
    struct Event {
      enum class Type : u8 { TX_COMPLETE, RX_COMPLETE };
      AVERSIVE_UNAVAILABLE_ELEMENT(TX_COMPLETE);
      AVERSIVE_UNAVAILABLE_ELEMENT(RX_COMPLETE);
    };

    //! \brief UART Settings
    template<
      typename BaudrateType,
      typename ParityType,
      typename StopBitType,
      typename WordSizeType,
      typename TXEnType,
      typename RXEnType,
      typename TXFifoSizeType,
      typename RXFifoSizeType,
      typename FlowControlType,
      typename EndianessType
      >
    struct GenericSettings {
      BaudrateType baudrate;
      ParityType parity;
      StopBitType stop_bit;
      WordSizeType word_size;
      
      TXEnType tx_enabled;
      RXEnType rx_enabled;
      TXFifoSizeType tx_fifo_size;
      RXFifoSizeType rx_fifo_size;

      FlowControlType flow_control;
      EndianessType endianess;
    };

    using Settings = GenericSettings<
      typename Baudrate::Type,
      typename Parity::Type,
      typename StopBit::Type,
      typename WordSize::Type,
      bool,
      bool,
      typename FifoSize::Type,
      typename FifoSize::Type,
      typename FlowControl::Type,
      typename Endianess::Type
    >;

    template<typename UARTType, typename Settings>
    static void init(UARTType uart, const Settings& settings) AVERSIVE_UNAVAILABLE;

    template<typename UARTType, typename Event, typename IRQ_Handler>
    static void setHandler(UARTType uart, Event evt, IRQ_Handler handler) AVERSIVE_UNAVAILABLE;
      
    template<typename UARTType>
    static void putChar(UARTType uart, IO_Type val) AVERSIVE_UNAVAILABLE; // Blocking
    
    template<typename UARTType>
    static IO_Type getChar(UARTType uart) AVERSIVE_UNAVAILABLE; // Blocking

    template<typename UARTType>
    static u32 write(UARTType uart, IO_Type* data, u32 length) AVERSIVE_UNAVAILABLE; // Blocking

    template<typename UARTType>
    static u32 read(UARTType uart, IO_Type* data, u32 length)  AVERSIVE_UNAVAILABLE; // Blocking

    template<typename UARTType>
    static u32 getWritable(UARTType uart) AVERSIVE_UNAVAILABLE;

    template<typename UARTType>
    static u32 getReadable(UARTType uart) AVERSIVE_UNAVAILABLE;
  };

}

#include <hal/macros_undef.hpp>

#endif//HAL_UART_INTERFACE_HPP
