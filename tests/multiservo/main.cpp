#include <system/scheduler.hpp>
#include <device/stream/buffered_uart_stream.hpp>
#include <hardware/interrupts.hpp>

#define F_CPU 8000000l

BufferedUartStream<0>& io = BufferedUartStream<0>::instance();
Scheduler& sched = Scheduler::instance();

#include <hardware/timer.hpp>
#include <device/eirbot2014/servomotor.hpp>
#include <container/list.hpp>
#include <math/saturate.hpp>

template<int ID>
class Multiservo : public Singleton<Multiservo<ID>> {
  friend class Singleton<Multiservo<ID>>;
  
 public:
  static const u32 MAX_SERVO = 16;
  static const u32 MAX_PWM_US = 2000;
  static const u32 PERIOD_US = 20000;
  class Servo;
  
 private:
  List<MAX_SERVO, Servo*> _servo;
  u32 _time_us;

 private:
  Multiservo(void);

 public:
  static void update(void);

 public:
  void addServo(Servo& servo);
};

template<int ID>
class Multiservo<ID>::Servo : public Servomotor {
  friend class Multiservo;

private:
  u16 _pwm;
  u16 _offset;
  
  volatile u8* _port;
  u8 _pin_mask;

public:
  Servo(const char* name, volatile u8* port, u8 pin)
    : Servomotor(name), _pwm(0), _offset(0),
      _port(port), _pin_mask((1 << pin)) {
    
  }

public:

  void setValue(s32 val) {
    _pwm = val;
  }
};


template<int ID>
Multiservo<ID>::Multiservo(void) 
  : _time_us(0) {
  
}

template<int ID>
void Multiservo<ID>::update(void) {
  Multiservo<ID>& inst = Multiservo<ID>::instance();
  inst._time_us += 1;//255 * 1000000 / F_CPU;

  inst._servo.doForeach([](Servo* s) {
      Multiservo<ID>& inst = Multiservo<ID>::instance();
      if(inst._time_us &1){//< s->_pwm){
	//Math::belong<u32>(inst._time_us % inst.PERIOD_US, s->_offset, s->_offset + s->_pwm)) {
	*(s->_port) = s->_pin_mask;
      }
      else if (inst._time_us < inst.PERIOD_US){
	*(s->_port) = ~(s->_pin_mask);
      }
      else{
	inst._time_us = 0;
      }
    });
}

template<int ID>
void Multiservo<ID>::addServo(typename Multiservo<ID>::Servo& servo) {
  _servo.append(&servo);
}


#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <hardware/timer.hpp>


//Timer<0>& tim = Timer<0>::instance();
//Multiservo<1>::Servo s1("test", &PORTB, 2);
  
ISR(TIMER0_OVF_vect){
  static u32 a=1;

  if (a<100/2)
    PORTA = 1 << 6 | 1 << 7;
  else
    PORTA = 0;

  a ++;
  if (a>100)
    a=0;
}

template<int ID> Timer<ID>::Timer() {}

template Timer<0>::Timer();
template Timer<1>::Timer();

int main(void){

  //io << "Begin\n";
  DDRA = 0xFF;
  DDRB = 0xFF;
  
  /*Multiservo<1>::instance().addServo(s1);
   
  s1.setValue(700);
  */
  
  TCCR0 |= CS02 | CS01 | CS00;
  TIMSK |= TOIE0;
  TIFR |= TOV0; 
  sei();

  /*tim.init();
  tim.setPrescaler<0>();
  Timer<0>::ComparEvent<0>& evt = tim.comparEvent<0>();
  //Timer<0>::OverflowEvent&evt = tim.overflowEvent();
  evt.setFunction([]() {
      Multiservo<1>::update();
      //io << "a\n";
    });


  evt.start();
  evt.setComparator(255);
  */
  //Interrupts::init();

  /*int a = 1000;
  while(1) {

    _delay_ms(1000);
    a+=100;
    s1.setValue(a%2000);
    }*/

  while(1);

  return 0;
}
