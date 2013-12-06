#ifndef UART_HPP
#define UART_HPP

#include "../base/singleton.hpp"
#include "../base/array.hpp"

class UartPrivateData;

//! \brief class providing routines for UART config, receiving and sending
//! \param ID : index of the UART
template<int ID = 0, typename UartImpl = UartPrivateData>
class Uart {
public:
  //! \brief Configure Uart
  inline void init(void);
  //! \brief Make UART available for an other purpose
  inline void reset(void);

  //! \brief Receive 1 character from RX
  template<typename T, bool WAIT = false> inline T recv(void);
  //! \brief Transmit 1 character from TX
  template<typename T, bool WAIT = false> inline void send(T);

  //! \brief Set the size in bits of transmitted characters
  template<int NBITS> inline void setNBits(void);
  //! \brief Set the baudrate
  template<int BAUDRATE> inline void setBaudrate(void);

private:
  //! \brief Private Constructor (Singleton)
  inline Uart();

  UartImpl data;
};

#endif//UART_HPP
