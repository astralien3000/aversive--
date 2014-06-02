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

#ifndef AVR_SCHEDULER_HPP
#define AVR_SCHEDULER_HPP

#include <base/array.hpp>
#include <container/heap.hpp>
#include <system/task.hpp>
#include <base/integer.hpp>

#define SCHEDULER_MAX_TASKS 8

#include <system/task.hpp>

class Scheduler;

class TaskRef {
private:
  Task* _task;
  u32 _origin;
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

  inline u32 nextCall(void) const {
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
  Array<SCHEDULER_MAX_TASKS, Task> tasks;
  Heap<SCHEDULER_MAX_TASKS, TaskRef> ordered_tasks;
  u32 current;
};

#include "../../common/system/scheduler.hpp"



#endif//AVR_SCHEDULER_HPP
