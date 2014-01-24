#ifndef SERVOMOTOR_PIN_HPP
#define SERVOMOTOR_PIN_HPP

#include <device/eirbot2014/servomotor.hpp>


//! \brief A servomotor, used by Eirbot in 2014
//! \param PORT : the port (1, 2, etc) where the servo is plugged
//! \param PIN : the number of the pin (1, 2, etc)

template<u8 PORT, u8 PIN>
class ServomotorPin : public Servomotor {
public:
  ServomotorPin(const char*);

  void setValue(u32);
};



#endif//SERVOMOTOR_PIN_HPP
