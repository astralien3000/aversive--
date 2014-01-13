#ifndef UART_HPP
#define UART_HPP

#include "../base/singleton.hpp"
#include "hardware_event.hpp"

//! \brief class providing routines for UART config, receiving and sending
//! \param ID : index of the UART
template<int ID = 0>
class Uart : public Singleton< Uart<ID> > {
  friend class Singleton< Uart<ID> >;

public:
  //! \brief Configure Uart
  void init(void);
  //! \brief Make UART available for an other purpose
  void reset(void);

  //! \brief Receive 1 character from RX
  template<typename T> T recv(void);
  //! \brief Transmit 1 character from TX
  template<typename T> void send(T);

  //! \brief Set the size in bits of transmitted characters
  template<int NBITS> void setNBits(void);
  //! \brief Set the baudrate
  template<typename T> void setBaudrate(const T&);

  class RecvEvent : public HardwareEvent {
    friend class Uart;

  private:
    //! \brief Default Constructor (Private)
    RecvEvent(void);
  public:
    //! \brief Enable interruption for receive complete event
    void start(void);
    //! \brief Disable interruption for receive complete event
    void stop (void);
    //! \brief Returns true if the event is activ
    bool activated(void);
  };

  class SendEvent : public HardwareEvent {
    friend class Uart;

  private:
    //! \brief Default Constructor (Private)
    SendEvent(void);
  public:
    //! \brief Enable interruption for send complete event
    void start(void);
    //! \brief Disable interruption for send complete event
    void stop (void);
    //! \brief Returns true if the event is activ
    bool activated(void);
  };

  class EmptyEvent : public HardwareEvent {
    friend class Uart;

  private:
    //! \brief Default Constructor (Private)
    EmptyEvent(void);
  public:
    //! \brief Enable interruption for empty event
    void start(void);
    //! \brief Disable interruption for empty event
    void stop (void);
    //! \brief Returns true if the event is activ
    bool activated(void);
  };

  RecvEvent& recvEvent(void);
  SendEvent& sendEvent(void);
  EmptyEvent& emptyEvent(void);

private:
  //! \brief Private Constructor (Singleton)
  Uart(void);
};

#endif//UART_HPP
