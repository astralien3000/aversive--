// Minimal main code

#include <aversive.hpp>

#include <device/other/fpga_timer.hpp>

#include <iostream>
using namespace std;

u16 S = 10, MS = 100, US = 222;

int main(int argc, char** argv) {
  (void) argc;
  (void) argv;
  
  Aversive::init();

  FpgaTimer timer("timer", &S, &MS, &US);
  
  cout << timer.getValue() << endl;
  timer.setMode(FpgaTimer::TIME_MS);
  cout << timer.getValue() << endl;
  timer.setMode(FpgaTimer::TIME_US);
  cout << timer.getValue() << endl;

  while(Aversive::sync()) {
  }
  
  Aversive::setReturnCode(0);
  return Aversive::exit();
}
