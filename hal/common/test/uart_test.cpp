#include "uart.hpp"

using UART = HAL::Example::UART<0>;

void uart_test(void) {
  UART::isModuleEnabled();
  UART::enableModule();
  UART::disableModule();

  UART::isModuleSleepEnabled();
  UART::enableModuleSleep();
  UART::disableModuleSleep();

  {
    auto settings = UART::Settings();
    UART::setSettings(settings);
    UART::setSettings<UART::Settings>();
    UART::getSettings(settings);
  }
  
  UART::setBaudrate(0);
  UART::setBaudrate<0>();
  UART::getBaudrate();

  UART::setParity(UART::Parity::UNDEFINED);
  UART::setParity<UART::Parity::UNDEFINED>();
  UART::getParity();

  UART::setStopBit(UART::StopBit::UNDEFINED);
  UART::setStopBit<UART::StopBit::UNDEFINED>();
  UART::getStopBit();

  UART::setWordSize(0);
  UART::setWordSize<0>();
  UART::getWordSize();

  UART::enableTx();
  UART::disableTx();
  UART::isTxEnabled();

  UART::enableRx();
  UART::disableRx();
  UART::isRxEnabled();

  UART::setTxFifoSize(0);
  UART::setTxFifoSize<0>();
  UART::getTxFifoSize();

  UART::setRxFifoSize(0);
  UART::setRxFifoSize<0>();
  UART::getRxFifoSize();

  UART::setFlowControl(UART::FlowControl::UNDEFINED);
  UART::setFlowControl<UART::FlowControl::UNDEFINED>();
  UART::getFlowControl();

  UART::setEndianess(UART::Endianess::UNDEFINED);
  UART::setEndianess<UART::Endianess::UNDEFINED>();
  UART::getEndianess();

  UART::setTxCompleteHandler(0);
  UART::setRxCompleteHandler(0);

  UART::putChar(0);
  UART::getChar();

  UART::write(0, 0);
  UART::read(0, 0);

  UART::getTxFifoAvailableSpace();
  UART::getRxFifoAvailableWords();
}
