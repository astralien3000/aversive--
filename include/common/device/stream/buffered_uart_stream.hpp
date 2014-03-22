#ifndef BUFFERED_UART_STREAM_HPP
#define BUFFERED_UART_STREAM_HPP

#include <device/stream/internal_buffered_stream.hpp>
#include <base/singleton.hpp>

template<int CHANNEL>
class BufferedUartStream : public InternalBufferedStream, public Singleton<BufferedUartStream<CHANNEL> > {
  friend Singleton<BufferedUartStream<CHANNEL> >;
  
  BufferedUartStream(const char* name) : InternalBufferedStream(name) {
  }
  
  BufferedUartStream(void);
  void init(void);
  
  static void send(void);
  static void receive(void);
  
public:
  virtual char getValue(void);
  virtual void setValue(char);
};
  
  

#endif//BUFFERED_UART_STREAM_HPP
