#ifndef TIMER_HPP
#define TIMER_HPP

#include "../base/singleton.hpp"

template<int ID> class TimerPrivateData;
class TimerEventPrivateData;

//! \brief Interface for microcontroller's Timer/Counter
//! \param ID : The index of the Timer
template<int ID, typename TimerImpl = TimerPrivateData<ID>>
class Timer : public Singleton<Timer<ID, TimerImpl>> {
  friend Singleton<Timer<ID, TimerImpl>>;

public:
  //! \brief Configure the Timer, to enable Events
  inline void init(void);
  //! \brief Makes the Timer available for an other purpose
  inline void quit(void);

  //! \brief Access to the counter
  //! \param T (template) : Type requested, available types are hardware-dependent
  /*!
    Will throw a compile-time error if type is unapropriate
   */
  template<typename T> inline T& counter(void);
  
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
  template<int EID = 0, typename EventImpl = TimerEventPrivateData>
  class Event {
  public:
    //! \brief Enable interruption for coprarison event
    inline void start(void);
    //! \brief Disable interruption for coprarison event
    inline void stop (void);

    //! \brief Set the function to call when interruption occurs
    //! \param func : A callable object which must be convertible into a "void (function*)(void)"
    template<typename Callable> inline void set(Callable func);

    //! \brief Access to the comparator's value
    //! \param T (template) : Type requested, available types are hardware-dependent
    /*!
      Will throw a compile-time error if type is unappropriate
     */
    template<typename T> inline void setComparator(T);

    //! \brief Returns true if the event is activ
    inline bool activated(void);

    //! \brief Calls the event function
    inline void exec(void);

  private:
    EventImpl data;
  };

  //! \brief Get Timer's event
  //! \param EID (template) : Index of the event
    template<int EID = 0> inline Event<EID>& event(void);
 
private:
  //! \brief Private Constructor, to init singleton
  Timer();

  TimerImpl data;
};

#endif//TIMER_HPP
