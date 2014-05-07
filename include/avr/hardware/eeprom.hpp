#ifndef EEPROM_HPP
#define EEPROM_HPP

#include <base/singleton.hpp>
#include <base/integer.hpp>
#include "architecture.hpp"

class Eeprom : public Singleton<Eeprom> {
  friend class Singleton<Eeprom>;

private:
  //! \brief Default Constructor (private)
  Eeprom(void) {}

public:
  void init(void) {}
  void quit(void) {}

  void write(u16 addr, u8 data) {
    while(REG(eeprom<0>::control) & CFG(eeprom<0>::control::write));
    REG(eeprom<0>::address) = VAL(eeprom<0>::address, addr);
    REG(eeprom<0>::data) = VAL(eeprom<0>::data, data);
    REG(eeprom<0>::control) |= CFG(eeprom<0>::control::masterwrite);
    REG(eeprom<0>::control) |= CFG(eeprom<0>::control::write);
  }
  
  u8 read(u16 addr) {
    while(REG(eeprom<0>::control) & CFG(eeprom<0>::control::write));
    REG(eeprom<0>::address) = VAL(eeprom<0>::address, addr);
    REG(eeprom<0>::control) |= CFG(eeprom<0>::control::read);
    return REG(eeprom<0>::data);
  }

  void read(u16 addr, u8& data) {
    data = read(addr);
  }
};

#endif//EEPROM_HPP
