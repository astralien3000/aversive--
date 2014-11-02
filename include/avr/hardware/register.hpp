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

#ifndef REGISTER_HPP
#define REGISTER_HPP

#include "config.hpp"

template<int SIZE, int ID>
class Register {
  const int reg_size;
  volatile typename Integer<SIZE>::Unsigned* const reg[3];
public:
  inline Register(void);
  
  template<typename Config>
  inline Register& operator=(const Config& cfg) {
    for(int i = 0 ; i < reg_size ; i++) {
      *reg[i] = cfg.value(i);
    }
    return *this;
  }

  template<typename Config>
  inline Register& operator|=(const Config& cfg) {
    for(int i = 0 ; i < reg_size ; i++) {
      *reg[i] |= cfg.value(i);
    }
    return *this;
  }

  template<typename Config>
  inline Register& operator&=(const Config& cfg) {
    for(int i = 0 ; i < reg_size ; i++) {
      *reg[i] &= cfg.value(i);
    }
    return *this;
  }

  template<typename Config>
  inline bool operator&(const Config& cfg) const {
    typename Integer<SIZE>::Unsigned ret = 0;
    for(int i = 0 ; i < reg_size ; i++) {
      ret |= *reg[i] & cfg.value(i);
    }
    return ret;
  }

  template<typename T>
  inline operator T(void) {
    T ret = 0;
    for(int i = 0 ; i < reg_size ; i++) {
      ret += (*reg[i]) << (SIZE * i);
    }
    return ret;
  }
};

#define REG(r) Register<r::SIZE, r::REG>()

#endif//REGISTER_HPP
