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

#ifndef SASIAE_SCHEDULER_HPP
#define SASIAE_SCHEDULER_HPP

#include <client_thread.hpp>
#include <container/heap.hpp>

//#ifndef SCHEDULER_MAX_TASKS
//#define SCHEDULER_MAX_TASKS 8
//#endif

#include "../../common/system/task.hpp"

//class Scheduler;

//class TaskRef {
//private:
//  Task* _task;
//  long long _origin;
//public:
//  TaskRef(void) : _task((Task*)0), _origin(0) {}
//  TaskRef(Task& t, long long origin) : _task(&t), _origin(origin) {}

//  TaskRef(const TaskRef& other) : _task(other._task), _origin(other._origin) {
//  }

//  TaskRef(const TaskRef& other, long long origin) : _task(other._task), _origin(origin) {
//  }

//  inline TaskRef& operator=(const TaskRef& other) {
//    _task = other._task;
//    _origin = other._origin;
//    return *this;
//  }

//  inline bool operator==(const TaskRef& other) const {
//    return _task == other._task;
//  }

//  inline long long nextCall(void) const {
//    return _origin + _task->period();
//  }
  
//  inline void exec(void) {
//    (*_task)();
//  }

//  inline bool unique(void) {
//    return _task->unique();
//  }

//  inline void setPriority(u16 p) {
//    _task->setPriority(p);
//  }

//  inline void setPeriod(u16 p) {
//    _task->setPeriod(p);
//  }

//  bool operator<(const TaskRef& other) const {
//    return nextCall() > other.nextCall();
//  }

//  bool operator>(const TaskRef& other) const {
//    return nextCall() < other.nextCall();
//  }
//};

//struct SchedulerPrivateData {
//  Heap<SCHEDULER_MAX_TASKS, TaskRef> tasks;
//  Array<SCHEDULER_MAX_TASKS, Task> save;
//  int current;
//};

#include "../../common/system/scheduler.hpp"

struct DefaultSchedulerConfig {
  static constexpr u32 MAX_TASKS = 8;
};

template<class Config>
struct Scheduler<Config>::PrivateData {
  Heap<Config::MAX_TASKS, Task*> heap;
  Array<Config::MAX_TASKS, Task> tasks;
  u32 current;
};

template<class Config>
Scheduler<Config>::Scheduler(void) {
//  Aversive::init();
//  _data.current = 0;

//  ClientThread::instance().setSyncFunction([&](long long t){
//      _data.current = t;

//      if(!_data.tasks.isEmpty()) {
//	TaskRef tsk = _data.tasks.max();

//	while(!_data.tasks.isEmpty() && _data.current > tsk.nextCall()) {


//	  _data.tasks.pop();
//	  tsk.exec();

//	  if(!tsk.unique()) {
//	    //tsk.setPeriod(0);
//	    _data.tasks.insert(TaskRef(tsk, tsk.nextCall()));
//	  }

//	  if(!_data.tasks.isEmpty()) {
//	    tsk = _data.tasks.max();
//	  }
//	}
//      }
//    });
}

template<class Config>
bool Scheduler<Config>::addTask(Task& task) {
  (void)task;
//  for(int i = 0 ; i < SCHEDULER_MAX_TASKS ; i++) {
//    if(_data.save[i].period() == 0) {
//      _data.save[i] = task;
//      _data.tasks.insert(TaskRef(_data.save[i], _data.current));
//      return true;
//    }
//  }
  return false;
}

template<class Config>
bool Scheduler<Config>::rmTask(Task& task) {
//  for(int i = 0 ; i < SCHEDULER_MAX_TASKS ; i++) {
//    if(_data.save[i] == task) {
//      _data.save[i] = Task();
//      return true;
//    }
//  }
  return false;
}


#endif//SASIAE_SCHEDULER_HPP
