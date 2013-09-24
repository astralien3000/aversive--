#ifndef TIMER_DEFS_HPP
#define TIMER_DEFS_HPP

#include <base/static_list.hpp>
#include <avr/io.h>

//////////////////////////////////////////////////////////////
// Types Decl ////////////////////////////////////////////////

// Register
template<int ID> struct TimerRegister { enum { SIZE = 0 }; };

// Waveform Generator Mode
template<int ID> struct WGM {};

// Prescaler
template<int ID, int PRESCALE> struct Prescaler {};

#define PRESCALER_NONE -1
#define PRESCALER_MASK -2

// Interrupt Mask
template<int ID, int EID = 0> struct InterruptMask {};


///////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////
// INTERRUPT REGISTERS ////////////////////////////////////////

#if defined (__AVR_ATmega128__)

struct TimerInterrupt {
  typedef StaticList<0,2, (int)&TIMSK,(int)&ETIMSK> Mask;
  typedef StaticList<0,2, (int)&TIFR,(int)&ETIFR>   Flag;
};

#else

struct TimerInterrupt {
  typedef StaticList<0,1, (int)&TIMSK> Mask;
  typedef StaticList<0,1, (int)&TIFR>   Flag;
};

#endif

///////////////////////////////////////////////////////////////
// TIMER 0 ////////////////////////////////////////////////////

// Register
template<>
struct TimerRegister<0> {
  typedef StaticList<0,1, (int)&TCCR0> Control;
  typedef StaticList<0,1, (int)&OCR0>  Compare;
  enum {
    // Registers
    COUNTER = (int)&TCNT0,
    ////////////
    SIZE = 8,
    EVENTS = 1,
    TIREGS = 1
  };
};

// Waveform Generator Mode
template<>
struct WGM<0> {
  typedef StaticList<0,1, 0> Normal;
  typedef StaticList<0,1, (1 << WGM00)> Pwm;
  typedef StaticList<0,1, (1 << WGM01)> Ctc;
  typedef StaticList<0,1, (1 << WGM00)|(1 << WGM01)> FastPwm;
};

// Prescaler
#define MACRO_PRESCALER(num, bit2, bit1, bit0)				\
  template<> struct Prescaler<0, num> {					\
    typedef StaticList<0,1, ((bit2 << CS02) | (bit1 << CS01) | (bit0 << CS00))> Config; \
  };

MACRO_PRESCALER(-1,   0,0,0)

MACRO_PRESCALER(0,    0,0,1)
MACRO_PRESCALER(8,    0,1,0)
MACRO_PRESCALER(32,   0,1,1)
MACRO_PRESCALER(64,   1,0,0)
MACRO_PRESCALER(128,  1,0,1)
MACRO_PRESCALER(256,  1,1,0)
MACRO_PRESCALER(1024, 1,1,1)

MACRO_PRESCALER(-2,   1,1,1)

#undef MACRO_PRESCALER

// Interrupt Mask
template<>
struct InterruptMask<0, 0> {
  typedef StaticList<0,2, (1 << OCIE0), 0> Match;
};


///////////////////////////////////////////////////////////////
// TIMER 1 ////////////////////////////////////////////////////

template<>
struct TimerRegister<1> {
#if defined (__AVR_ATmega128__)
  typedef StaticList<0,3, (int)&TCCR1A, (int)&TCCR1B, (int)&TCCR1C> Control;
  typedef StaticList<0,3, (int)&OCR1A, (int)&OCR1B, (int)&OCR1C>    Compare;
#else
  typedef StaticList<0,2, (int)&TCCR1A, (int)&TCCR1B> Control;
  typedef StaticList<0,2, (int)&OCR1A, (int)&OCR1B>    Compare;
#endif
  enum {
    // Registers
    COUNTER   = (int)&TCNT1,
    ////////////
    SIZE = 16,
#if defined (__AVR_ATmega128__)
    EVENTS = 3,
    TIREGS = 2
#else
    EVENTS = 2,
    TIREGS = 1
#endif
  };
};

// Waveform Generator Mode
//// README: only 10 bits PWM available
template<>
struct WGM<1> {
  typedef StaticList<0,3, 0,0,0> Normal;
  typedef StaticList<0,3, (1 << WGM10) | (1 << WGM11),0,0> Pwm;
  typedef StaticList<0,3, 0,(1 << WGM12),0> Ctc;
  typedef StaticList<0,3, (1 << WGM10) | (1 << WGM11),(1 << WGM12),0> FastPwm;
};

// Prescaler
#define MACRO_PRESCALER(num, bit2, bit1, bit0)				\
  template<> struct Prescaler<1, num> {					\
    typedef StaticList<0,3, 0,((bit2 << CS12) | (bit1 << CS11) | (bit0 << CS10)),0> Config; \
  };

MACRO_PRESCALER(-1,   0,0,0)

MACRO_PRESCALER(0,    0,0,1)
MACRO_PRESCALER(8,    0,1,0)
MACRO_PRESCALER(64,   0,1,1)
MACRO_PRESCALER(256,  1,0,0)
MACRO_PRESCALER(1024, 1,0,1)

MACRO_PRESCALER(-3,   1,1,0)
MACRO_PRESCALER(-4,   1,1,1)

MACRO_PRESCALER(-2,   1,1,1)

#undef MACRO_PRESCALER

// Interrupt Mask
template<>
struct InterruptMask<1,0> {
  typedef StaticList<0,2, (1 << OCIE1A), 0> Match;
};

template<>
struct InterruptMask<1,1> {
  typedef StaticList<0,2, (1 << OCIE1B), 0> Match;
};

#if defined (__AVR_ATmega128__)

template<>
struct InterruptMask<1,2> {
  typedef StaticList<0,2, 0, (1 << OCIE1C)> Match;
};

#endif

#endif//TIMER_DEFS_HPP
