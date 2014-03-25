#ifndef SASIAE_MOTOR_HPP
#define SASIAE_MOTOR_HPP

#include "../../../common/device/eirbot2014/motor.hpp"

#include <aversive.hpp>
#include <client_thread.hpp>

#include <sstream>

template<typename T>
Motor<T>::Motor(const char* name, T* addr)
  : Device(name), _addr(addr) {
  Aversive::init();

  ClientThread::instance().
    registerDevice(*this,
		   std::function<void(char*)>([&] (char*) mutable -> void {}));
}

template<typename T>
void Motor<T>::setValue(s32 val) {
  std::ostringstream oss;
  oss << "value " << ((double)val)/128.;

  ClientThread::instance().
    sendDeviceMessage(*this, 
		      oss.str().c_str());
}


#endif//SASIAE_MOTOR_HPP
