// Minimal main code

#include <aversive.hpp>

int main(int argc, char** argv) {
  (void) argc;
  (void) argv;
  
  Aversive::init();
  // Declare your devices here
  // Initialize your stuff here
  
  while(Aversive::sync()) {
    // Your while(1) code
  }
  
  // You can have several "while(Aversive::sync())" loops if needed
  
  // Unintialize your stuff here
  Aversive::setReturnCode(0); // Optional; default value is already 0
  return Aversive::exit();
}
