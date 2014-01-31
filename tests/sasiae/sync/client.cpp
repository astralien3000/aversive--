#include <aversive.hpp>
#include <client_thread.hpp>
#include <device/device.hpp>

static Device d("TESTER");
static int i = 0;
static char buffer[80];

bool robotInit(void) {
  return true;
}

void robotLoop(void) {
  sprintf(buffer, "value is %d", i++);
  ClientThread::instance().sendDeviceMessage(d, buffer);
  return;
}

void robotExit(void) {
  return;
}
