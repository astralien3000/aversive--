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

template<int ID> struct adc;
template<> struct adc<0> {
  struct select {
    template<int ID> struct value;
    template<int ID> struct value;
    template<int ID> struct value;
    template<int ID> struct value;
    template<int ID> struct value;
    template<int ID> struct value;
    template<int ID> struct value;
    template<int ID> struct value;
    template<int ID> struct value;
    template<int ID> struct value;
    template<int ID> struct value;
    template<int ID> struct value;
    template<int ID> struct value;
    template<int ID> struct value;
    template<int ID> struct value;
    template<int ID> struct value;
    struct mask {
      enum { CONFIG = 50, SIZE = 8 };
    };

    enum { REG = 19, SIZE = 8 };
  };

  struct control {
    struct enable {
      enum { CONFIG = 51, SIZE = 8 };
    };

    struct start {
      enum { CONFIG = 52, SIZE = 8 };
    };

    struct autotrigger {
      enum { CONFIG = 53, SIZE = 8 };
    };

    struct ended {
      enum { CONFIG = 54, SIZE = 8 };
    };

    struct ienable {
      enum { CONFIG = 55, SIZE = 8 };
    };

    struct reference {
      struct external {
        enum { CONFIG = 56, SIZE = 8 };
      };

      struct internal {
        enum { CONFIG = 57, SIZE = 8 };
      };

      struct fifthinternal {
        enum { CONFIG = 58, SIZE = 8 };
      };

      struct halfinternal {
        enum { CONFIG = 59, SIZE = 8 };
      };

    };

    struct align {
      struct left {
        enum { CONFIG = 60, SIZE = 8 };
      };

      struct right {
        enum { CONFIG = 61, SIZE = 8 };
      };

    };

    struct prescaler {
      template<int ID> struct value;
      template<int ID> struct value;
      template<int ID> struct value;
      template<int ID> struct value;
      template<int ID> struct value;
      template<int ID> struct value;
      template<int ID> struct value;
      template<int ID> struct value;
    };

    struct trigger {
      struct timer0ovf {
        enum { CONFIG = 62, SIZE = 8 };
      };

    };

    enum { REG = 20, SIZE = 8 };
  };

  struct disable {
    struct normal {
      enum { CONFIG = 63, SIZE = 8 };
    };

    template<int ID> struct value;
    template<int ID> struct value;
    template<int ID> struct value;
    template<int ID> struct value;
    template<int ID> struct value;
    template<int ID> struct value;
    template<int ID> struct value;
    template<int ID> struct value;
    template<int ID> struct value;
    template<int ID> struct value;
    template<int ID> struct value;
    template<int ID> struct value;
    template<int ID> struct value;
    template<int ID> struct value;
    template<int ID> struct value;
    template<int ID> struct value;
    enum { REG = 21, SIZE = 8 };
  };

  struct data {
    enum { REG = 22, SIZE = 8 };
  };

};

template<> template<> struct adc<0>::select::value<0> {
  enum { CONFIG = 64, SIZE = 8 };
};

template<> template<> struct adc<0>::select::value<1> {
  enum { CONFIG = 65, SIZE = 8 };
};

template<> template<> struct adc<0>::select::value<2> {
  enum { CONFIG = 66, SIZE = 8 };
};

template<> template<> struct adc<0>::select::value<3> {
  enum { CONFIG = 67, SIZE = 8 };
};

template<> template<> struct adc<0>::select::value<4> {
  enum { CONFIG = 68, SIZE = 8 };
};

template<> template<> struct adc<0>::select::value<5> {
  enum { CONFIG = 69, SIZE = 8 };
};

template<> template<> struct adc<0>::select::value<6> {
  enum { CONFIG = 70, SIZE = 8 };
};

template<> template<> struct adc<0>::select::value<7> {
  enum { CONFIG = 71, SIZE = 8 };
};

template<> template<> struct adc<0>::select::value<8> {
  enum { CONFIG = 72, SIZE = 8 };
};

template<> template<> struct adc<0>::select::value<9> {
  enum { CONFIG = 73, SIZE = 8 };
};

template<> template<> struct adc<0>::select::value<10> {
  enum { CONFIG = 74, SIZE = 8 };
};

template<> template<> struct adc<0>::select::value<11> {
  enum { CONFIG = 75, SIZE = 8 };
};

template<> template<> struct adc<0>::select::value<12> {
  enum { CONFIG = 76, SIZE = 8 };
};

template<> template<> struct adc<0>::select::value<13> {
  enum { CONFIG = 77, SIZE = 8 };
};

template<> template<> struct adc<0>::select::value<14> {
  enum { CONFIG = 78, SIZE = 8 };
};

template<> template<> struct adc<0>::select::value<15> {
  enum { CONFIG = 79, SIZE = 8 };
};

template<> template<> struct adc<0>::control::prescaler::value<1> {
  enum { CONFIG = 80, SIZE = 8 };
};

template<> template<> struct adc<0>::control::prescaler::value<2> {
  enum { CONFIG = 81, SIZE = 8 };
};

template<> template<> struct adc<0>::control::prescaler::value<4> {
  enum { CONFIG = 82, SIZE = 8 };
};

template<> template<> struct adc<0>::control::prescaler::value<8> {
  enum { CONFIG = 83, SIZE = 8 };
};

template<> template<> struct adc<0>::control::prescaler::value<16> {
  enum { CONFIG = 84, SIZE = 8 };
};

template<> template<> struct adc<0>::control::prescaler::value<32> {
  enum { CONFIG = 85, SIZE = 8 };
};

template<> template<> struct adc<0>::control::prescaler::value<64> {
  enum { CONFIG = 86, SIZE = 8 };
};

template<> template<> struct adc<0>::control::prescaler::value<128> {
  enum { CONFIG = 87, SIZE = 8 };
};

template<> template<> struct adc<0>::disable::value<0> {
  enum { CONFIG = 88, SIZE = 8 };
};

template<> template<> struct adc<0>::disable::value<1> {
  enum { CONFIG = 89, SIZE = 8 };
};

template<> template<> struct adc<0>::disable::value<2> {
  enum { CONFIG = 90, SIZE = 8 };
};

template<> template<> struct adc<0>::disable::value<3> {
  enum { CONFIG = 91, SIZE = 8 };
};

template<> template<> struct adc<0>::disable::value<4> {
  enum { CONFIG = 92, SIZE = 8 };
};

template<> template<> struct adc<0>::disable::value<5> {
  enum { CONFIG = 93, SIZE = 8 };
};

template<> template<> struct adc<0>::disable::value<6> {
  enum { CONFIG = 94, SIZE = 8 };
};

template<> template<> struct adc<0>::disable::value<7> {
  enum { CONFIG = 95, SIZE = 8 };
};

template<> template<> struct adc<0>::disable::value<8> {
  enum { CONFIG = 96, SIZE = 8 };
};

template<> template<> struct adc<0>::disable::value<9> {
  enum { CONFIG = 97, SIZE = 8 };
};

template<> template<> struct adc<0>::disable::value<10> {
  enum { CONFIG = 98, SIZE = 8 };
};

template<> template<> struct adc<0>::disable::value<11> {
  enum { CONFIG = 99, SIZE = 8 };
};

template<> template<> struct adc<0>::disable::value<12> {
  enum { CONFIG = 100, SIZE = 8 };
};

template<> template<> struct adc<0>::disable::value<13> {
  enum { CONFIG = 101, SIZE = 8 };
};

template<> template<> struct adc<0>::disable::value<14> {
  enum { CONFIG = 102, SIZE = 8 };
};

template<> template<> struct adc<0>::disable::value<15> {
  enum { CONFIG = 103, SIZE = 8 };
};

template<int ID> struct dummy;
template<> struct dummy<0> {
  enum { CONFIG = 104, SIZE = 0 };
};

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
template<> inline Register<8, 19>::Register(void) : reg_size(2), reg{(u8*)&ADCSRB, (u8*)&ADMUX} {}
template<> inline Config<8, 64>::Config(void) : conf{( 0 << MUX5 ), ( 0 << MUX4 ) | ( 0 << MUX3 ) | ( 0 << MUX2 ) | ( 0 << MUX1 ) | ( 0 << MUX0 )} {}
template<> inline Config<8, 65>::Config(void) : conf{( 0 << MUX5 ), ( 0 << MUX4 ) | ( 0 << MUX3 ) | ( 0 << MUX2 ) | ( 0 << MUX1 ) | ( 1 << MUX0 )} {}
template<> inline Config<8, 66>::Config(void) : conf{( 0 << MUX5 ), ( 0 << MUX4 ) | ( 0 << MUX3 ) | ( 0 << MUX2 ) | ( 1 << MUX1 ) | ( 0 << MUX0 )} {}
template<> inline Config<8, 67>::Config(void) : conf{( 0 << MUX5 ), ( 0 << MUX4 ) | ( 0 << MUX3 ) | ( 0 << MUX2 ) | ( 1 << MUX1 ) | ( 1 << MUX0 )} {}
template<> inline Config<8, 68>::Config(void) : conf{( 0 << MUX5 ), ( 0 << MUX4 ) | ( 0 << MUX3 ) | ( 1 << MUX2 ) | ( 0 << MUX1 ) | ( 0 << MUX0 )} {}
template<> inline Config<8, 69>::Config(void) : conf{( 0 << MUX5 ), ( 0 << MUX4 ) | ( 0 << MUX3 ) | ( 1 << MUX2 ) | ( 0 << MUX1 ) | ( 1 << MUX0 )} {}
template<> inline Config<8, 70>::Config(void) : conf{( 0 << MUX5 ), ( 0 << MUX4 ) | ( 0 << MUX3 ) | ( 1 << MUX2 ) | ( 1 << MUX1 ) | ( 0 << MUX0 )} {}
template<> inline Config<8, 71>::Config(void) : conf{( 0 << MUX5 ), ( 0 << MUX4 ) | ( 0 << MUX3 ) | ( 1 << MUX2 ) | ( 1 << MUX1 ) | ( 1 << MUX0 )} {}
template<> inline Config<8, 72>::Config(void) : conf{( 1 << MUX5 ), ( 0 << MUX4 ) | ( 0 << MUX3 ) | ( 0 << MUX2 ) | ( 0 << MUX1 ) | ( 0 << MUX0 )} {}
template<> inline Config<8, 73>::Config(void) : conf{( 1 << MUX5 ), ( 0 << MUX4 ) | ( 0 << MUX3 ) | ( 0 << MUX2 ) | ( 0 << MUX1 ) | ( 1 << MUX0 )} {}
template<> inline Config<8, 74>::Config(void) : conf{( 1 << MUX5 ), ( 0 << MUX4 ) | ( 0 << MUX3 ) | ( 0 << MUX2 ) | ( 1 << MUX1 ) | ( 0 << MUX0 )} {}
template<> inline Config<8, 75>::Config(void) : conf{( 1 << MUX5 ), ( 0 << MUX4 ) | ( 0 << MUX3 ) | ( 0 << MUX2 ) | ( 1 << MUX1 ) | ( 1 << MUX0 )} {}
template<> inline Config<8, 76>::Config(void) : conf{( 1 << MUX5 ), ( 0 << MUX4 ) | ( 0 << MUX3 ) | ( 1 << MUX2 ) | ( 0 << MUX1 ) | ( 0 << MUX0 )} {}
template<> inline Config<8, 77>::Config(void) : conf{( 1 << MUX5 ), ( 0 << MUX4 ) | ( 0 << MUX3 ) | ( 1 << MUX2 ) | ( 0 << MUX1 ) | ( 1 << MUX0 )} {}
template<> inline Config<8, 78>::Config(void) : conf{( 1 << MUX5 ), ( 0 << MUX4 ) | ( 0 << MUX3 ) | ( 1 << MUX2 ) | ( 1 << MUX1 ) | ( 0 << MUX0 )} {}
template<> inline Config<8, 79>::Config(void) : conf{( 1 << MUX5 ), ( 0 << MUX4 ) | ( 0 << MUX3 ) | ( 1 << MUX2 ) | ( 1 << MUX1 ) | ( 1 << MUX0 )} {}
template<> inline Config<8, 50>::Config(void) : conf{( 1 << MUX5 ), ( 1 << MUX4 ) | ( 1 << MUX3 ) | ( 1 << MUX2 ) | ( 1 << MUX1 ) | ( 1 << MUX0 )} {}
template<> inline Register<8, 20>::Register(void) : reg_size(2), reg{(u8*)&ADCSRA, (u8*)&ADCSRB} {}
template<> inline Config<8, 51>::Config(void) : conf{( 1 << ADEN ), 0} {}
template<> inline Config<8, 52>::Config(void) : conf{( 1 << ADSC ), 0} {}
template<> inline Config<8, 53>::Config(void) : conf{( 1 << ADATE ), 0} {}
template<> inline Config<8, 54>::Config(void) : conf{( 1 << ADIF ), 0} {}
template<> inline Config<8, 55>::Config(void) : conf{( 1 << ADIE ), 0} {}
template<> inline Config<8, 56>::Config(void) : conf{0, ( 0 << REFS1 ) | ( 0 << REFS0 )} {}
template<> inline Config<8, 57>::Config(void) : conf{0, ( 0 << REFS1 ) | ( 1 << REFS0 )} {}
template<> inline Config<8, 58>::Config(void) : conf{0, ( 1 << REFS1 ) | ( 0 << REFS0 )} {}
template<> inline Config<8, 59>::Config(void) : conf{0, ( 1 << REFS1 ) | ( 1 << REFS0 )} {}
template<> inline Config<8, 60>::Config(void) : conf{0, ( 1 << ADLAR )} {}
template<> inline Config<8, 61>::Config(void) : conf{0, ( 0 << ADLAR )} {}
template<> inline Config<8, 80>::Config(void) : conf{( 0 << ADPS2 ) | ( 0 << ADPS1 ) | ( 0 << ADPS0 ), 0} {}
template<> inline Config<8, 81>::Config(void) : conf{( 0 << ADPS2 ) | ( 0 << ADPS1 ) | ( 1 << ADPS0 ), 0} {}
template<> inline Config<8, 82>::Config(void) : conf{( 0 << ADPS2 ) | ( 1 << ADPS1 ) | ( 0 << ADPS0 ), 0} {}
template<> inline Config<8, 83>::Config(void) : conf{( 0 << ADPS2 ) | ( 1 << ADPS1 ) | ( 1 << ADPS0 ), 0} {}
template<> inline Config<8, 84>::Config(void) : conf{( 1 << ADPS2 ) | ( 0 << ADPS1 ) | ( 0 << ADPS0 ), 0} {}
template<> inline Config<8, 85>::Config(void) : conf{( 1 << ADPS2 ) | ( 0 << ADPS1 ) | ( 1 << ADPS0 ), 0} {}
template<> inline Config<8, 86>::Config(void) : conf{( 1 << ADPS2 ) | ( 1 << ADPS1 ) | ( 0 << ADPS0 ), 0} {}
template<> inline Config<8, 87>::Config(void) : conf{( 1 << ADPS2 ) | ( 1 << ADPS1 ) | ( 1 << ADPS0 ), 0} {}
template<> inline Config<8, 62>::Config(void) : conf{0, ( 1 << ADTS2 ) | ( 0 << ADTS1 ) | ( 0 << ADTS0 )} {}
template<> inline Register<8, 21>::Register(void) : reg_size(2), reg{(u8*)&DIDR0, (u8*)&DIDR2} {}
template<> inline Config<8, 63>::Config(void) : conf{0, 0} {}
template<> inline Config<8, 88>::Config(void) : conf{ADC0D, 0} {}
template<> inline Config<8, 89>::Config(void) : conf{ADC1D, 0} {}
template<> inline Config<8, 90>::Config(void) : conf{ADC2D, 0} {}
template<> inline Config<8, 91>::Config(void) : conf{ADC3D, 0} {}
template<> inline Config<8, 92>::Config(void) : conf{ADC4D, 0} {}
template<> inline Config<8, 93>::Config(void) : conf{ADC5D, 0} {}
template<> inline Config<8, 94>::Config(void) : conf{ADC6D, 0} {}
template<> inline Config<8, 95>::Config(void) : conf{ADC7D, 0} {}
template<> inline Config<8, 96>::Config(void) : conf{0, ADC8D} {}
template<> inline Config<8, 97>::Config(void) : conf{0, ADC9D} {}
template<> inline Config<8, 98>::Config(void) : conf{0, ADC10D} {}
template<> inline Config<8, 99>::Config(void) : conf{0, ADC11D} {}
template<> inline Config<8, 100>::Config(void) : conf{0, ADC12D} {}
template<> inline Config<8, 101>::Config(void) : conf{0, ADC13D} {}
template<> inline Config<8, 102>::Config(void) : conf{0, ADC14D} {}
template<> inline Config<8, 103>::Config(void) : conf{0, ADC15D} {}
template<> inline Register<8, 22>::Register(void) : reg_size(2), reg{(u8*)&ADCL, (u8*)&ADCH} {}
