#ifndef UART_STREAM_HPP
#define UART_STREAM_HPP

#include <base/singleton.hpp>
#include <container/buffer.hpp>
#include <stdint.h>

static const buffer_t STREAM_BUFFER_SIZE = 64;

//! \brief Uart stream which uses "thread-safe" Buffer implementation
//! \attention SIZE must be a power of 2
//! \param CHANNEL which Uart connection the stream must be bound to
//! \param SIZE the number of characters input and output buffers can both handle at any given time
template<int CHANNEL>
class UartStream : public Singleton<UartStream<CHANNEL>> {
  friend class Singleton<UartStream<CHANNEL>>;
public:
  //! \brief Mode represents the different modes the stream can be in (default is FORMATTED)
  enum Mode { BINARY, FORMATTED };
  
  //! \brief StrMode represents the different modes the stream can read string (default is WORD)
  enum StrMode { WORD, LINE };
  
protected:
  Buffer<STREAM_BUFFER_SIZE, uint8_t> _out_buff;
  Buffer<STREAM_BUFFER_SIZE, uint8_t> _in_buff;
  Mode _m = FORMATTED;
  StrMode _s = WORD;
  bool _sending = false;
  
  UartStream(void);
  
  bool binaryWrite(uint8_t data);
  bool binaryRead(uint8_t& data);
  
  bool complexBinaryWrite(const char* str);
  
  template<typename T>
  bool complexBinaryWrite(const T& val);
  
  bool complexBinaryRead(char* str, uint_fast16_t limit = 0);
  
  template<typename T>
  bool complexBinaryRead(T& val);
  
  bool formattedWrite(const char& val);
  bool formattedWrite(const unsigned char& val);
  bool formattedWrite(const short& val);
  bool formattedWrite(const unsigned short& val);
  bool formattedWrite(const long int& val);
  bool formattedWrite(const unsigned long int& val);
  bool formattedWrite(const float& val);
  bool formattedWrite(const double& val);

  bool formattedRead(char& val);
  bool formattedRead(unsigned char& val);
  bool formattedRead(short& val);
  bool formattedRead(unsigned short& val);
  bool formattedRead(long int& val);
  bool formattedRead(unsigned long int& val);
  bool formattedRead(float& val);
  bool formattedRead(double& val);
  
  static void read(void);
  static void write(void);
  static void empty(void);

public:  
  //! \brief Give the current mode which the stream is in
  Mode mode() const;
  
  //! \brief Change the mode the stream is currently in
  void setMode(Mode m);

  //! \brief Give the current string mode which the stream is in  
  StrMode strMode() const;
  
  //! \brief Change the string mode the stream is currently in
  void setStrMode(StrMode s);
  
  //! \brief Write a string into the stream
  UartStream<CHANNEL>& operator<<(const char* str);
  
  //! \brief Write anything into the stream
  template<typename T>
  UartStream<CHANNEL>& operator<<(const T& val);
  
  //! \brief Read a string from the stream
  //! \attention Its behavior depends on the string mode the stream is currently in
  UartStream<CHANNEL>& operator>>(char* str);
  
  //! \brief Read anything from the stream
  //! \attention Its behavior depends on the mode (binary or formatted) the stream is currently in
  template<typename T>
  UartStream<CHANNEL>& operator>>(T& val);
};

#endif//UART_STREAM_HPP
