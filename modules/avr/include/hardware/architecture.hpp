/*
    Aversive++                                                           
    Copyright (C) 2014 Eirbot                                            
                                                                         
    This program is free software: you can redistribute it and/or modify 
    it under the terms of the GNU General Public License as published by 
    the Free Software Foundation, either version 3 of the License, or    
    (at your option) any later version.                                  
                                                                         
    This program is distributed in the hope that it will be useful,      
    but WITHOUT ANY WARRANTY; without even the implied warranty of       
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the        
    GNU General Public License for more details.                         
                                                                         
    You should have received a copy of the GNU General Public License    
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef ARCHITECTURE_HPP
#define ARCHITECTURE_HPP

#include "register.hpp"
#include "config.hpp"

#include <avr/io.h>

#if defined (__AVR_ATmega32__)
#include "part/atmega32.hpp"
#elif defined (__AVR_ATmega128__)
#include "part/atmega128.hpp"
#elif defined (__AVR_ATmega2560__)
#include "part/atmega2560.hpp"
#endif

#define _VALUE(i) template value<i>

#endif//ARCHITECTURE_HPP
