#include <aversive.hpp>
#include <client_thread.hpp>
#include <device/device.hpp>

#include <functional>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <QThread>

#include <device/eirbot2014/gp2.hpp>
#include <assert.h>
#include <unistd.h>

GP2<5> can1;
GP2<4> can2;


bool robotInit(void) {
	can1=gp2("CAN1");
	can2=gp2("CAN2");
	return true;
}

void robotLoop(void) {
	assert(can1.getValue()==42);
	assert(can2.getValue()==51);
	assert(can1.getValue()==22);
  return;
}

void robotExit(void) {
  return;
}
