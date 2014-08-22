#include <aversive.hpp>
#include <device/eirbot2014/rds.hpp>
#include <iostream>

#include <base/integer.hpp>
#include <base/singleton.hpp>

using namespace std;

int main(int argc, char** argv) {
  (void) argc;
  (void) argv;
  
  Aversive::init();
  Rds rds("rds");
  
  List<2, Vect<2, s32> > robots;
  
  rds.setMode(Rds::CARTESIAN);
  Aversive::sync();
  robots = rds.getValue();
  cout << "robots number " << robots.usedSpace() << endl;

  for(int i = 0 ; i < (int)robots.usedSpace() ; i++) {
    cout << "robots[" << i << "] " << robots.get(i).coord(0) << " " << robots.get(i).coord(1) << endl;
  }

  rds.setMode(Rds::POLAR);
  Aversive::sync();
  robots = rds.getValue();
  cout << "robots number " << robots.usedSpace() << endl;

  for(int i = 0 ; i < (int)robots.usedSpace() ; i++) {
    cout << "robots[" << i << "] " << robots.get(i).coord(0) << " " << robots.get(i).coord(1) << endl;
  }  

  Aversive::setReturnCode(0);
  return Aversive::exit();
}
