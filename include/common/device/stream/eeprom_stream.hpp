#ifndef EEPROM_STREAM_HPP
#define EEPROM_STREAM_HPP

#include <device/stream/random_access_stream.hpp>
#include <device/device.hpp>

//! \class EepromStream eeprom_stream.hpp <device/stream/eeprom_stream.hpp>
//! \brief Eeprom stream device.
class EepromStream : public Device, public RandomAccessStream {
public:
  //! \brief EepromStream constructor.
  //! \param name : the device's name.
  EepromStream(const char* name);
  
  //! \brief Read a character from the stream.
  //! \return The read character.
  char getValue(void);
  
  //! \brief Write a character into the stream.
  //! \param c : the character to write.
  void setValue(char c);
};

#endif//EEPROM_STREAM_HPP
