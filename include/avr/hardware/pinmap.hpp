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
