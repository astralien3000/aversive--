#ifndef AVR_BUFFERED_UART_STREAM_HPP
#define AVR_BUFFERED_UART_STREAM_HPP

struct BufferedUartStreamPrivateData {
  volatile bool sending;
  volatile bool receiving;
};

#include "../../../common/device/stream/buffered_uart_stream.hpp"

#include <hardware/uart.hpp>
#include <hardware/interrupts.hpp>

template<int CHANNEL>
BufferedUartStream<CHANNEL>::BufferedUartStream(void) : InternalBufferedStream("NULL") {
}

template<>
BufferedUartStream<0>::BufferedUartStream(void) : InternalBufferedStream("BufferedUartStream_0") {
  init();
}

template<int CHANNEL>
void BufferedUartStream<CHANNEL>::init(void) {
  Uart<CHANNEL>& channel = Uart<CHANNEL>::instance();
  channel.init();
  channel.sendEvent().setFunction(send);
  channel.sendEvent().start();
  channel.recvEvent().setFunction(receive);
  channel.recvEvent().start();
  _data.sending = _data.receiving = false;
}

template<int CHANNEL>
void BufferedUartStream<CHANNEL>::send(void) {
  Interrupts::lock();
  BufferedUartStream<CHANNEL>& str = BufferedUartStream<CHANNEL>::instance();
  if(!str._output.isEmpty()) {
    Uart<CHANNEL>::instance().send(str._output.head());
    str._output.dequeue();
    str._data.sending = true;
  }
  else {
    str._data.sending = false;
  }
  Interrupts::unlock();
}

template<int CHANNEL>
void BufferedUartStream<CHANNEL>::receive(void) {
  Interrupts::lock();
  // TODO
  Interrupts::unlock();
}

template<int CHANNEL>
void BufferedUartStream<CHANNEL>::setValue(char val) {
  InternalBufferedStream::setValue(val);
  if(!_data.sending) {
    send();
  }
}

template<int CHANNEL>
char BufferedUartStream<CHANNEL>::getValue(void) {
  return InternalBufferedStream::getValue();
}

#endif//AVR_BUFFERED_UART_STREAM_HPP
