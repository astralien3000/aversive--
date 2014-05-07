#ifndef FPGA_ENCODER_HPP
#define FPGA_ENCODER_HPP

#include <device/encoder/encoder.hpp>

//! \brief An incremental encoder, used by Eirbot in 2014
//! \param T the FPGA register type
//! \param ADDR the FPGA register
/*! 

  This sensor is actually connected to a FPGA, which is viewed as an
  external memory by the microcontroller. The address is set by the
  user, so I hope you know how your FPGA works ;) !

*/
template<typename T, int ADDR>
class FpgaEncoder : public Encoder {
public:
  //! \brief Create a named encoder
  //! \param name : the name of the device (used with sasiae)
  //! \param addr : the FPGA register address
  FpgaEncoder(const char* name);

  //! \brief Get the number of impulsion of the incremental encoder
  /*!
    
    If the "wheel" turn in some way, the number of impulsion
    increases. If it turn in the other way, the number of impulsion
    decresases.
    
   */
  s32 getValue(void);
};

#endif//FPGA_ENCODER_HPP
