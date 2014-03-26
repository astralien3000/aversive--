#ifndef SASIAE_AX12_HPP
#define SASIAE_AX12_HPP

#include <base/integer.hpp>
#include <QStringList>
#include <QString>
#include <client_thread.hpp>
#include <sstream>

struct AX12PrivateData{
  u16 angle;
  u16 speed;
  u16 torque;
  WorkingMode wm;
  ComMode cm;
};

#include "../../../common/device/eirbot2014/ax12.hpp"

#endif//SASIAE_AX12_HPP
