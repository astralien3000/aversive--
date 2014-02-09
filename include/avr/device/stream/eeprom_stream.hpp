#ifndef AVR_EEPROM_STREAM_HPP
#define AVR_EEPROM_STREAM_HPP

#include "../../../common/device/stream/eeprom_stream.hpp"

#include <hardware/eeprom.hpp>

EepromStream::EepromStream(const char* name) : RandomAccessStream(name) {
  Eeprom::instance().init();
}

char EepromStream::getValue(void) {
  char ret = Eeprom::instance().read(cursor());
  seek(cursor()+1);
  return ret;
}

void EepromStream::setValue(char val) {
  Eeprom::instance().write(cursor(), val);
  seek(cursor()+1);
}


#endif//AVR_EEPROM_STREAM_HPP
