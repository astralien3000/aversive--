#ifndef TIMER_HPP
#define TIMER_HPP

#include "../base/singleton.hpp"

//! \brief Interface for microcontroller's Timer/Counter
//! \param ID : The index of the Timer
template<int ID>
class Timer {
public:
  //! \brief Configure the Timer, to enable Events
  static inline void init(void);
  //! \brief Makes the Timer available for an other purpose
  static inline void quit(void);

  //! \brief Access to the counter
  //! \param T (template) : Type requested, available types are hardware-dependent
  /*!
    Will throw a compile-time error if type is unapropriate
   */
  template<typename T> static inline T& counter(void);
  
  //! \brief Set the prescaler, with a value determined on compile-time
  //! \param PRESCALE (template) : the prescaler, availables values are hardware-dependent
  /*!
    Will throw a compile-time error if value is not available
   */
  template<int PRESCALE> static inline void setPrescaler(void);

  //! \brief Timer Comparison Event
  //! \param EID (template) : index of the Event
  /*!
    The number of available Events depends on the timer and the microcontroller
   */
  template<int EID = 0>
  class Event {
  public:
    //! \brief Enable interruption for coprarison event
    static inline void start(void);
    //! \brief Disable interruption for coprarison event
    static inline void stop (void);

    //! \brief Set the function to call when interruption occurs
    //! \param func : A callable object which must be convertible into a "void (function*)(void)"
    template<typename Callable>static inline void set(Callable func);

    //! \brief Access to the comparator's value
    //! \param T (template) : Type requested, available types are hardware-dependent
    /*!
      Will throw a compile-time error if type is unappropriate
     */
    template<typename T> static inline T& comparator(void);
  };
};

#endif//TIMER_HPP
