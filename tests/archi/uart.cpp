#include <hardware/register.hpp>

volatile u8 a = 0, b = 0, c = 0;

template<> inline Register<8, 0>::Register(void) : reg_size(3), reg{(u8*)&a, (u8*)&b, (u8*)&c} {}

template<> inline Config<8, 0>::Config(void) : conf{(1 << 5) , 0, 0} {}
template<> inline Config<8, 1>::Config(void) : conf{0, (1 << 3), 0} {}

#include <iostream>
using namespace std;

int main(int argc, char* argv[]) {
  
  Register<8, 0>() = Config<8, 1>() | Config<8, 0>();

  cout << (int)a << " " << (int)b << " " << (int)c << " " << endl;
  
  if(!(Register<8, 0>() & Config<8, 0>())) {
    cout << "ok" << endl;
  }

  return 0;
}
