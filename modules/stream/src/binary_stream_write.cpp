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
