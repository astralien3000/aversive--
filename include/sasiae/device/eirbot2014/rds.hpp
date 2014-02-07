#ifndef SASIAE_RDS_HPP
#define SASIAE_RDS_HPP


#include "../../../common/device/eirbot2014/rds.hpp"
#include <client_thread.hpp>


Rds::Rds(const char* name) : InputDevice<Array<6, Vect<2, int16_t> > > (name) {
  ClientThread::instance().registerDevice(*this, std::function<void(char*)>([this] (char* msg) mutable -> void {
	if (strncmp(msg, "values ", 7)) {
	  ClientThread::instance().sendMessage(ClientThread::ERROR, "RDS device : invalid message (\"values\" expected)");
	  return;
	}
	msg += 7;
	char* nmsg;
	int16_t n = strtol(msg, &nmsg, 10);
	this->_nb = n;
	Vect<2, int16_t> tmp;
	for (int i=0; i<n; i++) {
	  for (int j=0; j<2; j++) {
	    if (nmsg[0] == '\0') {
	      ClientThread::instance().sendMessage(ClientThread::ERROR, "RDS device : invalid size of argument array");
	      break;
	    }
	    tmp.coord(j) = (int16_t) strtol(nmsg + 1, &nmsg, 10);
	  }
	  this->_pos[i] = tmp;
	}
      }));
}

void Rds::setModeCartesian(void) {
  ClientThread::instance().sendDeviceMessage(*this, "mode cartesian");
}

void Rds::setModePolar(void) {
  ClientThread::instance().sendDeviceMessage(*this, "mode polar");
}

const Vect<2, int16_t>& Rds::getPosition(uint8_t index) const {
  return this->_pos[index];
}

uint8_t Rds::robotsNumber(void) const {
  return this->_nb;
}

#endif//SASIAE_RDS_HPP
