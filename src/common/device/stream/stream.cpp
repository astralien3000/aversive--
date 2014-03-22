#include <device/stream/stream.hpp>

const u16 MAX_BUFF = 32;

////////////////////////////////////////
// Binary Write

void Stream::binaryWrite(const char* str) {
  const char* ptr = str;
  for( ; *ptr != '\0' ; ptr++) {
    setValue(*ptr);
  }
}

template<typename T>
inline void basic_binary_write(Stream& s, const T& val) {
  const char* ptr = reinterpret_cast<const char*>(&val);
  for(s16 i = (sizeof(T) - 1) ; i >= 0 ; i--) {
    s.setValue(*(ptr + i));
  }
}

void Stream::binaryWrite(const s8& val) {
  basic_binary_write(*this, val);
}

void Stream::binaryWrite(const s16& val) {
  basic_binary_write(*this, val);
}

void Stream::binaryWrite(const s32& val) {
  basic_binary_write(*this, val);
}

void Stream::binaryWrite(const s64& val) {
  basic_binary_write(*this, val);
}

void Stream::binaryWrite(const u8& val) {
  basic_binary_write(*this, val);
}

void Stream::binaryWrite(const u16& val) {
  basic_binary_write(*this, val);
}

void Stream::binaryWrite(const u32& val) {
  basic_binary_write(*this, val);
}

void Stream::binaryWrite(const u64& val) {
  basic_binary_write(*this, val);
}

////////////////////////////////////////
// Formatted Write

template<bool SIGNED = true, typename T>
inline void basic_formatted_integer_write(Stream& s, T val) {
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

void Stream::formattedWrite(const s8& val) {
  basic_formatted_integer_write(*this, val);
}

void Stream::formattedWrite(const s16& val) {
  basic_formatted_integer_write(*this, val);
}

void Stream::formattedWrite(const s32& val) {
  basic_formatted_integer_write(*this, val);
}

void Stream::formattedWrite(const s64& val) {
  basic_formatted_integer_write(*this, val);
}

void Stream::formattedWrite(const u8& val) {
  basic_formatted_integer_write<false>(*this, val);
}

void Stream::formattedWrite(const u16& val) {
  basic_formatted_integer_write<false>(*this, val);
}

void Stream::formattedWrite(const u32& val) {
  basic_formatted_integer_write<false>(*this, val);
}

void Stream::formattedWrite(const u64& val) {
  basic_formatted_integer_write<false>(*this, val);
}

////////////////////////////////////////
// Binary Read

void clearBlank(Stream& s) {
  char c = s.nextValue();
  while(c == ' ' || c == '\0' || c == '\n' || c == '\r' || c == '\t') {
    s.getValue();
    c = s.nextValue();
  }
}

void Stream::binaryRead(char* str, u16 size) {
  clearBlank(*this);
  bool keep = true;
  char* beg = str;
  while(keep && (u16)(str-beg) < size) {
    char c = getValue();
    *str = c;
    if(_mode == FORMATTED) {
      if(_sep == WORD && (c == ' ' || c == '\t')) {
	keep = false;
      }
      else if(c == '\r' || c == '\n' || c == '\0') {
	*str = '\n';
	keep = false;
      }
    }
    str++;	
  }
  *(str-1) = '\0';
}

template<typename T>
inline void basic_binary_read(Stream& s, T& val) {
  char* ptr = reinterpret_cast<char*>(&val);
  for(s16 i = (sizeof(T) - 1) ; i >= 0 ; i--) {
    *(ptr + i) = s.getValue();
  }
}

void Stream::binaryRead(s8& val) {
  basic_binary_read(*this, val);
}

void Stream::binaryRead(s16& val) {
  basic_binary_read(*this, val);
}

void Stream::binaryRead(s32& val) {
  basic_binary_read(*this, val);
}

void Stream::binaryRead(s64& val) {
  basic_binary_read(*this, val);
}

void Stream::binaryRead(u8& val) {
  basic_binary_read(*this, val);
}

void Stream::binaryRead(u16& val) {
  basic_binary_read(*this, val);
}

void Stream::binaryRead(u32& val) {
  basic_binary_read(*this, val);
}

void Stream::binaryRead(u64& val) {
  basic_binary_read(*this, val);
}

////////////////////////////////////////
// Formatted Write

template<bool SIGNED = true, typename T>
void basic_formatted_integer_read(Stream& s, T& val) {
  clearBlank(s);
  val = 0;

  char c = 0;
  bool neg = false;
  c = s.nextValue();

  if(SIGNED && c == '-') {
    neg = true;
    s.getValue();
    c = s.nextValue();
  }

  while(c >= '0' && c <= '9') {
    s.getValue();
    val = val * 10 + ((T) (c - '0'));
    c = s.nextValue();
  }

  if(neg) {
    val = -val;
  }
}

void Stream::formattedRead(s8& val) {
  basic_formatted_integer_read(*this, val);
}

void Stream::formattedRead(s16& val) {
  basic_formatted_integer_read(*this, val);
}

void Stream::formattedRead(s32& val) {
  basic_formatted_integer_read(*this, val);
}

void Stream::formattedRead(s64& val) {
  basic_formatted_integer_read(*this, val);
}

void Stream::formattedRead(u8& val) {
  basic_formatted_integer_read<false>(*this, val);
}

void Stream::formattedRead(u16& val) {
  basic_formatted_integer_read<false>(*this, val);
}

void Stream::formattedRead(u32& val) {
  basic_formatted_integer_read<false>(*this, val);
}

void Stream::formattedRead(u64& val) {
  basic_formatted_integer_read<false>(*this, val);
}
