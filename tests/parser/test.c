#include "../../impl/avr/hardware/architecture.hpp"

template<int ID> struct timer;
template<> struct timer<0> {
  struct control {
    struct wgm {
      struct normal {
        enum { CONFIG = 0 };
      };

      struct pwm {
        enum { CONFIG = 1 };
      };

      struct ctc {
        enum { CONFIG = 2 };
      };

      struct fastpwm {
        enum { CONFIG = 3 };
      };

    };

    struct prescaler {
      enum { CONFIG = 4 };
    };

    enum { REG = 0 };
  };

  struct counter {
    enum { REG = 1 };
  };

  struct compare {
    enum { REG = 2 };
  };

  struct imask {
    struct match {
      enum { CONFIG = 5 };
    };

    enum { REG = 3 };
  };

  struct iflag {
    enum { REG = 4 };
  };

};

template<int ID> struct timer;
template<> struct timer<1> {
  struct control {
    struct wgm {
      struct normal {
        enum { CONFIG = 6 };
      };

      struct pwm {
        enum { CONFIG = 7 };
      };

      struct ctc {
        enum { CONFIG = 8 };
      };

      struct fastpwm {
        enum { CONFIG = 9 };
      };

    };

    struct prescaler {
      enum { CONFIG = 10 };
    };

    enum { REG = 5 };
  };

  struct counter {
    enum { REG = 6 };
  };

  template<int ID> struct compare;
  template<int ID> struct compare;
  struct imask {
    template<int ID> struct match;
    template<int ID> struct match;
    enum { REG = 7 };
  };

  struct iflag {
    enum { REG = 8 };
  };

};

template<> template<> struct timer<1>::compare<0> {
  enum { REG = 9 };
};

template<> template<> struct timer<1>::compare<1> {
  enum { REG = 10 };
};

template<> template<> struct timer<1>::imask::match<0> {
  enum { CONFIG = 11 };
};

template<> template<> struct timer<1>::imask::match<1> {
  enum { CONFIG = 12 };
};

template<int ID> struct uart;
template<> struct uart<0> {
  struct control {
    struct enable {
      struct send {
        enum { CONFIG = 13 };
      };

      struct recv {
        enum { CONFIG = 14 };
      };

      struct comm {
        enum { CONFIG = 15 };
      };

    };

    struct charsize {
      enum { CONFIG = 16 };
    };

    enum { REG = 11 };
  };

};

template<> inline Register<8, 0>::Register(void) : reg_size(1), reg{(u8*)&TCCR0} {}
template<> inline Config<8, 0>::Config(void) : conf{0} {}
template<> inline Config<8, 1>::Config(void) : conf{( 1 << WGM00 )} {}
template<> inline Config<8, 2>::Config(void) : conf{( 1 << WGM01 )} {}
template<> inline Config<8, 3>::Config(void) : conf{( 1 << WGM01 ) | ( 1 << WGM01 )} {}
template<> inline Register<8, 1>::Register(void) : reg_size(1), reg{(u8*)&TCNT0} {}
template<> inline Register<8, 2>::Register(void) : reg_size(1), reg{(u8*)&OCR0} {}
template<> inline Register<8, 3>::Register(void) : reg_size(1), reg{(u8*)&TIMSK} {}
template<> inline Config<8, 5>::Config(void) : conf{( 1 << OCIE0 )} {}
template<> inline Register<8, 4>::Register(void) : reg_size(1), reg{(u8*)&TIFR} {}
template<> inline Register<8, 5>::Register(void) : reg_size(2), reg{(u8*)&TCCR1A, (u8*)&TCCR1B} {}
template<> inline Config<8, 6>::Config(void) : conf{0, 0} {}
template<> inline Config<8, 7>::Config(void) : conf{( 1 << WGM10 ) | ( 1 << WGM11 ), 0} {}
template<> inline Config<8, 8>::Config(void) : conf{0, ( 1 << WGM12 )} {}
template<> inline Config<8, 9>::Config(void) : conf{( 1 << WGM10 ) | ( 1 << WGM11 ), ( 1 << WGM12 )} {}
template<> inline Register<16, 6>::Register(void) : reg_size(1), reg{(u16*)&TCNT1} {}
template<> inline Register<16, 9>::Register(void) : reg_size(1), reg{(u16*)&OCR1A} {}
template<> inline Register<16, 10>::Register(void) : reg_size(1), reg{(u16*)&OCR1B} {}
template<> inline Register<8, 7>::Register(void) : reg_size(1), reg{(u8*)&TIMSK} {}
template<> inline Config<8, 11>::Config(void) : conf{( 1 << OCIE1A )} {}
template<> inline Config<8, 12>::Config(void) : conf{( 1 << OCIE1B )} {}
template<> inline Register<8, 8>::Register(void) : reg_size(1), reg{(u8*)&TIFR} {}
template<> inline Register<8, 11>::Register(void) : reg_size(3), reg{(u8*)&UCSRA, (u8*)&UCSRB, (u8*)&UCSRC} {}
template<> inline Config<8, 13>::Config(void) : conf{0, ( 1 << TXEN ), 0} {}
template<> inline Config<8, 14>::Config(void) : conf{0, ( 1 << RXEN ), 0} {}
template<> inline Config<8, 15>::Config(void) : conf{0, ( 1 << TXEN ) | ( 1 << RXEN ), 0} {}
