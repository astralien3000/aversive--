#include <math/random.hpp>

Vect<2, u64> Random::state;

u64 Random::next(void) {
  u64 s1 = state[0];
  const u64 s0 = state[1];
  
  state[0] = s0;
  s1 ^= s1 << 23;
  state[1] = s1 ^ s0 ^ (s1 >> 17) ^ (s0 >> 26);
  
  return state[1] + s0;
}
