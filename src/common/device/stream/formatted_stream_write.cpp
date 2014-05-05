#include <device/stream/formatted_stream.hpp>

const u16 MAX_BUFF = 32;

////////////////////////////////////////
// Formatted Write

template<bool SIGNED = true, typename T>
inline void basic_formatted_integer_write(FormattedStream& s, T val) {
  char str[MAX_BUFF] = {0};
  bool _neg = false;

  // Initialize string
  char* ptr = str + MAX_BUFF;
  *(--ptr) = '\0';

  // Parsing sign and digits
  if(SIGNED && val < 0) {
    val = -val;
    _neg = true;
  }
  
  while(0 < val && str < ptr) {
    *(--ptr) = '0' + (val % 10);
    val /= 10;
  }

  if(SIGNED && _neg) {
    *(--ptr) = '-';
  }
  
  // If no digits found
  if(*ptr == '\0') {
    *(--ptr) = '0';
  }
  
  // Send
  s << (const char*)ptr;
}

void FormattedStream::formattedWrite(const s8& val) {
  basic_formatted_integer_write(*this, val);
}

void FormattedStream::formattedWrite(const s16& val) {
  basic_formatted_integer_write(*this, val);
}

void FormattedStream::formattedWrite(const s32& val) {
  basic_formatted_integer_write(*this, val);
}

void FormattedStream::formattedWrite(const s64& val) {
  basic_formatted_integer_write(*this, val);
}

void FormattedStream::formattedWrite(const u8& val) {
  basic_formatted_integer_write<false>(*this, val);
}

void FormattedStream::formattedWrite(const u16& val) {
  basic_formatted_integer_write<false>(*this, val);
}

void FormattedStream::formattedWrite(const u32& val) {
  basic_formatted_integer_write<false>(*this, val);
}

void FormattedStream::formattedWrite(const u64& val) {
  basic_formatted_integer_write<false>(*this, val);
}
