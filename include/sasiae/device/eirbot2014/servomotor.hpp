#ifndef SASIAE_SERVOMOTOR_HPP
#define SASIAE_SERVOMOTOR_HPP

#include "../../../common/device/eirbot2014/servomotor.hpp"

#include <aversive.hpp>
#include <client_thread.hpp>
#include <sstream>

Servomotor::Servomotor(const char* name)
  : Device(name),
    _min(0), _max(0) {

  ClientThread::instance().
    registerDevice(*this,
		   std::function<void(char*)>([&] (char*) mutable -> void {}));
}

void Servomotor::setValue(u32 val) {
  std::ostringstream oss;
  double sasiae_val = 0;
  if(_max - _min) {
    sasiae_val = (((double)val) - _min)/(_max - _min);
  }
  oss << "value " << sasiae_val;

  ClientThread::instance().
    sendDeviceMessage(*this, 
		      oss.str().c_str());
}

#endif//SASIAE_SERVOMOTOR_HPP
