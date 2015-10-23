#include <hal/gpio_interface.hpp>
#include <hal/timer_interface.hpp>
#include <hal/uart_interface.hpp>
#include <util/dummy.hpp>

#include <iostream>
using namespace std;

struct TEST : HAL::Private::GPIO_DriverInterface {
  struct Mode : GPIO_DriverInterface::Mode {
    static constexpr Type ALTERNATE_FUNCTION = Type::ALTERNATE_FUNCTION;
  };
  
  constexpr inline static bool isModuleEnabled(void) {
    return true;
  }

  static void setPinMode(u8, Mode::Type) {

  }

};

int main(int, char**) {
  TEST::setPinMode(0, TEST::Mode::ALTERNATE_FUNCTION);

  cout << "OK !" << endl;
  return 0;
}
