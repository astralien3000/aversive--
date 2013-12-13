#ifndef INPUT_DEVICE_HPP
#define INPUT_DEVICE_HPP

#include "device.hpp"
#include "input.hpp"

template<typename T>
class InputDevice : public Input<T>, public Device {
public:
  inline InputDevice(const char* name) : Device(name) {}
  
  inline T& getInput(void);

private:
  struct PrivateData;
  PrivateData _data;
};

#endif//INPUT_DEVICE_HPP
