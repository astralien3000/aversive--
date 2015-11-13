#include <hal/gpio_interface.hpp>
#include <hal/port_interface.hpp>
#include <hal/pingroup_interface.hpp>
#include <hal/pin_interface.hpp>

volatile ::HAL::GPIO_DriverInterface<u8>::Mode::Type test;
volatile ::HAL::GPIO_DriverInterface<u8>::Mode::Type test2;

#include <hal/macros_define.hpp>

struct GPIO : ::HAL::GPIO_DriverInterface<u8> {
private:
  using _Driver = ::HAL::GPIO_DriverInterface<u8>;

public:
  struct Mode : _Driver::Mode {
    _AVERSIVE_AVAILABLE_ELEMENT(UNDEFINED);
    _AVERSIVE_AVAILABLE_ELEMENT(INPUT);
    _AVERSIVE_AVAILABLE_ELEMENT(OUTPUT);
  };
  
  struct OutputMode : _Driver::OutputMode {
    _AVERSIVE_AVAILABLE_ELEMENT(UNDEFINED);
  };
  
  struct Pull : _Driver::Pull {
    _AVERSIVE_AVAILABLE_ELEMENT(UNDEFINED);
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
  
  PORT::init(COMPIL(0), settings);
  PORT::init(0, settings);
  PIN::init(COMPIL(1), COMPIL(1), settings);
  PINGROUP::init(COMPIL(1), COMPIL(0b00110011), settings);
  return 0;
}
