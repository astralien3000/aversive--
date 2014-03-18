#ifndef FPGA_UART_STREAM
#define FPGA_UART_STREAM

#include <device/stream/buffered_stream.hpp>
#include <base/integer.hpp>

class FpgaUartStream : public BufferedStream {
private:
  volatile u8& _tx;
  volatile u8& _tx_occup;
  volatile u8& _rx;
  volatile u8& _rx_ava;  

public:
  inline FpgaUartStream(const char* name, u8& tx, u8& tx_occup, u8& rx, u8& rx_ava)
    : BufferedStream(name),
      _tx((volatile u8&)tx),
      _tx_occup((volatile u8&)tx_occup), 
      _rx((volatile u8&)rx),
      _rx_ava((volatile u8&)rx_ava) {
  }

  inline FpgaUartStream(const char* name, volatile u8& tx, volatile u8& tx_occup, volatile u8& rx, volatile u8& rx_ava)
    : BufferedStream(name),
      _tx(tx),
      _tx_occup(tx_occup), 
      _rx(rx),
      _rx_ava(rx_ava) {
  }


  inline char getValue(void) {
    while(!_rx_ava);
    return _rx; 
  }

  inline void setValue(char val) {
    while(!(255 - _tx_occup));
    _tx = val;
  }

  inline u16 bufferSize(void) {
    return 256;
  }

  inline u16 outputFreeSpace(void) {
    return bufferSize() - _tx_occup;
  }

  inline u16 inputUsedSpace(void) {
    return bufferSize() - _rx_ava;
  }
};

#endif//FPGA_UART_STREAM
