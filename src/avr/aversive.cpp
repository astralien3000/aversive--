#include <aversive.hpp>
#include <stdlib.h>

static bool keep_going;

inline bool aversiveInit(int argc, char** argv) {
  (void) argc;
  (void) argv;
  keep_going = true;
  return true;
}

void Aversive::sleep(int ms) {
  (void) ms;
  return;
}

void Aversive::stop(void) {
  keep_going = false;
}

inline void aversiveExit(void) {
  Aversive::stop();
  keep_going = false;
  return;
}

int main(int argc, char** argv) {
  if(!aversiveInit(argc, argv)) {
    return 1;
  }
 
  if(!robotInit()) {
    return 1;
  }
  
  while(keep_going) {
    robotLoop();
    Aversive::sleep(0);
  }
  
  robotExit();
  aversiveExit();
  return 0;
}
