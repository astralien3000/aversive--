#ifndef ATMEGA32
#define ATMEGA32

#include <base/static_list.hpp>
#include <avr/io.h>

namespace AVR {
  
  template <int ID> struct Timer;

  // Timer Interruptions Registers
  struct TimerInterrupt {
    typedef StaticList<(int)&TIMSK> Mask;
    typedef StaticList<(int)&TIFR>  Flag;
  };
  
  // Timer 0
  template<> struct Timer<0> {
    // Registers
    typedef StaticList<(int)&TCCR0> Control;
    typedef StaticList<(int)&TCNT0> Counter;
    typedef StaticList<(int)&OCR0 > Compare;
    
    // Infos
    enum {
      SIZE = 8,
      EVENTS = 1
    };

    // Waveform Generator
    struct WGM {
      typedef StaticList<0> Normal;
      typedef StaticList<(1 << WGM00)> PWM;
      typedef StaticList<(1 << WGM01)> CTC;
      typedef StaticList<(1 << WGM00)|(1 << WGM01)> FastPWM;
    };

    // Prescaler (decl)
    template <int PRESCALE> struct Prescaler;

    // Interruption Mask for Interruption Register (decl)
    template <int EID = 0> struct InterruptMask;
  };

  // Prescaler (def)
#define MACRO_PRESCALER(num, bit2, bit1, bit0)				\
  template<> struct Timer<0>::Prescaler<num> {				\
    typedef StaticList<((bit2 << CS02) | (bit1 << CS01) | (bit0 << CS00))> Config; \
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

  // Interruption Mask (def)
  template<> template<> struct Timer<0>::InterruptMask<0> {
    typedef StaticList<(1 << OCIE0), 0> Match;
  };

  // Timer 1
  template<> struct Timer<1> {
    // Registers
    typedef StaticList<(int)&TCCR1A, (int)&TCCR1B> Control;
    typedef StaticList<(int)&TCNT1>                Counter;
    typedef StaticList<(int)&OCR1A, (int)&OCR1B>   Compare;
    
    // Infos
    enum {
      SIZE = 16,
      EVENTS = 2
    };

    // Waveform Generator
    struct WGM {
      typedef StaticList<0                          ,0           > Normal;
      typedef StaticList<(1 << WGM10) | (1 << WGM11),0           > Pwm;
      typedef StaticList<0                          ,(1 << WGM12)> Ctc;
      typedef StaticList<(1 << WGM10) | (1 << WGM11),(1 << WGM12)> FastPwm;
    };

    // Prescaler (decl)
    template <int PRESCALE> struct Prescaler;

    // Interruption Mask for Interruption Register (decl)
    template <int EID = 0> struct InterruptMask;
  };

  // Prescaler (def)
#define MACRO_PRESCALER(num, bit2, bit1, bit0)				\
  template<> template<> struct Timer<1>::Prescaler<num> {		\
    typedef StaticList<0,((bit2 << CS12) | (bit1 << CS11) | (bit0 << CS10))> Config; \
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

  // Interruption Mask (def)
  template<> template<> struct Timer<1>::InterruptMask<0> {
    typedef StaticList<(1 << OCIE1A), 0> Match;
  };

  template<> template<> struct Timer<1>::InterruptMask<1> {
    typedef StaticList<(1 << OCIE1B), 0> Match;
  };

}

#endif//ATMEGA32
