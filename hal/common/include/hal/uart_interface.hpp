#ifndef HAL_COMMON_UART_INTERFACE_HPP
#define HAL_COMMON_UART_INTERFACE_HPP

#include <base/integer.hpp>

//! \brief This define tells to the compiler (GNU) to warn the user when a marked funcionnality is used
//! \todo Replace by C++14 deprecated attribute
#define DEPRECATED __attribute__((deprecated))

namespace HAL {

  namespace Private {

    namespace UART {

      struct Settings {
	using Baudrate = u32;
	Baudrate baudrate;

	enum class Parity : u8 { NONE = 0, EVEN, ODD };
	Parity parity;

	enum class StopBit : u8 { UNDEFINED = 0, ONE_BIT, ONE_AND_HALF_BIT, TWO_BIT };
	StopBit stop_bit;

	using WordSize = u8;
	WordSize word_size;

	bool tx_enabled;
	bool rx_enabled;

	using FifoSize = u8;
	FifoSize tx_fifo_size;
	FifoSize rx_fifo_size;

	enum class FlowControl : u8 { UNDEFINED = 0, NONE, CTS, RTS };
	FlowControl flow_control;

	enum class Endianess: u8 { UNDEFINED = 0, MSB, LSB };
	Endianess endianess;

	using IRQ_Handler = void (*)(void);
	IRQ_Handler tx_complete_handler;
	IRQ_Handler rx_complete_handler;
      };

      class DriverInterface {
	inline static void init(const Settings&);
	inline static void getSettings(Settings&);
    
	void setParity(Settings::Parity);
	Settings::Parity getParity(void);
    
	void setStopBit(Settings::StopBit);
	Settings::StopBit getStopBit(void);

	void setWordSize(Settings::WordSize);
	Settings::WordSize getWordSize(void);

	void enableTx(void);
	void disableTx(void);
	bool isTxEnabled(void);

	void enableRx(void);
	void disableRx(void);
	bool isRxEnabled(void);

	void setTxFifoSize(Settings::FifoSize);
	Settings::FifoSize getTxFifoSize(void);

	void setRxFifoSize(Settings::FifoSize);
	Settings::FifoSize getRxFifoSize(void);

	void setFlowControl(Settings::FlowControl);
	Settings::FlowControl getFlowControl(void);

	void setEndianess(Settings::Endianess);
	Settings::Endianess getEndianess(void);

	void setTxCompleteHandler(Settings::IRQ_Handler); // Tx Fifo is Empty
	void setRxCompleteHandler(Settings::IRQ_Handler); // Rx Fifo is Full

	void putChar(u8); // Bloquant
	u8 getChar(void); // Bloquant

	u32 write(u8* data, u32 length); // Bloquant
	u32 read(u8* data, u32 length); // Bloquant

	u32 getTxFifoAvailableSpace();
	u32 getRxFifoAvailableWords();
      };

    }
  }
}

#undef DEPRECATED

#endif//HAL_COMMON_UART_INTERFACE_HPP
