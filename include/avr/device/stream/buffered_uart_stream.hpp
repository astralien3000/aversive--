/*
    Aversive++                                                           
    Copyright (C) 2014 Eirbot                                            
                                                                         
    This program is free software: you can redistribute it and/or modify 
    it under the terms of the GNU General Public License as published by 
    the Free Software Foundation, either version 3 of the License, or    
    (at your option) any later version.                                  
                                                                         
    This program is distributed in the hope that it will be useful,      
    but WITHOUT ANY WARRANTY; without even the implied warranty of       
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the        
    GNU General Public License for more details.                         
                                                                         
    You should have received a copy of the GNU General Public License    
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef AVR_BUFFERED_UART_STREAM_HPP
#define AVR_BUFFERED_UART_STREAM_HPP

#include "../../../common/device/stream/buffered_uart_stream.hpp"

#include <hardware/uart.hpp>
#include <hardware/interrupts.hpp>

template<int CHANNEL>
inline BufferedUartStream<CHANNEL>::BufferedUartStream(void) : Device("NULL") {
}

template<>
inline BufferedUartStream<0>::BufferedUartStream(void) : Device("BufferedUartStream_0") {
  init();
}

template<int CHANNEL>
void BufferedUartStream<CHANNEL>::init(void) {
  Uart<CHANNEL>::init();
  Uart<CHANNEL>::sendEvent().setFunction(send);
  Uart<CHANNEL>::recvEvent().setFunction(receive);
  Uart<CHANNEL>::recvEvent().start();
}

template<int CHANNEL>
void BufferedUartStream<CHANNEL>::send(void) {
  Interrupts::lock();
  BufferedUartStream<CHANNEL>& str = BufferedUartStream<CHANNEL>::instance();
  if(!str._output.isEmpty()) {
    Uart<CHANNEL>::send(str._output.head());
    str._output.dequeue();
    Uart<CHANNEL>::sendEvent().start();
  }
  else {
    Uart<CHANNEL>::sendEvent().stop();
  }
  Interrupts::unlock();
}

template<int CHANNEL>
void BufferedUartStream<CHANNEL>::receive(void) {
  Interrupts::lock();
  BufferedUartStream<CHANNEL>& str = BufferedUartStream<CHANNEL>::instance();
  str._input.enqueue(Uart<CHANNEL>::template recv<char>());
  if(str._input.isFull()) {
    Uart<CHANNEL>::recvEvent().stop();
  }
  Interrupts::unlock();
}

template<int CHANNEL>
void BufferedUartStream<CHANNEL>::setValue(char val) {
  InternalBufferedStream::setValue(val);
  if(!Uart<CHANNEL>::sendEvent().activated()) {
    send();
  }
}

template<int CHANNEL>
char BufferedUartStream<CHANNEL>::getValue(void) {
  char val = InternalBufferedStream::getValue();
  if(!Uart<CHANNEL>::recvEvent().activated() && !_input.isFull()) {
    Uart<CHANNEL>::recvEvent().start();
  }
  return val;
}

#endif//AVR_BUFFERED_UART_STREAM_HPP
