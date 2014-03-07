#include <system/scheduler.hpp>
#include <hardware/interrupts.hpp>
#include <hardware/timer.hpp>

static const int SCHEDULER_TIMER_ID = 0;

static const u32 SCHEDULER_TIMER_PRESCALER =  8;
static const u32 SCHEDULER_FREQ = (16000000/(256 * ((SCHEDULER_TIMER_PRESCALER) ? SCHEDULER_TIMER_PRESCALER : 1)));
static const u32 SCHEDULER_GRANULARITY = (1000000 / SCHEDULER_FREQ);

// Work around because of GCC's bug asking for "this" to be captured in lambda while you are just accessing a static method
inline Scheduler& sched_instance(void) {
  return Scheduler::instance();
}

#include <device/stream/uart_stream.hpp>

UartStream<0> test(0);

Scheduler::Scheduler(void) {
  _data.current = 0;
  Timer<SCHEDULER_TIMER_ID>& t = Timer<SCHEDULER_TIMER_ID>::instance();
  t.init();
  t.setPrescaler<SCHEDULER_TIMER_PRESCALER>();
  t.overflowEvent().setFunction([](void){
      Interrupts::lock();
      Scheduler& s = sched_instance();
      s._data.current++;
      if(!s._data.ordered_tasks.empty()) {
	TaskRef tsk = s._data.ordered_tasks.max();

	while(!s._data.ordered_tasks.empty() && s._data.current > tsk.nextCall()) {
	  s._data.ordered_tasks.pop();
	  //test << s._data.current << " ; next : " << tsk.nextCall() << "\n\r";
	  tsk.exec();
	  
	  if(!tsk.unique()) {
	    s._data.ordered_tasks.insert(TaskRef(tsk, tsk.nextCall()));
	  }

	  if(!s._data.ordered_tasks.empty()) {
	    tsk = s._data.ordered_tasks.max();
	  }
	  
	}
      }
      Interrupts::unlock();
    });
  t.overflowEvent().start();
}

bool Scheduler::addTask(Task& t) {
  if(!freeSlot()) {
    return false;
  }
  
  Interrupts::lock();
  for(u16 i = 0; i < SCHEDULER_MAX_TASKS; i++) {
    if(_data.tasks[i].period() == 0) {
      _data.tasks[i] = t;
      _data.tasks[i].setPeriod(_data.tasks[i].period()/SCHEDULER_GRANULARITY);
      _data.ordered_tasks.insert(TaskRef(_data.tasks[i], _data.current));
      Interrupts::unlock();
      return true;
    }
  }
  Interrupts::unlock();
  return false;
}

bool Scheduler::rmTask(Task& t) {
  Interrupts::lock();
  for(u16 i = 0; i < SCHEDULER_MAX_TASKS; i++) {
    if(_data.tasks[i] == t) {
      _data.tasks[i] = Task();
      Interrupts::unlock();
      return true;
    }
  }
  Interrupts::unlock();
  return false;
}

u16 Scheduler::freeSlot(void) const {
  return (u16) _data.ordered_tasks.freeSpace();
}
