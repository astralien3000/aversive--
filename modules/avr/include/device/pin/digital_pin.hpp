#ifndef DIGITAL_PIN_HPP
#define DIGITAL_PIN_HPP

#include <device/pin/output_digital_pin.hpp>

template<int ID>
class DigitalPin : public OutputDigitalPin<ID> {
public:
  DigitalPin(const char* name);
  void setValue(bool value);
  bool getValue(void);

  void setOutput(void);
  void setInput(void);

  bool isOutput(void);
  bool isInput(void);
};

/////////////////////////////////////////////////////////////////////////

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

#endif//DIGITAL_PIN_HPP
