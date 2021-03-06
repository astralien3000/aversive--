#include <hdl/hdl.hpp>
#include <avr/io.h>

using namespace HDL;

#define TEST_REGISTER(aversive, libc)		\
  static_assert((usys)aversive.ADDRESS == (usys)&libc, "ERROR : Bad Register address")

int main(int, char**) {
  
  TEST_REGISTER(GPIO_A::PIN , PINA);
  TEST_REGISTER(GPIO_A::DDR , DDRA);
  TEST_REGISTER(GPIO_A::PORT, PORTA);

  TEST_REGISTER(GPIO_B::PIN , PINB);
  TEST_REGISTER(GPIO_B::DDR , DDRB);
  TEST_REGISTER(GPIO_B::PORT, PORTB);

  TEST_REGISTER(GPIO_C::PIN , PINC);
  TEST_REGISTER(GPIO_C::DDR , DDRC);
  TEST_REGISTER(GPIO_C::PORT, PORTC);

  TEST_REGISTER(GPIO_D::PIN , PIND);
  TEST_REGISTER(GPIO_D::DDR , DDRD);
  TEST_REGISTER(GPIO_D::PORT, PORTD);

  TEST_REGISTER(GPIO_E::PIN , PINE);
  TEST_REGISTER(GPIO_E::DDR , DDRE);
  TEST_REGISTER(GPIO_E::PORT, PORTE);

  TEST_REGISTER(GPIO_F::PIN , PINF);
  TEST_REGISTER(GPIO_F::DDR , DDRF);
  TEST_REGISTER(GPIO_F::PORT, PORTF);

  TEST_REGISTER(GPIO_G::PIN , PING);
  TEST_REGISTER(GPIO_G::DDR , DDRG);
  TEST_REGISTER(GPIO_G::PORT, PORTG);

#if defined __ATmegaxx0__
  TEST_REGISTER(GPIO_H::PIN , PINH);
  TEST_REGISTER(GPIO_H::DDR , DDRH);
  TEST_REGISTER(GPIO_H::PORT, PORTH);

  TEST_REGISTER(GPIO_J::PIN , PINJ);
  TEST_REGISTER(GPIO_J::DDR , DDRJ);
  TEST_REGISTER(GPIO_J::PORT, PORTJ);

  TEST_REGISTER(GPIO_K::PIN , PINK);
  TEST_REGISTER(GPIO_K::DDR , DDRK);
  TEST_REGISTER(GPIO_K::PORT, PORTK);

  TEST_REGISTER(GPIO_L::PIN , PINL);
  TEST_REGISTER(GPIO_L::DDR , DDRL);
  TEST_REGISTER(GPIO_L::PORT, PORTL);
#endif    //__ATmegaxx0__

  TEST_REGISTER(TIMER_0::IFR  , TIFR0);
  TEST_REGISTER(TIMER_0::IMSK , TIMSK0);
  TEST_REGISTER(TIMER_0::CCR_A, TCCR0A);
  TEST_REGISTER(TIMER_0::CCR_B, TCCR0B);
  TEST_REGISTER(TIMER_0::CNT  , TCNT0);
  TEST_REGISTER(TIMER_0::OCR_A, OCR0A);
  TEST_REGISTER(TIMER_0::OCR_B, OCR0B);
  
  TEST_REGISTER(TIMER_1::IFR    , TIFR1);
  TEST_REGISTER(TIMER_1::IMSK   , TIMSK1);
  TEST_REGISTER(TIMER_1::CCR_A  , TCCR1A);
  TEST_REGISTER(TIMER_1::CCR_B  , TCCR1B);
  TEST_REGISTER(TIMER_1::CCR_C  , TCCR1C);
  TEST_REGISTER(TIMER_1::CNT    , TCNT1);
  TEST_REGISTER(TIMER_1::CNT_L  , TCNT1L);
  TEST_REGISTER(TIMER_1::CNT_H  , TCNT1H);
  TEST_REGISTER(TIMER_1::OCR_A  , OCR1A);
  TEST_REGISTER(TIMER_1::OCR_A_L, OCR1AL);
  TEST_REGISTER(TIMER_1::OCR_A_H, OCR1AH);
  TEST_REGISTER(TIMER_1::OCR_B  , OCR1B);
  TEST_REGISTER(TIMER_1::OCR_B_L, OCR1BL);
  TEST_REGISTER(TIMER_1::OCR_B_H, OCR1BH);
  
  TEST_REGISTER(TIMER_2::IFR  , TIFR2);
  TEST_REGISTER(TIMER_2::IMSK , TIMSK2);
  TEST_REGISTER(TIMER_2::CCR_A, TCCR2A);
  TEST_REGISTER(TIMER_2::CCR_B, TCCR2B);
  TEST_REGISTER(TIMER_2::CNT  , TCNT2);
  TEST_REGISTER(TIMER_2::OCR_A, OCR2A);
  TEST_REGISTER(TIMER_2::OCR_B, OCR2B);
  
  TEST_REGISTER(TIMER_3::IFR    , TIFR3);
  TEST_REGISTER(TIMER_3::IMSK   , TIMSK3);
  TEST_REGISTER(TIMER_3::CCR_A  , TCCR3A);
  TEST_REGISTER(TIMER_3::CCR_B  , TCCR3B);
  TEST_REGISTER(TIMER_3::CCR_C  , TCCR3C);
  TEST_REGISTER(TIMER_3::CNT    , TCNT3);
  TEST_REGISTER(TIMER_3::CNT_L  , TCNT3L);
  TEST_REGISTER(TIMER_3::CNT_H  , TCNT3H);
  TEST_REGISTER(TIMER_3::OCR_A  , OCR3A);
  TEST_REGISTER(TIMER_3::OCR_A_L, OCR3AL);
  TEST_REGISTER(TIMER_3::OCR_A_H, OCR3AH);
  TEST_REGISTER(TIMER_3::OCR_B  , OCR3B);
  TEST_REGISTER(TIMER_3::OCR_B_L, OCR3BL);
  TEST_REGISTER(TIMER_3::OCR_B_H, OCR3BH);
  
  TEST_REGISTER(TIMER_4::IFR    , TIFR4);
  TEST_REGISTER(TIMER_4::IMSK   , TIMSK4);
  TEST_REGISTER(TIMER_4::CCR_A  , TCCR4A);
  TEST_REGISTER(TIMER_4::CCR_B  , TCCR4B);
  TEST_REGISTER(TIMER_4::CCR_C  , TCCR4C);
  TEST_REGISTER(TIMER_4::CNT    , TCNT4);
  TEST_REGISTER(TIMER_4::CNT_L  , TCNT4L);
  TEST_REGISTER(TIMER_4::CNT_H  , TCNT4H);
  TEST_REGISTER(TIMER_4::OCR_A  , OCR4A);
  TEST_REGISTER(TIMER_4::OCR_A_L, OCR4AL);
  TEST_REGISTER(TIMER_4::OCR_A_H, OCR4AH);
  TEST_REGISTER(TIMER_4::OCR_B  , OCR4B);
  TEST_REGISTER(TIMER_4::OCR_B_L, OCR4BL);
  TEST_REGISTER(TIMER_4::OCR_B_H, OCR4BH);
  
  TEST_REGISTER(TIMER_5::IFR    , TIFR5);
  TEST_REGISTER(TIMER_5::IMSK   , TIMSK5);
  TEST_REGISTER(TIMER_5::CCR_A  , TCCR5A);
  TEST_REGISTER(TIMER_5::CCR_B  , TCCR5B);
  TEST_REGISTER(TIMER_5::CCR_C  , TCCR5C);
  TEST_REGISTER(TIMER_5::CNT    , TCNT5);
  TEST_REGISTER(TIMER_5::CNT_L  , TCNT5L);
  TEST_REGISTER(TIMER_5::CNT_H  , TCNT5H);
  TEST_REGISTER(TIMER_5::OCR_A  , OCR5A);
  TEST_REGISTER(TIMER_5::OCR_A_L, OCR5AL);
  TEST_REGISTER(TIMER_5::OCR_A_H, OCR5AH);
  TEST_REGISTER(TIMER_5::OCR_B  , OCR5B);
  TEST_REGISTER(TIMER_5::OCR_B_L, OCR5BL);
  TEST_REGISTER(TIMER_5::OCR_B_H, OCR5BH);

  TEST_REGISTER(UART_0::CSR_A, UCSR0A);
  TEST_REGISTER(UART_0::CSR_B, UCSR0B);
  TEST_REGISTER(UART_0::CSR_C, UCSR0C);
  TEST_REGISTER(UART_0::BRR  , UBRR0);
  TEST_REGISTER(UART_0::BRR_L, UBRR0L);
  TEST_REGISTER(UART_0::BRR_H, UBRR0H);
  TEST_REGISTER(UART_0::DR   , UDR0);

  TEST_REGISTER(UART_1::CSR_A, UCSR1A);
  TEST_REGISTER(UART_1::CSR_B, UCSR1B);
  TEST_REGISTER(UART_1::CSR_C, UCSR1C);
  TEST_REGISTER(UART_1::BRR  , UBRR1);
  TEST_REGISTER(UART_1::BRR_L, UBRR1L);
  TEST_REGISTER(UART_1::BRR_H, UBRR1H);
  TEST_REGISTER(UART_1::DR   , UDR1);

#if defined __ATmegaxx0__
  TEST_REGISTER(UART_2::CSR_A, UCSR2A);
  TEST_REGISTER(UART_2::CSR_B, UCSR2B);
  TEST_REGISTER(UART_2::CSR_C, UCSR2C);
  TEST_REGISTER(UART_2::BRR  , UBRR2);
  TEST_REGISTER(UART_2::BRR_L, UBRR2L);
  TEST_REGISTER(UART_2::BRR_H, UBRR2H);
  TEST_REGISTER(UART_2::DR   , UDR2);
  
  TEST_REGISTER(UART_3::CSR_A, UCSR3A);
  TEST_REGISTER(UART_3::CSR_B, UCSR3B);
  TEST_REGISTER(UART_3::CSR_C, UCSR3C);
  TEST_REGISTER(UART_3::BRR  , UBRR3);
  TEST_REGISTER(UART_3::BRR_L, UBRR3L);
  TEST_REGISTER(UART_3::BRR_H, UBRR3H);
  TEST_REGISTER(UART_3::DR   , UDR3);
#endif    //__ATmegaxx0__

  return 0;
}
