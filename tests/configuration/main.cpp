#include <config.hpp>

int main(int argc, char** argv) {
  (void) argc;
  (void) argv;

  if(Aversive::Config::dummy() == 42) {
    return 0;
  }
  else {
    return 1;
  }
}
