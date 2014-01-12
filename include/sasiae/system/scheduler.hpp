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
  friend class Scheduler;

private:
  Task _task;
  long long _origin;
public:
  TaskRef(void) : _origin(0) {}
  TaskRef(const Task& t, long long origin) : _task(t), _origin(origin) {}

  TaskRef(const TaskRef& other) : _task(other._task), _origin(other._origin) {
  }

  TaskRef& operator=(const TaskRef& other) {
    _task = other._task;
    _origin = other._origin;
    return *this;
  }

  bool operator==(const TaskRef& other) const {
    return _task == other._task;
  }

  bool operator<(const TaskRef& other) const {
    return _origin + _task.period() > other._origin + other._task.period();
  }

  bool operator>(const TaskRef& other) const {
    return _origin + _task.period() < other._origin + other._task.period();
  }
};

struct SchedulerPrivateData {
  Heap<SCHEDULER_MAX_TASKS, TaskRef> tasks;
  int current;
};

#include "../../common/system/scheduler.hpp"

Scheduler::Scheduler(void) {
  _data.current = 0;

  ClientThread::instance().setSyncFunction([&](long long t){
      _data.current = t;

      TaskRef tsk = _data.tasks.max();

      while(!_data.tasks.empty() && _data.current > tsk._origin + tsk._task._period) {
	_data.tasks.pop();
	if(tsk._task._func) {
	  tsk._task._func();
	}

	tsk._origin += tsk._task._period;

	if(!tsk._task._unique) {
	  _data.tasks.insert(tsk);
	}

	if(!_data.tasks.empty()) {
	  tsk = _data.tasks.max();
	}
      }
    });
}

void Scheduler::addTask(Task& task) {
  _data.tasks.insert(TaskRef(task, _data.current));
}



#endif//SASIAE_SCHEDULER_HPP
