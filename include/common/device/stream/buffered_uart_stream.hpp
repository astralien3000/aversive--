#ifndef BUFFERED_UART_STREAM_HPP
#define BUFFERED_UART_STREAM_HPP

#include <device/stream/internal_buffered_stream.hpp>
#include <device/device.hpp>
#include <base/singleton.hpp>

//! \class BufferedUartStream buffered_uart_stream.hpp <device/stream/buffered_uart_stream.hpp>
//! \brief Buffered Uart Steam device.
//! \param _CHANNEL : the Uart connection the stream must be bound to.
template<int CHANNEL>
class BufferedUartStream : public Device, public InternalBufferedStream, public Singleton<BufferedUartStream<CHANNEL> > {
  friend Singleton<BufferedUartStream<CHANNEL> >;
  
  //! \brief BufferedUartStream constructor.
  //! \param name : the device's name.
  inline BufferedUartStream(const char* name)
    : InternalBufferedStream(), Device(name) {
  }
  
  //! \brief Default constructor.
  BufferedUartStream(void);
  
  //! \brief Copy constructor.
  //! \param s : the buffered uart stream to copy.
  inline BufferedUartStream(const BufferedUartStream& s)
    : InternalBufferedStream(s), Device(s) {
  }
  
  //! \brief Deprecated method.
  //! \deprecated To be removed soon and its code will be moved to the constructor.
  void init(void);
  
  //! \brief Interruption method called when the uart channel is ready to send a new data.
  static void send(void);
  
  //! \brief Interruption method called when the uart channel received something.
  static void receive(void);
  
public:
  //! \brief Read a char from the stream's input buffer.
  //! \return The read character.
  //! \warning Blocking operation if the stream's input buffer is empty.
  virtual char getValue(void);
  
  //! \brief Write a char in the stream's input buffer.
  //! \param c : the character to write.
  //! \warning Blocking operation if the stream's output buffer is full
  virtual void setValue(char c);
};

#endif//BUFFERED_UART_STREAM_HPP
