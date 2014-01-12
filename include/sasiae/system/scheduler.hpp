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

  TaskRef& operator=(const TaskRef& other) {
    _task = other._task;
    _origin = other._origin;
    return *this;
  }

  bool operator==(const TaskRef& other) const {
    return _task == other._task;
  }

  long long nextCall(void) const {
    return _origin + _task->period();
  }
  
  void exec(void) {
    _task->exec();
  }

  bool unique(void) {
    return _task->unique();
  }

  void setPriority(u16 p) {
    _task->setPriority(p);
  }

  void setPeriod(u16 p) {
    _task->setPriority(p);
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

Scheduler::Scheduler(void) {
  _data.current = 0;

  ClientThread::instance().setSyncFunction([&](long long t){
      _data.current = t;

      if(!_data.tasks.empty()) {
	TaskRef tsk = _data.tasks.max();

	while(!_data.tasks.empty() && _data.current > tsk.nextCall()) {

	
	  _data.tasks.pop();
	  tsk.exec();

	  if(!tsk.unique()) {
	    tsk.setPeriod(0);
	    _data.tasks.insert(TaskRef(tsk, tsk.nextCall()));
	  }

	  if(!_data.tasks.empty()) {
	    tsk = _data.tasks.max();
	  }
	}
      }
    });
}

bool Scheduler::addTask(Task& task) {
  for(int i = 0 ; i < SCHEDULER_MAX_TASKS ; i++) {
    if(_data.save[i].period() == 0) {
      _data.save[i] = task;
      _data.tasks.insert(TaskRef(_data.save[i], _data.current));
      return true;
    }
  }
  return false;
}

bool Scheduler::rmTask(Task& task) {
  for(int i = 0 ; i < SCHEDULER_MAX_TASKS ; i++) {
    if(_data.save[i] == task) {
      _data.save[i] = Task();
      return true;
    }
  }
  return false;
}



#endif//SASIAE_SCHEDULER_HPP
