#include <hal/gpio_interface.hpp>
#include <hal/timer_interface.hpp>
#include <hal/uart_interface.hpp>
#include <util/dummy.hpp>

#include <iostream>
using namespace std;

struct TEST : HAL::Private::GPIO::DriverInterface {
  struct Mode : HAL::Private::GPIO::Mode {
    static constexpr Type UNDEFINED = Type::UNDEFINED;
    static constexpr Type INPUT = Type::INPUT;
    static constexpr Type OUTPUT = Type::OUTPUT;
    static constexpr Type ALTERNATE_FUNCTION = Type::ALTERNATE_FUNCTION;
  };
  
  constexpr inline static bool isModuleEnabled(void) {
    return true;
  }

  static void setValue(bool, u32) {
    
  }

  static void setMode(Mode::Type, u32) {

  }

};

struct TEST_TIMER : HAL::Private::TIMER::DriverInterface {
  struct Base : HAL::Private::TIMER::Base {
    struct CounterMode : HAL::Private::TIMER::Base::CounterMode {
      static constexpr Type UNDEFINED = Type::UNDEFINED;
    };
  };
};

struct Test {
  inline void setValue(bool val) {
    TEST::setValue(val, (u32)0b011110);
  }
};

template<bool COND>
struct static_if {
  template<typename Func>
  static_if(Func f) {}
};

template<>
struct static_if<true> {
  template<typename Func>
  static_if(Func f) { f(); }
};

template<DummyType DUMMY = DUMMY_VALUE>
void test(void) {
  static_if<!TEST::isModuleEnabled()>([] {
      TEST::enableModule();
    });
  
}

int main(int, char**) {
  Test test;
  test.setValue(true);
  TEST::setMode(TEST::Mode::ALTERNATE_FUNCTION, 0);

  cout << "OK !" << endl;
  return 0;
}
