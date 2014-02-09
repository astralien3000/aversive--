#ifndef EEPROM_STREAM_HPP
#define EEPROM_STREAM_HPP

#include <device/stream/random_access_stream.hpp>

//! \brief Eeprom stream
class EepromStream : public RandomAccessStream {
public:
  EepromStream(const char*);

  char getValue(void);
  void setValue(char);
};

#endif//EEPROM_STREAM_HPP
