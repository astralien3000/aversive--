#include <system/scheduler.hpp>

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
	    //tsk.setPeriod(0);
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
