#ifndef DEVICE_HPP
#define DEVICE_HPP

class Device {
private:
  const char* _name;

public:
  //! \brief Create a device with a name, used by sasiae to identify the device
  explicit inline Device(const char* name) : _name(name) {}
  
  //! \brief Returns the name of the device
  inline const char* name(void) const {
    return _name;
  }
};

#endif//DEVICE_HPP
