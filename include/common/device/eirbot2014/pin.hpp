#ifndef PIN_HPP
#define PIN_HPP

#include <device/input.hpp>
#include <device/output.hpp>
#include <device/device.hpp>

enum class PinMode {
  INPUT,
  OUTPUT
};

template<int ID>
class Pin : public Device, public Input<bool>, public Output<bool> {
public:
  Pin(const char* name);

  bool getValue(void);
  void setValue(bool);

  void setMode(PinMode);
};

#endif//PIN_HPP
