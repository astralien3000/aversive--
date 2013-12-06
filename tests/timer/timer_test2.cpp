
#include <hardware/timer.hpp>
#include <hardware/interrupts.hpp>
#include <maths/saturate.hpp>
#include <base/types.hpp>

typedef Timer<1> Timer0;

////////////////

#include <avr/io.h>
#include <avr/interrupt.h>

#include "impl/hardware/timer.cpp"
#include "impl/hardware/interrupts.cpp"



char bit = 4;
char toogle = 0;
void test(void) {
  if(toogle == 10) {
    PORTA = 1<<bit;
    bit = 4 + (bit+1)%4;
    toogle = 0;
  }
  else
    toogle++;
}

int main(int argc, char* argv[]) {
  DDRA = 0xFF;
  PORTA = 0xFF;

  Timer0& timer = Timer0::instance();
  timer.init();

  Timer0::Event<0>& evt = timer.event<0>();
  evt.set(test);
  
  evt.setComparator<u16>(50);
  timer.setPrescaler<0>();
  evt.start();

  Interrupts::set();

  int i = 0;
  while(1);

  Interrupts::clear();
  return 0;
}

