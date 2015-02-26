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

#ifndef FPGA_UART_STREAM
#define FPGA_UART_STREAM

#include <stream/buffered_stream.hpp>
#include <device/device.hpp>
#include <base/integer.hpp>


///////////////////////////////////////////////////////////////////////////

#include <base/integer.hpp>

struct FpgaUartStreamPrivateData {
  inline FpgaUartStreamPrivateData(volatile u8& _tx, volatile u8& _tx_occup, volatile u8& _rx, volatile u8& _rx_ava)
    : tx(_tx), tx_occup(_tx_occup),
      rx(_rx), rx_ava(_rx_ava) {
  }
  volatile u8& tx;
  volatile u8& tx_occup;
  volatile u8& rx;
  volatile u8& rx_ava;
};

///////////////////////////////////////////////////////////////////////////


//! \class FpgaUartStream fpga_uart_stream.hpp <device/stream/fpga_uart__stream.hpp>
//! \brief Uart stream through EIRBOT's FPGA.
class FpgaUartStream : public Device, public BufferedStream {
private:
  FpgaUartStreamPrivateData _data;
  
public:
  //! \brief FpgaUartStream constructor.
  //! \param name : the device's name.
  //! \param tx : a reference to the variable to write in to write in the stream.
  //! \param tx_occup : a reference to the variable telling how many characters are waiting in the FPGA's output buffer.
  //! \param rx : a reference to the variable to read to read from the stream.
  //! \param rx_ava : a reference to the variable telling how many characters are waiting in the FPGA's input buffer.
  inline FpgaUartStream(const char* name, u8& tx, u8& tx_occup, u8& rx, u8& rx_ava);
  
  //! \brief FpgaUartStream constructor.
  //! \param name : the device's name.
  //! \param tx : a reference to the variable to write in to write in the stream.
  //! \param tx_occup : a reference to the variable telling how many characters are waiting in the FPGA's output buffer.
  //! \param rx : a reference to the variable to read to read from the stream.
  //! \param rx_ava : a reference to the variable telling how many characters are waiting in the FPGA's input buffer.
  inline FpgaUartStream(const char* name, volatile u8& tx, volatile u8& tx_occup, volatile u8& rx, volatile u8& rx_ava);
  
  //! \brief Read a char from the stream's input buffer.
  //! \return The read character.
  //! \warning Blocking operation if the stream's input buffer is empty.
  inline char getValue(void);
  
  //! \brief Write a char in the stream's input buffer.
  //! \param c : the character to write.
  //! \warning Blocking operation if the stream's output buffer is full
  inline void setValue(char c);
  
  //! \brief Return the buffers' size.
  //! \return The buffers' size.
  inline u16 bufferSize(void) const;
  
  //! \brief Return the amout of characters waiting to be sent into the output buffer.
  //! \return The amout of characters within the output buffer.
  inline u16 outputFreeSpace(void) const;
  
  //! \brief Return the amount of characters currently pending into the input buffer.
  //! \return The amout of characters within the input buffer.
  inline u16 inputUsedSpace(void) const;
};


///////////////////////////////////////////////////////////////////////////


inline FpgaUartStream::FpgaUartStream(const char* name, u8& tx, u8& tx_occup, u8& rx, u8& rx_ava)
  : Device(name),
    _data((volatile u8&) tx, (volatile u8&) tx_occup, (volatile u8&) rx, (volatile u8&) rx_ava) {
}

inline FpgaUartStream::FpgaUartStream(const char* name, volatile u8& tx, volatile u8& tx_occup, volatile u8& rx, volatile u8& rx_ava)
  : Device(name),
    _data(tx, tx_occup, rx, rx_ava) {
}

inline char FpgaUartStream::getValue(void) {
  if(_mini_buffer_used) {
    _mini_buffer_used = false;
    return _mini_buffer;
  }
  else {
    while(!_data.rx_ava) {
    }
    return _data.rx;
  }
}

inline void FpgaUartStream::setValue(char val) {
  while(!(255 - _data.tx_occup)) {
  }
  _data.tx = val;
}

inline u16 FpgaUartStream::bufferSize(void) const {
  return 64;
}

inline u16 FpgaUartStream::outputFreeSpace(void) const {
  return bufferSize() - _data.tx_occup;
}

inline u16 FpgaUartStream::inputUsedSpace(void) const {
  return _data.rx_ava;
}


#endif//FPGA_UART_STREAM
