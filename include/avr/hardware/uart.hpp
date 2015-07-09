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

#ifndef UART_HPP
#define UART_HPP

#include "hardware_event.hpp"
#include "architecture.hpp"

//! \brief class providing routines for UART config, receiving and sending
//! \param ID : index of the UART
template<int ID = 0>
class Uart {
  static constexpr u32 FSOC = 16000000l;
  static constexpr u32 DIV = 16l;

public:
  //! \brief Configure Uart
  static void init(void);

  //! \brief Make UART available for an other purpose
  static void reset(void);

  //! \brief Receive 1 character from RX
  template<typename T>
  static T recv(void) {
    // Wait for data to be received
    while( ! (REG(uart<ID>::control) & CFG(uart<ID>::control::flag::recvend)));

    // Get and return received data from buffer
    return (T)REG(uart<ID>::data);
  }

  //! \brief Receive 1 character from RX
  template<typename T> 
  static void recv(T& ret) {
    // Wait for data to be received
    while( ! (REG(uart<ID>::control) & CFG(uart<ID>::control::flag::recvend)));

    // Get and return received data from buffer
    ret = (T)REG(uart<ID>::data);
  }

  //! \brief Transmit 1 character from TX
  template<typename T> 
  static void send(T val) {
    // Wait for empty transmit buffer
    while( ! (REG(uart<ID>::control) & CFG(uart<ID>::control::flag::empty)));

    // Put data into buffer
    REG(uart<ID>::data) =
      VAL(uart<ID>::data, val);
  }


  //! \brief Set the size in bits of transmitted characters
  template<int NBITS> 
  static void setNBits(void) {
    REG(uart<ID>::control) |=
      CFG(uart<ID>::control::charsize::template value<NBITS>);
  }

  //! \brief Set the baudrate
  template<typename T> 
  static void setBaudrate(const T& val) {
    unsigned long BAUD = (unsigned long)val;
    unsigned long ubrr = (FSOC / (DIV * BAUD)) - 1l;

    // Set baud rate
    REG(uart<ID>::baudrate) =
      VAL(uart<ID>::baudrate, ubrr);
  }


  class RecvEvent : public HardwareEvent {
    friend class Uart;

  private:
    //! \brief Default Constructor (Private)
    RecvEvent(void) {}

  public:
    //! \brief Enable interruption for receive complete event
    void start(void) {
      REG(uart<ID>::control) |=
	CFG(uart<ID>::control::ienable::recv);
    }
    
    //! \brief Disable interruption for receive complete event
    void stop (void) {
      REG(uart<ID>::control) &=
	~CFG(uart<ID>::control::ienable::recv);
    }

    //! \brief Returns true if the event is activ
    bool activated(void) {
      return (REG(uart<ID>::control) & CFG(uart<ID>::control::ienable::recv)) != 0;
    }
  };

  class SendEvent : public HardwareEvent {
    friend class Uart;

  private:
    //! \brief Default Constructor (Private)
    SendEvent(void) {}

  public:
    //! \brief Enable interruption for send complete event
    void start(void) {
      REG(uart<ID>::control) |=
	CFG(uart<ID>::control::ienable::send);
    }

    //! \brief Disable interruption for send complete event
    void stop (void) {
      REG(uart<ID>::control) &=
	~CFG(uart<ID>::control::ienable::send);
    }

    //! \brief Returns true if the event is activ
    bool activated(void) {
      return (REG(uart<ID>::control) & CFG(uart<ID>::control::ienable::send)) != 0;
    }
  };

  class EmptyEvent : public HardwareEvent {
    friend class Uart;

  private:
    //! \brief Default Constructor (Private)
    EmptyEvent(void) {}

  public:
    //! \brief Enable interruption for empty event
    void start(void) {
      REG(uart<ID>::control) |=
	CFG(uart<ID>::control::ienable::empty);
    }

    //! \brief Disable interruption for empty event
    void stop (void) {
      REG(uart<ID>::control) &=
	~CFG(uart<ID>::control::ienable::empty);
    }

    //! \brief Returns true if the event is activ
    bool activated(void) {
      return (REG(uart<ID>::control) & CFG(uart<ID>::control::ienable::empty)) != 0;
    }
  };

  static RecvEvent& recvEvent(void) {
    static typename Uart<ID>::RecvEvent evt;
    return evt;
  }

  static SendEvent& sendEvent(void) {
    static typename Uart<ID>::SendEvent evt;
    return evt;
  }

  static EmptyEvent& emptyEvent(void) {
    static typename Uart<ID>::EmptyEvent evt;
    return evt;
  }

private:
  //! \brief Private Constructor (Singleton)
  Uart(void);
};

#endif//UART_HPP
