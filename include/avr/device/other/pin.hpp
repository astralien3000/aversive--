#ifndef AVR_PIN_HPP
#define AVR_PIN_HPP

#include "../../../common/device/other/pin.hpp"

#include <hardware/pinmap.hpp>

template<int ID>
inline Pin<ID>::Pin(const char* name) : Device(name) {}

template<int ID>
inline bool Pin<ID>::getValue(void) {
  return Pinmap::instance().pin<ID>().read();
}

template<int ID>
inline void Pin<ID>::setValue(bool val) {
  if(Pinmap::instance().pin<ID>().mode() == Pinmap::OUT) {
    Pinmap::instance().pin<ID>().write(val);
  }
}

template<int ID>
inline void Pin<ID>::setMode(PinMode m) {
  if(m == PinMode::OUTPUT) {
    Pinmap::instance().pin<ID>().setMode(Pinmap::OUT);
  }
  else {
    Pinmap::instance().pin<ID>().setMode(Pinmap::IN);
  }
}

#endif//AVR_PIN_HPP
