#ifndef PIN_HPP
#define PIN_HPP

#include <device/pin/output_pin.hpp>

template<int ID>
class Pin : public OutputPin<ID> {
public:
  Pin(const char* name);
  void setValue(bool value);
  bool getValue(void);

  void setOutput(void);
  void setInput(void);
};

#endif//PIN_HPP
