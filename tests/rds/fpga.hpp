#ifndef FPGA_HPP
#define FPGA_HPP

#include <base/integer.hpp>

///////////////////////////////////////////////
// Functions

void fpga_init(void);
void fpga_reset(void);
void fpga_config(void);

///////////////////////////////////////////////
// On UNIOC
#if defined (__AVR_ATmega128__)

static const u32 UART_BAUD = 115200;

#define ENC_R      (*(volatile u32*)0x80A0)
#define ENC_L      (*(volatile u32*)0x8098)
#define ENC_MOT_R  (*(volatile u32*)0x809C)
#define ENC_MOT_L  (*(volatile u32*)0x8094)

#define MOT_R      (*(volatile s8*)0x8000)
#define MOT_L      (*(volatile s8*)0x8001)
#define RESET_FPGA (*(volatile u8*)0x807F)

#define RELATION   (*(volatile u32*)0x8024)

#define UART_TX_1_DATA (*(volatile u8*)0x8028)
#define UART_TX_2_DATA (*(volatile u8*)0x8029)

#define SERVO1   (*(volatile u16*)0x8004)
#define SERVO2   (*(volatile u16*)0x8006)
#define SERVO3   (*(volatile u16*)0x8008)
#define SERVO4   (*(volatile u16*)0x800A)
#define SERVO5   (*(volatile u16*)0x800C)
#define SERVO6   (*(volatile u16*)0x800E)
#define SERVO7   (*(volatile u16*)0x8010)
#define SERVO8   (*(volatile u16*)0x8012)
#define SERVO9   (*(volatile u16*)0x8014)
#define SERVO10   (*(volatile u16*)0x8016)
#define SERVO11   (*(volatile u16*)0x8018)
#define SERVO12   (*(volatile u16*)0x801A)
#define SERVO13   (*(volatile u16*)0x801C)
#define SERVO14   (*(volatile u16*)0x801E)
#define SERVO15   (*(volatile u16*)0x8020)
#define SERVO16   (*(volatile u16*)0x8022)

// Min servo = 600
// Max servo = 2000

// READ-ONLY
#define FPGA_US    (*(volatile u16*)0x8080)
#define FPGA_MS    (*(volatile u16*)0x8082)
#define FPGA_S     (*(volatile u16*)0x8084)

#define POSX_FPGA  (*(volatile s32*)0x8088)
#define POSY_FPGA  (*(volatile s32*)0x808C)
#define ROT_FPGA   (*(volatile u16*)0x8090)

#define UART_TX_1_OCUP (*(volatile u8*)0x80A4) 
#define UART_TX_2_OCUP (*(volatile u8*)0x80A5) 

#define UART_RX_1_DATA (*(volatile u8*)0x80A8)
#define UART_RX_2_DATA (*(volatile u8*)0x80A9)

#define UART_RX_1_AVA  (*(volatile u8*)0x80AC)
#define UART_RX_2_AVA  (*(volatile u8*)0x80AD)

///////////////////////////////////////////////
// NO UNIOC
#else

extern volatile u32 ENC_R;
extern volatile u32 ENC_L;
extern volatile u32 ENC_MOT_R;
extern volatile u32 ENC_MOT_L;

extern volatile s8 MOT_R;
extern volatile s8 MOT_L;
extern volatile u8 RESET_FPGA;

extern volatile u32 RELATION;

// READ-ONLY
extern volatile u16 FPGA_US;
extern volatile u16 FPGA_MS;
extern volatile u16 FPGA_S;
extern volatile u16 POSX_FPGA;
extern volatile u16 POSY_FPGA;
extern volatile u16 ROT_FPGA;

#endif//UNIOC

#endif//FPGA_HPP
