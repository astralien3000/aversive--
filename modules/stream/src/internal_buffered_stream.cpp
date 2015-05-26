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

#include <stream/internal_buffered_stream.hpp>

char InternalBufferedStream::getValue(void) {
  if(_mini_buffer_used) {
    _mini_buffer_used = false;
    return _mini_buffer;
  }
  else {
    while(_input.isEmpty()) {
    }
    char val = _input.head();
    _input.dequeue();
    return val;
  }
}

void InternalBufferedStream::setValue(char val) {
  while(_output.isFull()) {
  }
  _output.enqueue(val);
}

u16 InternalBufferedStream::bufferSize(void) const {
  return _output.SIZE;
}

u16 InternalBufferedStream::outputFreeSpace(void) const {
  return _output.freeSpace();
}

u16 InternalBufferedStream::inputUsedSpace(void) const {
  return _input.usedSpace();
}
