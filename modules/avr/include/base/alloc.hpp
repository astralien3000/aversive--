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

#ifndef AVR_ALLOC_HPP
#define AVR_ALLOC_HPP

#include <base/_base_alloc.hpp>

#include <stdlib.h>

inline void* Alloc::malloc(usys size) {
  return ::malloc((size_t) size);
}

inline void Alloc::free(void* ptr) {
  ::free(ptr);
}

inline void* Alloc::calloc(usys n, usys size) {
  return ::calloc((size_t) n, (size_t) size);
}

inline void* Alloc::realloc(void* ptr, usys size) {
  return ::realloc(ptr, (size_t) size);
}

//! \brief New operator. Allocate a memory area.
//! \param s : the size of the memory area to allocate.
//! \return A pointer to the newly allocated memory area.
inline void* operator new(usys s) {
  return Alloc::malloc(s);
}

//! \brief Delete operator.
//! \param p : the memory area address to free.
inline void operator delete(void* p) {
  Alloc::free(p);
}

//! \brief New[] operator. Allocate a memory area.
//! \param s : the size of the memory area to allocate.
//! \return A pointer to the newly allocated memory area.
inline void* operator new[](usys s) {
  return Alloc::malloc(s);
}

//! \brief Delete[] operator.
//! \param p : the memory area address to free.
inline void operator delete[](void* p) {
  Alloc::free(p);
}

#endif//AVR_ALLOC_HPP
