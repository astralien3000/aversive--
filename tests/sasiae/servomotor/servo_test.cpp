#include <device/eirbot2014/servomotor.hpp>
#include <device/eirbot2014/servomotor_pin.hpp>
#include <device/eirbot2014/servomotor_fpga.hpp>
#include <iostream>

s32 value;

int main(int argc, char* argv[]) {

  ServomotorPin<1,2> servo1("Servo PIN");
  ServomotorFpga<&value> servo2("Servo FPGA");

  servo1.setValue(1234);
  servo2.setValue(2345);
  
  std::cout << "Value of fgpa servo (expected to be 2345) : " << value << std::endl;

  return 0;
}
