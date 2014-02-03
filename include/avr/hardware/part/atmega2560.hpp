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
    };

    enum { REG = 0, SIZE = 8 };
  };

  struct counter {
    enum { REG = 1, SIZE = 8 };
  };

  template<int ID> struct compare;
  template<int ID> struct compare;
  struct imask {
    template<int ID> struct match;
    template<int ID> struct match;
    struct overflow {
      enum { CONFIG = 5, SIZE = 8 };
    };

    enum { REG = 2, SIZE = 8 };
  };

  struct iflag {
    enum { REG = 3, SIZE = 8 };
  };

};

template<> template<> struct timer<0>::control::prescaler::value<0> {
  enum { CONFIG = 6, SIZE = 8 };
};

template<> template<> struct timer<0>::control::prescaler::value<8> {
  enum { CONFIG = 7, SIZE = 8 };
};

template<> template<> struct timer<0>::control::prescaler::value<64> {
  enum { CONFIG = 8, SIZE = 8 };
};

template<> template<> struct timer<0>::control::prescaler::value<256> {
  enum { CONFIG = 9, SIZE = 8 };
};

template<> template<> struct timer<0>::control::prescaler::value<1024> {
  enum { CONFIG = 10, SIZE = 8 };
};

template<> template<> struct timer<0>::compare<0> {
  enum { REG = 4, SIZE = 8 };
};

template<> template<> struct timer<0>::compare<1> {
  enum { REG = 5, SIZE = 8 };
};

template<> template<> struct timer<0>::imask::match<0> {
  enum { CONFIG = 11, SIZE = 8 };
};

template<> template<> struct timer<0>::imask::match<1> {
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

    enum { REG = 6, SIZE = 8 };
  };

  struct counter {
    enum { REG = 7, SIZE = 16 };
  };

  template<int ID> struct compare;
  template<int ID> struct compare;
  struct imask {
    template<int ID> struct match;
    template<int ID> struct match;
    struct overflow {
      enum { CONFIG = 18, SIZE = 8 };
    };

    enum { REG = 8, SIZE = 8 };
  };

  struct iflag {
    enum { REG = 9, SIZE = 8 };
  };

};

template<> template<> struct timer<1>::control::prescaler::value<0> {
  enum { CONFIG = 19, SIZE = 8 };
};

template<> template<> struct timer<1>::control::prescaler::value<8> {
  enum { CONFIG = 20, SIZE = 8 };
};

template<> template<> struct timer<1>::control::prescaler::value<64> {
  enum { CONFIG = 21, SIZE = 8 };
};

template<> template<> struct timer<1>::control::prescaler::value<256> {
  enum { CONFIG = 22, SIZE = 8 };
};

template<> template<> struct timer<1>::control::prescaler::value<1024> {
  enum { CONFIG = 23, SIZE = 8 };
};

template<> template<> struct timer<1>::compare<0> {
  enum { REG = 10, SIZE = 16 };
};

template<> template<> struct timer<1>::compare<1> {
  enum { REG = 11, SIZE = 16 };
};

template<> template<> struct timer<1>::imask::match<0> {
  enum { CONFIG = 24, SIZE = 8 };
};

template<> template<> struct timer<1>::imask::match<1> {
  enum { CONFIG = 25, SIZE = 8 };
};

template<int ID> struct uart;
template<> struct uart<0> {
  struct flag {
    struct recvend {
      enum { CONFIG = 26, SIZE = 8 };
    };

    struct sendend {
      enum { CONFIG = 27, SIZE = 8 };
    };

    struct empty {
      enum { CONFIG = 28, SIZE = 8 };
    };

    enum { REG = 12, SIZE = 8 };
  };

  struct control {
    struct enable {
      struct send {
        enum { CONFIG = 29, SIZE = 8 };
      };

      struct recv {
        enum { CONFIG = 30, SIZE = 8 };
      };

    };

    struct ienable {
      struct recv {
        enum { CONFIG = 31, SIZE = 8 };
      };

      struct send {
        enum { CONFIG = 32, SIZE = 8 };
      };

      struct empty {
        enum { CONFIG = 33, SIZE = 8 };
      };

    };

    struct flag {
      struct recvend {
        enum { CONFIG = 34, SIZE = 8 };
      };

      struct sendend {
        enum { CONFIG = 35, SIZE = 8 };
      };

      struct empty {
        enum { CONFIG = 36, SIZE = 8 };
      };

    };

    struct charsize {
      template<int ID> struct value;
      template<int ID> struct value;
      template<int ID> struct value;
      template<int ID> struct value;
      template<int ID> struct value;
    };

    struct parity {
      struct disabled {
        enum { CONFIG = 37, SIZE = 8 };
      };

      struct even {
        enum { CONFIG = 38, SIZE = 8 };
      };

      struct odd {
        enum { CONFIG = 39, SIZE = 8 };
      };

    };

    struct stopbit {
      template<int ID> struct value;
      template<int ID> struct value;
    };

    enum { REG = 13, SIZE = 8 };
  };

  struct baudrate {
    enum { REG = 14, SIZE = 8 };
  };

  struct data {
    enum { REG = 15, SIZE = 8 };
  };

};

template<> template<> struct uart<0>::control::charsize::value<5> {
  enum { CONFIG = 40, SIZE = 8 };
};

template<> template<> struct uart<0>::control::charsize::value<6> {
  enum { CONFIG = 41, SIZE = 8 };
};

template<> template<> struct uart<0>::control::charsize::value<7> {
  enum { CONFIG = 42, SIZE = 8 };
};

template<> template<> struct uart<0>::control::charsize::value<8> {
  enum { CONFIG = 43, SIZE = 8 };
};

template<> template<> struct uart<0>::control::charsize::value<9> {
  enum { CONFIG = 44, SIZE = 8 };
};

template<> template<> struct uart<0>::control::stopbit::value<1> {
  enum { CONFIG = 45, SIZE = 8 };
};

template<> template<> struct uart<0>::control::stopbit::value<2> {
  enum { CONFIG = 46, SIZE = 8 };
};

template<int ID> struct eeprom;
template<> struct eeprom<0> {
  struct address {
    enum { REG = 16, SIZE = 8 };
  };

  struct data {
    enum { REG = 17, SIZE = 8 };
  };

  struct control {
    struct masterwrite {
      enum { CONFIG = 47, SIZE = 8 };
    };

    struct write {
      enum { CONFIG = 48, SIZE = 8 };
    };

    struct read {
      enum { CONFIG = 49, SIZE = 8 };
    };

    enum { REG = 18, SIZE = 8 };
  };

};

template<int ID> struct xmem;
template<> struct xmem<0> {
  struct control {
    struct enable {
      enum { CONFIG = 50, SIZE = 8 };
    };

    struct defaultwait {
      enum { CONFIG = 51, SIZE = 8 };
    };

    enum { REG = 19, SIZE = 8 };
  };

};

struct dummy;
template<> inline Register<8, 0>::Register(void) : reg_size(2), reg{(u8*)&TCCR0A, (u8*)&TCCR0B} {}
template<> inline Config<8, 0>::Config(void) : conf{0, 0} {}
template<> inline Config<8, 1>::Config(void) : conf{( 1 << WGM00 ) | ( 1 << WGM01 ), 0} {}
template<> inline Config<8, 2>::Config(void) : conf{0, ( 1 << WGM02 )} {}
template<> inline Config<8, 3>::Config(void) : conf{( 1 << WGM00 ) | ( 1 << WGM01 ), ( 1 << WGM02 )} {}
template<> inline Config<8, 4>::Config(void) : conf{0, ( 0 << CS02 ) | ( 0 << CS01 ) | ( 0 << CS00 )} {}
template<> inline Config<8, 6>::Config(void) : conf{0, ( 0 << CS02 ) | ( 0 << CS01 ) | ( 1 << CS00 )} {}
template<> inline Config<8, 7>::Config(void) : conf{0, ( 0 << CS02 ) | ( 1 << CS01 ) | ( 0 << CS00 )} {}
template<> inline Config<8, 8>::Config(void) : conf{0, ( 0 << CS02 ) | ( 1 << CS01 ) | ( 1 << CS00 )} {}
template<> inline Config<8, 9>::Config(void) : conf{0, ( 1 << CS02 ) | ( 0 << CS01 ) | ( 0 << CS00 )} {}
template<> inline Config<8, 10>::Config(void) : conf{0, ( 1 << CS02 ) | ( 0 << CS01 ) | ( 1 << CS00 )} {}
template<> inline Register<8, 1>::Register(void) : reg_size(1), reg{(u8*)&TCNT0} {}
template<> inline Register<8, 4>::Register(void) : reg_size(1), reg{(u8*)&OCR0A} {}
template<> inline Register<8, 5>::Register(void) : reg_size(1), reg{(u8*)&OCR0B} {}
template<> inline Register<8, 2>::Register(void) : reg_size(1), reg{(u8*)&TIMSK0} {}
template<> inline Config<8, 11>::Config(void) : conf{( 1 << OCIE0A )} {}
template<> inline Config<8, 12>::Config(void) : conf{( 1 << OCIE0B )} {}
template<> inline Config<8, 5>::Config(void) : conf{( 1 << TOIE0 )} {}
template<> inline Register<8, 3>::Register(void) : reg_size(1), reg{(u8*)&TIFR0} {}
template<> inline Register<8, 6>::Register(void) : reg_size(3), reg{(u8*)&TCCR1A, (u8*)&TCCR1B, (u8*)&TCCR1C} {}
template<> inline Config<8, 13>::Config(void) : conf{0, 0, 0} {}
template<> inline Config<8, 14>::Config(void) : conf{( 1 << WGM10 ) | ( 1 << WGM11 ), 0, 0} {}
template<> inline Config<8, 15>::Config(void) : conf{0, ( 1 << WGM12 ), 0} {}
template<> inline Config<8, 16>::Config(void) : conf{( 1 << WGM10 ) | ( 1 << WGM11 ), ( 1 << WGM12 ), 0} {}
template<> inline Config<8, 17>::Config(void) : conf{0, ( 0 << CS12 ) | ( 0 << CS11 ) | ( 0 << CS10 ), 0} {}
template<> inline Config<8, 19>::Config(void) : conf{0, ( 0 << CS12 ) | ( 0 << CS11 ) | ( 1 << CS10 ), 0} {}
template<> inline Config<8, 20>::Config(void) : conf{0, ( 0 << CS12 ) | ( 1 << CS11 ) | ( 0 << CS10 ), 0} {}
template<> inline Config<8, 21>::Config(void) : conf{0, ( 0 << CS12 ) | ( 1 << CS11 ) | ( 1 << CS10 ), 0} {}
template<> inline Config<8, 22>::Config(void) : conf{0, ( 1 << CS12 ) | ( 0 << CS11 ) | ( 0 << CS10 ), 0} {}
template<> inline Config<8, 23>::Config(void) : conf{0, ( 1 << CS12 ) | ( 0 << CS11 ) | ( 1 << CS10 ), 0} {}
template<> inline Register<16, 7>::Register(void) : reg_size(1), reg{(u16*)&TCNT1} {}
template<> inline Register<16, 10>::Register(void) : reg_size(1), reg{(u16*)&OCR1A} {}
template<> inline Register<16, 11>::Register(void) : reg_size(1), reg{(u16*)&OCR1B} {}
template<> inline Register<8, 8>::Register(void) : reg_size(1), reg{(u8*)&TIMSK0} {}
template<> inline Config<8, 24>::Config(void) : conf{( 1 << OCIE1A )} {}
template<> inline Config<8, 25>::Config(void) : conf{( 1 << OCIE1B )} {}
template<> inline Config<8, 18>::Config(void) : conf{( 1 << TOIE1 )} {}
template<> inline Register<8, 9>::Register(void) : reg_size(1), reg{(u8*)&TIFR0} {}
template<> inline Register<8, 12>::Register(void) : reg_size(1), reg{(u8*)&UCSR0A} {}
template<> inline Config<8, 26>::Config(void) : conf{( 1 << RXC0 )} {}
template<> inline Config<8, 27>::Config(void) : conf{( 1 << TXC0 )} {}
template<> inline Config<8, 28>::Config(void) : conf{( 1 << UDRE0 )} {}
template<> inline Register<8, 13>::Register(void) : reg_size(3), reg{(u8*)&UCSR0A, (u8*)&UCSR0B, (u8*)&UCSR0C} {}
template<> inline Config<8, 29>::Config(void) : conf{0, ( 1 << TXEN0 ), 0} {}
template<> inline Config<8, 30>::Config(void) : conf{0, ( 1 << RXEN0 ), 0} {}
template<> inline Config<8, 31>::Config(void) : conf{0, ( 1 << RXCIE0 ), 0} {}
template<> inline Config<8, 32>::Config(void) : conf{0, ( 1 << TXCIE0 ), 0} {}
template<> inline Config<8, 33>::Config(void) : conf{0, ( 1 << UDRIE0 ), 0} {}
template<> inline Config<8, 34>::Config(void) : conf{( 1 << RXC0 ), 0, 0} {}
template<> inline Config<8, 35>::Config(void) : conf{( 1 << TXC0 ), 0, 0} {}
template<> inline Config<8, 36>::Config(void) : conf{( 1 << UDRE0 ), 0, 0} {}
template<> inline Config<8, 40>::Config(void) : conf{0, ( 0 << UCSZ02 ), ( 0 << UCSZ01 ) | ( 0 << UCSZ00 )} {}
template<> inline Config<8, 41>::Config(void) : conf{0, ( 0 << UCSZ02 ), ( 0 << UCSZ01 ) | ( 1 << UCSZ00 )} {}
template<> inline Config<8, 42>::Config(void) : conf{0, ( 0 << UCSZ02 ), ( 1 << UCSZ01 ) | ( 0 << UCSZ00 )} {}
template<> inline Config<8, 43>::Config(void) : conf{0, ( 0 << UCSZ02 ), ( 1 << UCSZ01 ) | ( 1 << UCSZ00 )} {}
template<> inline Config<8, 44>::Config(void) : conf{0, ( 1 << UCSZ02 ), ( 1 << UCSZ01 ) | ( 1 << UCSZ00 )} {}
template<> inline Config<8, 37>::Config(void) : conf{0, 0, 0} {}
template<> inline Config<8, 38>::Config(void) : conf{0, 0, ( 1 << UPM01 )} {}
template<> inline Config<8, 39>::Config(void) : conf{0, 0, ( 1 << UPM01 ) | ( 1 << UPM00 )} {}
template<> inline Config<8, 45>::Config(void) : conf{0, 0, 0} {}
template<> inline Config<8, 46>::Config(void) : conf{0, 0, ( 1 << USBS0 )} {}
template<> inline Register<8, 14>::Register(void) : reg_size(2), reg{(u8*)&UBRR0L, (u8*)&UBRR0H} {}
template<> inline Register<8, 15>::Register(void) : reg_size(1), reg{(u8*)&UDR0} {}
template<> inline Register<8, 16>::Register(void) : reg_size(2), reg{(u8*)&EEARL, (u8*)&EEARH} {}
template<> inline Register<8, 17>::Register(void) : reg_size(1), reg{(u8*)&EEDR} {}
template<> inline Register<8, 18>::Register(void) : reg_size(1), reg{(u8*)&EECR} {}
template<> inline Config<8, 47>::Config(void) : conf{( 1 << EEMPE )} {}
template<> inline Config<8, 48>::Config(void) : conf{( 1 << EEPE )} {}
template<> inline Config<8, 49>::Config(void) : conf{( 1 << EERE )} {}
template<> inline Register<8, 19>::Register(void) : reg_size(1), reg{(u8*)&XMCRA} {}
template<> inline Config<8, 50>::Config(void) : conf{( 1 << SRE )} {}
template<> inline Config<8, 51>::Config(void) : conf{( 1 << SRW11 ) | ( 1 << SRW00 )} {}
