#ifndef AVR_EEPROM_STREAM_HPP
#define AVR_EEPROM_STREAM_HPP

#include "../../../common/device/stream/eeprom_stream.hpp"

#include <hardware/eeprom.hpp>

inline EepromStream::EepromStream(const char* name) : Device(name) {
  Eeprom::instance().init();
}

inline char EepromStream::getValue(void) {
  if(_mini_buffer_used) {
    _mini_buffer_used = false;
    return _mini_buffer;
  }
  else {
    char ret = Eeprom::instance().read(cursor());
    seek(cursor()+1);
    return ret;
  }
}

inline void EepromStream::setValue(char val) {
  Eeprom::instance().write(cursor(), val);
  seek(cursor()+1);
}


#endif//AVR_EEPROM_STREAM_HPP
