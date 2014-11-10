#ifndef OUTPUT_DIGITAL_PIN_HPP
#define OUTPUT_DIGITAL_PIN_HPP

#include <device/pin/input_digital_pin.hpp>
#include <device/output.hpp>

template<int ID>
class OutputDigitalPin : public InputDigitalPin<ID>, public Output<bool> {
protected:
  OutputDigitalPin(const char* name, bool init);

public:
  OutputDigitalPin(const char* name);
  void setValue(bool value);
  bool getValue(void);

  void toggle(void);
};

/////////////////////////////////////////////////////////////////////


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


#endif//OUTPUT_DIGITAL_PIN_HPP
