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

//! \todo DEBUG. Writing stops when the buffer gets empty just once. Reading still need to be tested.
template<int CHANNEL>
void BufferedUartStream<CHANNEL>::init(void) {
  Uart<CHANNEL>& channel = Uart<CHANNEL>::instance();
  channel.init();
  channel.sendEvent().setFunction(send);
  //channel.sendEvent().start();
  channel.recvEvent().setFunction(receive);
  //channel.recvEvent().start();
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
    Uart<CHANNEL>::instance().sendEvent().start();
  }
  else {
    str._data.sending = false;
    Uart<CHANNEL>::instance().sendEvent().stop();
  }
  Interrupts::unlock();
}

template<int CHANNEL>
void BufferedUartStream<CHANNEL>::receive(void) {
  Interrupts::lock();
  BufferedUartStream<CHANNEL>& str = BufferedUartStream<CHANNEL>::instance();
  Uart<CHANNEL>& channel = Uart<CHANNEL>::instance();
  str._input.enqueue(channel.template recv<char>());
  if(str._input.isFull()) {
    channel.recvEvent().stop();
  }
  Interrupts::unlock();
}

template<int CHANNEL>
void BufferedUartStream<CHANNEL>::setValue(char val) {
  InternalBufferedStream::setValue(val);
  if(!Uart<CHANNEL>::instance().sendEvent().activated()) { //(!_data.sending) {
    send();
  }
}

template<int CHANNEL>
char BufferedUartStream<CHANNEL>::getValue(void) {
  char val = InternalBufferedStream::getValue();
  if(!Uart<CHANNEL>::instance().recvEvent().activated() && !_input.isFull()) {
    Uart<CHANNEL>::instance().recvEvent().start();
  }
  return val;
}

#endif//AVR_BUFFERED_UART_STREAM_HPP
