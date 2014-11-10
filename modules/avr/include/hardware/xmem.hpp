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

class Xmem : public Singleton<Xmem> {
  friend class Singleton<Xmem>;

private:
  //! \brief Private Default Constructor
Xmem(void) {}

public:
  //! \brief Enable external memory management
  void init(void) {
    REG(xmem<0>::control) |= CFG(xmem<0>::control::enable);
    REG(xmem<0>::control) |= CFG(xmem<0>::control::defaultwait);  
  }
  
  //! \brief Disable external memory management
  void quit(void);
};

#endif//XMEM_HPP
