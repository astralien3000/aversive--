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

#ifndef XMEM_HPP
#define XMEM_HPP

#include <base/singleton.hpp>
#include "architecture.hpp"

template<int ID> struct xmem;

template<int ID>
class Xmem : public Singleton<Xmem<ID>> {
  friend class Singleton<Xmem<ID>>;

private:
  //! \brief Private Default Constructor
Xmem(void) {}

public:
  //! \brief Enable external memory management
  void init(void) {
    REG(xmem<ID>::control) |= CFG(xmem<ID>::control::enable);
    REG(xmem<ID>::control) |= CFG(xmem<ID>::control::defaultwait);  
  }
  
  //! \brief Disable external memory management
  void quit(void);
};

#endif//XMEM_HPP
