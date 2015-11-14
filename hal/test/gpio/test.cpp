#include <hal/gpio_interface.hpp>
#include <hal/port_interface.hpp>
#include <hal/pingroup_interface.hpp>
#include <hal/pin_interface.hpp>

volatile ::HAL::GPIO_DriverInterface<u8>::Mode::Type test;
volatile ::HAL::GPIO_DriverInterface<u8>::Mode::Type test2;

#include <hal/macros_define.hpp>

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
  template<typename GPIOType>
  static inline constexpr void init(GPIOType gpio, const Settings& settings) {
    (void)gpio;
    (void)settings;
    test = settings.mode;
  }

  template<int GPIO>
  static inline constexpr void init(Compil<int, GPIO> gpio, const Settings& settings) {
    (void)gpio;
    (void)settings;
    test2 = settings.mode;
  }
};

struct PIN : ::HAL::PIN_DriverInterface<u8> {
  template<typename GPIOType, typename PinType>
  static void init(GPIOType, PinType, const Settings&) {
  }
};

struct PINGROUP : ::HAL::PINGROUP_DriverInterface<u8> {
  template<typename GPIOType, typename MASKType>
  static void init(GPIOType, MASKType, const Settings&) {
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
  PORT::init(0, settings);
  PIN::init(1_c, 1_c, settings);
  PINGROUP::init(1_c, 0b00110011_c, settings);
  PINGROUP::init(1_c, 0b00110011_cu8, settings);
  PINGROUP::init(1_c, 0b00110011, settings);
  return 0;
}
