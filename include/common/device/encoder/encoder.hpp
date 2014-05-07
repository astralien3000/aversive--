#ifndef ENCODER_HPP
#define ENCODER_HPP

#include <device/device.hpp>
#include <device/input.hpp>
#include <base/integer.hpp>

//! \brief An incremental encoder
class Encoder : public Device, public Input<s32> {

protected:
  bool _inverse;

protected:
  //! \brief Create a named encoder
  //! \param name : the name of the device (used with sasiae)
  Encoder(const char* name)
    : Device(name), _inverse(false) {}

public:
  //! \brief Get the number of impulsion of the incremental encoder
  /*!
    
    If the "wheel" turn in some way, the number of impulsion
    increases. If it turn in the other way, the number of impulsion
    decresases.
    
   */
  virtual s32 getValue(void) = 0;

  //! \brief Switch the way of increase/decrease
  void inverse(void) {
    _inverse = !_inverse;
  }
};

#endif//ENCODER_HPP
