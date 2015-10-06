//#include <memory_mapping.hpp>

//#define AVERSIVE

#if defined AVERSIVE
#include <hdl/reg.hpp>
using namespace HDL;

#else
#include <avr/io.h>

#endif

int main(int, char**) {
#if defined AVERSIVE

  //TIMER_1::Fields::WGM = TIMER_5::Fields::WGM;
  //UART_0::Fields::CSZ = UART_1::Fields::CSZ;
  UART_0::Fields::RXC = true;
  TIMER_0::IFR = 0x10;
  
#else

  UCSR0A |= (1 << RXC0);
  TIFR0 = 0x10;

#endif
  
  return 0;
}
