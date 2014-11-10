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

#ifndef INTERRUPTS_HPP
#define INTERRUPTS_HPP

#include <base/integer.hpp>

//! \brief Class providing routines for interruption management
class Interrupts {
  static volatile u16 counter;
public:
  //! \brief Start the interruptions
  static inline void init(void) {
    unlock();
  }
  
  //! \brief Stop the interruptions
  static inline void stop(void) {
    lock();
  }
  
  //! \brief Disable temporarily the interruptions if needed
  //! \note Use it at the beginning of a critical section
  static inline void lock(void) {
    clear();
    counter++;
  }
  
  //! \brief Revive the interruptions if needed
  //! \note Use it at the end of a critical section
  static inline void unlock(void) {
    clear();
    if(counter) {
      counter--;
    }
    if(!counter) {
      set();
    }
  }
  
  //! \brief An alias for "cli" instruction, disable interruptions
  //! \warning Use it only if you know what you are doing (see the other methods otherwise)
  static inline void clear(void) {
    __asm__ __volatile__ ("CLI\n");
  }
  
  //! \brief An alias for "sei" instruction, enable interruptions
  //! \warning Use it only if you know what you are doing (see the other methods otherwise)
  static inline void set(void) {
    __asm__ __volatile__ ("SEI\n");
  }
};

#endif//INTERRUPTS_HPP
