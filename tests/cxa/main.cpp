/*
  This is the minimal code that would not link if __cxa functions are not defined.
  It would also not compile if __cxa functions have not the attribute "weak", if REDEFINE_CXA is defined.
 */

#include <aversive.hpp>
#include <system/scheduler.hpp>

#ifdef REDEFINE_CXA
extern "C" {
int __cxa_guard_acquire(int *)   {while(1); return 0;}
void __cxa_guard_release (int *) {while(1);}
void __cxa_guard_abort (int *)   {while(1);}
void __cxa_pure_virtual(void)    {while(1);}
}
#endif

int main(int argc, char** argv) {
  (void) argc;
  (void) argv;
  Aversive::init();

  Scheduler& sched = Scheduler::instance();
  (void) sched;

  return 0;
}
