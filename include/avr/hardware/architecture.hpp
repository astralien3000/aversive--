#ifndef ARCHITECTURE_HPP
#define ARCHITECTURE_HPP

#include "register.hpp"

#include <avr/io.h>
//#include "part/atmega32.hpp"

//#if defined (__AVR_ATxmega128__)
//#include "part/atmega128.hpp"
//#elif defined (__AVR_ATxmega2560__)
#include "part/atmega2560.hpp"
//#endif

#define _VALUE(i) template value<i>

#endif//ARCHITECTURE_HPP
