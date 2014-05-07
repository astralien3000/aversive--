
































































































































































































































































































































































// Architecture : atmega128
template<int param> struct timer;
template<int param> struct timer;
template<int param> struct uart;
template<int param> struct eeprom;
template<int param> struct xmem;
struct pinmap;
template<>
struct timer<0> {
  struct control;
  struct counter;
  template<int param> struct compare;
  struct imask;
  struct iflag;
};

struct timer<0>::control {
  enum {
    REG = 0,
    SIZE = 8
  };

  struct wgm;
  struct prescaler;
};

struct timer<0>::control::wgm {
  struct normal;
  struct pwm;
  struct ctc;
  struct fastpwm;
};

struct timer<0>::control::wgm::normal {
  enum {
    CONFIG = 0,
    SIZE = 8
  };
};

struct timer<0>::control::wgm::pwm {
  enum {
    CONFIG = 1,
    SIZE = 8
  };
};

struct timer<0>::control::wgm::ctc {
  enum {
    CONFIG = 2,
    SIZE = 8
  };
};

struct timer<0>::control::wgm::fastpwm {
  enum {
    CONFIG = 3,
    SIZE = 8
  };
};

struct timer<0>::control::prescaler {
  struct disable;
  template<int param> struct value;
  template<int param> struct value;
  template<int param> struct value;
  template<int param> struct value;
  template<int param> struct value;
  template<int param> struct value;
  template<int param> struct value;
};

struct timer<0>::control::prescaler::disable {
  enum {
    CONFIG = 4,
    SIZE = 8
  };
};

template<>
struct timer<0>::control::prescaler::value<0> {
  enum {
    CONFIG = 5,
    SIZE = 8
  };
};

template<>
struct timer<0>::control::prescaler::value<8> {
  enum {
    CONFIG = 6,
    SIZE = 8
  };
};

template<>
struct timer<0>::control::prescaler::value<32> {
  enum {
    CONFIG = 7,
    SIZE = 8
  };
};

template<>
struct timer<0>::control::prescaler::value<64> {
  enum {
    CONFIG = 8,
    SIZE = 8
  };
};

template<>
struct timer<0>::control::prescaler::value<128> {
  enum {
    CONFIG = 9,
    SIZE = 8
  };
};

template<>
struct timer<0>::control::prescaler::value<256> {
  enum {
    CONFIG = 10,
    SIZE = 8
  };
};

template<>
struct timer<0>::control::prescaler::value<1024> {
  enum {
    CONFIG = 11,
    SIZE = 8
  };
};

struct timer<0>::counter {
  enum {
    REG = 1,
    SIZE = 8
  };
};

template<>
struct timer<0>::compare<0> {
  enum {
    REG = 2,
    SIZE = 8
  };
};

struct timer<0>::imask {
  enum {
    REG = 3,
    SIZE = 8
  };

  template<int param> struct match;
  struct overflow;
};

template<>
struct timer<0>::imask::match<0> {
  enum {
    CONFIG = 12,
    SIZE = 8
  };
};

struct timer<0>::imask::overflow {
  enum {
    CONFIG = 13,
    SIZE = 8
  };
};

struct timer<0>::iflag {
  enum {
    REG = 4,
    SIZE = 8
  };
};

template<>
struct timer<1> {
  struct control;
  struct counter;
  template<int param> struct compare;
  template<int param> struct compare;
  struct imask;
  struct iflag;
};

struct timer<1>::control {
  enum {
    REG = 5,
    SIZE = 8
  };

  struct wgm;
  struct prescaler;
};

struct timer<1>::control::wgm {
  struct normal;
  struct pwm;
  struct ctc;
  struct fastpwm;
};

struct timer<1>::control::wgm::normal {
  enum {
    CONFIG = 14,
    SIZE = 8
  };
};

struct timer<1>::control::wgm::pwm {
  enum {
    CONFIG = 15,
    SIZE = 8
  };
};

struct timer<1>::control::wgm::ctc {
  enum {
    CONFIG = 16,
    SIZE = 8
  };
};

struct timer<1>::control::wgm::fastpwm {
  enum {
    CONFIG = 17,
    SIZE = 8
  };
};

struct timer<1>::control::prescaler {
  struct disable;
  template<int param> struct value;
  template<int param> struct value;
  template<int param> struct value;
  template<int param> struct value;
  template<int param> struct value;
};

struct timer<1>::control::prescaler::disable {
  enum {
    CONFIG = 18,
    SIZE = 8
  };
};

template<>
struct timer<1>::control::prescaler::value<0> {
  enum {
    CONFIG = 19,
    SIZE = 8
  };
};

template<>
struct timer<1>::control::prescaler::value<8> {
  enum {
    CONFIG = 20,
    SIZE = 8
  };
};

template<>
struct timer<1>::control::prescaler::value<64> {
  enum {
    CONFIG = 21,
    SIZE = 8
  };
};

template<>
struct timer<1>::control::prescaler::value<256> {
  enum {
    CONFIG = 22,
    SIZE = 8
  };
};

template<>
struct timer<1>::control::prescaler::value<1024> {
  enum {
    CONFIG = 23,
    SIZE = 8
  };
};

struct timer<1>::counter {
  enum {
    REG = 0,
    SIZE = 16
  };
};

template<>
struct timer<1>::compare<0> {
  enum {
    REG = 1,
    SIZE = 16
  };
};

template<>
struct timer<1>::compare<1> {
  enum {
    REG = 2,
    SIZE = 16
  };
};

struct timer<1>::imask {
  enum {
    REG = 6,
    SIZE = 8
  };

  template<int param> struct match;
  template<int param> struct match;
  struct overflow;
};

template<>
struct timer<1>::imask::match<0> {
  enum {
    CONFIG = 24,
    SIZE = 8
  };
};

template<>
struct timer<1>::imask::match<1> {
  enum {
    CONFIG = 25,
    SIZE = 8
  };
};

struct timer<1>::imask::overflow {
  enum {
    CONFIG = 26,
    SIZE = 8
  };
};

struct timer<1>::iflag {
  enum {
    REG = 7,
    SIZE = 8
  };
};

template<>
struct uart<0> {
  struct flag;
  struct control;
  struct baudrate;
  struct data;
};

struct uart<0>::flag {
  enum {
    REG = 8,
    SIZE = 8
  };

  struct recvend;
  struct sendend;
  struct empty;
};

struct uart<0>::flag::recvend {
  enum {
    CONFIG = 27,
    SIZE = 8
  };
};

struct uart<0>::flag::sendend {
  enum {
    CONFIG = 28,
    SIZE = 8
  };
};

struct uart<0>::flag::empty {
  enum {
    CONFIG = 29,
    SIZE = 8
  };
};

struct uart<0>::control {
  enum {
    REG = 9,
    SIZE = 8
  };

  struct synchronous;
  struct enable;
  struct ienable;
  struct flag;
  struct charsize;
  struct parity;
  struct stopbit;
};

struct uart<0>::control::synchronous {
  enum {
    CONFIG = 30,
    SIZE = 8
  };
};

struct uart<0>::control::enable {
  struct recv;
  struct send;
};

struct uart<0>::control::enable::recv {
  enum {
    CONFIG = 31,
    SIZE = 8
  };
};

struct uart<0>::control::enable::send {
  enum {
    CONFIG = 32,
    SIZE = 8
  };
};

struct uart<0>::control::ienable {
  struct recv;
  struct send;
  struct empty;
};

struct uart<0>::control::ienable::recv {
  enum {
    CONFIG = 33,
    SIZE = 8
  };
};

struct uart<0>::control::ienable::send {
  enum {
    CONFIG = 34,
    SIZE = 8
  };
};

struct uart<0>::control::ienable::empty {
  enum {
    CONFIG = 35,
    SIZE = 8
  };
};

struct uart<0>::control::flag {
  struct recvend;
  struct sendend;
  struct empty;
};

struct uart<0>::control::flag::recvend {
  enum {
    CONFIG = 36,
    SIZE = 8
  };
};

struct uart<0>::control::flag::sendend {
  enum {
    CONFIG = 37,
    SIZE = 8
  };
};

struct uart<0>::control::flag::empty {
  enum {
    CONFIG = 38,
    SIZE = 8
  };
};

struct uart<0>::control::charsize {
  template<int param> struct value;
  template<int param> struct value;
  template<int param> struct value;
  template<int param> struct value;
  template<int param> struct value;
};

template<>
struct uart<0>::control::charsize::value<5> {
  enum {
    CONFIG = 39,
    SIZE = 8
  };
};

template<>
struct uart<0>::control::charsize::value<6> {
  enum {
    CONFIG = 40,
    SIZE = 8
  };
};

template<>
struct uart<0>::control::charsize::value<7> {
  enum {
    CONFIG = 41,
    SIZE = 8
  };
};

template<>
struct uart<0>::control::charsize::value<8> {
  enum {
    CONFIG = 42,
    SIZE = 8
  };
};

template<>
struct uart<0>::control::charsize::value<9> {
  enum {
    CONFIG = 43,
    SIZE = 8
  };
};

struct uart<0>::control::parity {
  struct disabled;
  struct even;
  struct odd;
};

struct uart<0>::control::parity::disabled {
  enum {
    CONFIG = 44,
    SIZE = 8
  };
};

struct uart<0>::control::parity::even {
  enum {
    CONFIG = 45,
    SIZE = 8
  };
};

struct uart<0>::control::parity::odd {
  enum {
    CONFIG = 46,
    SIZE = 8
  };
};

struct uart<0>::control::stopbit {
  template<int param> struct value;
  template<int param> struct value;
};

template<>
struct uart<0>::control::stopbit::value<1> {
  enum {
    CONFIG = 47,
    SIZE = 8
  };
};

template<>
struct uart<0>::control::stopbit::value<2> {
  enum {
    CONFIG = 48,
    SIZE = 8
  };
};

struct uart<0>::baudrate {
  enum {
    REG = 10,
    SIZE = 8
  };
};

struct uart<0>::data {
  enum {
    REG = 11,
    SIZE = 8
  };
};

template<>
struct eeprom<0> {
  struct address;
  struct data;
  struct control;
};

struct eeprom<0>::address {
  enum {
    REG = 12,
    SIZE = 8
  };
};

struct eeprom<0>::data {
  enum {
    REG = 13,
    SIZE = 8
  };
};

struct eeprom<0>::control {
  enum {
    REG = 14,
    SIZE = 8
  };

  struct masterwrite;
  struct write;
  struct read;
};

struct eeprom<0>::control::masterwrite {
  enum {
    CONFIG = 49,
    SIZE = 8
  };
};

struct eeprom<0>::control::write {
  enum {
    CONFIG = 50,
    SIZE = 8
  };
};

struct eeprom<0>::control::read {
  enum {
    CONFIG = 51,
    SIZE = 8
  };
};

template<>
struct xmem<0> {
  struct control;
};

struct xmem<0>::control {
  enum {
    REG = 15,
    SIZE = 8
  };

  struct enable;
  struct defaultwait;
};

struct xmem<0>::control::enable {
  enum {
    CONFIG = 52,
    SIZE = 8
  };
};

struct xmem<0>::control::defaultwait {
  enum {
    CONFIG = 53,
    SIZE = 8
  };
};

struct pinmap {
  template<int param> struct control_out;
  template<int param> struct control_out;
  template<int param> struct control_out;
  template<int param> struct control_out;
  template<int param> struct control_out;
  template<int param> struct control_out;
  template<int param> struct control_out;
  template<int param> struct port;
  template<int param> struct port;
  template<int param> struct port;
  template<int param> struct port;
  template<int param> struct port;
  template<int param> struct port;
  template<int param> struct port;
  template<int param> struct pin;
  template<int param> struct pin;
  template<int param> struct pin;
  template<int param> struct pin;
  template<int param> struct pin;
  template<int param> struct pin;
  template<int param> struct pin;
};

template<>
struct pinmap::control_out<0> {
  enum {
    REG = 16,
    SIZE = 8
  };

  template<int param> struct bit;
  template<int param> struct bit;
  template<int param> struct bit;
  template<int param> struct bit;
  template<int param> struct bit;
  template<int param> struct bit;
  template<int param> struct bit;
  template<int param> struct bit;
};

template<>
struct pinmap::control_out<0>::bit<0> {
  enum {
    CONFIG = 54,
    SIZE = 8
  };
};

template<>
struct pinmap::control_out<0>::bit<1> {
  enum {
    CONFIG = 55,
    SIZE = 8
  };
};

template<>
struct pinmap::control_out<0>::bit<2> {
  enum {
    CONFIG = 56,
    SIZE = 8
  };
};

template<>
struct pinmap::control_out<0>::bit<3> {
  enum {
    CONFIG = 57,
    SIZE = 8
  };
};

template<>
struct pinmap::control_out<0>::bit<4> {
  enum {
    CONFIG = 58,
    SIZE = 8
  };
};

template<>
struct pinmap::control_out<0>::bit<5> {
  enum {
    CONFIG = 59,
    SIZE = 8
  };
};

template<>
struct pinmap::control_out<0>::bit<6> {
  enum {
    CONFIG = 60,
    SIZE = 8
  };
};

template<>
struct pinmap::control_out<0>::bit<7> {
  enum {
    CONFIG = 61,
    SIZE = 8
  };
};

template<>
struct pinmap::control_out<1> {
  enum {
    REG = 17,
    SIZE = 8
  };

  template<int param> struct bit;
  template<int param> struct bit;
  template<int param> struct bit;
  template<int param> struct bit;
  template<int param> struct bit;
  template<int param> struct bit;
  template<int param> struct bit;
  template<int param> struct bit;
};

template<>
struct pinmap::control_out<1>::bit<0> {
  enum {
    CONFIG = 62,
    SIZE = 8
  };
};

template<>
struct pinmap::control_out<1>::bit<1> {
  enum {
    CONFIG = 63,
    SIZE = 8
  };
};

template<>
struct pinmap::control_out<1>::bit<2> {
  enum {
    CONFIG = 64,
    SIZE = 8
  };
};

template<>
struct pinmap::control_out<1>::bit<3> {
  enum {
    CONFIG = 65,
    SIZE = 8
  };
};

template<>
struct pinmap::control_out<1>::bit<4> {
  enum {
    CONFIG = 66,
    SIZE = 8
  };
};

template<>
struct pinmap::control_out<1>::bit<5> {
  enum {
    CONFIG = 67,
    SIZE = 8
  };
};

template<>
struct pinmap::control_out<1>::bit<6> {
  enum {
    CONFIG = 68,
    SIZE = 8
  };
};

template<>
struct pinmap::control_out<1>::bit<7> {
  enum {
    CONFIG = 69,
    SIZE = 8
  };
};

template<>
struct pinmap::control_out<2> {
  enum {
    REG = 18,
    SIZE = 8
  };

  template<int param> struct bit;
  template<int param> struct bit;
  template<int param> struct bit;
  template<int param> struct bit;
  template<int param> struct bit;
  template<int param> struct bit;
  template<int param> struct bit;
  template<int param> struct bit;
};

template<>
struct pinmap::control_out<2>::bit<0> {
  enum {
    CONFIG = 70,
    SIZE = 8
  };
};

template<>
struct pinmap::control_out<2>::bit<1> {
  enum {
    CONFIG = 71,
    SIZE = 8
  };
};

template<>
struct pinmap::control_out<2>::bit<2> {
  enum {
    CONFIG = 72,
    SIZE = 8
  };
};

template<>
struct pinmap::control_out<2>::bit<3> {
  enum {
    CONFIG = 73,
    SIZE = 8
  };
};

template<>
struct pinmap::control_out<2>::bit<4> {
  enum {
    CONFIG = 74,
    SIZE = 8
  };
};

template<>
struct pinmap::control_out<2>::bit<5> {
  enum {
    CONFIG = 75,
    SIZE = 8
  };
};

template<>
struct pinmap::control_out<2>::bit<6> {
  enum {
    CONFIG = 76,
    SIZE = 8
  };
};

template<>
struct pinmap::control_out<2>::bit<7> {
  enum {
    CONFIG = 77,
    SIZE = 8
  };
};

template<>
struct pinmap::control_out<3> {
  enum {
    REG = 19,
    SIZE = 8
  };

  template<int param> struct bit;
  template<int param> struct bit;
  template<int param> struct bit;
  template<int param> struct bit;
  template<int param> struct bit;
  template<int param> struct bit;
  template<int param> struct bit;
  template<int param> struct bit;
};

template<>
struct pinmap::control_out<3>::bit<0> {
  enum {
    CONFIG = 78,
    SIZE = 8
  };
};

template<>
struct pinmap::control_out<3>::bit<1> {
  enum {
    CONFIG = 79,
    SIZE = 8
  };
};

template<>
struct pinmap::control_out<3>::bit<2> {
  enum {
    CONFIG = 80,
    SIZE = 8
  };
};

template<>
struct pinmap::control_out<3>::bit<3> {
  enum {
    CONFIG = 81,
    SIZE = 8
  };
};

template<>
struct pinmap::control_out<3>::bit<4> {
  enum {
    CONFIG = 82,
    SIZE = 8
  };
};

template<>
struct pinmap::control_out<3>::bit<5> {
  enum {
    CONFIG = 83,
    SIZE = 8
  };
};

template<>
struct pinmap::control_out<3>::bit<6> {
  enum {
    CONFIG = 84,
    SIZE = 8
  };
};

template<>
struct pinmap::control_out<3>::bit<7> {
  enum {
    CONFIG = 85,
    SIZE = 8
  };
};

template<>
struct pinmap::control_out<4> {
  enum {
    REG = 20,
    SIZE = 8
  };

  template<int param> struct bit;
  template<int param> struct bit;
  template<int param> struct bit;
  template<int param> struct bit;
  template<int param> struct bit;
  template<int param> struct bit;
  template<int param> struct bit;
  template<int param> struct bit;
};

template<>
struct pinmap::control_out<4>::bit<0> {
  enum {
    CONFIG = 86,
    SIZE = 8
  };
};

template<>
struct pinmap::control_out<4>::bit<1> {
  enum {
    CONFIG = 87,
    SIZE = 8
  };
};

template<>
struct pinmap::control_out<4>::bit<2> {
  enum {
    CONFIG = 88,
    SIZE = 8
  };
};

template<>
struct pinmap::control_out<4>::bit<3> {
  enum {
    CONFIG = 89,
    SIZE = 8
  };
};

template<>
struct pinmap::control_out<4>::bit<4> {
  enum {
    CONFIG = 90,
    SIZE = 8
  };
};

template<>
struct pinmap::control_out<4>::bit<5> {
  enum {
    CONFIG = 91,
    SIZE = 8
  };
};

template<>
struct pinmap::control_out<4>::bit<6> {
  enum {
    CONFIG = 92,
    SIZE = 8
  };
};

template<>
struct pinmap::control_out<4>::bit<7> {
  enum {
    CONFIG = 93,
    SIZE = 8
  };
};

template<>
struct pinmap::control_out<5> {
  enum {
    REG = 21,
    SIZE = 8
  };

  template<int param> struct bit;
  template<int param> struct bit;
  template<int param> struct bit;
  template<int param> struct bit;
  template<int param> struct bit;
  template<int param> struct bit;
  template<int param> struct bit;
  template<int param> struct bit;
};

template<>
struct pinmap::control_out<5>::bit<0> {
  enum {
    CONFIG = 94,
    SIZE = 8
  };
};

template<>
struct pinmap::control_out<5>::bit<1> {
  enum {
    CONFIG = 95,
    SIZE = 8
  };
};

template<>
struct pinmap::control_out<5>::bit<2> {
  enum {
    CONFIG = 96,
    SIZE = 8
  };
};

template<>
struct pinmap::control_out<5>::bit<3> {
  enum {
    CONFIG = 97,
    SIZE = 8
  };
};

template<>
struct pinmap::control_out<5>::bit<4> {
  enum {
    CONFIG = 98,
    SIZE = 8
  };
};

template<>
struct pinmap::control_out<5>::bit<5> {
  enum {
    CONFIG = 99,
    SIZE = 8
  };
};

template<>
struct pinmap::control_out<5>::bit<6> {
  enum {
    CONFIG = 100,
    SIZE = 8
  };
};

template<>
struct pinmap::control_out<5>::bit<7> {
  enum {
    CONFIG = 101,
    SIZE = 8
  };
};

template<>
struct pinmap::control_out<6> {
  enum {
    REG = 22,
    SIZE = 8
  };

  template<int param> struct bit;
  template<int param> struct bit;
  template<int param> struct bit;
  template<int param> struct bit;
  template<int param> struct bit;
  template<int param> struct bit;
  template<int param> struct bit;
  template<int param> struct bit;
};

template<>
struct pinmap::control_out<6>::bit<0> {
  enum {
    CONFIG = 102,
    SIZE = 8
  };
};

template<>
struct pinmap::control_out<6>::bit<1> {
  enum {
    CONFIG = 103,
    SIZE = 8
  };
};

template<>
struct pinmap::control_out<6>::bit<2> {
  enum {
    CONFIG = 104,
    SIZE = 8
  };
};

template<>
struct pinmap::control_out<6>::bit<3> {
  enum {
    CONFIG = 105,
    SIZE = 8
  };
};

template<>
struct pinmap::control_out<6>::bit<4> {
  enum {
    CONFIG = 106,
    SIZE = 8
  };
};

template<>
struct pinmap::control_out<6>::bit<5> {
  enum {
    CONFIG = 107,
    SIZE = 8
  };
};

template<>
struct pinmap::control_out<6>::bit<6> {
  enum {
    CONFIG = 108,
    SIZE = 8
  };
};

template<>
struct pinmap::control_out<6>::bit<7> {
  enum {
    CONFIG = 109,
    SIZE = 8
  };
};

template<>
struct pinmap::port<0> {
  enum {
    REG = 23,
    SIZE = 8
  };

  template<int param> struct bit;
  template<int param> struct bit;
  template<int param> struct bit;
  template<int param> struct bit;
  template<int param> struct bit;
  template<int param> struct bit;
  template<int param> struct bit;
  template<int param> struct bit;
};

template<>
struct pinmap::port<0>::bit<0> {
  enum {
    CONFIG = 110,
    SIZE = 8
  };
};

template<>
struct pinmap::port<0>::bit<1> {
  enum {
    CONFIG = 111,
    SIZE = 8
  };
};

template<>
struct pinmap::port<0>::bit<2> {
  enum {
    CONFIG = 112,
    SIZE = 8
  };
};

template<>
struct pinmap::port<0>::bit<3> {
  enum {
    CONFIG = 113,
    SIZE = 8
  };
};

template<>
struct pinmap::port<0>::bit<4> {
  enum {
    CONFIG = 114,
    SIZE = 8
  };
};

template<>
struct pinmap::port<0>::bit<5> {
  enum {
    CONFIG = 115,
    SIZE = 8
  };
};

template<>
struct pinmap::port<0>::bit<6> {
  enum {
    CONFIG = 116,
    SIZE = 8
  };
};

template<>
struct pinmap::port<0>::bit<7> {
  enum {
    CONFIG = 117,
    SIZE = 8
  };
};

template<>
struct pinmap::port<1> {
  enum {
    REG = 24,
    SIZE = 8
  };

  template<int param> struct bit;
  template<int param> struct bit;
  template<int param> struct bit;
  template<int param> struct bit;
  template<int param> struct bit;
  template<int param> struct bit;
  template<int param> struct bit;
  template<int param> struct bit;
};

template<>
struct pinmap::port<1>::bit<0> {
  enum {
    CONFIG = 118,
    SIZE = 8
  };
};

template<>
struct pinmap::port<1>::bit<1> {
  enum {
    CONFIG = 119,
    SIZE = 8
  };
};

template<>
struct pinmap::port<1>::bit<2> {
  enum {
    CONFIG = 120,
    SIZE = 8
  };
};

template<>
struct pinmap::port<1>::bit<3> {
  enum {
    CONFIG = 121,
    SIZE = 8
  };
};

template<>
struct pinmap::port<1>::bit<4> {
  enum {
    CONFIG = 122,
    SIZE = 8
  };
};

template<>
struct pinmap::port<1>::bit<5> {
  enum {
    CONFIG = 123,
    SIZE = 8
  };
};

template<>
struct pinmap::port<1>::bit<6> {
  enum {
    CONFIG = 124,
    SIZE = 8
  };
};

template<>
struct pinmap::port<1>::bit<7> {
  enum {
    CONFIG = 125,
    SIZE = 8
  };
};

template<>
struct pinmap::port<2> {
  enum {
    REG = 25,
    SIZE = 8
  };

  template<int param> struct bit;
  template<int param> struct bit;
  template<int param> struct bit;
  template<int param> struct bit;
  template<int param> struct bit;
  template<int param> struct bit;
  template<int param> struct bit;
  template<int param> struct bit;
};

template<>
struct pinmap::port<2>::bit<0> {
  enum {
    CONFIG = 126,
    SIZE = 8
  };
};

template<>
struct pinmap::port<2>::bit<1> {
  enum {
    CONFIG = 127,
    SIZE = 8
  };
};

template<>
struct pinmap::port<2>::bit<2> {
  enum {
    CONFIG = 128,
    SIZE = 8
  };
};

template<>
struct pinmap::port<2>::bit<3> {
  enum {
    CONFIG = 129,
    SIZE = 8
  };
};

template<>
struct pinmap::port<2>::bit<4> {
  enum {
    CONFIG = 130,
    SIZE = 8
  };
};

template<>
struct pinmap::port<2>::bit<5> {
  enum {
    CONFIG = 131,
    SIZE = 8
  };
};

template<>
struct pinmap::port<2>::bit<6> {
  enum {
    CONFIG = 132,
    SIZE = 8
  };
};

template<>
struct pinmap::port<2>::bit<7> {
  enum {
    CONFIG = 133,
    SIZE = 8
  };
};

template<>
struct pinmap::port<3> {
  enum {
    REG = 26,
    SIZE = 8
  };

  template<int param> struct bit;
  template<int param> struct bit;
  template<int param> struct bit;
  template<int param> struct bit;
  template<int param> struct bit;
  template<int param> struct bit;
  template<int param> struct bit;
  template<int param> struct bit;
};

template<>
struct pinmap::port<3>::bit<0> {
  enum {
    CONFIG = 134,
    SIZE = 8
  };
};

template<>
struct pinmap::port<3>::bit<1> {
  enum {
    CONFIG = 135,
    SIZE = 8
  };
};

template<>
struct pinmap::port<3>::bit<2> {
  enum {
    CONFIG = 136,
    SIZE = 8
  };
};

template<>
struct pinmap::port<3>::bit<3> {
  enum {
    CONFIG = 137,
    SIZE = 8
  };
};

template<>
struct pinmap::port<3>::bit<4> {
  enum {
    CONFIG = 138,
    SIZE = 8
  };
};

template<>
struct pinmap::port<3>::bit<5> {
  enum {
    CONFIG = 139,
    SIZE = 8
  };
};

template<>
struct pinmap::port<3>::bit<6> {
  enum {
    CONFIG = 140,
    SIZE = 8
  };
};

template<>
struct pinmap::port<3>::bit<7> {
  enum {
    CONFIG = 141,
    SIZE = 8
  };
};

template<>
struct pinmap::port<4> {
  enum {
    REG = 27,
    SIZE = 8
  };

  template<int param> struct bit;
  template<int param> struct bit;
  template<int param> struct bit;
  template<int param> struct bit;
  template<int param> struct bit;
  template<int param> struct bit;
  template<int param> struct bit;
  template<int param> struct bit;
};

template<>
struct pinmap::port<4>::bit<0> {
  enum {
    CONFIG = 142,
    SIZE = 8
  };
};

template<>
struct pinmap::port<4>::bit<1> {
  enum {
    CONFIG = 143,
    SIZE = 8
  };
};

template<>
struct pinmap::port<4>::bit<2> {
  enum {
    CONFIG = 144,
    SIZE = 8
  };
};

template<>
struct pinmap::port<4>::bit<3> {
  enum {
    CONFIG = 145,
    SIZE = 8
  };
};

template<>
struct pinmap::port<4>::bit<4> {
  enum {
    CONFIG = 146,
    SIZE = 8
  };
};

template<>
struct pinmap::port<4>::bit<5> {
  enum {
    CONFIG = 147,
    SIZE = 8
  };
};

template<>
struct pinmap::port<4>::bit<6> {
  enum {
    CONFIG = 148,
    SIZE = 8
  };
};

template<>
struct pinmap::port<4>::bit<7> {
  enum {
    CONFIG = 149,
    SIZE = 8
  };
};

template<>
struct pinmap::port<5> {
  enum {
    REG = 28,
    SIZE = 8
  };

  template<int param> struct bit;
  template<int param> struct bit;
  template<int param> struct bit;
  template<int param> struct bit;
  template<int param> struct bit;
  template<int param> struct bit;
  template<int param> struct bit;
  template<int param> struct bit;
};

template<>
struct pinmap::port<5>::bit<0> {
  enum {
    CONFIG = 150,
    SIZE = 8
  };
};

template<>
struct pinmap::port<5>::bit<1> {
  enum {
    CONFIG = 151,
    SIZE = 8
  };
};

template<>
struct pinmap::port<5>::bit<2> {
  enum {
    CONFIG = 152,
    SIZE = 8
  };
};

template<>
struct pinmap::port<5>::bit<3> {
  enum {
    CONFIG = 153,
    SIZE = 8
  };
};

template<>
struct pinmap::port<5>::bit<4> {
  enum {
    CONFIG = 154,
    SIZE = 8
  };
};

template<>
struct pinmap::port<5>::bit<5> {
  enum {
    CONFIG = 155,
    SIZE = 8
  };
};

template<>
struct pinmap::port<5>::bit<6> {
  enum {
    CONFIG = 156,
    SIZE = 8
  };
};

template<>
struct pinmap::port<5>::bit<7> {
  enum {
    CONFIG = 157,
    SIZE = 8
  };
};

template<>
struct pinmap::port<6> {
  enum {
    REG = 29,
    SIZE = 8
  };

  template<int param> struct bit;
  template<int param> struct bit;
  template<int param> struct bit;
  template<int param> struct bit;
  template<int param> struct bit;
  template<int param> struct bit;
  template<int param> struct bit;
  template<int param> struct bit;
};

template<>
struct pinmap::port<6>::bit<0> {
  enum {
    CONFIG = 158,
    SIZE = 8
  };
};

template<>
struct pinmap::port<6>::bit<1> {
  enum {
    CONFIG = 159,
    SIZE = 8
  };
};

template<>
struct pinmap::port<6>::bit<2> {
  enum {
    CONFIG = 160,
    SIZE = 8
  };
};

template<>
struct pinmap::port<6>::bit<3> {
  enum {
    CONFIG = 161,
    SIZE = 8
  };
};

template<>
struct pinmap::port<6>::bit<4> {
  enum {
    CONFIG = 162,
    SIZE = 8
  };
};

template<>
struct pinmap::port<6>::bit<5> {
  enum {
    CONFIG = 163,
    SIZE = 8
  };
};

template<>
struct pinmap::port<6>::bit<6> {
  enum {
    CONFIG = 164,
    SIZE = 8
  };
};

template<>
struct pinmap::port<6>::bit<7> {
  enum {
    CONFIG = 165,
    SIZE = 8
  };
};

template<>
struct pinmap::pin<0> {
  enum {
    REG = 30,
    SIZE = 8
  };

  template<int param> struct bit;
  template<int param> struct bit;
  template<int param> struct bit;
  template<int param> struct bit;
  template<int param> struct bit;
  template<int param> struct bit;
  template<int param> struct bit;
  template<int param> struct bit;
};

template<>
struct pinmap::pin<0>::bit<0> {
  enum {
    CONFIG = 166,
    SIZE = 8
  };
};

template<>
struct pinmap::pin<0>::bit<1> {
  enum {
    CONFIG = 167,
    SIZE = 8
  };
};

template<>
struct pinmap::pin<0>::bit<2> {
  enum {
    CONFIG = 168,
    SIZE = 8
  };
};

template<>
struct pinmap::pin<0>::bit<3> {
  enum {
    CONFIG = 169,
    SIZE = 8
  };
};

template<>
struct pinmap::pin<0>::bit<4> {
  enum {
    CONFIG = 170,
    SIZE = 8
  };
};

template<>
struct pinmap::pin<0>::bit<5> {
  enum {
    CONFIG = 171,
    SIZE = 8
  };
};

template<>
struct pinmap::pin<0>::bit<6> {
  enum {
    CONFIG = 172,
    SIZE = 8
  };
};

template<>
struct pinmap::pin<0>::bit<7> {
  enum {
    CONFIG = 173,
    SIZE = 8
  };
};

template<>
struct pinmap::pin<1> {
  enum {
    REG = 31,
    SIZE = 8
  };

  template<int param> struct bit;
  template<int param> struct bit;
  template<int param> struct bit;
  template<int param> struct bit;
  template<int param> struct bit;
  template<int param> struct bit;
  template<int param> struct bit;
  template<int param> struct bit;
};

template<>
struct pinmap::pin<1>::bit<0> {
  enum {
    CONFIG = 174,
    SIZE = 8
  };
};

template<>
struct pinmap::pin<1>::bit<1> {
  enum {
    CONFIG = 175,
    SIZE = 8
  };
};

template<>
struct pinmap::pin<1>::bit<2> {
  enum {
    CONFIG = 176,
    SIZE = 8
  };
};

template<>
struct pinmap::pin<1>::bit<3> {
  enum {
    CONFIG = 177,
    SIZE = 8
  };
};

template<>
struct pinmap::pin<1>::bit<4> {
  enum {
    CONFIG = 178,
    SIZE = 8
  };
};

template<>
struct pinmap::pin<1>::bit<5> {
  enum {
    CONFIG = 179,
    SIZE = 8
  };
};

template<>
struct pinmap::pin<1>::bit<6> {
  enum {
    CONFIG = 180,
    SIZE = 8
  };
};

template<>
struct pinmap::pin<1>::bit<7> {
  enum {
    CONFIG = 181,
    SIZE = 8
  };
};

template<>
struct pinmap::pin<2> {
  enum {
    REG = 32,
    SIZE = 8
  };

  template<int param> struct bit;
  template<int param> struct bit;
  template<int param> struct bit;
  template<int param> struct bit;
  template<int param> struct bit;
  template<int param> struct bit;
  template<int param> struct bit;
  template<int param> struct bit;
};

template<>
struct pinmap::pin<2>::bit<0> {
  enum {
    CONFIG = 182,
    SIZE = 8
  };
};

template<>
struct pinmap::pin<2>::bit<1> {
  enum {
    CONFIG = 183,
    SIZE = 8
  };
};

template<>
struct pinmap::pin<2>::bit<2> {
  enum {
    CONFIG = 184,
    SIZE = 8
  };
};

template<>
struct pinmap::pin<2>::bit<3> {
  enum {
    CONFIG = 185,
    SIZE = 8
  };
};

template<>
struct pinmap::pin<2>::bit<4> {
  enum {
    CONFIG = 186,
    SIZE = 8
  };
};

template<>
struct pinmap::pin<2>::bit<5> {
  enum {
    CONFIG = 187,
    SIZE = 8
  };
};

template<>
struct pinmap::pin<2>::bit<6> {
  enum {
    CONFIG = 188,
    SIZE = 8
  };
};

template<>
struct pinmap::pin<2>::bit<7> {
  enum {
    CONFIG = 189,
    SIZE = 8
  };
};

template<>
struct pinmap::pin<3> {
  enum {
    REG = 33,
    SIZE = 8
  };

  template<int param> struct bit;
  template<int param> struct bit;
  template<int param> struct bit;
  template<int param> struct bit;
  template<int param> struct bit;
  template<int param> struct bit;
  template<int param> struct bit;
  template<int param> struct bit;
};

template<>
struct pinmap::pin<3>::bit<0> {
  enum {
    CONFIG = 190,
    SIZE = 8
  };
};

template<>
struct pinmap::pin<3>::bit<1> {
  enum {
    CONFIG = 191,
    SIZE = 8
  };
};

template<>
struct pinmap::pin<3>::bit<2> {
  enum {
    CONFIG = 192,
    SIZE = 8
  };
};

template<>
struct pinmap::pin<3>::bit<3> {
  enum {
    CONFIG = 193,
    SIZE = 8
  };
};

template<>
struct pinmap::pin<3>::bit<4> {
  enum {
    CONFIG = 194,
    SIZE = 8
  };
};

template<>
struct pinmap::pin<3>::bit<5> {
  enum {
    CONFIG = 195,
    SIZE = 8
  };
};

template<>
struct pinmap::pin<3>::bit<6> {
  enum {
    CONFIG = 196,
    SIZE = 8
  };
};

template<>
struct pinmap::pin<3>::bit<7> {
  enum {
    CONFIG = 197,
    SIZE = 8
  };
};

template<>
struct pinmap::pin<4> {
  enum {
    REG = 34,
    SIZE = 8
  };

  template<int param> struct bit;
  template<int param> struct bit;
  template<int param> struct bit;
  template<int param> struct bit;
  template<int param> struct bit;
  template<int param> struct bit;
  template<int param> struct bit;
  template<int param> struct bit;
};

template<>
struct pinmap::pin<4>::bit<0> {
  enum {
    CONFIG = 198,
    SIZE = 8
  };
};

template<>
struct pinmap::pin<4>::bit<1> {
  enum {
    CONFIG = 199,
    SIZE = 8
  };
};

template<>
struct pinmap::pin<4>::bit<2> {
  enum {
    CONFIG = 200,
    SIZE = 8
  };
};

template<>
struct pinmap::pin<4>::bit<3> {
  enum {
    CONFIG = 201,
    SIZE = 8
  };
};

template<>
struct pinmap::pin<4>::bit<4> {
  enum {
    CONFIG = 202,
    SIZE = 8
  };
};

template<>
struct pinmap::pin<4>::bit<5> {
  enum {
    CONFIG = 203,
    SIZE = 8
  };
};

template<>
struct pinmap::pin<4>::bit<6> {
  enum {
    CONFIG = 204,
    SIZE = 8
  };
};

template<>
struct pinmap::pin<4>::bit<7> {
  enum {
    CONFIG = 205,
    SIZE = 8
  };
};

template<>
struct pinmap::pin<5> {
  enum {
    REG = 35,
    SIZE = 8
  };

  template<int param> struct bit;
  template<int param> struct bit;
  template<int param> struct bit;
  template<int param> struct bit;
  template<int param> struct bit;
  template<int param> struct bit;
  template<int param> struct bit;
  template<int param> struct bit;
};

template<>
struct pinmap::pin<5>::bit<0> {
  enum {
    CONFIG = 206,
    SIZE = 8
  };
};

template<>
struct pinmap::pin<5>::bit<1> {
  enum {
    CONFIG = 207,
    SIZE = 8
  };
};

template<>
struct pinmap::pin<5>::bit<2> {
  enum {
    CONFIG = 208,
    SIZE = 8
  };
};

template<>
struct pinmap::pin<5>::bit<3> {
  enum {
    CONFIG = 209,
    SIZE = 8
  };
};

template<>
struct pinmap::pin<5>::bit<4> {
  enum {
    CONFIG = 210,
    SIZE = 8
  };
};

template<>
struct pinmap::pin<5>::bit<5> {
  enum {
    CONFIG = 211,
    SIZE = 8
  };
};

template<>
struct pinmap::pin<5>::bit<6> {
  enum {
    CONFIG = 212,
    SIZE = 8
  };
};

template<>
struct pinmap::pin<5>::bit<7> {
  enum {
    CONFIG = 213,
    SIZE = 8
  };
};

template<>
struct pinmap::pin<6> {
  enum {
    REG = 36,
    SIZE = 8
  };

  template<int param> struct bit;
  template<int param> struct bit;
  template<int param> struct bit;
  template<int param> struct bit;
  template<int param> struct bit;
  template<int param> struct bit;
  template<int param> struct bit;
  template<int param> struct bit;
};

template<>
struct pinmap::pin<6>::bit<0> {
  enum {
    CONFIG = 214,
    SIZE = 8
  };
};

template<>
struct pinmap::pin<6>::bit<1> {
  enum {
    CONFIG = 215,
    SIZE = 8
  };
};

template<>
struct pinmap::pin<6>::bit<2> {
  enum {
    CONFIG = 216,
    SIZE = 8
  };
};

template<>
struct pinmap::pin<6>::bit<3> {
  enum {
    CONFIG = 217,
    SIZE = 8
  };
};

template<>
struct pinmap::pin<6>::bit<4> {
  enum {
    CONFIG = 218,
    SIZE = 8
  };
};

template<>
struct pinmap::pin<6>::bit<5> {
  enum {
    CONFIG = 219,
    SIZE = 8
  };
};

template<>
struct pinmap::pin<6>::bit<6> {
  enum {
    CONFIG = 220,
    SIZE = 8
  };
};

template<>
struct pinmap::pin<6>::bit<7> {
  enum {
    CONFIG = 221,
    SIZE = 8
  };
};

template<> inline Register<8, 0>::Register(void) : reg_size(1), reg{(u8*)&TCCR0} {}
template<> inline Config<8, 0>::Config(void) : conf{0} {}
template<> inline Config<8, 1>::Config(void) : conf{(1 << WGM00)} {}
template<> inline Config<8, 2>::Config(void) : conf{(1 << WGM01)} {}
template<> inline Config<8, 3>::Config(void) : conf{0} {}
template<> inline Config<8, 4>::Config(void) : conf{(0 << CS02) | (0 << CS01) | (0 << CS00)} {}
template<> inline Config<8, 5>::Config(void) : conf{(0 << CS02) | (0 << CS01) | (1 << CS00)} {}
template<> inline Config<8, 6>::Config(void) : conf{(0 << CS02) | (1 << CS01) | (0 << CS00)} {}
template<> inline Config<8, 7>::Config(void) : conf{(0 << CS02) | (1 << CS01) | (1 << CS00)} {}
template<> inline Config<8, 8>::Config(void) : conf{(1 << CS02) | (0 << CS01) | (0 << CS00)} {}
template<> inline Config<8, 9>::Config(void) : conf{(1 << CS02) | (0 << CS01) | (1 << CS00)} {}
template<> inline Config<8, 10>::Config(void) : conf{(1 << CS02) | (1 << CS01) | (0 << CS00)} {}
template<> inline Config<8, 11>::Config(void) : conf{(1 << CS02) | (1 << CS01) | (1 << CS00)} {}
template<> inline Register<8, 1>::Register(void) : reg_size(1), reg{(u8*)&TCNT0} {}
template<> inline Register<8, 2>::Register(void) : reg_size(1), reg{(u8*)&OCR0} {}
template<> inline Register<8, 3>::Register(void) : reg_size(1), reg{(u8*)&TIMSK} {}
template<> inline Config<8, 12>::Config(void) : conf{(1 << OCIE0)} {}
template<> inline Config<8, 13>::Config(void) : conf{(1 << TOIE0)} {}
template<> inline Register<8, 4>::Register(void) : reg_size(1), reg{(u8*)&TIFR} {}
template<> inline Register<8, 5>::Register(void) : reg_size(3), reg{(u8*)&TCCR1A, (u8*)&TCCR1B, (u8*)&TCCR1C} {}
template<> inline Config<8, 14>::Config(void) : conf{0, 0, 0} {}
template<> inline Config<8, 15>::Config(void) : conf{(1 << WGM10) | (1 << WGM11), 0, 0} {}
template<> inline Config<8, 16>::Config(void) : conf{0, (1 << WGM12), 0} {}
template<> inline Config<8, 17>::Config(void) : conf{(1 << WGM10) | (1 << WGM11), (1 << WGM12), 0} {}
template<> inline Config<8, 18>::Config(void) : conf{0, (0 << CS12) | (0 << CS11) | (0 << CS10), 0} {}
template<> inline Config<8, 19>::Config(void) : conf{0, (0 << CS12) | (0 << CS11) | (1 << CS10), 0} {}
template<> inline Config<8, 20>::Config(void) : conf{0, (0 << CS12) | (1 << CS11) | (0 << CS10), 0} {}
template<> inline Config<8, 21>::Config(void) : conf{0, (0 << CS12) | (1 << CS11) | (1 << CS10), 0} {}
template<> inline Config<8, 22>::Config(void) : conf{0, (1 << CS12) | (0 << CS11) | (0 << CS10), 0} {}
template<> inline Config<8, 23>::Config(void) : conf{0, (1 << CS12) | (0 << CS11) | (1 << CS10), 0} {}
template<> inline Register<16, 0>::Register(void) : reg_size(1), reg{(u16*)&TCNT1} {}
template<> inline Register<16, 1>::Register(void) : reg_size(1), reg{(u16*)&OCR1A} {}
template<> inline Register<16, 2>::Register(void) : reg_size(1), reg{(u16*)&OCR1B} {}
template<> inline Register<8, 6>::Register(void) : reg_size(1), reg{(u8*)&TIMSK} {}
template<> inline Config<8, 24>::Config(void) : conf{(1 << OCIE1A)} {}
template<> inline Config<8, 25>::Config(void) : conf{(1 << OCIE1B)} {}
template<> inline Config<8, 26>::Config(void) : conf{(1 << TOIE1)} {}
template<> inline Register<8, 7>::Register(void) : reg_size(1), reg{(u8*)&TIFR} {}
template<> inline Register<8, 8>::Register(void) : reg_size(1), reg{(u8*)&UCSR0A} {}
template<> inline Config<8, 27>::Config(void) : conf{(1 << RXC0)} {}
template<> inline Config<8, 28>::Config(void) : conf{(1 << TXC0)} {}
template<> inline Config<8, 29>::Config(void) : conf{(1 << UDRE0)} {}
template<> inline Register<8, 9>::Register(void) : reg_size(3), reg{(u8*)&UCSR0A, (u8*)&UCSR0B, (u8*)&UCSR0C} {}
template<> inline Config<8, 30>::Config(void) : conf{0, 0, (1 << UMSEL0)} {}
template<> inline Config<8, 31>::Config(void) : conf{0, (1 << RXEN0), 0} {}
template<> inline Config<8, 32>::Config(void) : conf{0, (1 << TXEN0), 0} {}
template<> inline Config<8, 33>::Config(void) : conf{0, (1 << RXCIE0), 0} {}
template<> inline Config<8, 34>::Config(void) : conf{0, (1 << TXCIE0), 0} {}
template<> inline Config<8, 35>::Config(void) : conf{0, (1 << UDRIE0), 0} {}
template<> inline Config<8, 36>::Config(void) : conf{(1 << RXC0), 0, 0} {}
template<> inline Config<8, 37>::Config(void) : conf{(1 << TXC0), 0, 0} {}
template<> inline Config<8, 38>::Config(void) : conf{(1 << UDRE0), 0, 0} {}
template<> inline Config<8, 39>::Config(void) : conf{0, (0 << UCSZ2), (0 << UCSZ1) | (0 << UCSZ0)} {}
template<> inline Config<8, 40>::Config(void) : conf{0, (0 << UCSZ2), (0 << UCSZ1) | (1 << UCSZ0)} {}
template<> inline Config<8, 41>::Config(void) : conf{0, (0 << UCSZ2), (1 << UCSZ1) | (0 << UCSZ0)} {}
template<> inline Config<8, 42>::Config(void) : conf{0, (0 << UCSZ2), (1 << UCSZ1) | (1 << UCSZ0)} {}
template<> inline Config<8, 43>::Config(void) : conf{0, (1 << UCSZ2), (1 << UCSZ1) | (1 << UCSZ0)} {}
template<> inline Config<8, 44>::Config(void) : conf{0, 0, 0} {}
template<> inline Config<8, 45>::Config(void) : conf{0, 0, (1 << UPM01)} {}
template<> inline Config<8, 46>::Config(void) : conf{0, 0, (1 << UPM01) | (1 << UPM00)} {}
template<> inline Config<8, 47>::Config(void) : conf{0, 0, 0} {}
template<> inline Config<8, 48>::Config(void) : conf{0, 0, (1 << USBS0)} {}
template<> inline Register<8, 10>::Register(void) : reg_size(2), reg{(u8*)&UBRR0L, (u8*)&UBRR0H} {}
template<> inline Register<8, 11>::Register(void) : reg_size(1), reg{(u8*)&UDR0} {}
template<> inline Register<8, 12>::Register(void) : reg_size(2), reg{(u8*)&EEARL, (u8*)&EEARH} {}
template<> inline Register<8, 13>::Register(void) : reg_size(1), reg{(u8*)&EEDR} {}
template<> inline Register<8, 14>::Register(void) : reg_size(1), reg{(u8*)&EECR} {}
template<> inline Config<8, 49>::Config(void) : conf{(1 << EEMWE)} {}
template<> inline Config<8, 50>::Config(void) : conf{(1 << EEWE)} {}
template<> inline Config<8, 51>::Config(void) : conf{(1 << EERE)} {}
template<> inline Register<8, 15>::Register(void) : reg_size(2), reg{(u8*)&MCUCR, (u8*)&XMCRA} {}
template<> inline Config<8, 52>::Config(void) : conf{(1 << SRE), 0} {}
template<> inline Config<8, 53>::Config(void) : conf{0, (1 << SRW11) | (1 << SRW00)} {}
template<> inline Register<8, 16>::Register(void) : reg_size(1), reg{(u8*)&DDRA} {}
template<> inline Config<8, 54>::Config(void) : conf{(1 << 0)} {}
template<> inline Config<8, 55>::Config(void) : conf{(1 << 1)} {}
template<> inline Config<8, 56>::Config(void) : conf{(1 << 2)} {}
template<> inline Config<8, 57>::Config(void) : conf{(1 << 3)} {}
template<> inline Config<8, 58>::Config(void) : conf{(1 << 4)} {}
template<> inline Config<8, 59>::Config(void) : conf{(1 << 5)} {}
template<> inline Config<8, 60>::Config(void) : conf{(1 << 6)} {}
template<> inline Config<8, 61>::Config(void) : conf{(1 << 7)} {}
template<> inline Register<8, 17>::Register(void) : reg_size(1), reg{(u8*)&DDRB} {}
template<> inline Config<8, 62>::Config(void) : conf{(1 << 0)} {}
template<> inline Config<8, 63>::Config(void) : conf{(1 << 1)} {}
template<> inline Config<8, 64>::Config(void) : conf{(1 << 2)} {}
template<> inline Config<8, 65>::Config(void) : conf{(1 << 3)} {}
template<> inline Config<8, 66>::Config(void) : conf{(1 << 4)} {}
template<> inline Config<8, 67>::Config(void) : conf{(1 << 5)} {}
template<> inline Config<8, 68>::Config(void) : conf{(1 << 6)} {}
template<> inline Config<8, 69>::Config(void) : conf{(1 << 7)} {}
template<> inline Register<8, 18>::Register(void) : reg_size(1), reg{(u8*)&DDRC} {}
template<> inline Config<8, 70>::Config(void) : conf{(1 << 0)} {}
template<> inline Config<8, 71>::Config(void) : conf{(1 << 1)} {}
template<> inline Config<8, 72>::Config(void) : conf{(1 << 2)} {}
template<> inline Config<8, 73>::Config(void) : conf{(1 << 3)} {}
template<> inline Config<8, 74>::Config(void) : conf{(1 << 4)} {}
template<> inline Config<8, 75>::Config(void) : conf{(1 << 5)} {}
template<> inline Config<8, 76>::Config(void) : conf{(1 << 6)} {}
template<> inline Config<8, 77>::Config(void) : conf{(1 << 7)} {}
template<> inline Register<8, 19>::Register(void) : reg_size(1), reg{(u8*)&DDRD} {}
template<> inline Config<8, 78>::Config(void) : conf{(1 << 0)} {}
template<> inline Config<8, 79>::Config(void) : conf{(1 << 1)} {}
template<> inline Config<8, 80>::Config(void) : conf{(1 << 2)} {}
template<> inline Config<8, 81>::Config(void) : conf{(1 << 3)} {}
template<> inline Config<8, 82>::Config(void) : conf{(1 << 4)} {}
template<> inline Config<8, 83>::Config(void) : conf{(1 << 5)} {}
template<> inline Config<8, 84>::Config(void) : conf{(1 << 6)} {}
template<> inline Config<8, 85>::Config(void) : conf{(1 << 7)} {}
template<> inline Register<8, 20>::Register(void) : reg_size(1), reg{(u8*)&DDRE} {}
template<> inline Config<8, 86>::Config(void) : conf{(1 << 0)} {}
template<> inline Config<8, 87>::Config(void) : conf{(1 << 1)} {}
template<> inline Config<8, 88>::Config(void) : conf{(1 << 2)} {}
template<> inline Config<8, 89>::Config(void) : conf{(1 << 3)} {}
template<> inline Config<8, 90>::Config(void) : conf{(1 << 4)} {}
template<> inline Config<8, 91>::Config(void) : conf{(1 << 5)} {}
template<> inline Config<8, 92>::Config(void) : conf{(1 << 6)} {}
template<> inline Config<8, 93>::Config(void) : conf{(1 << 7)} {}
template<> inline Register<8, 21>::Register(void) : reg_size(1), reg{(u8*)&DDRF} {}
template<> inline Config<8, 94>::Config(void) : conf{(1 << 0)} {}
template<> inline Config<8, 95>::Config(void) : conf{(1 << 1)} {}
template<> inline Config<8, 96>::Config(void) : conf{(1 << 2)} {}
template<> inline Config<8, 97>::Config(void) : conf{(1 << 3)} {}
template<> inline Config<8, 98>::Config(void) : conf{(1 << 4)} {}
template<> inline Config<8, 99>::Config(void) : conf{(1 << 5)} {}
template<> inline Config<8, 100>::Config(void) : conf{(1 << 6)} {}
template<> inline Config<8, 101>::Config(void) : conf{(1 << 7)} {}
template<> inline Register<8, 22>::Register(void) : reg_size(1), reg{(u8*)&DDRG} {}
template<> inline Config<8, 102>::Config(void) : conf{(1 << 0)} {}
template<> inline Config<8, 103>::Config(void) : conf{(1 << 1)} {}
template<> inline Config<8, 104>::Config(void) : conf{(1 << 2)} {}
template<> inline Config<8, 105>::Config(void) : conf{(1 << 3)} {}
template<> inline Config<8, 106>::Config(void) : conf{(1 << 4)} {}
template<> inline Config<8, 107>::Config(void) : conf{(1 << 5)} {}
template<> inline Config<8, 108>::Config(void) : conf{(1 << 6)} {}
template<> inline Config<8, 109>::Config(void) : conf{(1 << 7)} {}
template<> inline Register<8, 23>::Register(void) : reg_size(1), reg{(u8*)&PORTA} {}
template<> inline Config<8, 110>::Config(void) : conf{(1 << 0)} {}
template<> inline Config<8, 111>::Config(void) : conf{(1 << 1)} {}
template<> inline Config<8, 112>::Config(void) : conf{(1 << 2)} {}
template<> inline Config<8, 113>::Config(void) : conf{(1 << 3)} {}
template<> inline Config<8, 114>::Config(void) : conf{(1 << 4)} {}
template<> inline Config<8, 115>::Config(void) : conf{(1 << 5)} {}
template<> inline Config<8, 116>::Config(void) : conf{(1 << 6)} {}
template<> inline Config<8, 117>::Config(void) : conf{(1 << 7)} {}
template<> inline Register<8, 24>::Register(void) : reg_size(1), reg{(u8*)&PORTB} {}
template<> inline Config<8, 118>::Config(void) : conf{(1 << 0)} {}
template<> inline Config<8, 119>::Config(void) : conf{(1 << 1)} {}
template<> inline Config<8, 120>::Config(void) : conf{(1 << 2)} {}
template<> inline Config<8, 121>::Config(void) : conf{(1 << 3)} {}
template<> inline Config<8, 122>::Config(void) : conf{(1 << 4)} {}
template<> inline Config<8, 123>::Config(void) : conf{(1 << 5)} {}
template<> inline Config<8, 124>::Config(void) : conf{(1 << 6)} {}
template<> inline Config<8, 125>::Config(void) : conf{(1 << 7)} {}
template<> inline Register<8, 25>::Register(void) : reg_size(1), reg{(u8*)&PORTC} {}
template<> inline Config<8, 126>::Config(void) : conf{(1 << 0)} {}
template<> inline Config<8, 127>::Config(void) : conf{(1 << 1)} {}
template<> inline Config<8, 128>::Config(void) : conf{(1 << 2)} {}
template<> inline Config<8, 129>::Config(void) : conf{(1 << 3)} {}
template<> inline Config<8, 130>::Config(void) : conf{(1 << 4)} {}
template<> inline Config<8, 131>::Config(void) : conf{(1 << 5)} {}
template<> inline Config<8, 132>::Config(void) : conf{(1 << 6)} {}
template<> inline Config<8, 133>::Config(void) : conf{(1 << 7)} {}
template<> inline Register<8, 26>::Register(void) : reg_size(1), reg{(u8*)&PORTD} {}
template<> inline Config<8, 134>::Config(void) : conf{(1 << 0)} {}
template<> inline Config<8, 135>::Config(void) : conf{(1 << 1)} {}
template<> inline Config<8, 136>::Config(void) : conf{(1 << 2)} {}
template<> inline Config<8, 137>::Config(void) : conf{(1 << 3)} {}
template<> inline Config<8, 138>::Config(void) : conf{(1 << 4)} {}
template<> inline Config<8, 139>::Config(void) : conf{(1 << 5)} {}
template<> inline Config<8, 140>::Config(void) : conf{(1 << 6)} {}
template<> inline Config<8, 141>::Config(void) : conf{(1 << 7)} {}
template<> inline Register<8, 27>::Register(void) : reg_size(1), reg{(u8*)&PORTE} {}
template<> inline Config<8, 142>::Config(void) : conf{(1 << 0)} {}
template<> inline Config<8, 143>::Config(void) : conf{(1 << 1)} {}
template<> inline Config<8, 144>::Config(void) : conf{(1 << 2)} {}
template<> inline Config<8, 145>::Config(void) : conf{(1 << 3)} {}
template<> inline Config<8, 146>::Config(void) : conf{(1 << 4)} {}
template<> inline Config<8, 147>::Config(void) : conf{(1 << 5)} {}
template<> inline Config<8, 148>::Config(void) : conf{(1 << 6)} {}
template<> inline Config<8, 149>::Config(void) : conf{(1 << 7)} {}
template<> inline Register<8, 28>::Register(void) : reg_size(1), reg{(u8*)&PORTF} {}
template<> inline Config<8, 150>::Config(void) : conf{(1 << 0)} {}
template<> inline Config<8, 151>::Config(void) : conf{(1 << 1)} {}
template<> inline Config<8, 152>::Config(void) : conf{(1 << 2)} {}
template<> inline Config<8, 153>::Config(void) : conf{(1 << 3)} {}
template<> inline Config<8, 154>::Config(void) : conf{(1 << 4)} {}
template<> inline Config<8, 155>::Config(void) : conf{(1 << 5)} {}
template<> inline Config<8, 156>::Config(void) : conf{(1 << 6)} {}
template<> inline Config<8, 157>::Config(void) : conf{(1 << 7)} {}
template<> inline Register<8, 29>::Register(void) : reg_size(1), reg{(u8*)&PORTG} {}
template<> inline Config<8, 158>::Config(void) : conf{(1 << 0)} {}
template<> inline Config<8, 159>::Config(void) : conf{(1 << 1)} {}
template<> inline Config<8, 160>::Config(void) : conf{(1 << 2)} {}
template<> inline Config<8, 161>::Config(void) : conf{(1 << 3)} {}
template<> inline Config<8, 162>::Config(void) : conf{(1 << 4)} {}
template<> inline Config<8, 163>::Config(void) : conf{(1 << 5)} {}
template<> inline Config<8, 164>::Config(void) : conf{(1 << 6)} {}
template<> inline Config<8, 165>::Config(void) : conf{(1 << 7)} {}
template<> inline Register<8, 30>::Register(void) : reg_size(1), reg{(u8*)&PINA} {}
template<> inline Config<8, 166>::Config(void) : conf{(1 << 0)} {}
template<> inline Config<8, 167>::Config(void) : conf{(1 << 1)} {}
template<> inline Config<8, 168>::Config(void) : conf{(1 << 2)} {}
template<> inline Config<8, 169>::Config(void) : conf{(1 << 3)} {}
template<> inline Config<8, 170>::Config(void) : conf{(1 << 4)} {}
template<> inline Config<8, 171>::Config(void) : conf{(1 << 5)} {}
template<> inline Config<8, 172>::Config(void) : conf{(1 << 6)} {}
template<> inline Config<8, 173>::Config(void) : conf{(1 << 7)} {}
template<> inline Register<8, 31>::Register(void) : reg_size(1), reg{(u8*)&PINB} {}
template<> inline Config<8, 174>::Config(void) : conf{(1 << 0)} {}
template<> inline Config<8, 175>::Config(void) : conf{(1 << 1)} {}
template<> inline Config<8, 176>::Config(void) : conf{(1 << 2)} {}
template<> inline Config<8, 177>::Config(void) : conf{(1 << 3)} {}
template<> inline Config<8, 178>::Config(void) : conf{(1 << 4)} {}
template<> inline Config<8, 179>::Config(void) : conf{(1 << 5)} {}
template<> inline Config<8, 180>::Config(void) : conf{(1 << 6)} {}
template<> inline Config<8, 181>::Config(void) : conf{(1 << 7)} {}
template<> inline Register<8, 32>::Register(void) : reg_size(1), reg{(u8*)&PINC} {}
template<> inline Config<8, 182>::Config(void) : conf{(1 << 0)} {}
template<> inline Config<8, 183>::Config(void) : conf{(1 << 1)} {}
template<> inline Config<8, 184>::Config(void) : conf{(1 << 2)} {}
template<> inline Config<8, 185>::Config(void) : conf{(1 << 3)} {}
template<> inline Config<8, 186>::Config(void) : conf{(1 << 4)} {}
template<> inline Config<8, 187>::Config(void) : conf{(1 << 5)} {}
template<> inline Config<8, 188>::Config(void) : conf{(1 << 6)} {}
template<> inline Config<8, 189>::Config(void) : conf{(1 << 7)} {}
template<> inline Register<8, 33>::Register(void) : reg_size(1), reg{(u8*)&PIND} {}
template<> inline Config<8, 190>::Config(void) : conf{(1 << 0)} {}
template<> inline Config<8, 191>::Config(void) : conf{(1 << 1)} {}
template<> inline Config<8, 192>::Config(void) : conf{(1 << 2)} {}
template<> inline Config<8, 193>::Config(void) : conf{(1 << 3)} {}
template<> inline Config<8, 194>::Config(void) : conf{(1 << 4)} {}
template<> inline Config<8, 195>::Config(void) : conf{(1 << 5)} {}
template<> inline Config<8, 196>::Config(void) : conf{(1 << 6)} {}
template<> inline Config<8, 197>::Config(void) : conf{(1 << 7)} {}
template<> inline Register<8, 34>::Register(void) : reg_size(1), reg{(u8*)&PINE} {}
template<> inline Config<8, 198>::Config(void) : conf{(1 << 0)} {}
template<> inline Config<8, 199>::Config(void) : conf{(1 << 1)} {}
template<> inline Config<8, 200>::Config(void) : conf{(1 << 2)} {}
template<> inline Config<8, 201>::Config(void) : conf{(1 << 3)} {}
template<> inline Config<8, 202>::Config(void) : conf{(1 << 4)} {}
template<> inline Config<8, 203>::Config(void) : conf{(1 << 5)} {}
template<> inline Config<8, 204>::Config(void) : conf{(1 << 6)} {}
template<> inline Config<8, 205>::Config(void) : conf{(1 << 7)} {}
template<> inline Register<8, 35>::Register(void) : reg_size(1), reg{(u8*)&PINF} {}
template<> inline Config<8, 206>::Config(void) : conf{(1 << 0)} {}
template<> inline Config<8, 207>::Config(void) : conf{(1 << 1)} {}
template<> inline Config<8, 208>::Config(void) : conf{(1 << 2)} {}
template<> inline Config<8, 209>::Config(void) : conf{(1 << 3)} {}
template<> inline Config<8, 210>::Config(void) : conf{(1 << 4)} {}
template<> inline Config<8, 211>::Config(void) : conf{(1 << 5)} {}
template<> inline Config<8, 212>::Config(void) : conf{(1 << 6)} {}
template<> inline Config<8, 213>::Config(void) : conf{(1 << 7)} {}
template<> inline Register<8, 36>::Register(void) : reg_size(1), reg{(u8*)&PING} {}
template<> inline Config<8, 214>::Config(void) : conf{(1 << 0)} {}
template<> inline Config<8, 215>::Config(void) : conf{(1 << 1)} {}
template<> inline Config<8, 216>::Config(void) : conf{(1 << 2)} {}
template<> inline Config<8, 217>::Config(void) : conf{(1 << 3)} {}
template<> inline Config<8, 218>::Config(void) : conf{(1 << 4)} {}
template<> inline Config<8, 219>::Config(void) : conf{(1 << 5)} {}
template<> inline Config<8, 220>::Config(void) : conf{(1 << 6)} {}
template<> inline Config<8, 221>::Config(void) : conf{(1 << 7)} {}
