#ifndef BUFFERED_UART_STREAM_HPP
#define BUFFERED_UART_STREAM_HPP

#include <device/stream/internal_buffered_stream.hpp>
#include <base/singleton.hpp>

template<int CHANNEL>
class BufferedUartStream : public InternalBufferedStream, public Singleton<BufferedUartStream<CHANNEL> > {
  friend Singleton<BufferedUartStream<CHANNEL> >;
  
  BufferedUartStreamPrivateData _data;
  
  BufferedUartStream(const char*) : InternalBufferedStream(name) {
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
