#ifndef HDL_AVR_MEGA_XX0_1_ASM_HPP
#define HDL_AVR_MEGA_XX0_1_ASM_HPP

namespace HDL {

  static inline void sei(void) {
    asm("sei");
  }

  static inline void cli(void) {
    asm("cli");
  }

}
  
#endif//HDL_AVR_MEGA_XX0_1_ASM_HPP
