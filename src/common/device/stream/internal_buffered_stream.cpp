#include <device/stream/internal_buffered_stream.hpp>

InternalBufferedStream::InternalBufferedStream(const char* name) : BufferedStream(name) {
}

char InternalBufferedStream::getValue(void) {
  while(_input.isEmpty()) {
  }
  char val = _input.head();
  _input.dequeue();
  return val;
}

void InternalBufferedStream::setValue(char val) {
  while(_output.isFull()) {
  }
  _output.enqueue(val);
}

u16 InternalBufferedStream::bufferSize(void) {
  return _output.size;
}

u16 InternalBufferedStream::outputFreeSpace(void) {
  return _output.freeSpace();
}

u16 InternalBufferedStream::inputUsedSpace(void) {
  return _input.usedSpace();
}
