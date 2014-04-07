#include <iostream>
#include <cassert>
#include <base/function.hpp>
#include <base/integer.hpp>

static const u8 LOOP = 10;

static void h(u8& z) {
  z++;
  return;
}

int main(int argc, char** argv) {
  (void) argc;
  (void) argv;
  
  u8 x = 0;
  u8 y = 0;
  
  Function<u8(void)> f;
  assert(!((bool) f));
  
  f = [x, &y](void) mutable -> u8 {
    x++;
    y++;
    return y;
  };
  
  assert((bool) f);
  
  for(u8 i = 0; i < LOOP; i++) {
    assert(f() == (i + 1));
  }
  
  assert(x == 0);
  assert(y == 10);
  
  f = [](void) mutable -> u8 {
    static u8 i = 0;
    return i++;
  };
  
  assert((bool) f);
  
  for(u8 i = 0; i < LOOP; i++) {
    assert(f() == i);
  }
  
  Function<bool(const Function<u8(void)>&)> g =
    [](const Function<u8(void)>& f) mutable -> bool {
    for(u8 i = LOOP; i < (2 * LOOP); i++) {
      assert(f() == i);
    }
    return true;
  };
  
  assert(g(f));
  
  Function<bool(const Function<void(u8&)>&)> k =
    [](const Function<void(u8&)>& f) mutable -> bool {
    u8 j = 0;
    for(u8 i = 0; i < LOOP; i++) {
      f(j);
      assert(j == (i+1));
    }
    return true;
  };
  
  assert(k(h));
  
  std::cout << "OK" << std::endl;
  return 0;
}
