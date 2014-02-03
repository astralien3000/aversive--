#ifndef AVR_EEPROM_HPP
#define AVR_EEPROM_HPP

#include "../../common/hardware/eeprom.hpp"

inline Eeprom::Eeprom(void) {}

inline void Eeprom::init(void) {}

inline void Eeprom::quit(void) {}

inline void Eeprom::write(u16 addr, u8 data) {
  while(REG(eeprom<0>::control) & CFG(eeprom<0>::control::write));
  REG(eeprom<0>::address) = VAL(eeprom<0>::address, addr);
  REG(eeprom<0>::data) = VAL(eeprom<0>::data, data);
  REG(eeprom<0>::control) |= CFG(eeprom<0>::control::masterwrite);
  REG(eeprom<0>::control) |= CFG(eeprom<0>::control::write);
}

inline u8 Eeprom::read(u16 addr) {
  while(REG(eeprom<0>::control) & CFG(eeprom<0>::control::write));
  REG(eeprom<0>::address) = VAL(eeprom<0>::address, addr);
  REG(eeprom<0>::control) |= CFG(eeprom<0>::control::read);
  return REG(eeprom<0>::data);
}

inline void Eeprom::read(u16 addr, u8& data) {
  data = read(addr);
}

#endif//AVR_EEPROM_HPP
