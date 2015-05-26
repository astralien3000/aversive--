#ifndef STM32_OUTPUT_DIGITAL_PIN_HPP
#define STM32_OUTPUT_DIGITAL_PIN_HPP

#include <device/pin/output_digital_pin.hpp>

#include <hardware/pinmap.hpp>

template<int ID>
inline OutputDigitalPin<ID>::OutputDigitalPin(const char *name, bool init)
  : InputDigitalPin<ID>(name, init) {
}

template<int ID>
inline OutputDigitalPin<ID>::OutputDigitalPin(const char *name)
  : OutputDigitalPin<ID>(name, false) {
  Pinmap::Pin<ID>::setMode(Pinmap::OUT);
}

template<int ID>
inline void OutputDigitalPin<ID>::setValue(bool value) {
  Pinmap::Pin<ID>::write(value);
}

template<int ID>
inline bool OutputDigitalPin<ID>::getValue(void) {
  return InputDigitalPin<ID>::getValue();
}

template<int ID>
inline void OutputDigitalPin<ID>::toggle(void) {
  setValue(!getValue());
}

#endif//STM32_OUTPUT_DIGITAL_PIN_HPP
