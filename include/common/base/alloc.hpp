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

#include <stdlib.h>

//! \brief New operator. Allocate a memory area.
//! \param s : the size of the memory area to allocate.
//! \return A pointer to the newly allocated memory area.
inline void* operator new(size_t s) {
  return malloc(s);
}

//! \brief Delete operator.
//! \param p : the memory area address to free.
inline void operator delete(void* p) {
  free(p);
}
