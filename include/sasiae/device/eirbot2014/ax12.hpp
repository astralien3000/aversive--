#ifndef SASIAE_AX12_HPP
#define SASIAE_AX12_HPP

#include <base/integer.hpp>
#include <QString>
#include <client_thread.hpp>
#include <sstream>

enum workingMode{WHEEL,JOIN};
enum switchMode{POSITION,SPEED,TORQUE};

struct ax12PrivateData{
	u16 angle;
	u16 speed;
	u16 torque;
	workingMode wM;
	switchMode sM;
}


#include "../../../common/device/eirbot2014/ax12.hpp"

#endif//SASIAE_AX12_HPP
