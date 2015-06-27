# Aversive++

This project provides a C++ library that ease microcontroller programming.

It's aim is to provide an interface simple enough to be able to create complex applications, 
and optimized enough to enable small microcontrollers to execute these applications.

The other aspect of this library is to be multiplatform. 
Indeed, it is designed to provide the same API for a simulator, called SASIAE, 
AVR's microcontrollers, and ARM-based microcontrollers.

## Documentation

A big part of the API is documented. 
You can find an [online documentation](http://astralien3000.github.io/aversive--), 
or compile the documentation from the source code with Doxygen.

Build the documentation by executing this command at the root of the project :

`make doc`

Then, you can open build/doc/html/index.html with any web browser.

## Compile

### Compile for SASIAE
Type the command :

`make sasiae`

#### dependencies
 - Qt5

### Compile for AVR
Type the command :

`make ${MMCU}`

Where `${MMCU}` is the microcontroller's name.
You can find a list of supported microcontrollers after the dependencies.

#### dependencies
 - avr-gcc
 - libc-avr
 - avr-binutils

#### microcontroller support
 - atmega32
 - atmega128
 - atmega2560

### Compile for STM32
Type the command :

`make stm32`

You can find a list of supported microcontrollers after the dependencies.

#### dependencies
 - arm-none-eabi-gcc

#### microcontroller support
 - stm32f4

### Compile all
This command will compile Aversive++ for all supported platform.

`make`

## Execute unit tests
Some unit tests are implemented for each platform.

### Hardware intependent code

`make test_common`

### SASIAE

`make test_sasiae`

### AVR
The AVR tests needs you to have an arduino Mega2560 connected to the computer.
The board will be automatically programmed with different unit tests.

`make test_avr`


