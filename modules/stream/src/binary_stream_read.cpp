/*
    Aversive++                                                           
    Copyright (C) 2014 Eirbot                                            
                                                                         
    This program is free software: you can redistribute it and/or modify 
    it under the terms of the GNU General Public License as published by 
    the Free Software Foundation, either version 3 of the License, or    
    (at your option) any later version.                                  
                                                                         
    This program is distributed in the hope that it will be useful,      
    but WITHOUT ANY WARRANTY; without even the implied warranty of       
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the        
    GNU General Public License for more details.                         
                                                                         
    You should have received a copy of the GNU General Public License    
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include <stream/binary_stream.hpp>

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
