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

#endif//OUTPUT_DIGITAL_PIN_HPP
