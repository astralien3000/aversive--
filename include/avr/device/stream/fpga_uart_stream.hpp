#ifndef AVR_FPGA_UART_STREAM_HPP
#define AVR_FPGA_UART_STREAM_HPP

#include <base/integer.hpp>

struct FpgaUartStreamPrivateData {
  inline FpgaUartStreamPrivateData(volatile u8& _tx, volatile u8& _tx_occup, volatile u8& _rx, volatile u8& _rx_ava)
    : tx(_tx), tx_occup(_tx_occup),
      rx(_rx), rx_ava(_rx_ava) {
  }
  volatile u8& tx;
  volatile u8& tx_occup;
  volatile u8& rx;
  volatile u8& rx_ava;
};

#include "../../../common/device/stream/fpga_uart_stream.hpp"

inline FpgaUartStream::FpgaUartStream(const char* name, u8& tx, u8& tx_occup, u8& rx, u8& rx_ava)
  : Device(name),
    _data((volatile u8&) tx, (volatile u8&) tx_occup, (volatile u8&) rx, (volatile u8&) rx_ava) {
}

inline FpgaUartStream::FpgaUartStream(const char* name, volatile u8& tx, volatile u8& tx_occup, volatile u8& rx, volatile u8& rx_ava)
  : Device(name),
    _data(tx, tx_occup, rx, rx_ava) {
}

inline char FpgaUartStream::getValue(void) {
  if(_mini_buffer_used) {
    _mini_buffer_used = false;
    return _mini_buffer;
  }
  else {
    while(!_data.rx_ava) {
    }
    return _data.rx; 
  }
}

inline void FpgaUartStream::setValue(char val) {
  while(!(255 - _data.tx_occup)) {
  }
  _data.tx = val;
}

inline u16 FpgaUartStream::bufferSize(void) const {
  return 64;
}

inline u16 FpgaUartStream::outputFreeSpace(void) const {
  return bufferSize() - _data.tx_occup;
}

inline u16 FpgaUartStream::inputUsedSpace(void) const {
  return _data.rx_ava;
}

#endif//AVR_FPGA_UART_STREAM_HPP
