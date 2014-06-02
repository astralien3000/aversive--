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

#include <hardware/interrupts.hpp>

inline void Interrupts::clear(void) {
  __asm__ __volatile__ ("CLI\n");
}

inline void Interrupts::set(void) {
  __asm__ __volatile__ ("SEI\n");
}

template<typename T> inline void Interrupts::lock(T& flag) {
  flag = SREG;
  Interrupts::clear();
}

template<typename T> inline void Interrupts::unlock(T& flag) {
  SREG = flag;
  Interrupts::set();
}
