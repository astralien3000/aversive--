#include <aversive.hpp>

static bool initialized = false;
static bool running = false;
static int ret = 0;

extern "C" void __cxa_pure_virtual(void) {
  while(1);
}

void Aversive::init(void) {
  if(!initialized) {
    running = initialized = true;
  }
}

bool Aversive::sync(void) {
  return Aversive::isRunning();
}

void Aversive::sleep(int ms) {
  (void) ms;
}

void Aversive::stop(void) {
  running = false;
}

int Aversive::exit(void) {
  Aversive::stop();
  return ret;
}

bool Aversive::isInitialized(void) {
  return initialized;
}

bool Aversive::isRunning(void) {
  return running;
}

int Aversive::returnCode(void) {
  return ret;
}

void Aversive::setReturnCode(int returnCode) {
  ret = returnCode;
}
