#ifndef TASK_HPP
#define TASK_HPP

#include <base/integer.hpp>

class Scheduler;

typedef void(*TaskFunc)(void);

//! \brief Define the period and priority of a function called by the scheduler
class Task {
  friend class Scheduler;

private:
  TaskFunc _func;
    
  u16 _period;
  u8 _priority;
  bool _unique;

public:

  //! \brief Default constructor
  Task(void) : _func(0), _unique(true) {}

  //! \brief Task constructor
  Task(TaskFunc f) : _func(f), _unique(true) {}

  //! \brief Copy Constructor
  Task(const Task& other) {
    (*this) = other;
  }

  //! \brief Copy operation
  Task& operator=(const Task& other) {
    _func = other._func;

    _period = other._period;
    _priority = other._priority;
    _unique = other._unique;
    return *this;
  }

  //! \brief Set the interval of time during two task call (in milliseconds)
  inline void setPeriod(u16 period_ms) {
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

  inline int period(void) const {
    return _period;
  }

  bool operator==(const Task& other) const {
    return _func == other._func;
  }
};

#endif//TASK_HPP
