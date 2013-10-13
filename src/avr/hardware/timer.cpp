#include <base/types.hpp>
#include <hardware/timer.hpp>
#include <hardware/interrupts.hpp>

#include <base/static_container.hpp>

#include "../config/atmega32.hpp"

template<int SIZE = 8>
inline typename Integer<SIZE>::Unsigned & REG(int r) {
  return *(typename Integer<SIZE>::Unsigned*)r;
}

typedef void (*InterruptFunc)(void);

////////////////////////////////////////////////////////
// DATA ////////////////////////////////////////////////

class TimerEventPrivateData {
public:
  InterruptFunc func = 0;
};

template<int ID>
class TimerPrivateData {
public:
  typedef StaticContainer<typename Timer<ID>::template Event<0>> EventList;
  EventList events;
};

////////////////////////////////////////////////////////
// INTERRUPTION FUNCS //////////////////////////////////

#include <avr/interrupt.h>

#define MACRO_INTERRUPT_BIND(timer, comp, ev)				\
  ISR(TIMER##timer##_COMP##comp##_vect, ISR_NAKED) {			\
    uint8_t flags = SREG;						\
    Timer<timer>::Event<ev>& evt = Timer<timer>::instance().event<ev>(); \
    if(evt.activated())							\
      evt.exec();							\
    SREG = flags;							\
    reti();								\
  }

MACRO_INTERRUPT_BIND(0,,0)
//MACRO_INTERRUPT_BIND(1,A,0)
//MACRO_INTERRUPT_BIND(1,B,1)
#if defined (__AVR_ATmega128__)
//MACRO_INTERRUPT_BIND(1,C,2)
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
    static_assert(EID < AVR::Timer<ID>::EVENTS, "ERROR : Invalid Event ID");

    // Disable interrupts
    Interrupts::lock(flag);
  }

  inline~TimerFuncHelper(void) {
    // Enable interrupts
    Interrupts::unlock(flag);
  }
};

////////////////////////////////////////////////////////

template<int ID, typename TimerImpl>
inline Timer<ID, TimerImpl>::Timer() {
  
}

template<int ID, typename TimerImpl>
inline void Timer<ID, TimerImpl>::init(void) {
  TimerFuncHelper<ID,0> helper();

  // Set Waveform Generator Mode to Normal
  StaticListLooper<
    typename AVR::Timer<ID>::Control, 
    typename AVR::Timer<ID>::WGM::Normal
    >::exec([](int reg, int val) {
	REG(reg) = val;
      });

  // Set Prescaler to 0
  StaticListLooper<
    typename AVR::Timer<ID>::Control, 
    typename AVR::Timer<ID>::template Prescaler<0>::Config
    >::exec([](int reg, int val){
	REG(reg) |= val;
      });
  
  // Set Counter to 0
  StaticListLooper<
    typename AVR::Timer<ID>::Counter, 
    StaticList<0,0,0,0>
    >::exec([](int reg, int val){
      REG(reg) |= val;
    });
}

template<int ID, typename TimerImpl> template<typename T>
inline T& Timer<ID, TimerImpl>::counter(void) {
  TimerFuncHelper<ID,0,AVR::Timer<ID>::SIZE == sizeof(T)*8> helper;

  // Set counter value
  return REG<AVR::Timer<ID>::SIZE>(AVR::Timer<ID>::Counter::ELEM);
}

template<int ID, typename TimerImpl> template<int PRESCALE>
inline void Timer<ID, TimerImpl>::setPrescaler(void) {
  TimerFuncHelper<ID,0> helper;

  // Set to 0 all prescaler bits
  StaticListLooper<
    typename AVR::Timer<ID>::Control, 
    typename AVR::Timer<ID>::template Prescaler<PRESCALE>::Config
    >::exec([](int reg, int val){
      REG(reg) &= ~val;
    });

  // Set prescaler value
  StaticListLooper<
    typename AVR::Timer<ID>::Control, 
    typename AVR::Timer<ID>::template Prescaler<PRESCALE>::Config
    >::exec([](int reg, int val){
      REG(reg) |= val;
    });
}

template<int ID, typename TimerImpl> template<int EID, typename EventImpl>
inline void Timer<ID, TimerImpl>::Event<EID, EventImpl>::start(void) {
  TimerFuncHelper<ID,EID> helper;

  // Enable event interrupt bit
  StaticListLooper<
    typename AVR::TimerInterrupt::Mask, 
    typename AVR::Timer<ID>::template InterruptMask<EID>::Match
    >::exec([](int reg, int val){
      REG(reg) |= val;
    });
}

template<int ID, typename TimerImpl> template<int EID, typename EventImpl>
inline void Timer<ID, TimerImpl>::Event<EID, EventImpl>::stop(void) {
  TimerFuncHelper<ID,EID> helper;

  // Disable event interrupt bit
  StaticListLooper<
    typename AVR::TimerInterrupt::Mask, 
    typename AVR::Timer<ID>::template InterruptMask<EID>::Match
    >::exec([](int reg, int val){
      REG(reg) &= ~val;
    });
}

template<int ID, typename TimerImpl> template<int EID, typename EventImpl> template<typename Callable> 
inline void Timer<ID, TimerImpl>::Event<EID, EventImpl>::set(Callable func) {
  TimerFuncHelper<ID,EID> helper;

  this->data.func = static_cast<InterruptFunc>(func);
}

template<int ID, typename TimerImpl> template<int EID, typename EventImpl> template<typename T>
inline void Timer<ID, TimerImpl>::Event<EID, EventImpl>::setComparator(T val) {
  TimerFuncHelper<ID,EID,AVR::Timer<ID>::SIZE == sizeof(T)*8> helper;

  REG<AVR::Timer<ID>::SIZE>(StaticListIterator<typename AVR::Timer<ID>::Compare, EID>::VALUE) = val;
}

template<int ID, typename TimerImpl> template<int EID, typename EventImpl>
inline void Timer<ID, TimerImpl>::Event<EID, EventImpl>::exec(void) {
  this->data.func();
}

template<int ID, typename TimerImpl> template<int EID, typename EventImpl>
inline bool Timer<ID, TimerImpl>::Event<EID, EventImpl>::activated(void) {
  return this->data.func != 0;
}

template<int ID, typename TimerImpl> template<int EID>
inline Timer<ID, TimerImpl>::Event<EID>& Timer<ID, TimerImpl>::event() {
  return StaticContainerIterator<typename TimerPrivateData<ID>::EventList, EID>::value(this->data.events);
}
