#include "../include/int.hpp"

extern "C" void __import(void) {}

#define XJMP(lbl) "jmp "#lbl

#define VECTORS __attribute__((naked,section(".vectors")))

extern "C" void __aversive_vectors(void) VECTORS;

void __aversive_vectors(void) {
  asm(XJMP(_init));                                      // 0
  asm(XJMP(_default_handler));                           // 1
  asm(XJMP(_default_handler));                           // 2
  asm(XJMP(_default_handler));                           // 3
  asm(XJMP(_default_handler));                           // 4
  asm(XJMP(_default_handler));                           // 5
  asm(XJMP(_default_handler));                           // 6
  asm(XJMP(_default_handler));                           // 7
  asm(XJMP(_default_handler));                           // 8
  asm(XJMP(_default_handler));                           // 9
  asm(XJMP(_default_handler));                           // 10
  asm(XJMP(_default_handler));                           // 11
  asm(XJMP(_default_handler));                           // 12
  asm(XJMP(_default_handler));                           // 13
  asm(XJMP(_default_handler));                           // 14
  asm(XJMP(_default_handler));                           // 15
  asm(XJMP(_default_handler));                           // 16
  asm(XJMP(_default_handler));                           // 17
  asm(XJMP(_default_handler));                           // 18
  asm(XJMP(_default_handler));                           // 19
  asm(XJMP(_default_handler));                           // 20
  asm(XJMP(_default_handler));                           // 21
  asm(XJMP(_default_handler));                           // 22
  asm(XJMP(_default_handler));                           // 23
  asm(XJMP(_default_handler));                           // 24
  asm(XJMP(_ZN3HDL10Interrupts4UARTILh0EE2rxEv));        // 25
  asm(XJMP(_ZN3HDL10Interrupts4UARTILh0EE2dreEv));       // 26
  asm(XJMP(_ZN3HDL10Interrupts4UARTILh0EE2txEv));        // 27
  asm(XJMP(_default_handler));                           // 28
  asm(XJMP(_default_handler));                           // 29
  asm(XJMP(_default_handler));                           // 30
  asm(XJMP(_default_handler));                           // 31
  asm(XJMP(_default_handler));                           // 32
  asm(XJMP(_default_handler));                           // 33
  asm(XJMP(_default_handler));                           // 34
  asm(XJMP(_default_handler));                           // 35
  asm(XJMP(_ZN3HDL10Interrupts4UARTILh1EE2rxEv));        // 36
  asm(XJMP(_ZN3HDL10Interrupts4UARTILh1EE2dreEv));       // 37
  asm(XJMP(_ZN3HDL10Interrupts4UARTILh1EE2txEv));        // 38
  asm(XJMP(_default_handler));                           // 39
  asm(XJMP(_default_handler));                           // 40
  asm(XJMP(_default_handler));                           // 41
  asm(XJMP(_default_handler));                           // 42
  asm(XJMP(_default_handler));                           // 43
  asm(XJMP(_default_handler));                           // 44
  asm(XJMP(_default_handler));                           // 45
  asm(XJMP(_default_handler));                           // 46
  asm(XJMP(_default_handler));                           // 47
  asm(XJMP(_default_handler));                           // 48
  asm(XJMP(_default_handler));                           // 49
  asm(XJMP(_default_handler));                           // 50
  asm(XJMP(_ZN3HDL10Interrupts4UARTILh2EE2rxEv));        // 51
  asm(XJMP(_ZN3HDL10Interrupts4UARTILh2EE2dreEv));       // 52
  asm(XJMP(_ZN3HDL10Interrupts4UARTILh2EE2txEv));        // 53
  asm(XJMP(_ZN3HDL10Interrupts4UARTILh3EE2rxEv));        // 54
  asm(XJMP(_ZN3HDL10Interrupts4UARTILh3EE2dreEv));       // 55
  asm(XJMP(_ZN3HDL10Interrupts4UARTILh3EE2txEv));        // 56
};


extern "C" __attribute__((naked,section(".init2"))) void _init(void) {
  asm("eor     r1, r1");
  asm("out     0x3f, r1");
  asm("ldi     r28, 0xFF");
  asm("ldi     r29, 0x21");
  asm("out     0x3e, r29");
  asm("out     0x3d, r28");
  asm("ldi     r16, 0x00");
  asm("out     0x3c, r16");
  asm("call    main");
  asm("jmp     _exit");
}
//*/

#pragma weak _ZN3HDL10Interrupts4UARTILh0EE2txEv  = _default_handler
#pragma weak _ZN3HDL10Interrupts4UARTILh0EE2dreEv = _default_handler
#pragma weak _ZN3HDL10Interrupts4UARTILh0EE2rxEv  = _default_handler

#pragma weak _ZN3HDL10Interrupts4UARTILh1EE2txEv  = _default_handler
#pragma weak _ZN3HDL10Interrupts4UARTILh1EE2dreEv = _default_handler
#pragma weak _ZN3HDL10Interrupts4UARTILh1EE2rxEv  = _default_handler

#pragma weak _ZN3HDL10Interrupts4UARTILh2EE2txEv  = _default_handler
#pragma weak _ZN3HDL10Interrupts4UARTILh2EE2dreEv = _default_handler
#pragma weak _ZN3HDL10Interrupts4UARTILh2EE2rxEv  = _default_handler

#pragma weak _ZN3HDL10Interrupts4UARTILh3EE2txEv  = _default_handler
#pragma weak _ZN3HDL10Interrupts4UARTILh3EE2dreEv = _default_handler
#pragma weak _ZN3HDL10Interrupts4UARTILh3EE2rxEv  = _default_handler

extern "C" __attribute__((naked)) void _default_handler(void) {
  while(1);
}
