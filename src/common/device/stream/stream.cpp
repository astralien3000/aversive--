#include <device/stream/stream.hpp>

Stream::Stream(const char* name) : Device(name) {}

Stream& Stream::operator<<(const char* str) {
  for( ; *str != '\0' ; str++) {
    setValue(*str);
    //*this << *str;
  }
  return *this;
}


Stream& Stream::operator<<(char* str) {
  return *this << (const char*)str;
}

template<typename T>
Stream& Stream::operator<<(const T& val) {
  char str[32] = {0};

  if(_mode == BINARY) {
    for(u16 i = 0 ; i < sizeof(val) ; i++) {
      //str[i] = (char)val >> ((sizeof(val) - 1 - i) * 8);
      setValue(((u64)val >> (i * 8)) % 256);
    }
  }
  else if(_mode == FORMATTED) {
    T tmp = val;
    
    u16 beg = 0;
    if(val == 0) {
      str[beg++] = '0';
    }
    else if(val < 0) {
      str[beg++] = '-';
      tmp = -val;
    }
    
    u16 i = beg;
    while(0 < tmp && i < 32) {
      str[i] = '0' + tmp % 10;
      tmp /= 10;
      i++;
    }
    
    i--;
    while(beg < i) {
      char aux = str[i];
      str[i] = str[beg];
      str[beg] = aux;
      i--;
      beg++;
    }
    *this << (const char*)str;
  }

  return *this;
}

Stream& Stream::operator>>(char* str) {
  bool keep = true;
  char* beg = str;
  while(keep && (str-beg) < 32) {
    char c = getValue();
    //*this >> c;
    *str = c;
    if(_mode == FORMATTED) {
      if(_sep == WORD && c == ' ') {
	keep = false;
      }
      else if(c == '\r' || c == '\n') {
	*str = '\n';
	keep = false;
      }
      setValue(*str);
      //*this << *str;
    }
    str++;	
  }
  *(str-1) = '\0';
  return *this;
}

template<typename T>
Stream& Stream::operator>>(T& val) {
  val = 0;
  
  if(_mode == BINARY) {
    for(u16 i = 0 ; i < sizeof(val) ; i++) {
      //val += str[i] << (i * 8);
      val += getValue() << (i * 8) % 256;
    }
  }
  else if(_mode == FORMATTED) {
    char str[32] = {0};
    *this >> str;

    u16 beg = 0;
    if(str[0] == '-') {
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

    if(beg == 1) {
      val = -val;
    }
  }
  return *this;
}

// Input
/*
template Stream& Stream::operator>> <u8>(u32&);
template Stream& Stream::operator>> <u16>(u16&);
template Stream& Stream::operator>> <u32>(u32&);
template Stream& Stream::operator>> <u64>(u64&);
*/

template Stream& Stream::operator>> <s8>(s8&);
template Stream& Stream::operator>> <s16>(s16&);
template Stream& Stream::operator>> <s32>(s32&);
template Stream& Stream::operator>> <s64>(s64&);

// Output
/*
template Stream& Stream::operator<< <u8>(const u8&);
template Stream& Stream::operator<< <u16>(const u16&);
template Stream& Stream::operator<< <u32>(const u32&);
template Stream& Stream::operator<< <u64>(const u64&);
*/

template Stream& Stream::operator<< <s8>(const s8&);
template Stream& Stream::operator<< <s16>(const s16&);
template Stream& Stream::operator<< <s32>(const s32&);
template Stream& Stream::operator<< <s64>(const s64&);
