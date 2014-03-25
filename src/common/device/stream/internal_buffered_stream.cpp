#include <device/stream/internal_buffered_stream.hpp>

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
