#include <memory_mapping.hpp>

struct G1;
constexpr MemoryMapping::Register8<G1> reg1 = 0x22;

int main(int argc, char* argv[]) {
  (void) argc;
  (void) argv;
  
  reg1 = 10;
  
  return 0;
}
