# A new Home !

The project is currently migrating to a new repository.

Indeed, the project will be managed by the [AversivePlusPlus organisation](https://github.com/AversivePlusPlus).

It will contain a set of modules separated into several repositories.
The library will be more modulare, and easier to maintain.

You can visit the [project's website](http://aversiveplusplus.com) to get the most recent news.

# Aversive++

This project provides a C++ library that eases microcontroller programming.

Its aim is to provide an interface simple enough to be able to create complex applications, and optimized enough to enable small microcontrollers to execute these applications.

The other aspect of this library is to be multiplatform. Indeed, it is designed to provide the same API for a simulator (named SASIAE) and for AVR-based and ARM-based microcontrollers.

## Documentation

A big part of the API is documented. 
You can find an [online documentation](http://astralien3000.github.io/aversive--), or compile the documentation from the source code with Doxygen.

Build the documentation by executing this command at the root of the project:

`make doc`

Then, you can open build/doc/html/index.html with any web browser.

## Building

### Building for SASIAE
Type the command:

`make sasiae`

#### dependencies
 - Qt5-core

### Building for AVR
Type the command:

`make ${MMCU}`

Where `${MMCU}` is the microcontroller's name.
You can find the names of the supported microcontrollers below.

#### dependencies
 - avr-gcc
 - libc-avr
 - avr-binutils

#### microcontroller support
 - atmega32
 - atmega128
 - atmega2560

### Building for STM32
Type the command:

`make stm32`

You can find the names of the supported microcontrollers below.

#### dependencies
 - arm-none-eabi-gcc

#### microcontroller support
 - stm32f4

### Building for all the supported platforms
The command below will build Aversive++ for all the supported platforms:

`make`

## Running unit tests
Note: some unit tests are implemented for every supported platforms.

### Hardware independent code

`make test_common`

### SASIAE

`make test_sasiae`

### AVR
The AVR tests requires an Arduino Mega2560 to be connected to the computer.
The board will be automatically programmed with different unit tests.

`make test_avr`

