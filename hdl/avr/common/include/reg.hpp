#ifndef HDL_AVR_COMMON_REG_HPP
#define HDL_AVR_COMMON_REG_HPP

namespace HDL {
  
  //! \brief Definitions that are common to all AVR MCUs
  namespace AVR {
    
    namespace Private {
      
      //! \brief Transform an IO address into a MEM address
      //! \param addr : IO address, can take a value between 0x0000 and 0x003F.
      //! \return MEM address
      static constexpr usys SFR_IO(usys addr) {
	return 0x0020 + addr;
      }
      
      //! \brief Returns a MEM address
      //! \param addr : The address of a register in the MEM Space
      //! \return MEM address
      /*! 
       * Doesn't do anything, but must be used by HDL developpers
       * to specify that an address is a memory space address
       * (instead of an IO space address).
       */
      static constexpr usys SFR_MEM(usys addr) {
	return addr;
      }
      
    }
    
  }

  using namespace AVR;
}

#endif//HDL_AVR_COMMON_REG_HPP
