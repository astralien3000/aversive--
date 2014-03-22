#ifndef INTERNAL_BUFFERED_STREAM_HPP
#define INTERNAL_BUFFERED_STREAM_HPP

#include <device/stream/buffered_stream.hpp>
#include <container/buffer.hpp>

//! \brief Internal buffered stream interface
class InternalBufferedStream : public BufferedStream {
protected:
  Buffer<64, char> _output;
  Buffer<64, char> _input;
public:
  InternalBufferedStream(const char*);
  
  inline void flushOutput(void) {
    while(!_output.isEmpty()) {
    }
  }
  
  inline void flushInput(void) {
    _mini_buffer_used = false;
    _input.flush();
  }
  
  virtual char getValue(void);
  virtual void setValue(char);
  
  virtual u16 bufferSize(void);
  virtual u16 outputFreeSpace(void);
  virtual u16 inputUsedSpace(void);
};

#endif//INTERNAL_BUFFERED_STREAM_HPP
