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

#include <stream/formatted_stream.hpp>

static void clearBlank(BinaryStream& s) {
  char c = s.nextValue();
  while(c == ' ' || c == '\0' || c == '\n' || c == '\r' || c == '\t') {
    s.getValue();
    c = s.nextValue();
  }
}

//! \fixme Last character is overwritten by \0 when the user's buffer is fulfilled.
void FormattedStream::formattedRead(char* str, u16 size) {
  clearBlank(*this);
  bool keep = true;
  char* beg = str;
  while(keep && (u16)(str-beg) < size) {
    char c = getValue();
    *str = c;
    if(_sep == WORD && (c == ' ' || c == '\t')) {
      keep = false;
    }
    else if(c == '\r' || c == '\n' || c == '\0') {
      *str = '\n';
      keep = false;
    }
    str++;	
  }
  *(str-1) = '\0';
}

////////////////////////////////////////
// Formatted Read

template<bool SIGNED = true, typename T>
void basic_formatted_integer_read(FormattedStream& s, T& val) {
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

void FormattedStream::formattedRead(s8& val) {
  basic_formatted_integer_read(*this, val);
}

void FormattedStream::formattedRead(s16& val) {
  basic_formatted_integer_read(*this, val);
}

void FormattedStream::formattedRead(s32& val) {
  basic_formatted_integer_read(*this, val);
}

void FormattedStream::formattedRead(s64& val) {
  basic_formatted_integer_read(*this, val);
}

void FormattedStream::formattedRead(u8& val) {
  basic_formatted_integer_read<false>(*this, val);
}

void FormattedStream::formattedRead(u16& val) {
  basic_formatted_integer_read<false>(*this, val);
}

void FormattedStream::formattedRead(u32& val) {
  basic_formatted_integer_read<false>(*this, val);
}

void FormattedStream::formattedRead(u64& val) {
  basic_formatted_integer_read<false>(*this, val);
}
