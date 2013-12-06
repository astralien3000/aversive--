template<int ID> struct timer;
template<> struct timer<0> {
  struct control {
    struct wgm {
      struct normal {
        enum { CONFIG = 0, SIZE = 8 };
      };

      struct pwm {
        enum { CONFIG = 1, SIZE = 8 };
      };

      struct ctc {
        enum { CONFIG = 2, SIZE = 8 };
      };

      struct fastpwm {
        enum { CONFIG = 3, SIZE = 8 };
      };

    };

    struct prescaler {
      struct disable {
        enum { CONFIG = 4, SIZE = 8 };
      };

      template<int ID> struct value;
      template<int ID> struct value;
      template<int ID> struct value;
      template<int ID> struct value;
      template<int ID> struct value;
      template<int ID> struct value;
      template<int ID> struct value;
    };

    enum { REG = 0, SIZE = 8 };
  };

  struct counter {
    enum { REG = 1, SIZE = 8 };
  };

  template<int ID> struct compare;
  struct imask {
    template<int ID> struct match;
    enum { REG = 2, SIZE = 8 };
  };

  struct iflag {
    enum { REG = 3, SIZE = 8 };
  };

};

template<> template<> struct timer<0>::control::prescaler::value<0> {
  enum { CONFIG = 5, SIZE = 8 };
};

template<> template<> struct timer<0>::control::prescaler::value<8> {
  enum { CONFIG = 6, SIZE = 8 };
};

template<> template<> struct timer<0>::control::prescaler::value<32> {
  enum { CONFIG = 7, SIZE = 8 };
};

template<> template<> struct timer<0>::control::prescaler::value<64> {
  enum { CONFIG = 8, SIZE = 8 };
};

template<> template<> struct timer<0>::control::prescaler::value<128> {
  enum { CONFIG = 9, SIZE = 8 };
};

template<> template<> struct timer<0>::control::prescaler::value<256> {
  enum { CONFIG = 10, SIZE = 8 };
};

template<> template<> struct timer<0>::control::prescaler::value<1024> {
  enum { CONFIG = 11, SIZE = 8 };
};

template<> template<> struct timer<0>::compare<0> {
  enum { REG = 4, SIZE = 8 };
};

template<> template<> struct timer<0>::imask::match<0> {
  enum { CONFIG = 12, SIZE = 8 };
};

template<int ID> struct timer;
template<> struct timer<1> {
  struct control {
    struct wgm {
      struct normal {
        enum { CONFIG = 13, SIZE = 8 };
      };

      struct pwm {
        enum { CONFIG = 14, SIZE = 8 };
      };

      struct ctc {
        enum { CONFIG = 15, SIZE = 8 };
      };

      struct fastpwm {
        enum { CONFIG = 16, SIZE = 8 };
      };

    };

    struct prescaler {
      struct disable {
        enum { CONFIG = 17, SIZE = 8 };
      };

      template<int ID> struct value;
      template<int ID> struct value;
      template<int ID> struct value;
      template<int ID> struct value;
      template<int ID> struct value;
    };

    enum { REG = 5, SIZE = 8 };
  };

  struct counter {
    enum { REG = 6, SIZE = 16 };
  };

  template<int ID> struct compare;
  template<int ID> struct compare;
  struct imask {
    template<int ID> struct match;
    template<int ID> struct match;
    enum { REG = 7, SIZE = 8 };
  };

  struct iflag {
    enum { REG = 8, SIZE = 8 };
  };

};

template<> template<> struct timer<1>::control::prescaler::value<0> {
  enum { CONFIG = 18, SIZE = 8 };
};

template<> template<> struct timer<1>::control::prescaler::value<8> {
  enum { CONFIG = 19, SIZE = 8 };
};

template<> template<> struct timer<1>::control::prescaler::value<64> {
  enum { CONFIG = 20, SIZE = 8 };
};

template<> template<> struct timer<1>::control::prescaler::value<256> {
  enum { CONFIG = 21, SIZE = 8 };
};

template<> template<> struct timer<1>::control::prescaler::value<1024> {
  enum { CONFIG = 22, SIZE = 8 };
};

template<> template<> struct timer<1>::compare<0> {
  enum { REG = 9, SIZE = 16 };
};

template<> template<> struct timer<1>::compare<1> {
  enum { REG = 10, SIZE = 16 };
};

template<> template<> struct timer<1>::imask::match<0> {
  enum { CONFIG = 23, SIZE = 8 };
};

template<> template<> struct timer<1>::imask::match<1> {
  enum { CONFIG = 24, SIZE = 8 };
};

template<int ID> struct uart;
template<> struct uart<0> {
  struct control {
    struct enable {
      struct send {
        enum { CONFIG = 25, SIZE = 8 };
      };

      struct recv {
        enum { CONFIG = 26, SIZE = 8 };
      };

      struct comm {
        enum { CONFIG = 27, SIZE = 8 };
      };

    };

    struct charsize {
      template<int ID> struct value;
      template<int ID> struct value;
      template<int ID> struct value;
      template<int ID> struct value;
      template<int ID> struct value;
    };

    enum { REG = 11, SIZE = 8 };
  };

};

template<> template<> struct uart<0>::control::charsize::value<5> {
  enum { CONFIG = 28, SIZE = 8 };
};

template<> template<> struct uart<0>::control::charsize::value<6> {
  enum { CONFIG = 29, SIZE = 8 };
};

template<> template<> struct uart<0>::control::charsize::value<7> {
  enum { CONFIG = 30, SIZE = 8 };
};

template<> template<> struct uart<0>::control::charsize::value<8> {
  enum { CONFIG = 31, SIZE = 8 };
};

template<> template<> struct uart<0>::control::charsize::value<9> {
  enum { CONFIG = 32, SIZE = 8 };
};

template<> inline Register<8, 0>::Register(void) : reg_size(1), reg{(u8*)&TCCR0} {}
template<> inline Config<8, 0>::Config(void) : conf{0} {}
template<> inline Config<8, 1>::Config(void) : conf{( 1 << WGM00 )} {}
template<> inline Config<8, 2>::Config(void) : conf{( 1 << WGM01 )} {}
template<> inline Config<8, 3>::Config(void) : conf{( 1 << WGM01 ) | ( 1 << WGM01 )} {}
template<> inline Config<8, 4>::Config(void) : conf{( 0 << CS02 ) | ( 0 << CS01 ) | ( 0 << CS00 )} {}
template<> inline Config<8, 5>::Config(void) : conf{( 0 << CS02 ) | ( 0 << CS01 ) | ( 1 << CS00 )} {}
template<> inline Config<8, 6>::Config(void) : conf{( 0 << CS02 ) | ( 1 << CS01 ) | ( 0 << CS00 )} {}
template<> inline Config<8, 7>::Config(void) : conf{( 0 << CS02 ) | ( 1 << CS01 ) | ( 1 << CS00 )} {}
template<> inline Config<8, 8>::Config(void) : conf{( 1 << CS02 ) | ( 0 << CS01 ) | ( 0 << CS00 )} {}
template<> inline Config<8, 9>::Config(void) : conf{( 1 << CS02 ) | ( 0 << CS01 ) | ( 1 << CS00 )} {}
template<> inline Config<8, 10>::Config(void) : conf{( 1 << CS02 ) | ( 1 << CS01 ) | ( 0 << CS00 )} {}
template<> inline Config<8, 11>::Config(void) : conf{( 1 << CS02 ) | ( 1 << CS01 ) | ( 1 << CS00 )} {}
template<> inline Register<8, 1>::Register(void) : reg_size(1), reg{(u8*)&TCNT0} {}
template<> inline Register<8, 4>::Register(void) : reg_size(1), reg{(u8*)&OCR0} {}
template<> inline Register<8, 2>::Register(void) : reg_size(1), reg{(u8*)&TIMSK} {}
template<> inline Config<8, 12>::Config(void) : conf{( 1 << OCIE0 )} {}
template<> inline Register<8, 3>::Register(void) : reg_size(1), reg{(u8*)&TIFR} {}
template<> inline Register<8, 5>::Register(void) : reg_size(3), reg{(u8*)&TCCR1A, (u8*)&TCCR1B, (u8*)&TCCR1C} {}
template<> inline Config<8, 13>::Config(void) : conf{0, 0, 0} {}
template<> inline Config<8, 14>::Config(void) : conf{( 1 << WGM10 ) | ( 1 << WGM11 ), 0, 0} {}
template<> inline Config<8, 15>::Config(void) : conf{0, ( 1 << WGM12 ), 0} {}
template<> inline Config<8, 16>::Config(void) : conf{( 1 << WGM10 ) | ( 1 << WGM11 ), ( 1 << WGM12 ), 0} {}
template<> inline Config<8, 17>::Config(void) : conf{0, ( 0 << CS12 ) | ( 0 << CS11 ) | ( 0 << CS10 ), 0} {}
template<> inline Config<8, 18>::Config(void) : conf{0, ( 0 << CS12 ) | ( 0 << CS11 ) | ( 1 << CS10 ), 0} {}
template<> inline Config<8, 19>::Config(void) : conf{0, ( 0 << CS12 ) | ( 1 << CS11 ) | ( 0 << CS10 ), 0} {}
template<> inline Config<8, 20>::Config(void) : conf{0, ( 0 << CS12 ) | ( 1 << CS11 ) | ( 1 << CS10 ), 0} {}
template<> inline Config<8, 21>::Config(void) : conf{0, ( 1 << CS12 ) | ( 0 << CS11 ) | ( 0 << CS10 ), 0} {}
template<> inline Config<8, 22>::Config(void) : conf{0, ( 1 << CS12 ) | ( 0 << CS11 ) | ( 1 << CS10 ), 0} {}
template<> inline Register<16, 6>::Register(void) : reg_size(1), reg{(u16*)&TCNT1} {}
template<> inline Register<16, 9>::Register(void) : reg_size(1), reg{(u16*)&OCR1A} {}
template<> inline Register<16, 10>::Register(void) : reg_size(1), reg{(u16*)&OCR1B} {}
template<> inline Register<8, 7>::Register(void) : reg_size(1), reg{(u8*)&TIMSK} {}
template<> inline Config<8, 23>::Config(void) : conf{( 1 << OCIE1A )} {}
template<> inline Config<8, 24>::Config(void) : conf{( 1 << OCIE1B )} {}
template<> inline Register<8, 8>::Register(void) : reg_size(1), reg{(u8*)&TIFR} {}
template<> inline Register<8, 11>::Register(void) : reg_size(3), reg{(u8*)&UCSR0A, (u8*)&UCSR0B, (u8*)&UCSR0C} {}
template<> inline Config<8, 25>::Config(void) : conf{0, ( 1 << TXEN ), 0} {}
template<> inline Config<8, 26>::Config(void) : conf{0, ( 1 << RXEN ), 0} {}
template<> inline Config<8, 27>::Config(void) : conf{0, ( 1 << TXEN ) | ( 1 << RXEN ), 0} {}
template<> inline Config<8, 28>::Config(void) : conf{0, ( 0 << UCSZ2 ), ( 0 << UCSZ1 ) | ( 0 << UCSZ0 )} {}
template<> inline Config<8, 29>::Config(void) : conf{0, ( 0 << UCSZ2 ), ( 0 << UCSZ1 ) | ( 1 << UCSZ0 )} {}
template<> inline Config<8, 30>::Config(void) : conf{0, ( 0 << UCSZ2 ), ( 1 << UCSZ1 ) | ( 0 << UCSZ0 )} {}
template<> inline Config<8, 31>::Config(void) : conf{0, ( 0 << UCSZ2 ), ( 1 << UCSZ1 ) | ( 1 << UCSZ0 )} {}
template<> inline Config<8, 32>::Config(void) : conf{0, ( 1 << UCSZ2 ), ( 1 << UCSZ1 ) | ( 1 << UCSZ0 )} {}
