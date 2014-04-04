#ifndef FPGA_UART_STREAM
#define FPGA_UART_STREAM

#include <device/stream/buffered_stream.hpp>
#include <device/device.hpp>
#include <base/integer.hpp>

class FpgaUartStream : public Device, public BufferedStream {
private:
  FpgaUartStreamPrivateData _data;
  
public:
  inline FpgaUartStream(const char* name, u8& tx, u8& tx_occup, u8& rx, u8& rx_ava);
  
  inline FpgaUartStream(const char* name, volatile u8& tx, volatile u8& tx_occup, volatile u8& rx, volatile u8& rx_ava);
  
  inline char getValue(void);
  
  inline void setValue(char val);
  
  inline u16 bufferSize(void) const;
  
  inline u16 outputFreeSpace(void) const;
  
  inline u16 inputUsedSpace(void) const;
};

#endif//FPGA_UART_STREAM
