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

#include <system/scheduler.hpp>

#include <aversive.hpp>

Scheduler::Scheduler(void) {
  Aversive::init();
  _data.current = 0;

  ClientThread::instance().setSyncFunction([&](long long t){
      _data.current = t;

      if(!_data.tasks.isEmpty()) {
	TaskRef tsk = _data.tasks.max();

	while(!_data.tasks.isEmpty() && _data.current > tsk.nextCall()) {

	
	  _data.tasks.pop();
	  tsk.exec();

	  if(!tsk.unique()) {
	    //tsk.setPeriod(0);
	    _data.tasks.insert(TaskRef(tsk, tsk.nextCall()));
	  }

	  if(!_data.tasks.isEmpty()) {
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
