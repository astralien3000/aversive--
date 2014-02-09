#ifndef SASIAE_RDS_HPP
#define SASIAE_RDS_HPP


#include "../../../common/device/eirbot2014/rds.hpp"
#include <client_thread.hpp>


template<int CHANNEL>
Rds<CHANNEL>::Rds(void) : {
  Aversive::init();
  
  ClientThread::instance().registerDevice(*this, std::function<void(char*)>([this] (char* msg) mutable -> void {
	if (strncmp(msg, "values ", 7)) {
	  ClientThread::instance().sendMessage(ERROR, "RDS device : invalid message (\"values\" expected)");
	  return:
	}
	msg += 7;
	char* nmsg;
	int16_t n = strtol(msg, &nmsg, 10);
	this->_values[0] = n;
	for (int i = 1; i <= n*2; i++) {
	  if (nmsg[0] == '\0') {
	    ClientThread::instance().sendMessage(ERROR, "RDS device : invalid size of argument array");
	    break;
	  }
	  this->_values[i] = strtol(nmsg + 1, &nmsg, 10);
	}
      }));
}

template<int CHANNEL>
void Rds<CHANNEL>::setModeCartesian(void) {
  ClientThread::instance().sendDeviceMessage(*this, "mode cartesian");
}

template<int CHANNEL>
void Rds<CHANNEL>::setModePolar(void) {
  ClientThread::instance().sendDeviceMessage(*this, "mode polar");
}

template<int CHANNEL>
const Array<13, int16_t>& Rds<CHANNEL>::getPositions(void) const {
  return _values;
}


#endif//SASIAE_RDS_HPP
