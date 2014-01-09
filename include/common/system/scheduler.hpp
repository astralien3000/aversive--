#ifndef SCHEDULER_HPP
#define SCHEDULER_HPP

#include "../base/integer.hpp"
#include "../base/singleton.hpp"

typedef void(*TaskFunc)(void);

class Scheduler : public Singleton<Scheduler> {
  friend class Singleton<Scheduler>;

public:
  class Task {
  public:
    Task(TaskFunc f);

    inline void setPeriod(u16 period_unit);
    inline void setPriority(u8 priority);
    inline void setRepeat(void);
    inline void setUnique(void);
  };
  
  Scheduler(void);

  void addTask(Task& tsk);
  void rmTask(Task& tsk);
};

#endif//SCHEDULER_HPP
