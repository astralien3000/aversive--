#ifndef SERVOMOTOR_HPP
#define SERVOMOTOR_HPP

#include <device/device.hpp>
#include <device/output.hpp>
#include <base/integer.hpp>

//! \brief A servomotor INTERFACE, used by Eirbot in 2014. Can not be used (see ServomotorFpga or ServomotorPin).
class Servomotor : public Device, public Output<u32> {
protected:
  //! \brief Protected Constructor
  Servomotor(const char*);

public:
  //! \brief Send a command to the servomotor
  virtual void setValue(u32) = 0;

private:
  u32 _min;
  u32 _max;

public:
  //! \brief Set the allowed maximum command
  inline void setMaxCommand(u32 val) {
    _max = val;
  }

  //! \brief Set the allowed minimum command
  inline void setMinCommand(u32 val) {
    _min = val;
  }

  //! \brief Return the allowed maximum command
  inline u32 getMaxCommand(void) {
    return _max;
  }

  //! \brief Return the allowed minimum command
  inline u32 getMinCommand(void) {
    return _min;
  }
};

#endif//SERVOMOTOR_HPP

