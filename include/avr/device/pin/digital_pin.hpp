#ifndef AVR_DIGITAL_PIN_HPP
#define AVR_DIGITAL_PIN_HPP

#include "../../../common/device/pin/digital_pin.hpp"

#include <hardware/pinmap.hpp>

template<int ID>
inline DigitalPin<ID>::DigitalPin(const char *name)
  : OutputDigitalPin<ID>(name, false) {
  Pinmap::Pin<ID>::setMode(Pinmap::IN);
}

template<int ID>
inline void DigitalPin<ID>::setValue(bool value) {
  if(isOutput()) {
    OutputDigitalPin<ID>::setValue(value);
  }
}

template<int ID>
inline bool DigitalPin<ID>::getValue(void) {
  return OutputDigitalPin<ID>::getValue();
}

template<int ID>
inline void DigitalPin<ID>::setInput(void) {
  Pinmap::Pin<ID>::setMode(Pinmap::IN);
}

template<int ID>
inline void DigitalPin<ID>::setOutput(void) {
  Pinmap::Pin<ID>::setMode(Pinmap::OUT);
}

template<int ID>
inline bool DigitalPin<ID>::isInput(void) {
  return Pinmap::Pin<ID>::mode() == Pinmap::IN;
}

template<int ID>
inline bool DigitalPin<ID>::isOutput(void) {
  return Pinmap::Pin<ID>::mode() == Pinmap::OUT;
}


#endif//AVR_DIGITAL_PIN_HPP
