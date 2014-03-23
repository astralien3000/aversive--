#ifndef ENCODER_HPP
#define ENCODER_HPP

#include <device/device.hpp>
#include <device/input.hpp>
#include <base/integer.hpp>

//! \brief An incremental encoder, used by Eirbot in 2014
//! \param T the FPGA register type
/*! 

  This sensor is actually connected to a FPGA, which is viewed as an
  external memory by the microcontroller. The address is set by the
  user, so I hope you know how your FPGA works ;) !

*/
template<typename T>
class Encoder : public Device, public Input<T> {
public:
  //! \brief Create a named encoder
  //! \param name : the name of the device (used with sasiae)
  //! \param addr : the FPGA register address
  inline Encoder(const char* name, T* addr);

  //! \brief Get the number of impulsion of the incremental encoder
  /*!
    
    If the "wheel" turn in some way, the number of impulsion
    increases. If it turn in the other way, the number of impulsion
    decresases.
    
   */
  inline T getValue(void);

  //! \brief Switch the way of increase/decrease
  inline void inverse(void);
  
private:
  T* _addr;
  bool _inverse;
};

#endif//ENCODER_HPP
