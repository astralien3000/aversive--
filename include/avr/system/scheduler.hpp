#ifndef AVR_SCHEDULER_HPP
#define AVR_SCHEDULER_HPP

#include <base/array.hpp>
#include <container/heap.hpp>
#include <system/task.hpp>
#include <base/integer.hpp>

#define SCHEDULER_MAX_TASKS 8
#define SCHEDULER_TIMER_PRESCALER 0
#define SCHEDULER_FREQ (16000000/(256 * ((SCHEDULER_TIMER_PRESCALER) ? SCHEDULER_TIMER_PRESCALER : 1)))
#define SCHEDULER_GRANULARITY (1000000 / SCHEDULER_FREQ)

class TaskRef {
private:
  const Task* _task;
  u16 _next_call;
  const u16* _counter;
  
  inline void updateNextCall(void) {
    if(!_task) {
      _next_call = 0;
      return;
    }
    
    if(_task->period() < SCHEDULER_GRANULARITY) {
      _next_call = *_counter + 1;
    }
    else {
      _next_call = *_counter + _task->period() / SCHEDULER_GRANULARITY;
    }
  }
  
public:
  inline TaskRef(void) : _task(0), _next_call(0), _counter(0) {
  }
  
  inline TaskRef(const u16* counter) : _task(0), _next_call(0), _counter(counter) {
  }
  
  inline TaskRef(const Task& other, const u16* counter) : _task(&other), _next_call(0), _counter(counter) {
    updateNextCall();
  }
  
  inline TaskRef(const TaskRef& other) {
    *this = other;
  }

  inline TaskRef& operator=(const TaskRef& other) {
    _task = other._task;
    _next_call = other._next_call;
    _counter = other._counter;
    return *this;
  }
  
  inline bool operator==(const TaskRef& other) {
    return *_task == *(other._task);
  }
  
  inline bool operator==(const Task& other) {
    return *_task == other;
  }
  
  inline bool operator()() const {
    if(*_counter == _next_call) {
      (*_task)();
      if(_task->unique()) {
	Task* tk = const_cast<Task*>(_task);
	tk->setPeriod(0);
      }
      else {
	TaskRef* tr = const_cast<TaskRef*>(this);
	tr->updateNextCall();
      }
      return true;
    }
    else {
      return false;
    }
  }
  
  inline u32 period(void) const {
    return (_task) ? _task->period() : 0;
  }
  
  inline bool operator<(const TaskRef& other) const {
    return (_next_call - *_counter) > (other._next_call - *_counter);
  }
  
  inline bool operator>(const TaskRef& other) const {
    return (_next_call - *_counter) < (other._next_call - *_counter);
  }
};

struct SchedulerPrivateData {
  Array<SCHEDULER_MAX_TASKS, Task> tasks;
  Heap<SCHEDULER_MAX_TASKS, TaskRef> ordered_tasks;
  u16 counter;
};

#include "../../common/system/scheduler.hpp"



#endif//AVR_SCHEDULER_HPP
