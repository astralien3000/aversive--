#include <system/scheduler.hpp>
#include <device/stream/buffered_uart_stream.hpp>
#include <hardware/interrupts.hpp>

BufferedUartStream<0>& io = BufferedUartStream<0>::instance();
Scheduler& sched = Scheduler::instance();

#include <hardware/timer.hpp>
#include <device/eirbot2014/servomotor.hpp>
#include <container/list.hpp>
#include <math/saturate.hpp>

template<int ID>
class Multiservo : public Singleton<Multiservo<ID>> {
  friend class Singleton<Multiservo<ID>>;
  friend int main(int, char**);
  
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
  inst._time_us+= 55;
  //*(inst._servo.get(0)->_port) = 16;
  inst._servo.doForeach([](Servo* s) {
      Multiservo<ID>& inst = Multiservo<ID>::instance();
      if(Math::belong<u32>(inst._time_us % inst.PERIOD_US, s->_offset, s->_offset + s->_pwm)) {
	*(s->_port) = s->_pin_mask;
      }
      else {
	*(s->_port) = ~(s->_pin_mask);
	//io << "b\n";
      }
    });
}

template<int ID>
void Multiservo<ID>::addServo(typename Multiservo<ID>::Servo& servo) {
  _servo.append(&servo);
}


#include <avr/io.h>
#define F_CPU 16000000l
#include <util/delay.h>

#include <hardware/timer.hpp>

void test(volatile u8* p) {
  *p = (1<<4);
}

Timer<0>& tim = Timer<0>::instance();
Multiservo<1>::Servo s1("test", &PORTA, 4);

int main(int argc, char* argv[]) {
  (void)argc;
  (void)argv;

  io << "Begin\n";
  DDRA = 0xFF;
  
  Multiservo<1>::instance().addServo(s1);

  s1.setValue(700);

  tim.init();
  tim.setPrescaler<0>();
  Timer<0>::ComparEvent<0>& evt = tim.comparEvent<0>();
  evt.setFunction([]() {
      Multiservo<1>::update();
      //io << "a\n";
    });

  evt.setComparator(1);

  evt.start();

  Interrupts::init();

  while(1) {

    //test(&PORTH);
  }

  while(1);

  return 0;
}
