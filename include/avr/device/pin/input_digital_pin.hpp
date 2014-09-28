#ifndef AVR_INPUT_PIN_HPP
#define AVR_INPUT_PIN_HPP

#include "../../../common/device/pin/input_digital_pin.hpp"

#include <hardware/pinmap.hpp>

template<int ID>
inline InputDigitalPin<ID>::InputDigitalPin(const char *name, bool init)
  : Device(name) {
  (void) init;
}

template<int ID>
inline InputDigitalPin<ID>::InputDigitalPin(const char *name)
  : InputDigitalPin(name, false) {
  Pinmap::Pin<ID>::setMode(Pinmap::IN);
}

template<int ID>
inline bool InputDigitalPin<ID>::getValue(void) {
  return Pinmap::Pin<ID>::read();
}

#endif//AVR_INPUT_PIN_HPP
