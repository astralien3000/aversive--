#ifndef SASIAE_SCHEDULER_HPP
#define SASIAE_SCHEDULER_HPP

#include "../client_thread.hpp"
#include <container/heap.hpp>

#ifndef SCHEDULER_MAX_TASKS
#define SCHEDULER_MAX_TASKS 8
#endif

#include "../../common/system/task.hpp"

class Scheduler;

class TaskRef {
private:
  Task* _task;
  long long _origin;
public:
  TaskRef(void) : _task((Task*)0), _origin(0) {}
  TaskRef(Task& t, long long origin) : _task(&t), _origin(origin) {}

  TaskRef(const TaskRef& other) : _task(other._task), _origin(other._origin) {
  }

  TaskRef(const TaskRef& other, long long origin) : _task(other._task), _origin(origin) {
  }

  inline TaskRef& operator=(const TaskRef& other) {
    _task = other._task;
    _origin = other._origin;
    return *this;
  }

  inline bool operator==(const TaskRef& other) const {
    return _task == other._task;
  }

  inline long long nextCall(void) const {
    return _origin + _task->period();
  }
  
  inline void exec(void) {
    (*_task)();
  }

  inline bool unique(void) {
    return _task->unique();
  }

  inline void setPriority(u16 p) {
    _task->setPriority(p);
  }

  inline void setPeriod(u16 p) {
    _task->setPeriod(p);
  }

  bool operator<(const TaskRef& other) const {
    return nextCall() > other.nextCall();
  }

  bool operator>(const TaskRef& other) const {
    return nextCall() < other.nextCall();
  }
};

struct SchedulerPrivateData {
  Heap<SCHEDULER_MAX_TASKS, TaskRef> tasks;
  Array<SCHEDULER_MAX_TASKS, Task> save;
  int current;
};

#include "../../common/system/scheduler.hpp"

#endif//SASIAE_SCHEDULER_HPP
