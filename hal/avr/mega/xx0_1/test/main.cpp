#include "hdl/hdl.hpp"
#include "hal/hal.hpp"

using namespace HAL;

extern void delay(void);

struct LedSettings {
  static constexpr auto mode = GPIOx::Mode::OUTPUT;
  static constexpr auto output_mode = GPIOx::OutputMode::UNDEFINED;
  static constexpr auto alternate = GPIOx::Alternate::UNDEFINED;
  static constexpr auto speed = GPIOx::Speed::UNDEFINED;
  static constexpr auto pull = GPIOx::Pull::UNDEFINED;
};

struct UARTSettings {
  static constexpr UARTx::Baudrate::Type baudrate = 9600;
  static constexpr auto parity = UARTx::Parity::NONE;
  static constexpr auto stop_bit = UARTx::StopBit::ONE_BIT;
  static constexpr auto word_size = 8;
      
  static constexpr bool tx_enabled = true;
  static constexpr bool rx_enabled = true;

  static constexpr UARTx::FifoSize::Type tx_fifo_size = 1;
  static constexpr UARTx::FifoSize::Type rx_fifo_size = 1;

  static constexpr auto flow_control = UARTx::FlowControl::NONE;

  static constexpr auto endianess = UARTx::Endianess::LSB;
};


//*/
template<u8 ID>
inline u32 HAL::UART<ID>::getSystemClockFrequency(void) {
  return 16000000;
}
//*/

int main(int, char**) {
  UART_0::setSettings<UARTSettings>();
  GPIO_B::Pin<7>::setSettings<LedSettings>();

  UART_0::setRxCompleteHandler([]() {
      UART_0::putChar(UART_0::getChar());
      GPIO_B::Pin<7>::toggle();
    });

  HDL::sei();
  
  while(1);
  
  return 0;
}
