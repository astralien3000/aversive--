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

#endif//DIGITAL_PIN_HPP
