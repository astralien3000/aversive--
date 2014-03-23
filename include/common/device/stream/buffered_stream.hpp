#ifndef BUFFERED_STREAM_HPP
#define BUFFERED_STREAM_HPP

#include <device/stream/stream.hpp>
#include <base/integer.hpp>

//! \brief Buffered stream interface
class BufferedStream : public Stream {
public:
  inline BufferedStream(void) {
  }
  
  //! \brief Read a char from the stream's input buffer
  //! \warning Blocking operation if the stream's input buffer is empty
  virtual char getValue(void) = 0;
  
  //! \brief Write a char in the stream's input buffer
  //! \warning Blocking operation if the stream's output buffer is full
  virtual void setValue(char) = 0;
  
  //! \brief Return the stream's buffers' size
  virtual u16 bufferSize(void) = 0;
  
  //! \brief Return the space currently free to use in the ouput buffer
  virtual u16 outputFreeSpace(void) = 0;
  
  //! \brief Return the space currently used in the input buffer
  virtual u16 inputUsedSpace(void) = 0;
};

#endif//BUFFERED_STREAM_HPP
