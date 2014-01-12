#ifndef UART_STREAM_HPP
#define UART_STREAM_HPP

#include <base/singleton.hpp>
#include <container/buffer.hpp>
#include <stdint.h>

//! \brief Uart stream which uses "thread-safe" Buffer implementation
//! \attention SIZE must be a power of 2
//! \param CHANNEL which Uart connection the stream must be bound to
//! \param SIZE the number of characters input and output buffers can both handle at any given time
template<int CHANNEL, buffer_t SIZE = DEFAULT_BUFFER_SIZE>
class UartStream : public Singleton<UartStream<CHANNEL, SIZE>> {
  friend class Singleton<UartStream<CHANNEL, SIZE>>;
public:
  //! \brief Mode represents the different modes the stream can be in
  enum Mode { BINARY, FORMATTED };
  
protected:
  Buffer<SIZE, uint8_t> _out_buff;
  Buffer<SIZE, uint8_t> _in_buff;
  Mode _m;
  
  UartStream(void);
  
  bool binaryWrite(uint8_t data);
  bool binaryRead(uint8_t& data);
  
  bool complexBinaryWrite(const char* str);
  bool complexBinaryRead(char* str);
  
  template<typename T>
  bool complexBinaryWrite(const T& val);
  template<typename T>
  bool complexBinaryRead(T& val);
  
  bool formattedWrite(const char& val);
  bool formattedWrite(const unsigned char& val);
  bool formattedWrite(const short& val);
  bool formattedWrite(const unsigned short& val);
  bool formattedWrite(const long int& val);
  bool formattedWrite(const unsigned long int& val);
  bool formattedWrite(const long long int& val);
  bool formattedWrite(const unsigned long long int& val);
  bool formattedWrite(const float& val);
  bool formattedWrite(const double& val);
  
public:  
  ~UartStream(void);
  
  //! \brief Give the current mode which the stream is in
  Mode mode() const;
  
  //! \brief Change the mode the stream is currently in
  void setMode(Mode m);
  
  UartStream<CHANNEL, SIZE>& operator<<(const char* str);
  
  template<typename T>
  UartStream<CHANNEL, SIZE>& operator<<(const T& val);

  UartStream<CHANNEL, SIZE>& operator>>(char* str);
  
  template<typename T>
  UartStream<CHANNEL, SIZE>& operator>>(T& val);
};

#endif//UART_STREAM_HPP
