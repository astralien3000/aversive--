#ifndef TIMER_HPP
#define TIMER_HPP

#include "../base/singleton.hpp"

#include "hardware_event.hpp"

//! \brief Interface for microcontroller's Timer/Counter
//! \param ID : The index of the Timer
template<int ID>
class Timer : public Singleton< Timer<ID> > {
  friend class Singleton< Timer<ID> >;

public:
  //! \brief Configure the Timer, to enable Events
  inline void init(void);
  //! \brief Makes the Timer available for an other purpose
  inline void reset(void);

  //! \brief Access to the counter
  //! \param T (template) : Type requested, available types are hardware-dependent
  /*!
    Will throw a compile-time error if type is unapropriate
   */
  template<typename T> inline const T& counter(void);

  template<typename T> inline void setCounter(const T&);
  
  //! \brief Set the prescaler, with a value determined on compile-time
  //! \param PRESCALE (template) : the prescaler, availables values are hardware-dependent
  /*!
    Will throw a compile-time error if value is not available
   */
  template<int PRESCALE> inline void setPrescaler(void);

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
    inline ComparEvent(void);
    
  public:
    //! \brief Enable interruption for coprarison event
    inline void start(void);
    //! \brief Disable interruption for coprarison event
    inline void stop (void);

    //! \brief Access to the comparator's value
    //! \param T (template) : Type requested, available types are hardware-dependent
    /*!
      Will throw a compile-time error if type is unappropriate
     */
    template<typename T> inline void setComparator(const T&);

    //! \brief Returns true if the event is activ
    inline bool activated(void);
  };

  //! \brief Timer Overflow Event
  /*!
    This event occurs when the timer's compter is at it's maximum value.
  */
  class OverflowEvent : public HardwareEvent {
  public:
  };

  //! \brief Get Timer's comparison event
  //! \param EID (template) : Index of the event
  template<int EID = 0> inline ComparEvent<EID>& comparEvent(void);

  //! \brief Get Timer's overflow event
  inline OverflowEvent& overflowEvent(void);
 
private:
  //! \brief Private Constructor, to init singleton
  Timer();

  struct PrivateData;
  PrivateData data;
};

#endif//TIMER_HPP
