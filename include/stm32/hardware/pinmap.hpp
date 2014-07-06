#ifndef PINMAP_HPP
#define PINMAP_HPP

#include "hardware/gpio.hpp"

class Pinmap {

public:
  enum Mode {
    IN,
    OUT
  };

  template<int ID>
  class Pin {
  private:
    static constexpr u32 GPIO_ID = ID / 16;
    static constexpr u32 PIN_ID  = ID % 16;

    typedef typename Gpio<GPIO_ID>::template Pin<PIN_ID> MyPin;

  public:
    static inline void initGpio(void) {
      Gpio<GPIO_ID>::init();
    }

    static inline void setMode(Mode mod) {
      if(mod == OUT) {
        MyPin::setModeOutput();
      }
      else {
        MyPin::setModeInput();
      }
    }

    static inline void write(bool val) {
      if(val) {
        MyPin::set();
      }
      else {
        MyPin::reset();
      }
    }

  };
};

#endif//PINMAP_HPP
