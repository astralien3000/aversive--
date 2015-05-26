#ifndef INPUT_DIGITAL_PIN_HPP
#define INPUT_DIGITAL_PIN_HPP

#include <device/device.hpp>
#include <device/input.hpp>

template<int ID>
class InputDigitalPin : public Device, public Input<bool> {
protected:
  InputDigitalPin(const char* name, bool init);

public:
  InputDigitalPin(const char* name);
  bool getValue(void);
};

//////////////////////////////////////////////////////////////////////


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


#endif//INPUT_DIGITAL_PIN_HPP
