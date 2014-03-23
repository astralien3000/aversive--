#ifndef EEPROM_STREAM_HPP
#define EEPROM_STREAM_HPP

#include <device/stream/random_access_stream.hpp>
#include <device/device.hpp>

//! \brief Eeprom stream
class EepromStream : public Device, public RandomAccessStream {
public:
  EepromStream(const char*);

  char getValue(void);
  void setValue(char);
};

#endif//EEPROM_STREAM_HPP
