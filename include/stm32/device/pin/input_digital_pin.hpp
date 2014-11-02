#ifndef STM32_INPUT_DIGITAL_PIN_HPP
#define STM32_INPUT_DIGITAL_PIN_HPP

#include "../../../common/device/pin/input_digital_pin.hpp"

#include <hardware/pinmap.hpp>

template<int ID>
inline InputDigitalPin<ID>::InputDigitalPin(const char *name, bool init)
  : Device(name) {
  (void) init;
  Pinmap::Pin<ID>::initGpio();
}

template<int ID>
inline InputDigitalPin<ID>::InputDigitalPin(const char *name)
  : InputDigitalPin(name, false) {
  Pinmap::Pin<ID>::setMode(Pinmap::IN);
}

template<int ID>
inline bool InputDigitalPin<ID>::getValue(void) {
  // TODO
#warning "This method is not implemented"
  return false;
}


#endif//STM32_INPUT_DIGITAL_PIN_HPP
