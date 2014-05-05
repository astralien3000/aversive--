#include <device/stream/binary_stream.hpp>

////////////////////////////////////////
// Binary Read

static void clearBlank(BinaryStream& s) {
  char c = s.nextValue();
  while(c == ' ' || c == '\0' || c == '\n' || c == '\r' || c == '\t') {
    s.getValue();
    c = s.nextValue();
  }
}

//! \fixme Last character is overwritten by \0 when the user's buffer is fulfilled.
void BinaryStream::binaryRead(char* str, u16 size) {
  clearBlank(*this);
  bool keep = true;
  char* beg = str;
  while(keep && (u16)(str-beg) < size) {
    char c = getValue();
    *str = c;
    str++;	
  }
  *(str-1) = '\0';
}

template<typename T>
inline void basic_binary_read(BinaryStream& s, T& val) {
  char* ptr = reinterpret_cast<char*>(&val);
  for(u8 i = 0 ; i < sizeof(T) ; i++, ptr++) {
    *ptr = s.getValue();
  }
}

void BinaryStream::binaryRead(s8& val) {
  basic_binary_read(*this, val);
}

void BinaryStream::binaryRead(s16& val) {
  basic_binary_read(*this, val);
}

void BinaryStream::binaryRead(s32& val) {
  basic_binary_read(*this, val);
}

void BinaryStream::binaryRead(s64& val) {
  basic_binary_read(*this, val);
}

void BinaryStream::binaryRead(u8& val) {
  basic_binary_read(*this, val);
}

void BinaryStream::binaryRead(u16& val) {
  basic_binary_read(*this, val);
}

void BinaryStream::binaryRead(u32& val) {
  basic_binary_read(*this, val);
}

void BinaryStream::binaryRead(u64& val) {
  basic_binary_read(*this, val);
}
