#ifndef BUFFERED_STREAM_HPP
#define BUFFERED_STREAM_HPP

#include <device/stream/stream.hpp>
#include <base/integer.hpp>

//! \class BufferedStream buffered_stream.hpp <device/stream/buffered_stream.hpp>
//! \brief Buffered stream interface.
class BufferedStream : public Stream {
public:
  //! \brief Default constructor.
  inline BufferedStream(void)
    : Stream() {
  }
  
  //! \brief Copy constructor.
  //! \param s : the buffered stream to copy.
  inline BufferedStream(const BufferedStream& s)
    : Stream(s) {
  }
  
  //! \brief Read a char from the stream's input buffer.
  //! \return The read character.
  //! \warning Blocking operation if the stream's input buffer is empty.
  virtual char getValue(void) = 0;
  
  //! \brief Write a char in the stream's input buffer.
  //! \param c : the character to write.
  //! \warning Blocking operation if the stream's output buffer is full
  virtual void setValue(char c) = 0;
  
  //! \brief Return the buffers' size.
  //! \return The buffers' size.
  virtual u16 bufferSize(void) const = 0;
  
  //! \brief Return the amout of characters waiting to be sent into the output buffer.
  //! \return The amout of characters within the output buffer.
  virtual u16 outputFreeSpace(void) const = 0;
  
  //! \brief Return the amount of characters currently pending into the input buffer.
  //! \return The amout of characters within the input buffer.
  virtual u16 inputUsedSpace(void) const = 0;
};

#endif//BUFFERED_STREAM_HPP
