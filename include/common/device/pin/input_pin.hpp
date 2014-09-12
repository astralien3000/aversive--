#ifndef INPUT_PIN_HPP
#define INPUT_PIN_HPP

#include <device/device.hpp>
#include <device/input.hpp>

template<int ID>
class InputPin : public Device, public Input<bool> {
protected:
  InputPin(const char* name, bool init);

public:
  InputPin(const char* name);
  bool getValue(void);
};

#endif//INPUT_PIN_HPP
