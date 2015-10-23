#include "../doc/gpio.hpp"
#include "../doc/timer.hpp"
#include "../doc/uart.hpp"

using GPIO = HAL::Example::GPIO<0>;

int main(int, char**) {
  GPIO::setPinMode(0, GPIO::Mode::ALTERNATE_FUNCTION);

  return 0;
}
