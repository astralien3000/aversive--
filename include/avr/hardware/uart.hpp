#ifndef AVR_UART_HPP
#define AVR_UART_HPP

#include "../../common/hardware/uart.hpp"

#include "architecture.hpp"

////////////////////////////////////////////////////////
// UART ////////////////////////////////////////////////

// TODO : FIND AN OTHER WAY !!!!
// TODO : MOVE
#define FSOC 16000000l
#define DIV 16l

template<int ID>
inline Uart<ID>::Uart(void) {}

template<int ID>
inline void Uart<ID>::init(void) {
  setBaudrate(9600);
  setNBits<8>();

  // 1 Stop bit
  REG(uart<ID>::control) |=
    CFG(uart<ID>::control::stopbit::template value<1>);

  // Enable RX and TX
  REG(uart<ID>::control) |=
    CFG(uart<ID>::control::enable::send)|
    CFG(uart<ID>::control::enable::recv);
}

template<int ID> template<typename T>
inline void Uart<ID>::setBaudrate(const T& val) {
  unsigned long BAUD = (unsigned long)val;
  unsigned long ubrr = (FSOC / (DIV * BAUD)) - 1l;

  // Set baud rate
  REG(uart<ID>::baudrate) =
    VAL(uart<ID>::baudrate, ubrr);
}

template<int ID> template<int NBITS>
inline void Uart<ID>::setNBits(void) {
  REG(uart<ID>::control) |=
    CFG(uart<ID>::control::charsize::template value<NBITS>);
}

// WARNING : 9th bit not managed !!
// ADVICE : wait after sending
template<int ID> template<typename T>
inline void Uart<ID>::send(T val) {
  // Wait for empty transmit buffer
  while( ! (REG(uart<ID>::control) & CFG(uart<ID>::control::flag::empty)));

  // Put data into buffer
  REG(uart<ID>::data) =
    VAL(uart<ID>::data, val);

  for(volatile int i = 255 ; i > 0 ; i--);
}

// WARNING : 9th bit not managed !!
template<int ID> template<typename T>
inline T Uart<ID>::recv(void) {
  // Wait for data to be received
  while( ! (REG(uart<ID>::control) & CFG(uart<ID>::control::flag::recvend)));

  // Get and return received data from buffer
  return (T)REG(uart<ID>::data);
}

template<int ID>
inline typename Uart<ID>::RecvEvent& Uart<ID>::recvEvent(void) {
  static typename Uart<ID>::RecvEvent evt;
  return evt;
}

template<int ID>
inline typename Uart<ID>::SendEvent& Uart<ID>::sendEvent(void) {
  static typename Uart<ID>::SendEvent evt;
  return evt;
}

template<int ID>
inline typename Uart<ID>::EmptyEvent& Uart<ID>::emptyEvent(void) {
  static typename Uart<ID>::EmptyEvent evt;
  return evt;
}

////////////////////////////////////////////////////////
// UART::RecvEvent ////////////////////////////////////

template<int ID>
inline Uart<ID>::RecvEvent::RecvEvent(void) {}

template<int ID>
inline void Uart<ID>::RecvEvent::start(void) {
  REG(uart<ID>::control) |=
    CFG(uart<ID>::control::ienable::recv);
}

template<int ID>
inline void Uart<ID>::RecvEvent::stop(void) {
  REG(uart<ID>::control) &=
    ~CFG(uart<ID>::control::ienable::recv);
}

////////////////////////////////////////////////////////
// UART::SendEvent ////////////////////////////////////

template<int ID>
inline Uart<ID>::SendEvent::SendEvent(void) {}

template<int ID>
inline void Uart<ID>::SendEvent::start(void) {
  REG(uart<ID>::control) |=
    CFG(uart<ID>::control::ienable::send);
}

template<int ID>
inline void Uart<ID>::SendEvent::stop(void) {
  REG(uart<ID>::control) &=
    ~CFG(uart<ID>::control::ienable::send);
}

////////////////////////////////////////////////////////
// UART::EmptyEvent ////////////////////////////////////

template<int ID>
inline Uart<ID>::EmptyEvent::EmptyEvent(void) {}

template<int ID>
inline void Uart<ID>::EmptyEvent::start(void) {
  REG(uart<ID>::control) |=
    CFG(uart<ID>::control::ienable::empty);
}

template<int ID>
inline void Uart<ID>::EmptyEvent::stop(void) {
  REG(uart<ID>::control) &=
    ~CFG(uart<ID>::control::ienable::empty);
}


#endif//AVR_UART_HPP
