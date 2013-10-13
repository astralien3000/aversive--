#ifndef UART_HPP
#define UART_HPP

#include "../base/singleton.hpp"
#include "../base/array.hpp"

//! \brief class providing routines for UART config, receiving and sending
//! \todo WHAT IS FLAGS ?!?
//! \todo Not completely defined yet...
template<int ID = 0, typename UartImpl = UartPrivateData>
class Uart {
public:
  inline void init(void);
  inline void quit(void);

  template<typename T, bool WAIT = false> inline T recv(void);
  template<typename T, bool WAIT = false> inline void send(T);

  template<int SIZE, typename T, bool WAIT = false> inline void recv(Array<SIZE, T>&);
  template<int SIZE, typename T, bool WAIT = false> inline void send(Array<SIZE, T>&);

  template<int NBITS> inline void setNBits(void);
  template<int BAUDRATE> inline void setBaudrate(void);

private:
  inline Uart();

  UartImpl data;
};

#endif//UART_HPP
