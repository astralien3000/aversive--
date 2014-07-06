#ifndef STM32_PIN_HPP
#define STM32_PIN_HPP

#include "../../../common/device/other/pin.hpp"

#include <hardware/pinmap.hpp>

template<int ID>
inline Pin<ID>::Pin(const char* name) : Device(name) {
  Pinmap::Pin<ID>::initGpio();
}

template<int ID>
inline bool Pin<ID>::getValue(void) {
  //static_assert(ID == -1, "This is not implemented yet");
  return false;
}

template<int ID>
inline void Pin<ID>::setValue(bool val) {
  Pinmap::Pin<ID>::write(val);
}

template<int ID>
inline void Pin<ID>::setMode(PinMode m) {
  if(m == PinMode::OUTPUT) {
    Pinmap::Pin<ID>::setMode(Pinmap::OUT);
  }
  else {
    Pinmap::Pin<ID>::setMode(Pinmap::IN);
  }
}


#endif//STM32_PIN_HPP
