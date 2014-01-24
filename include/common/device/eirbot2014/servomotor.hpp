#ifndef SERVOMOTOR_HPP
#define SERVOMOTOR_HPP

#include <device/output_device.hpp>
#include "../../base/integer.hpp"

//! \brief A servomotor INTERFACE, used by Eirbot in 2014. Can not be used (see ServomotorFpga or ServomotorPin).


class Servomotor : public OutputDevice<u32> {
public:
  Servomotor(const char*);

  void setValue(u32);
};

#endif//SERVOMOTOR_HPP

