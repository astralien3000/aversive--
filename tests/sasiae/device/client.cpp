#include <aversive.hpp>
#include <device/eirbot2014/encoder.hpp>
#include <device/eirbot2014/motor.hpp>

#include <base/integer.hpp>
#include <base/singleton.hpp>

u32 ENC;
s32 MOT;

Encoder<&ENC> _id("intest");
Motor<&MOT> _od("outtest");

bool robotInit(void) {
  //ClientThread::instance().sendMessage(ClientThread::INFO, "Send value 10 to intest to end the program");
  
  return 1;
}

void robotLoop(void) {
  if(_id.getValue() == 10) {
    Aversive::stop();
  }
  return;
}

void robotExit(void) {
  _od.setValue(_id.getValue());
  
  return;
}
