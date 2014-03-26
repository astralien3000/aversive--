#ifndef SASIAE_RDS_HPP
#define SASIAE_RDS_HPP


#include "../../../common/device/eirbot2014/rds.hpp"

#include <aversive.hpp>
#include <client_thread.hpp>
#include <sstream>

Rds::Rds(const char* name) : Device(name) {
  ClientThread::instance().registerDevice(*this, std::function<void(char*)>([this] (char* msg) mutable -> void {
	using namespace std;
	istringstream iss(msg);
	string cmd;
	int n;
	iss >> cmd >> n;
	
	_values.flush();
	for(int i = 0 ; i < n ; i++) {
	  Vect<2, s32> v;
	  iss >> v.coord(0) >> v.coord(1);
	  _values.append(v);
	}
      }));
}

void Rds::setMode(Mode m) {
  if(m == CARTESIAN) {
    ClientThread::instance().sendDeviceMessage(*this, "mode cartesian");
  }
  else if(m == POLAR) {
    ClientThread::instance().sendDeviceMessage(*this, "mode polar");
  }
}

List<2, Vect<2, s32> > Rds::getValue(void) {
  return this->_values;
}

#endif//SASIAE_RDS_HPP
