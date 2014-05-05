#include <device/stream/binary_stream.hpp>

////////////////////////////////////////
// Binary Write

void BinaryStream::binaryWrite(const char* str) {
  const char* ptr = str;
  for( ; *ptr != '\0' ; ptr++) {
    setValue(*ptr);
  }
}

template<typename T>
inline void basic_binary_write(BinaryStream& s, const T& val) {
  const char* ptr = reinterpret_cast<const char*>(&val);
  for(u8 i = 0 ; i < sizeof(T) ; i++, ptr++) {
    s.setValue(*ptr);
  }
}

void BinaryStream::binaryWrite(const s8& val) {
  basic_binary_write(*this, val);
}

void BinaryStream::binaryWrite(const s16& val) {
  basic_binary_write(*this, val);
}

void BinaryStream::binaryWrite(const s32& val) {
  basic_binary_write(*this, val);
}

void BinaryStream::binaryWrite(const s64& val) {
  basic_binary_write(*this, val);
}

void BinaryStream::binaryWrite(const u8& val) {
  basic_binary_write(*this, val);
}

void BinaryStream::binaryWrite(const u16& val) {
  basic_binary_write(*this, val);
}

void BinaryStream::binaryWrite(const u32& val) {
  basic_binary_write(*this, val);
}

void BinaryStream::binaryWrite(const u64& val) {
  basic_binary_write(*this, val);
}
