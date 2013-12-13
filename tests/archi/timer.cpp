#include <hardware/architecture.hpp>

#include<avr/interrupt.h>

#include <hardware/interrupts.hpp>

#define F_CPU 16000000L
#include <util/delay.h>

void wait() {
  volatile u32 cnt = 0;
  while(cnt < 524288) cnt++;
}

u16 cnt = 0;
u8 toogle = 0;

#include <avr/io.h>

#define MOTEUR1 ((u8*)0x8000); 
#define MOTEUR2 ((u8*)0x8001);

#define COMPTEUR1    ((u32*)0x8092)
#define COMPTEUR2    ((u32*)0x8096)
#define COMPTEUR3    ((u32*)0x809A)
#define COMPTEUR4    ((u32*)0x809E)

void test(void) {
  cnt++;
  if(cnt == 3) {
    if(toogle) {
      u8* mem = MOTEUR1;
      *mem = 25;
      //*MOTEUR2 = 100;
      PORTE = 0xFF;
    }
    else {
      u8* mem = MOTEUR1;
      *mem = 50;
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


template<unsigned long FSOC, unsigned long DIV, unsigned long BAUD>
void uart_init(void)
{
  unsigned long ubrr = (FSOC / (DIV * BAUD)) - 1l;

  /* Set baud rate */
  UBRR0H = (unsigned char)(ubrr>>8);
  UBRR0L = (unsigned char)ubrr;
  /* Enable receiver and transmitter */
  UCSR0B = (1<<RXEN0)|(1<<TXEN0);
  /* Set frame format: 8data, 1stop bit */
  UCSR0C = (1<<UCSZ00)|(1<<UCSZ01);
}

void uart_send( unsigned char data )
{
  /* Wait for empty transmit buffer */
  while (!( UCSR0A & (1<<UDRE0)));
  /* Put data into buffer, sends the data */
  UDR0 = data;
  for(int i = 255 ; i > 0 ; i--);
}

unsigned char uart_recv( void )
{
  /* Wait for data to be received */
  while ( !(UCSR0A & (1<<RXC0)) );
  /* Get and return received data from buffer */
  return UDR0;
}

#include <base/array.hpp>

template<int SIZE>
class OutputStream {
protected:
  Array<SIZE, char> buff;
  int i = 0;
public:
  OutputStream(void) {
    uart_init<16000000, 16, 9600>();
  }
  
  void setOutput(const Array<SIZE, char>& ar) {
    buff = ar;
  }

  OutputStream<SIZE>& operator<<(const char* str) {
    const char* it = str;
    while((*it) != '\0' && i < SIZE) {
      buff[i] = *it;
      i++;
      if(*it == '\n') {
	buff[i] = '\0';
	flushOutput();
      }
      it++;
    }
    buff[i] = '\0';
    return (*this);
  }

  template<typename T>
  OutputStream<SIZE>& operator<<(T val) {
    int beg = i;
    if(val == 0) {
      buff[i] = '0';
      i++;
    }
    else {
      while(val != 0 && i < SIZE) {
	buff[i] = '0' + (val % 10);
	val /= 10;
	i++;
      }
      
      for(int j = 0; j <= (i-beg-1)/2 ; j++) {
	char aux = buff[beg + j];
	buff[beg + j] = buff[i - j - 1];
	buff[i - j - 1] = aux;
      }
    }
    buff[i] = '\0';
    return (*this);
  }

  void flushOutput(void) {
    for(int j = 0 ; j < SIZE && buff[j] != '\0' ; j++) {
      uart_send(buff[j]);
    }
    i = 0;
  }
};


int main(int argc, char* argv[]) {
  
  XMCRA |= (1 << SRW11) | (1 << SRW00);
  MCUCR |= (1 << SRE);
  DDRB = 1;
  PORTB = 0;
  _delay_ms(300);
  PORTB = 1; // RESET ??
  PORTB = 0; // RESET ??

  REG(timer<1>::control) = 
    CFG(timer<1>::control::wgm::normal) | 
    CFG(timer<1>::control::prescaler::value<64>);
  
  REG(timer<1>::imask) =
    CFG(timer<1>::imask::match<0>);
  
  REG(timer<1>::counter) = VAL(timer<1>::counter, 257);

  Interrupts::set();
  
  wait();

  u8* mem = MOTEUR1;
  *mem = 120;
  mem = MOTEUR2;
  *mem = 120;

  DDRE = 0xFF;
  PORTE = 0xFF;

  u32* c1 = COMPTEUR1;
  u32* c2 = COMPTEUR2;
  u32* c3 = COMPTEUR3;
  u32* c4 = COMPTEUR4;

  OutputStream<255> cout;
  //uart_init<16000000, 16, 9600>();
  _delay_ms(1000);
  while(1) {
    //uart_send('a');
    cout << *c1 << " " << *c2 << " " << *c3 << " " << *c4 << "\n";
    cout.flushOutput();
    _delay_ms(500);
  }
  
  return 0;
}

//#include <trash/interrupts.cpp>
