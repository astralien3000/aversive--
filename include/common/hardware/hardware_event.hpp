#ifndef HARDWARE_EVENT_HPP
#define HARDWARE_EVENT_HPP

class HardwareEvent {
private:
  void (*_func)(void);

protected:
  //! \brief Default Constructor
  inline HardwareEvent(void) : _func(0) {}

public:
  //! \brief Set the function to call when interruption occurs
  //! \param func : A callable object which must be convertible into a "void (function*)(void)"
  template<typename Callable> inline void setFunction(Callable func) {
    _func = static_cast< void (*)(void) >(func);
  }

  //! \brief Unset the function to call when interruption occurs
  inline void unsetFunction(void) {
    _func = 0;
  }
  
  //! \brief Execute the function (only if there is one, of course)
  inline void execFunction(void) {
    if(_func) {
      _func();
    }
  }

  //! \brief Enable interruption for overflow event
  inline void start(void);
  //! \brief Disable interruption for overflow event
  inline void stop (void);

  //! \brief Returns true if the event is activ
  inline bool activated(void);
};

#endif//HARDWARE_EVENT_HPP