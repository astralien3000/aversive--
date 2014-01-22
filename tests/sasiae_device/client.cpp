#include <aversive.hpp>
#include <device/eirbot2014/encoder.hpp>
#include <device/eirbot2014/motor.hpp>

#include <base/integer.hpp>
#include <base/singleton.hpp>

u32 ENC;
s32 MOT;

class Robot : public Singleton<Robot> {
  friend class Singleton<Robot>;

public:
  Encoder<&ENC> _id;
  Motor<&MOT> _od;

  Robot(void) : _id("intest"), _od("outtest") {}
};

bool robotInit(void) {
  (void) Robot::instance();

  //ClientThread::instance().sendMessage(ClientThread::INFO, "Send value 10 to intest to end the program");
  
  return 1;
}

void robotLoop(void) {
  if(Robot::instance()._id.getValue() == 10) {
    Aversive::stop();
  }
  return;
}

void robotExit(void) {
  Robot::instance()._od.setValue(Robot::instance()._id.getValue());
  
  return;
}
