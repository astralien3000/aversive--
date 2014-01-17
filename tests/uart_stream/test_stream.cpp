#include <device/stream/uart_stream.hpp>
#include <hardware/interrupts.hpp>

#define F_CPU 16000000L
#include <util/delay.h>

void reset_fpga(){
  DDRB |= (1<<0); 
  PORTB &= ~(1<<0);
  _delay_ms(300);
  PORTB |= (1<<0);
  PORTB &= ~(1<<0);
}

//Les 2 moteurs sont accedés par ces 2 bytes. Ils ont la logique de complement de 2, donc pour 
//les faire marcher arriere, il suffit attibuer -127
#define MOTEUR1   _SFR_IO8(0x8000)
#define MOTEUR2   _SFR_IO8(0x8001)
//0x8002  RESERVED
//0x8003  RESERVED
//Les registreurs SERVOx gardent le temps du pulse qui será envoye au servo-moteur (en microsecondes)
//Ils sont organizees sur le modele "little-endian" (+1<=MSB, 0<=LSB)
#define SERVO1   _SFR_IO8(0x8004) 
#define SERVO2   _SFR_IO8(0x8005) 
#define SERVO3   _SFR_IO8(0x8006) 
#define SERVO4   _SFR_IO8(0x8007) 
#define SERVO5   _SFR_IO8(0x8008) 
#define SERVO6   _SFR_IO8(0x8009) 
#define SERVO7   _SFR_IO8(0x800A) 
#define SERVO8   _SFR_IO8(0x800B) 
#define SERVO9   _SFR_IO8(0x800C) 
#define SERVO10   _SFR_IO8(0x800D) 
#define SERVO11   _SFR_IO8(0x800E) 
#define SERVO12   _SFR_IO8(0x800F) 
#define SERVO13   _SFR_IO8(0x8010) 
#define SERVO14   _SFR_IO8(0x8011) 
#define SERVO15   _SFR_IO8(0x8012) 
#define SERVO16   _SFR_IO8(0x8013)
//Le prochain registreur est la relation entre la distance entre roues et la distance de chaque pas.
//il est necessaire pour la calibration du module qui determine la position relative
#define RELATION   _SFR_IO32(0x8024) 
//du 0x8026 au 0x807e => reserved
//Le registreur de RESET permet au programmateur faire du reset à une partie especifique de la FPGA.
//Pour faire une reset, par example, du timer, il suffit ecrire RESET_FPGA = 1; et apres RESET_FPGA = 0;
//(RESERVED - RESERVED - DEBBUGER - COUNTEUR - PWM - SERVO - COUNTERROT - TIMER)
#define RESET_FPGA   _SFR_IO8(0x807F)
//Tous les prochains registreurs sont "READ-ONLY", donc essayer d'ecrire sur ces addresses ne sortirá
//aucun effet
//les MICROSECONDES, MILISECONDES et SECONDES determinent la periode de temps depuis 
//le module a eté redemaré (soit par le pin RESET, soit par le registreur RESET_FPGA)
#define FPGA_US   _SFR_IO16(0x8080)
#define FPGA_MS   _SFR_IO16(0x8082)
#define FPGA_S    _SFR_IO16(0x8084)
//les registreurs POSX_FPGA et POSY_FPGA disent la position du robot en nombre de pas du encoder.
//le registreur ROT_FPGA dit le angle avec un format "fixed point", ça veut dire qui il est organizée
//comme ça:
//(angle de 0 à 360 <9 bits>)(1/2 degrée <1 bit>)(1/4 degrée <1 bit>)(1/8 degrée <1
//bit>)(1/16)(1/32)(1/64)(1/128)
#define POSX_FPGA    _SFR_IO32(0x8086)
#define POSY_FPGA    _SFR_IO32(0x808A)
#define ROT_FPGA     _SFR_IO16(0x808E)
//les compteurs ont le nombre de pas qui chaque encoder a tourné.
#define COMPTEUR1    _SFR_IO32(0x8094)
#define COMPTEUR2    _SFR_IO32(0x8098)
#define COMPTEUR3    _SFR_IO32(0x809C)
#define COMPTEUR4    _SFR_IO32(0x80A0)
// du 0x808e au 0x80ff => RESERVED (read as 0)


/*
int main(void) {
  Uart<0>::instance().init();

  while(1) {
    _delay_ms(500);
    Uart<0>::instance().send('a');
  }

  return 0;
}
*/

static u16 i = 0;

bool robotInit() {
  (void)UartStream<0>::instance();
  /*
  Uart<0>::instance().init();

  Uart<0>::instance().recvEvent().setFunction([]() {
      char c = Uart<0>::instance().recv<u8>();      
      Uart<0>::instance().send(c);
    });
  Uart<0>::instance().recvEvent().start();
  
  Uart<0>::instance().sendEvent().setFunction([]() {
    });
  Uart<0>::instance().sendEvent().start();
  */
  Interrupts::set();
  _delay_ms(3000);
  reset_fpga();
  //UartStream<0>::instance() << "123456789\n";
  Uart<0>::instance().send('a');
  return true;
}

void robotLoop() {
  //_delay_ms(3000);
  //char c = Uart<0>::instance().recv<u8>();
  //UartStream<0>::instance() << "123456789012345678901234567890123456789012345678901234567890123456789\n";// << (u16)++i;
  for(i=0;i<64;i++)
    UartStream<0>::instance() << (double)14;
/*
  UartStream<0>::instance() << "" << (u8)++i;
  UartStream<0>::instance() << " :: " << (u16)i;
  UartStream<0>::instance() << " :: " << (u32)i;
  UartStream<0>::instance() << " :: " << (float)i;
  //UartStream<0>::instance() << " :: " << (double)i;
  UartStream<0>::instance() << "128372819120\n";*/
}

void robotExit() {
}
