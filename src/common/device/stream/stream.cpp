#include <device/stream/stream.hpp>

const u16 MAX_BUFF = 32;

////////////////////////////////////////
// Constructor

Stream::Stream(const char* name) : Device(name) {}

////////////////////////////////////////
// Binary Write

void Stream::binaryWrite(const char* str, u16 size) {  
  const char* ptr = str;
  for( ; *ptr != '\0' && (ptr - str) < size  ; ptr++) {
    setValue(*ptr);
  }
}

template<typename T>
inline void basic_binary_write(Stream& s, const T& val) {
  for(u16 i = 0 ; i < sizeof(val) ; i++) {
    s.setValue((val >> (i * 8)) % 256);
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

  char* ptr = str + MAX_BUFF;
  bool neg = false;

  *(--ptr) = '\0';

  if(SIGNED && val < 0) {
    val = -val;
    neg = true;
  }

  while(0 < val && str < ptr) {
    *(--ptr) = '0' + (val % 10);
    val /= 10;
  }

  if(SIGNED && neg) {
    *(--ptr) = '-';
  }
  
  if(*ptr == '\0') {
    *(--ptr) = '0';
  }
  
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

void Stream::binaryRead(char* str, u16 size) {
  bool keep = true;
  char* beg = str;
  while(keep && (str-beg) < size) {
    char c = getValue();
    *str = c;
    if(_mode == FORMATTED) {
      if(_sep == WORD && c == ' ') {
	keep = false;
      }
      else if(c == '\r' || c == '\n' || c == '\0') {
	*str = '\n';
	keep = false;
      }
      setValue(*str);
      //*this << *str;
    }
    str++;	
  }
  *(str-1) = '\0';
}

template<typename T>
inline void basic_binary_read(Stream& s, T& val) {
  for(u16 i = 0 ; i < sizeof(val) ; i++) {
    val += s.getValue() << (i * 8) % 256;
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
  val = 0;

  char str[32] = {0};
  s >> str;

  u16 beg = 0;
  if(SIGNED && str[0] == '-') {
    beg = 1;
  }
    
  for(u16 i = beg ; str[i] ; i++) {
    if('0' <= str[i] && str[i] <= '9') {
      val *= 10;
      val += (T)(str[i] - '0');
    }
    else {
      str[i+1] = '\0';
    }
  }

  if(SIGNED && beg == 1) {
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
