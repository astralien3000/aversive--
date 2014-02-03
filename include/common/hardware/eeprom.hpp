#ifndef EEPROM_HPP
#define EEPROM_HPP

#include <base/singleton.hpp>
#include <base/integer.hpp>

class Eeprom : public Singleton<Eeprom> {
  friend class Singleton<Eeprom>;

private:
  //! \brief Default Constructor (private)
  Eeprom(void);

public:
  void init(void);
  void quit(void);

  void write(u16 addr, u8 data);
  
  u8 read(u16 addr);
  void read(u16 addr, u8& data);
};

#endif//EEPROM_HPP
