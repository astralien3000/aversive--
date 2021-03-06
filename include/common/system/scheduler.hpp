/*
    Aversive++
    Copyright (C) 2014 Eirbot

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef SCHEDULER_HPP
#define SCHEDULER_HPP

#include <base/integer.hpp>
#include <base/singleton.hpp>

#include <container/heap.hpp>
#include <container/list.hpp>

#include <system/task.hpp>

//! \brief System to enable the robot to execute some tasks periodically, using interruptions
template<class Config>
class Scheduler : public Singleton<Scheduler<Config>> {
  friend class Singleton<Scheduler>;

  //! \brief Default Constructor (implementation dependent)
  Scheduler(void);

  //! \brief Disable interrupts
  void lock(void);

  //! \brief Cancel the effect of lock
  void unlock(void);

  //! \brief A task with more information used by the scheduler
  class PrivateTask : public Task {
  private:
    u32 _next_call;
  public:
    //! \brief Default constructor
    PrivateTask(void)
      : Task(), _next_call(0) {
    }

    //! \brief Copy constructor
    PrivateTask(const PrivateTask& other)
      : Task((Task&)other), _next_call(other._next_call) {
    }

    //! \brief Task constructor
    PrivateTask(const Task& other)
      : Task(other), _next_call(0) {
    }

    //! \brief Copy operator
    PrivateTask& operator=(const PrivateTask& other) {
      (Task&)(*this) = (const Task&)other;
      _next_call = other._next_call;
      return *this;
    }

    //! \brief Copy Task operator
    PrivateTask& operator=(const Task& other) {
      (Task&)(*this) = other;
      _next_call = 0;
    }

    //! \brief Get the next call date
    u32 nextCall(void) const {
      return _next_call;
    }

    //! \brief Add the task's period to the nextCall date
    void setNextCall(void) {
      _next_call += _period;
    }

    //! \brief Add a value to the next call date
    void setNextCall(u32 val) {
      _next_call += val;
    }

    //! \brief Return the priority of the task
    u8 priority(void) {
      return _priority;
    }
  };

  //! \brief Encapsulate the PrivateTask into an interface usable with the Heap
  class HeapElement {
    PrivateTask* _task;

  public:
    HeapElement(void)
      : _task(0) {
    }

    HeapElement(PrivateTask& tsk)
      : _task(&tsk) {
    }

    bool operator<(const HeapElement& other) {
      return _task->nextCall() > other._task->nextCall()
          || ((_task->nextCall() == other._task->nextCall())
              && (_task->priority() < other._task->priority()));
    }

    PrivateTask& task(void) const { return *_task; }
  };

  Heap<Config::MAX_TASKS, HeapElement> _heap;
  List<Config::MAX_TASKS, PrivateTask> _tasks;
  u32 _current;

  //! \brief Check if a date is anterior to the current date
  inline bool isInPast(u32 date) {
    constexpr u32 LIM = (1L << 31);
    constexpr u32 HIG = LIM + LIM / 2;
    constexpr u32 LOW = LIM - LIM / 2;

    if(_current < LOW && date > HIG) {
      return true;
    }
    else if(date < LOW && _current > HIG) {
      return false;
    }
    else {
      return date < _current;
    }
  }

  //! \brief Execute current tasks
  inline void processTasks(void) {
    lock();
    while(!_heap.isEmpty() && isInPast(_heap.max().task().nextCall())) {
      HeapElement e = _heap.max();
      e.task().operator ()();
      _heap.pop();

      if(e.task().isUnique()) {
        rmTask(e.task());
      }
      else {
        e.task().setNextCall();
        _heap.insert(e);
      }
    }
    unlock();
  }

public:
  //! \brief Add a task to execute
  void addTask(Task& tsk) {
    lock();
    if(_tasks.append(tsk)) {
      PrivateTask& ptsk = _tasks.get(_tasks.indexOf(tsk));
      ptsk.setNextCall(_current + ptsk.period());
      Scheduler::instance()._heap.insert(HeapElement(ptsk));
    }
    unlock();
  }
  
  //! \brief Remove a Task
  void rmTask(Task& tsk) {
    lock();
    if(_tasks.remove(tsk)) {
      Scheduler::instance()._heap.flush();
      _tasks.doForeach([](PrivateTask& tsk) {
        Scheduler::instance()._heap.insert(HeapElement(tsk));
      });
    }
    unlock();
  }
  
  //! \brief Return the number of slots available
  u16 freeSlot(void) const {
    return _tasks.freeSpace();
  }
};

//! \brief The default Scheduler Configuration structure
struct DefaultSchedulerConfig;

#endif//SCHEDULER_HPP
