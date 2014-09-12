#ifndef OUTPUT_PIN_HPP
#define OUTPUT_PIN_HPP

#include <device/pin/input_pin.hpp>
#include <device/output.hpp>

template<int ID>
class OutputPin : public InputPin<ID>, public Output<bool> {
protected:
  OutputPin(const char* name, bool init);

public:
  OutputPin(const char* name);
  void setValue(bool value);
  bool getValue(void);
};

#endif//OUTPUT_PIN_HPP
