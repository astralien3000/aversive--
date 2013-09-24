#include <hardware/timer.hpp>
#include <hardware/interrupts.hpp>

#include <hardware/interrupts.hpp>
#include "timer_defs.hpp"

template<int SIZE = 8>
inline typename Integer<SIZE>::Unsigned& REG(int r) {
  return *(typename Integer<SIZE>::Unsigned*)r;
}

typedef void (*InterruptFunc)(void);

////////////////////////////////////////////////////////
// DATA ////////////////////////////////////////////////

template<int ID>
struct TimerData {
  static InterruptFunc event[TimerRegister<ID>::EVENTS];
};

template<int ID>
InterruptFunc TimerData<ID>::event[] = {0};


////////////////////////////////////////////////////////
// INTERRUPTION FUNCS //////////////////////////////////

#include <avr/interrupt.h>

#define MACRO_INTERRUPT_BIND(timer, comp, ev)				\
  ISR(TIMER##timer##_COMP##comp##_vect, ISR_NAKED) {			\
    uint8_t flags = SREG;						\
    if(TimerData<timer>::event[ev])					\
      TimerData<timer>::event[ev]();					\
    SREG = flags;							\
    reti();								\
  }

MACRO_INTERRUPT_BIND(0,,0)
MACRO_INTERRUPT_BIND(1,A,0)
MACRO_INTERRUPT_BIND(1,B,1)
#if defined (__AVR_ATmega128__)
MACRO_INTERRUPT_BIND(1,C,2)
#endif

////////////////////////////////////////////////////////
// EVENT FUNC HELPER ///////////////////////////////////

template<int ID, int EID, bool TYPE_OK = true>
struct TimerFuncHelper {
  uint8_t flag;

  inline TimerFuncHelper(void) {
    // Check type
    static_assert(TYPE_OK, "ERROR : Wrong type used during register manipulation");

    // Check if event exist
    static_assert(EID < TimerRegister<ID>::EVENTS, "ERROR : Invalid Event ID");

    // Disable interrupts
    InterruptsHandler::lock(flag);
  }

  inline~TimerFuncHelper(void) {
    // Enable interrupts
    InterruptsHandler::unlock(flag);
  }
};

////////////////////////////////////////////////////////

template<int ID>
inline void TimerHandler<ID>::init(void) {
  TimerFuncHelper<ID,0> helper();
  
  // Set Waveform Generator Mode to Normal
  StaticListLooper<
    0,TimerRegister<ID>::EVENTS, 
    typename TimerRegister<ID>::Control, 
    typename WGM<ID>::Normal
    >::exec([](int reg, int val) {
      REG(reg) = val;
    });

  // Set Prescaler to 0
  StaticListLooper<
    0,TimerRegister<ID>::EVENTS, 
    typename TimerRegister<ID>::Control, 
    typename Prescaler<ID, 0>::Config
    >::exec([](int reg, int val){
      REG(reg) |= val;
    });

  // Set Counter to 0
  REG<TimerRegister<ID>::SIZE>(TimerRegister<ID>::COUNTER) = 0;
}

template<int ID> template<typename T>
inline T& TimerHandler<ID>::counter(void) {
  TimerFuncHelper<ID,0,TimerRegister<ID>::SIZE == sizeof(T)*8> helper;

  // Set counter value
  return REG<TimerRegister<ID>::SIZE>(TimerRegister<ID>::COUNTER);
}

template<int ID> template<int PRESCALE>
inline void TimerHandler<ID>::setPrescaler(void) {
  TimerFuncHelper<ID,0> helper;

  // Set to 0 all prescaler bits
  StaticListLooper<
    0,TimerRegister<ID>::EVENTS, 
    typename TimerRegister<ID>::Control, 
    typename Prescaler<ID, PRESCALER_MASK>::Config
    >::exec([](int reg, int val){
      REG(reg) &= ~val;
    });

  // Set prescaler value
  StaticListLooper<
    0,TimerRegister<ID>::EVENTS, 
    typename TimerRegister<ID>::Control, 
    typename Prescaler<ID, PRESCALE>::Config
    >::exec([](int reg, int val){
      REG(reg) |= val;
    });
}

template<int ID> template<int EID>
inline void TimerHandler<ID>::Event<EID>::start(void) {
  TimerFuncHelper<ID,EID> helper;

  // Enable event interrupt bit
  StaticListLooper<
    0,TimerRegister<ID>::TIREGS, 
    typename TimerInterrupt::Mask, 
    typename InterruptMask<ID,EID>::Match
    >::exec([](int reg, int val){
      REG(reg) |= val;
    });
}

template<int ID> template<int EID>
inline void TimerHandler<ID>::Event<EID>::stop(void) {
  TimerFuncHelper<ID,EID> helper;

  // Disable event interrupt bit
  StaticListLooper<
    0,TimerRegister<ID>::TIREGS, 
    typename TimerInterrupt::Mask, 
    typename InterruptMask<ID,EID>::Match
    >::exec([](int reg, int val){
      REG(reg) &= ~val;
    });
}

template<int ID> template<int EID> template<typename Callable> 
inline void TimerHandler<ID>::Event<EID>::set(Callable func) {
  TimerFuncHelper<ID,EID> helper;

  TimerData<ID>::event[EID] = static_cast<InterruptFunc>(func);
}

template<int ID> template<int EID> template<typename T>
inline void TimerHandler<ID>::Event<EID>::setComparator(T val) {
  TimerFuncHelper<ID,EID,TimerRegister<ID>::SIZE == sizeof(T)*8> helper;

  REG<TimerRegister<ID>::SIZE>(StaticListIterator<typename TimerRegister<ID>::Compare, EID>::VALUE) = val;
}
