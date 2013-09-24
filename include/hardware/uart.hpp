#ifndef UART_HPP
#define UART_HPP

//! \brief class providing routines for UART config, receiving and sending
//! \todo WHAT IS FLAGS ?!?
//! \todo Not completely defined yet...
template<int ID, int FLAGS>
class Uart {
public:
  static inline void init(void);
  static inline void quit(void);

  static inline void enable();
  static inline void disable();

  template<typename T, bool WAIT> static inline T recv(void);
  template<typename T, bool WAIT> static inline void send(T);

  template<int NBITS> static inline void setNBits(void);
  template<int BAUDRATE> static inline void setBaudrate(void);
};

#endif//UART_HPP
