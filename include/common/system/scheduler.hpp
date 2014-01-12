#ifndef SCHEDULER_HPP
#define SCHEDULER_HPP

#include "../base/integer.hpp"
#include "../base/singleton.hpp"

#include "../base/array.hpp"

#include "task.hpp"

#ifndef SCHEDULER_MAX_TASKS
#define SCHEDULER_MAX_TASKS 8
#endif

//! \brief System to enable the robot to execute some tasks periodically, using interruptions
class Scheduler : public Singleton<Scheduler> {
  friend class Singleton<Scheduler>;

public:
  //! \brief Default Constructor
  Scheduler(void);

  //! \brief Add a task to execute
  void addTask(Task& tsk);
  
  //! \brief Remove manually a task (tasks can be removed by the scheduler when they won't be called anymore)
  void rmTask(Task& tsk);


private:
  SchedulerPrivateData _data;
};

#endif//SCHEDULER_HPP
