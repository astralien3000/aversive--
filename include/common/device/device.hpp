#ifndef DEVICE_HPP
#define DEVICE_HPP

//! \class Device device.hpp <device/device.hpp>
//! \brief Class representing a generic device.
class Device {
private:
  //! \brief The device's name.
  const char* _name;
  
  //! \brief Private default constructor to prevent its use.
  inline Device(void) {
  }
  
protected:
  //! \brief Protected copy constructor to prevent its use by final user.
  //! \param other : the device to copy.
  inline Device(const Device& other)
    : _name(other._name) {
  }
  
public:
  //! \brief Construct a device with a given name.
  //! \param name : the device's name.
  //! \note The device's name is used by SASIAE to identify it.
  explicit inline Device(const char* name)
    : _name(name) {
  }
  
  //! \brief Return the name of the device.
  //! \return The device's name.
  inline const char* name(void) const {
    return _name;
  }
};

#endif//DEVICE_HPP
