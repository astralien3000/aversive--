#include <hardware/architecture.hpp>

#include<avr/interrupt.h>

#include <hardware/interrupts.hpp>

void wait() {
  volatile u16 cnt = 0;
  while(cnt < 1024 * 8) cnt++;
}

u16 cnt = 0;
u8 toogle = 0;

#define MOTEUR1 ((u8*)0x8000); 
#define MOTEUR2 ((u8*)0x8001);

void test(void) {
  cnt++;
  if(cnt == 3) {
    if(toogle) {
      u8* mem = MOTEUR1;
      *mem = 0;
      //*MOTEUR2 = 100;
      PORTE = 0xFF;
    }
    else {
      u8* mem = MOTEUR1;
      *mem = 100;
      //*MOTEUR2 = 0;
      PORTE = 0x0;
    }
    toogle = !toogle;
    cnt = 0;
  }
}

ISR(TIMER1_COMPA_vect, ISR_NAKED) {
  uint8_t flags = SREG;
  
  test();
  
  SREG = flags;
  reti();
}

ISR(TIMER0_COMP_vect, ISR_NAKED) {
  uint8_t flags = SREG;

  test();
  
  SREG = flags;
  reti();
}


int main(int argc, char* argv[]) {
  
  XMCRA |= (1 << SRW11) | (1 << SRW00);
  MCUCR |= (1 << SRE);
  DDRB |= 1; // RESET ??

  REG(timer<1>::control) = 
    CFG(timer<1>::control::wgm::normal) | 
    CFG(timer<1>::control::prescaler::value<64>);

  REG(timer<1>::imask) =
    CFG(timer<1>::imask::match<0>);

  REG(timer<1>::counter) = 0;

  Interrupts::set();

  wait();

  u8* mem = MOTEUR1;
  *mem = 120;
  mem = MOTEUR2;
  *mem = 120;

  DDRE = 0xFF;
  PORTE = 0xFF;

  while(1);
  
  return 0;
}

#include <trash/interrupts.cpp>
