#include <base/integer.hpp>
#include <aversive.hpp>
#include <device/other/pin.hpp>
#include <base/array.hpp>

#include <device/pin/digital_pin.hpp>

int main(int argc, char* argv[]) {
  (void)argc;
  (void)argv;

  Aversive::init();

  DigitalPin<3 * 16 + 12> led1("");
  Pin<3 * 16 + 13> led2("");
  Pin<3 * 16 + 14> led3("");
  Pin<3 * 16 + 15> led4("");

  led1.setOutput();
  led2.setMode(PinMode::OUTPUT);
  led3.setMode(PinMode::OUTPUT);
  led4.setMode(PinMode::OUTPUT);

  Array<4, Output<bool>*> leds;

  leds[0] = &led1;
  leds[1] = &led2;
  leds[2] = &led3;
  leds[3] = &led4;

  Array<4, u32> offsets;
  Array<4, u32> speeds;

  const u32 PERIOD = 10000;
  const u32 MAX = 5000;

  offsets[0] = 0;
  offsets[1] = MAX / 2;
  offsets[2] = MAX;
  offsets[3] = MAX / 2;

  speeds[0] =  20;
  speeds[1] =  20;
  speeds[2] = -20;
  speeds[3] = -20;

  while(Aversive::sync()) {

    for(int i = 0 ; i < 4 ; i++) {
      leds[i]->setValue(true);
      offsets[i] += speeds[i];
      if(MAX < offsets[i]) {
        speeds[i] = -speeds[i];
        offsets[i] += speeds[i];
      }
    }

    for(volatile u32 t = 0 ; t < PERIOD ; t++) {
      for(int i = 0 ; i < 4 ; i++) {
        if(t == offsets[i]) {
          leds[i]->setValue(false);
        }
      }
    }
  }

  return 0;
}
