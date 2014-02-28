#include <device/stream/eeprom_stream.hpp>

#include <aversive.hpp>
#include <client_thread.hpp>
#include <sstream>

EepromStream::EepromStream(const char* name) : RandomAccessStream(name) {

}

char EepromStream::getValue(void) {
  seek(cursor()+1);
  return 0;
}

void EepromStream::setValue(char val) {
  std::ostringstream oss;
  oss << "value " << (int)((u8)val);

  ClientThread::instance().
    sendDeviceMessage(*this, 
		      oss.str().c_str());
  seek(cursor()+1);
}
