#include <device/eirbot2014/rds.hpp>
#include <iostream>


int main() {

  Rds rds("RDS");
  
  std::cout << "robotsNumber = " << rds.robotsNumber() << std::endl;
  Vect<2, int16_t> pos;

  std::cout << "mode = cartesian" << std::endl;
  pos = rds.getPosition(0);
  std::cout << "position robot 1 : " << pos.coord(0) << " " << pos.coord(1) << std::endl;
  pos = rds.getPosition(1);
  std::cout << "position robot 2 : " << pos.coord(0) << " " << pos.coord(1) << std::endl;

  rds.setModePolar();
  std::cout << "mode = polar" << std::endl;
  pos = rds.getPosition(0);
  std::cout << "position robot 1 : " << pos.coord(0) << " " << pos.coord(1) << std::endl;
  pos = rds.getPosition(1);
  std::cout << "position robot 2 : " << pos.coord(0) << " " << pos.coord(1) << std::endl;

  rds.setModeCartesian();
  std::cout << "mode = cartesian" << std::endl;
  pos = rds.getPosition(0);
  std::cout << "position robot 1 : " << pos.coord(0) << " " << pos.coord(1) << std::endl;
  
  return 0;
}
