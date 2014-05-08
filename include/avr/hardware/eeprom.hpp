#ifndef EEPROM_HPP
#define EEPROM_HPP

#include <base/integer.hpp>
#include "architecture.hpp"

class Eeprom {
private:
  //! \brief Default Constructor (private)
  Eeprom(void);
  Eeprom(const Eeprom&);

public:
  static inline void write(u16 addr, u8 data) {
    while(REG(eeprom<0>::control) & CFG(eeprom<0>::control::write));
    REG(eeprom<0>::address) = VAL(eeprom<0>::address, addr);
    REG(eeprom<0>::data) = VAL(eeprom<0>::data, data);
    REG(eeprom<0>::control) |= CFG(eeprom<0>::control::masterwrite);
    REG(eeprom<0>::control) |= CFG(eeprom<0>::control::write);
  }
  
  static inline u8 read(u16 addr) {
    while(REG(eeprom<0>::control) & CFG(eeprom<0>::control::write));
    REG(eeprom<0>::address) = VAL(eeprom<0>::address, addr);
    REG(eeprom<0>::control) |= CFG(eeprom<0>::control::read);
    return REG(eeprom<0>::data);
  }

  static inline void read(u16 addr, u8& data) {
    data = read(addr);
  }
};

#endif//EEPROM_HPP
