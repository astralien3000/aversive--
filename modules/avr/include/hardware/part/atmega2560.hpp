/*
    Aversive++                                                           
    Copyright (C) 2014 Eirbot                                            
                                                                         
    This program is free software: you can redistribute it and/or modify 
    it under the terms of the GNU General Public License as published by 
    the Free Software Foundation, either version 3 of the License, or    
    (at your option) any later version.                                  
                                                                         
    This program is distributed in the hope that it will be useful,      
    but WITHOUT ANY WARRANTY; without even the implied warranty of       
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the        
    GNU General Public License for more details.                         
                                                                         
    You should have received a copy of the GNU General Public License    
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/











































































































































































// Architecture : atmega2560
template<int param> struct timer;
template<int param> struct timer;
template<int param> struct uart;
template<int param> struct eeprom;
struct pinmap;
template<>
struct timer<0> {
  struct control;
  struct counter;
  template<int param> struct compare;
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
  struct mask;
};

struct timer<0>::control::prescaler::disable {
  enum {
    CONFIG = 4,
    SIZE = 8
  };
};

template<>
struct timer<0>::control::prescaler::value<1> {
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
struct timer<0>::control::prescaler::value<64> {
  enum {
    CONFIG = 7,
    SIZE = 8
  };
};

template<>
struct timer<0>::control::prescaler::value<256> {
  enum {
    CONFIG = 8,
    SIZE = 8
  };
};

template<>
struct timer<0>::control::prescaler::value<1024> {
  enum {
    CONFIG = 9,
    SIZE = 8
  };
};

struct timer<0>::control::prescaler::mask {
  enum {
    CONFIG = 10,
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

template<>
struct timer<0>::compare<1> {
  enum {
    REG = 3,
    SIZE = 8
  };
};

struct timer<0>::imask {
  enum {
    REG = 4,
    SIZE = 8
  };

  template<int param> struct match;
  template<int param> struct match;
  struct overflow;
};

template<>
struct timer<0>::imask::match<0> {
  enum {
    CONFIG = 11,
    SIZE = 8
  };
};

template<>
struct timer<0>::imask::match<1> {
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
    REG = 5,
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
    REG = 6,
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
  struct mask;
};

struct timer<1>::control::prescaler::disable {
  enum {
    CONFIG = 18,
    SIZE = 8
  };
};

template<>
struct timer<1>::control::prescaler::value<1> {
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

struct timer<1>::control::prescaler::mask {
  enum {
    CONFIG = 24,
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
    REG = 7,
    SIZE = 8
  };

  template<int param> struct match;
  template<int param> struct match;
  struct overflow;
};

template<>
struct timer<1>::imask::match<0> {
  enum {
    CONFIG = 25,
    SIZE = 8
  };
};

template<>
struct timer<1>::imask::match<1> {
  enum {
    CONFIG = 26,
    SIZE = 8
  };
};

struct timer<1>::imask::overflow {
  enum {
    CONFIG = 27,
    SIZE = 8
  };
};

struct timer<1>::iflag {
  enum {
    REG = 8,
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
    REG = 9,
    SIZE = 8
  };

  struct recvend;
  struct sendend;
  struct empty;
};

struct uart<0>::flag::recvend {
  enum {
    CONFIG = 28,
    SIZE = 8
  };
};

struct uart<0>::flag::sendend {
  enum {
    CONFIG = 29,
    SIZE = 8
  };
};

struct uart<0>::flag::empty {
  enum {
    CONFIG = 30,
    SIZE = 8
  };
};

struct uart<0>::control {
  enum {
    REG = 10,
    SIZE = 8
  };

  struct enable;
  struct ienable;
  struct flag;
  struct charsize;
  struct parity;
  struct stopbit;
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
    REG = 11,
    SIZE = 8
  };
};

struct uart<0>::data {
  enum {
    REG = 12,
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
    REG = 13,
    SIZE = 8
  };
};

struct eeprom<0>::data {
  enum {
    REG = 14,
    SIZE = 8
  };
};

struct eeprom<0>::control {
  enum {
    REG = 15,
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

struct pinmap {
  template<int param> struct control_out;
  template<int param> struct control_out;
  template<int param> struct control_out;
  template<int param> struct control_out;
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
};

template<>
struct pinmap::control_out<1> {
  enum {
    REG = 17,
    SIZE = 8
  };
};

template<>
struct pinmap::control_out<2> {
  enum {
    REG = 18,
    SIZE = 8
  };
};

template<>
struct pinmap::control_out<3> {
  enum {
    REG = 19,
    SIZE = 8
  };
};

template<>
struct pinmap::control_out<4> {
  enum {
    REG = 20,
    SIZE = 8
  };
};

template<>
struct pinmap::control_out<5> {
  enum {
    REG = 21,
    SIZE = 8
  };
};

template<>
struct pinmap::control_out<6> {
  enum {
    REG = 22,
    SIZE = 8
  };
};

template<>
struct pinmap::control_out<7> {
  enum {
    REG = 23,
    SIZE = 8
  };
};

template<>
struct pinmap::control_out<8> {
  enum {
    REG = 24,
    SIZE = 8
  };
};

template<>
struct pinmap::control_out<9> {
  enum {
    REG = 25,
    SIZE = 8
  };
};

template<>
struct pinmap::control_out<10> {
  enum {
    REG = 26,
    SIZE = 8
  };
};

template<>
struct pinmap::port<0> {
  enum {
    REG = 27,
    SIZE = 8
  };
};

template<>
struct pinmap::port<1> {
  enum {
    REG = 28,
    SIZE = 8
  };
};

template<>
struct pinmap::port<2> {
  enum {
    REG = 29,
    SIZE = 8
  };
};

template<>
struct pinmap::port<3> {
  enum {
    REG = 30,
    SIZE = 8
  };
};

template<>
struct pinmap::port<4> {
  enum {
    REG = 31,
    SIZE = 8
  };
};

template<>
struct pinmap::port<5> {
  enum {
    REG = 32,
    SIZE = 8
  };
};

template<>
struct pinmap::port<6> {
  enum {
    REG = 33,
    SIZE = 8
  };
};

template<>
struct pinmap::port<7> {
  enum {
    REG = 34,
    SIZE = 8
  };
};

template<>
struct pinmap::port<8> {
  enum {
    REG = 35,
    SIZE = 8
  };
};

template<>
struct pinmap::port<9> {
  enum {
    REG = 36,
    SIZE = 8
  };
};

template<>
struct pinmap::port<10> {
  enum {
    REG = 37,
    SIZE = 8
  };
};

template<>
struct pinmap::pin<0> {
  enum {
    REG = 38,
    SIZE = 8
  };
};

template<>
struct pinmap::pin<1> {
  enum {
    REG = 39,
    SIZE = 8
  };
};

template<>
struct pinmap::pin<2> {
  enum {
    REG = 40,
    SIZE = 8
  };
};

template<>
struct pinmap::pin<3> {
  enum {
    REG = 41,
    SIZE = 8
  };
};

template<>
struct pinmap::pin<4> {
  enum {
    REG = 42,
    SIZE = 8
  };
};

template<>
struct pinmap::pin<5> {
  enum {
    REG = 43,
    SIZE = 8
  };
};

template<>
struct pinmap::pin<6> {
  enum {
    REG = 44,
    SIZE = 8
  };
};

template<>
struct pinmap::pin<7> {
  enum {
    REG = 45,
    SIZE = 8
  };
};

template<>
struct pinmap::pin<8> {
  enum {
    REG = 46,
    SIZE = 8
  };
};

template<>
struct pinmap::pin<9> {
  enum {
    REG = 47,
    SIZE = 8
  };
};

template<>
struct pinmap::pin<10> {
  enum {
    REG = 48,
    SIZE = 8
  };
};

template<> inline Register<8, 0>::Register(void) : reg_size(2), reg{(u8*)&TCCR0A, (u8*)&TCCR0B} {}
template<> inline Config<8, 0>::Config(void) : conf{0, 0} {}
template<> inline Config<8, 1>::Config(void) : conf{(1 << WGM00) | (1 << WGM01), 0} {}
template<> inline Config<8, 2>::Config(void) : conf{0, (1 << WGM02)} {}
template<> inline Config<8, 3>::Config(void) : conf{(1 << WGM00) | (1 << WGM01), (1 << WGM02)} {}
template<> inline Config<8, 4>::Config(void) : conf{0, (0 << CS02) | (0 << CS01) | (0 << CS00)} {}
template<> inline Config<8, 5>::Config(void) : conf{0, (0 << CS02) | (0 << CS01) | (1 << CS00)} {}
template<> inline Config<8, 6>::Config(void) : conf{0, (0 << CS02) | (1 << CS01) | (0 << CS00)} {}
template<> inline Config<8, 7>::Config(void) : conf{0, (0 << CS02) | (1 << CS01) | (1 << CS00)} {}
template<> inline Config<8, 8>::Config(void) : conf{0, (1 << CS02) | (0 << CS01) | (0 << CS00)} {}
template<> inline Config<8, 9>::Config(void) : conf{0, (1 << CS02) | (0 << CS01) | (1 << CS00)} {}
template<> inline Config<8, 10>::Config(void) : conf{0, (1 << CS02) | (1 << CS01) | (1 << CS00)} {}
template<> inline Register<8, 1>::Register(void) : reg_size(1), reg{(u8*)&TCNT0} {}
template<> inline Register<8, 2>::Register(void) : reg_size(1), reg{(u8*)&OCR0A} {}
template<> inline Register<8, 3>::Register(void) : reg_size(1), reg{(u8*)&OCR0B} {}
template<> inline Register<8, 4>::Register(void) : reg_size(1), reg{(u8*)&TIMSK0} {}
template<> inline Config<8, 11>::Config(void) : conf{(1 << OCIE0A)} {}
template<> inline Config<8, 12>::Config(void) : conf{(1 << OCIE0B)} {}
template<> inline Config<8, 13>::Config(void) : conf{(1 << TOIE0)} {}
template<> inline Register<8, 5>::Register(void) : reg_size(1), reg{(u8*)&TIFR0} {}
template<> inline Register<8, 6>::Register(void) : reg_size(3), reg{(u8*)&TCCR1A, (u8*)&TCCR1B, (u8*)&TCCR1C} {}
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
template<> inline Config<8, 24>::Config(void) : conf{0, (1 << CS12) | (1 << CS11) | (1 << CS10), 0} {}
template<> inline Register<16, 0>::Register(void) : reg_size(1), reg{(u16*)&TCNT1} {}
template<> inline Register<16, 1>::Register(void) : reg_size(1), reg{(u16*)&OCR1A} {}
template<> inline Register<16, 2>::Register(void) : reg_size(1), reg{(u16*)&OCR1B} {}
template<> inline Register<8, 7>::Register(void) : reg_size(1), reg{(u8*)&TIMSK1} {}
template<> inline Config<8, 25>::Config(void) : conf{(1 << OCIE1A)} {}
template<> inline Config<8, 26>::Config(void) : conf{(1 << OCIE1B)} {}
template<> inline Config<8, 27>::Config(void) : conf{(1 << TOIE1)} {}
template<> inline Register<8, 8>::Register(void) : reg_size(1), reg{(u8*)&TIFR0} {}
template<> inline Register<8, 9>::Register(void) : reg_size(1), reg{(u8*)&UCSR0A} {}
template<> inline Config<8, 28>::Config(void) : conf{(1 << RXC0)} {}
template<> inline Config<8, 29>::Config(void) : conf{(1 << TXC0)} {}
template<> inline Config<8, 30>::Config(void) : conf{(1 << UDRE0)} {}
template<> inline Register<8, 10>::Register(void) : reg_size(3), reg{(u8*)&UCSR0A, (u8*)&UCSR0B, (u8*)&UCSR0C} {}
template<> inline Config<8, 31>::Config(void) : conf{0, (1 << RXEN0), 0} {}
template<> inline Config<8, 32>::Config(void) : conf{0, (1 << TXEN0), 0} {}
template<> inline Config<8, 33>::Config(void) : conf{0, (1 << RXCIE0), 0} {}
template<> inline Config<8, 34>::Config(void) : conf{0, (1 << TXCIE0), 0} {}
template<> inline Config<8, 35>::Config(void) : conf{0, (1 << UDRIE0), 0} {}
template<> inline Config<8, 36>::Config(void) : conf{(1 << RXC0), 0, 0} {}
template<> inline Config<8, 37>::Config(void) : conf{(1 << TXC0), 0, 0} {}
template<> inline Config<8, 38>::Config(void) : conf{(1 << UDRE0), 0, 0} {}
template<> inline Config<8, 39>::Config(void) : conf{0, (0 << UCSZ02), (0 << UCSZ01) | (0 << UCSZ00)} {}
template<> inline Config<8, 40>::Config(void) : conf{0, (0 << UCSZ02), (0 << UCSZ01) | (1 << UCSZ00)} {}
template<> inline Config<8, 41>::Config(void) : conf{0, (0 << UCSZ02), (1 << UCSZ01) | (0 << UCSZ00)} {}
template<> inline Config<8, 42>::Config(void) : conf{0, (0 << UCSZ02), (1 << UCSZ01) | (1 << UCSZ00)} {}
template<> inline Config<8, 43>::Config(void) : conf{0, (1 << UCSZ02), (1 << UCSZ01) | (1 << UCSZ00)} {}
template<> inline Config<8, 44>::Config(void) : conf{0, 0, 0} {}
template<> inline Config<8, 45>::Config(void) : conf{0, 0, (1 << UPM01)} {}
template<> inline Config<8, 46>::Config(void) : conf{0, 0, (1 << UPM01) | (1 << UPM00)} {}
template<> inline Config<8, 47>::Config(void) : conf{0, 0, 0} {}
template<> inline Config<8, 48>::Config(void) : conf{0, 0, (1 << USBS0)} {}
template<> inline Register<8, 11>::Register(void) : reg_size(2), reg{(u8*)&UBRR0L, (u8*)&UBRR0H} {}
template<> inline Register<8, 12>::Register(void) : reg_size(1), reg{(u8*)&UDR0} {}
template<> inline Register<8, 13>::Register(void) : reg_size(2), reg{(u8*)&EEARL, (u8*)&EEARH} {}
template<> inline Register<8, 14>::Register(void) : reg_size(1), reg{(u8*)&EEDR} {}
template<> inline Register<8, 15>::Register(void) : reg_size(1), reg{(u8*)&EECR} {}
template<> inline Config<8, 49>::Config(void) : conf{(1 << EEMPE)} {}
template<> inline Config<8, 50>::Config(void) : conf{(1 << EEPE)} {}
template<> inline Config<8, 51>::Config(void) : conf{(1 << EERE)} {}
template<> inline Register<8, 16>::Register(void) : reg_size(1), reg{(u8*)&DDRA} {}
template<> inline Register<8, 17>::Register(void) : reg_size(1), reg{(u8*)&DDRB} {}
template<> inline Register<8, 18>::Register(void) : reg_size(1), reg{(u8*)&DDRC} {}
template<> inline Register<8, 19>::Register(void) : reg_size(1), reg{(u8*)&DDRD} {}
template<> inline Register<8, 20>::Register(void) : reg_size(1), reg{(u8*)&DDRE} {}
template<> inline Register<8, 21>::Register(void) : reg_size(1), reg{(u8*)&DDRF} {}
template<> inline Register<8, 22>::Register(void) : reg_size(1), reg{(u8*)&DDRG} {}
template<> inline Register<8, 23>::Register(void) : reg_size(1), reg{(u8*)&DDRH} {}
template<> inline Register<8, 24>::Register(void) : reg_size(1), reg{(u8*)&DDRJ} {}
template<> inline Register<8, 25>::Register(void) : reg_size(1), reg{(u8*)&DDRK} {}
template<> inline Register<8, 26>::Register(void) : reg_size(1), reg{(u8*)&DDRL} {}
template<> inline Register<8, 27>::Register(void) : reg_size(1), reg{(u8*)&PORTA} {}
template<> inline Register<8, 28>::Register(void) : reg_size(1), reg{(u8*)&PORTB} {}
template<> inline Register<8, 29>::Register(void) : reg_size(1), reg{(u8*)&PORTC} {}
template<> inline Register<8, 30>::Register(void) : reg_size(1), reg{(u8*)&PORTD} {}
template<> inline Register<8, 31>::Register(void) : reg_size(1), reg{(u8*)&PORTE} {}
template<> inline Register<8, 32>::Register(void) : reg_size(1), reg{(u8*)&PORTF} {}
template<> inline Register<8, 33>::Register(void) : reg_size(1), reg{(u8*)&PORTG} {}
template<> inline Register<8, 34>::Register(void) : reg_size(1), reg{(u8*)&PORTH} {}
template<> inline Register<8, 35>::Register(void) : reg_size(1), reg{(u8*)&PORTJ} {}
template<> inline Register<8, 36>::Register(void) : reg_size(1), reg{(u8*)&PORTK} {}
template<> inline Register<8, 37>::Register(void) : reg_size(1), reg{(u8*)&PORTL} {}
template<> inline Register<8, 38>::Register(void) : reg_size(1), reg{(u8*)&PINA} {}
template<> inline Register<8, 39>::Register(void) : reg_size(1), reg{(u8*)&PINB} {}
template<> inline Register<8, 40>::Register(void) : reg_size(1), reg{(u8*)&PINC} {}
template<> inline Register<8, 41>::Register(void) : reg_size(1), reg{(u8*)&PIND} {}
template<> inline Register<8, 42>::Register(void) : reg_size(1), reg{(u8*)&PINE} {}
template<> inline Register<8, 43>::Register(void) : reg_size(1), reg{(u8*)&PINF} {}
template<> inline Register<8, 44>::Register(void) : reg_size(1), reg{(u8*)&PING} {}
template<> inline Register<8, 45>::Register(void) : reg_size(1), reg{(u8*)&PINH} {}
template<> inline Register<8, 46>::Register(void) : reg_size(1), reg{(u8*)&PINJ} {}
template<> inline Register<8, 47>::Register(void) : reg_size(1), reg{(u8*)&PINK} {}
template<> inline Register<8, 48>::Register(void) : reg_size(1), reg{(u8*)&PINL} {}
