
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
/* #include <FreeRTOS.h> */
/* #include <list.h> */
/* #include <queue.h> */
/* #include <task.h> */
/* #include <semphr.h> */
/* #include <platform.h> */


#define GPIOD_BASE_ADDR 0x40020C00
#define GPIOD_MODER  (*(volatile long*)(GPIOD_BASE_ADDR + 0x00))
#define GPIOD_OTYPER (*(volatile long*)(GPIOD_BASE_ADDR + 0x04))

#define MODER0_0 0
#define MODER0_1 1

#define MODER1_0 2
#define MODER1_1 3

#define MODER2_0 4
#define MODER2_1 5

#define MODER12_0 24
#define MODER12_1 25

#define MODER13_0 26
#define MODER13_1 27

#define MODER14_0 28
#define MODER14_1 29

#define MODER15_0 30
#define MODER15_1 31

#define GPIOD_ODR (*(volatile long*)(GPIOD_BASE_ADDR + 0x14))

#define GPIOD_BSRR (*(volatile long*)(GPIOD_BASE_ADDR + 0x18))

#define BS12 12
#define BS13 13
#define BS14 14
#define BS15 15

#define BR12 28
#define BR13 29
#define BR14 30
#define BR15 31

#define RCC_BASE_ADDR 0x40023800

#define RCC_AHB1ENR (*(volatile long*)(RCC_BASE_ADDR + 0x30))

#define GPIODEN 3

extern "C" void SystemCoreClockUpdate(void);
extern "C" volatile void* Default_Handler;
extern "C" void _fork(void);

extern "C" void __aeabi_unwind_cpp_pr0(void) {
  return;
}

int errno;

volatile int test = 1;

void wait(void) {
  for(volatile int i = 0 ; i < 1000000 ; i++) {
      if(!test) {
          return;
        }
    }
}

int main(int argc, char* argv[]) {
  (void)argc;
  (void)argv;

  volatile void* test = Default_Handler;
  //RCC_AHB1ENR = (1 << GPIODEN);
  RCC_AHB1ENR = 0xFFFFFFFF;

  GPIOD_MODER = (1 << MODER12_0) | (1 << MODER13_0) | (1 << MODER14_0) | (1 << MODER15_0);
  //GPIOD_ODR = 0xFFFFFFFF;

  while(test) {
      GPIOD_BSRR = (1 << BS12) | (1 << BS13); // | (1 << BS14) | (1 << BS15);
      wait();
      GPIOD_BSRR = 0;
      wait();
    }

  //SystemCoreClockUpdate();
  //_fork();
  while(test);
  return 0;
}

/* xSemaphoreHandle xTestSemaphore = NULL; */
/* xTaskHandle xHandleBlinkTask, xHandleMEMSTask; */
