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

#endif//INPUT_DIGITAL_PIN_HPP
