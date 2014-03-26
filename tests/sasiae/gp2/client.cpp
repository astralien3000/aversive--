#include <aversive.hpp>
#include <device/eirbot2014/gp2.hpp>

#include <base/integer.hpp>

#include <iostream>
using namespace std;

int main(int argc, char** argv) {
  (void) argc;
  (void) argv;
  
  Aversive::init();
  GP2<0> in("in");
  
  cout << "in value " << in.getValue() << endl;
  Aversive::sync();
  cout << "in value " << in.getValue() << endl;

  Aversive::setReturnCode(0);
  return Aversive::exit();
}
