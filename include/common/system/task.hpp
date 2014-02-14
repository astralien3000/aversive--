#ifndef TASK_HPP
#define TASK_HPP

#include <base/integer.hpp>

typedef void(*TaskFunc)(void);

//! \brief Define the period and priority of a function called by the scheduler
class Task {
private:
  TaskFunc _func;
    
  u32 _period;
  u8 _priority;
  bool _unique;

public:

  //! \brief Default constructor
  inline Task(void) : _func(0), _period(0), _priority(0), _unique(true) {}

  //! \brief Task constructor
  inline Task(TaskFunc f) : _func(f), _period(0), _priority(0), _unique(true) {}

  //! \brief Copy Constructor
  inline Task(const Task& other) {
    (*this) = other;
  }

  //! \brief Copy operation
  inline Task& operator=(const Task& other) {
    _func = other._func;

    _period = other._period;
    _priority = other._priority;
    _unique = other._unique;
    return *this;
  }

  //! \brief Set the interval of time during two task call (in milliseconds)
  inline void setPeriod(u32 period_ms) {
    _period = period_ms;
  }

  //! \brief Set the priority of the task
  /*!

    If two tasks may be executed at the same time, the first to be
    called is the one with the greatest priority
      
  */
  inline void setPriority(u8 priority) {
    _priority = priority;
  }

  //! \brief Enable periodicity
  inline void setRepeat(void) {
    _unique = false;
  }

  //! \brief Disable periodicity, the task will be removed once executed
  inline void setUnique(void) {
    _unique = true;
  }

  inline u32 period(void) const {
    return _period;
  }

  inline bool unique(void) const {
    return _unique;
  }

  inline bool operator==(const Task& other) const {
    return _func == other._func;
  }

  inline void operator()(void) const {
    if(_func) {
      _func();
    }
  }
};

#endif//TASK_HPP
