#include <hardware/uart.hpp>

#include <base/types.hpp>

#include "../config/atmega32.hpp"

// DATA

class UartPrivateData {
  
};

template<int ID, typename UartImpl>
inline Uart<ID, UartImpl>::Uart(void) {
  
}

template<int ID, typename UartImpl>
inline void Uart<ID, UartImpl>::init(void) {

}

template<int ID, typename UartImpl>
inline void Uart<ID, UartImpl>::quit(void) {

}

template<int ID, typename UartImpl> template<int NBITS>
inline void Uart<ID, UartImpl>::setNBits(void) {

}

template<int ID, typename UartImpl> template<int BAUDRATE>
inline void Uart<ID, UartImpl>::setBaudrate(void) {
  StaticListLooper<
    typename AVR::Uart<ID>::Baudrate,
    StaticList<static_cast<unsigned char>(BAUDRATE/256), static_cast<unsigned char>(BAUDRATE)>
      >::exec([](int reg, int val){
	  REG(reg) = val;
	});
}

template<int ID, typename UartImpl> template<typename T, bool WAIT>
inline T Uart<ID, UartImpl>::recv(void) {

}

template<int ID, typename UartImpl> template<typename T, bool WAIT>
inline void Uart<ID, UartImpl>::send(T val) {

}

template<int ID, typename UartImpl> template<int SIZE, typename T, bool WAIT>
inline void Uart<ID, UartImpl>::recv(Array<SIZE, T>& buff) {

}

template<int ID, typename UartImpl> template<int SIZE, typename T, bool WAIT>
inline void Uart<ID, UartImpl>::send(Array<SIZE, T>& buff) {

}

