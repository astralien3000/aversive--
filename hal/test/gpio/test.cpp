#include <hal/gpio_interface.hpp>
#include <hal/port_interface.hpp>
#include <hal/pingroup_interface.hpp>
#include <hal/pin_interface.hpp>

volatile ::HAL::GPIO_DriverInterface<u8>::Mode::Type test;
volatile ::HAL::GPIO_DriverInterface<u8>::Mode::Type test2;

#include <hal/macros_define.hpp>

template<typename T>
struct isCompil {
  static constexpr auto VALUE = COMPIL(false);
};

template<typename T, T VAL>
struct isCompil<Compil<T, VAL>> {
  static constexpr auto VALUE = COMPIL(true);
};

template<typename F1, typename F2>
void CompilIf(Compil<bool, true>, F1 true_func, F2) {
  true_func();
}

template<typename F1, typename F2>
void CompilIf(Compil<bool, false>, F1, F2 false_func) {
  false_func();
}

template<typename F>
void CompilIf(Compil<bool, true>, F func) {
  func();
}

template<typename F>
void CompilIf(Compil<bool, false>, F) {
}

struct GPIO : ::HAL::GPIO_DriverInterface<u8> {
private:
  using Parent = ::HAL::GPIO_DriverInterface<u8>;

public:
  struct Mode : Parent::Mode {
    AVERSIVE_AVAILABLE_ELEMENT(UNDEFINED);
    AVERSIVE_AVAILABLE_ELEMENT(INPUT);
    AVERSIVE_AVAILABLE_ELEMENT(OUTPUT);
  };
  
  struct OutputMode : Parent::OutputMode {
    AVERSIVE_AVAILABLE_ELEMENT(UNDEFINED);
  };
  
  struct Pull : Parent::Pull {
    AVERSIVE_AVAILABLE_ELEMENT(UNDEFINED);
  };
};

struct PORT : ::HAL::PORT_DriverInterface<u8> {
  template<typename GPIOType, typename Settings>
  static inline constexpr void init(GPIOType gpio, const Settings& settings) {
    CompilIf(isCompil<decltype(gpio)>::VALUE, [&](){
	test = settings.mode;
      },
      //else
      [&]() {
	test2 = settings.mode;
      });
  }
};

#include <hal/macros_undef.hpp>

int main(int, char**) {
  GPIO::Settings settings = {
    .mode = GPIO::Mode::OUTPUT,
    .output_mode = GPIO::OutputMode::UNDEFINED,
    .pull = GPIO::Pull::UNDEFINED
  };

  PORT::init(0_c, settings);
  PORT::init(1, settings);
  return 0;
}
