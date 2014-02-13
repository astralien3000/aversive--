#ifndef SCHEDULER_HPP
#define SCHEDULER_HPP

#include <base/integer.hpp>
#include <base/singleton.hpp>

#include <base/array.hpp>

#include <system/task.hpp>

#ifndef SCHEDULER_MAX_TASKS
#define SCHEDULER_MAX_TASKS 8
#endif

//! \brief System to enable the robot to execute some tasks periodically, using interruptions
class Scheduler : public Singleton<Scheduler> {
  friend class Singleton<Scheduler>;
  
  //! \brief Default Constructor
  Scheduler(void);
  
public:
  //! \brief Add a task to execute
  bool addTask(Task& tsk);
  
  //! \brief Remove a Task, it won't be executed anymore
  //! \warning The Task data is only removed from the scheduler at the next scheduler update, so you are not sure to be able to add a Task after that
  bool rmTask(Task& tsk);
  
  u16 freeSlot(void) const;
  
private:
  SchedulerPrivateData _data;
};

#endif//SCHEDULER_HPP
