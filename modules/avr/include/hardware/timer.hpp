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

#ifndef TIMER_HPP
#define TIMER_HPP

#include <base/singleton.hpp>
#include "hardware_event.hpp"
#include "architecture.hpp"

//! \brief Interface for microcontroller's Timer/Counter
//! \param ID : The index of the Timer
template<int ID>
class Timer {
public:
  //! \brief Configure the Timer, to enable Events
  static void init(void);

  //! \brief Makes the Timer available for an other purpose
  static void reset(void);

  //! \brief Access to the counter
  //! \param T (template) : Type requested, available types are hardware-dependent
  /*!
1    Will throw a compile-time error if type is unapropriate
   */
  template<typename T> static const T& counter(void) {
    return REG(timer<ID>::counter);
  }

  template<typename T> static void setCounter(const T& val) {
    REG(timer<ID>::counter) = 
      VAL(timer<ID>::counter, val);
  }
  
  //! \brief Set the prescaler, with a value determined on compile-time
  //! \param PRESCALE (template) : the prescaler, availables values are hardware-dependent
  /*!
    Will throw a compile-time error if value is not available
   */
  template<int PRESCALE> static void setPrescaler(void) {
    // Set to ID all prescaler bits
    REG(timer<ID>::control) &= 
      ~CFG(timer<ID>::control::prescaler::mask);
    
    // Set prescaler value
    REG(timer<ID>::control) |= 
      CFG(timer<ID>::control::prescaler::template value<PRESCALE>);
  }

  //! \brief Timer Comparison Event
  //! \param EID (template) : index of the Event
  /*!
    The number of available Events depends on the timer and the microcontroller
  */
  template<int EID = 0>
  class ComparEvent : public HardwareEvent {
    friend class Timer;

  private:
    //! \brief Default Constructor (Private)
    ComparEvent(void) : HardwareEvent() {}

    //! \brief Copy Constructor (Private, must never be called)
    ComparEvent(const ComparEvent&);
    
  public:
    //! \brief Enable interruption for comprarison event
    void start(void) {
      // Enable event interrupt bit
      REG(timer<ID>::imask) |=
	CFG(timer<ID>::imask::template match<EID>);
    }

    //! \brief Disable interruption for comprarison event
    void stop (void) {
      // Disable event interrupt bit
      REG(timer<ID>::imask) &=
	~CFG(timer<ID>::imask::template match<EID>);
    }

    //! \brief Access to the comparator's value
    //! \param T (template) : Type requested, available types are hardware-dependent
    /*!
      Will throw a compile-time error if type is unappropriate
     */
    template<typename T> void setComparator(const T& val) {
      // Disable event interrupt bit
      REG(timer<ID>::template compare<EID>) =
	VAL(timer<ID>::template compare<EID>, val);
    }

    //! \brief Returns true if the event is activ
    bool activated(void);
  };

  //! \brief Timer Overflow Event
  /*!
    This event occurs when the timer's compter is at it's maximum value.
  */
  class OverflowEvent : public HardwareEvent {
    friend class Timer;
    
  private:
    //! \brief Default Constructor (Private)
    OverflowEvent(void) : HardwareEvent() {}

    //! \brief Copy Constructor (Private, must never be called)
    OverflowEvent(const OverflowEvent&);

  public:
    //! \brief Enable interruption for overflow event
    void start(void) {
      // Enable event interrupt bit
      REG(timer<ID>::imask) |=
	CFG(timer<ID>::imask::overflow);
    }

    //! \brief Disable interruption for overflow event
    void stop (void) {
      // Disable event interrupt bit
      REG(timer<ID>::imask) &=
	~CFG(timer<ID>::imask::overflow);
    }
  };

  //! \brief Get Timer's comparison event
  //! \param EID (template) : Index of the event
  template<int EID = 0> static ComparEvent<EID>& comparEvent(void) {
    static Timer<ID>::ComparEvent<EID> evt;
    return evt;
  }

  //! \brief Get Timer's overflow event
  static OverflowEvent& overflowEvent(void) {
    static Timer<ID>::OverflowEvent evt;
    return evt;
  }
 
private:
  //! \brief Private Constructor, to init singleton
  Timer(void);

  //! \brief Copy Constructor (Private, must never be called)
  Timer(const Timer&);
};

#endif//TIMER_HPP
