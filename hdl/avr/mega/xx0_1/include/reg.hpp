#ifndef HDL_AVR_MEGA_XX0_1_REG_HPP
#define HDL_AVR_MEGA_XX0_1_REG_HPP

#include <util/memory_mapping.hpp>
#include <util/dummy.hpp>
#include "../../../common/include/reg.hpp"


#if defined(__AVR_ATmega640__) || defined(__AVR_ATmega1280__) || defined(__AVR_ATmega2560__)
# define __ATmegaxx0__
#elif defined(__AVR_ATmega1281__) || defined(__AVR_ATmega2561__)
# define __ATmegaxx1__
#endif

#include "gpio/modules.hpp"
#include "timer/modules.hpp"
#include "uart/modules.hpp"

namespace HDL {
  using namespace ATMegaxx0_1;
}
  
#endif
