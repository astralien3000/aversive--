#ifndef DEVICE_HPP
#define DEVICE_HPP

class Device {
private:
  const char* _name;

public:
  //! \brief Create a device with a name, used by sasiae to identify the device
  inline Device(const char* name) : _name(name) {}
  
  //! \brief Returns the name of the device
  inline const char* getName(void) {
    return _name;
  }
};

#endif//DEVICE_HPP
