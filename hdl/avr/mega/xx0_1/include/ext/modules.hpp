#ifndef HDL_AVR_MEGA_XX0_1_EXT_MODULES_HPP
#define HDL_AVR_MEGA_XX0_1_EXT_MODULES_HPP

#include "regs.hpp"
#include "fields.hpp"
#include "defs.hpp"


namespace HDL {
    
  namespace ATMegaxx0_1 {  

    //! \brief This is the final EXT module structure, which implements the HDL structure specification
    struct EXT : Private::EXT::EXT_ModuleRegisters<> {
      struct Fields : Private::EXT::EXT_ModuleFields<> {};
    };
    
  }
}

#endif//HDL_AVR_MEGA_XX0_1_EXT_MODULES_HPP
