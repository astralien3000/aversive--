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

#ifndef PINMAP_HPP
#define PINMAP_HPP

#include "architecture.hpp"

class Pinmap {
private:
  Pinmap(void);
  Pinmap(const Pinmap&);

public:
  enum Mode {
    IN,
    OUT
  };

  template<int ID>
  class Pin {
  private:
    Pin(void);
    Pin(const Pin&);
    
  private:
    static constexpr int port_num = ID / 8;
    static constexpr int bit_num  = ID % 8;

  public:
    static inline bool read(void) {
      return (REG(pinmap::pin<port_num>) & 
	      VAL(pinmap::pin<port_num>, (1 << bit_num))) != 0;
    }

    static inline void write(bool val) {
      if(val) {
	REG(pinmap::port<port_num>) |=
	  VAL(pinmap::port<port_num>, (1 << bit_num));
      }
      else {
	REG(pinmap::port<port_num>) &=
	  VAL(pinmap::port<port_num>, ~(1 << bit_num));
      }
    }

    static inline Mode mode(void) {
      bool d_out = REG(pinmap::control_out<port_num>) &
	VAL(pinmap::control_out<port_num>, (1 << bit_num));
      if(d_out) {
	return OUT;
      }
      else {
	return IN;
      }
    }

    static inline void setMode(Mode mod) {
      if(mod == OUT) {
	REG(pinmap::control_out<port_num>) |=
	  VAL(pinmap::control_out<port_num>, (1 << bit_num));
      }
      else {
	REG(pinmap::control_out<port_num>) &=
	  VAL(pinmap::control_out<port_num>, ~(1 << bit_num));
      }
    }
  };
};

#endif//PINMAP_HPP
