#include <iostream>
#include <base/function.hpp>
#include <base/integer.hpp>
#include "../../../my_assert.hpp"

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
  myAssert(!((bool) f), "Line " S__LINE__ ": f should not be set");
  
  f.unset();
  myAssert(!((bool) f), "Line " S__LINE__ ": f should not be set");
  
  f = [x, &y](void) mutable -> u8 {
    x++;
    y++;
    return y;
  };
  
  myAssert((bool) f, "Line " S__LINE__ ": f should be set");
  
  Function<u8(void)> l(f);
  
  for(u8 i = 0; i < LOOP; i++) {
    myAssert(f() == (2*i + 1), "Line " S__LINE__ ": Bad result");
    myAssert(l() == (2*i + 2), "Line " S__LINE__ ": Bad result");
  }
  
  myAssert(x == 0, "Line " S__LINE__ ": Bad result");
  myAssert(y == 20, "Line " S__LINE__ ": Bad result");
  
  myAssert(f.isSet(), "Line " S__LINE__ ": f should be set");
  f.unset();
  myAssert(!f.isSet(), "Line " S__LINE__ ": f should not be set");
  
  f = [](void) mutable -> u8 {
    static u8 i = 0;
    return i++;
  };
  
  l = f;
  
  for(u8 i = 0; i < LOOP; i++) {
    myAssert(f() == (i * 2), "Line " S__LINE__ ": Bad result");
    myAssert(l() == (i * 2 + 1), "Line " S__LINE__ ": Bad result");
  }
  
  f = [](void) mutable -> u8 {
    static u8 i = 0;
    return i++;
  };
  
  myAssert((bool) f, "Line " S__LINE__ ": f should be set");
  myAssert(f.isSet(), "Line " S__LINE__ ": f should be set");
  
  for(u8 i = 0; i < LOOP; i++) {
    myAssert(f() == i, "Line " S__LINE__ ": Bad result");
  }
  
  Function<bool(const Function<u8(void)>&)> g =
    [](const Function<u8(void)>& f) mutable -> bool {
    for(u8 i = LOOP; i < (2 * LOOP); i++) {
      myAssert(f() == i, "Line " S__LINE__ ": Bad result");
    }
    return true;
  };
  
  myAssert(g(f), "Line " S__LINE__ ": Bad result");
  
  Function<bool(const Function<void(u8&)>&)> k =
    [](const Function<void(u8&)>& f) mutable -> bool {
    u8 j = 0;
    for(u8 i = 0; i < LOOP; i++) {
      f(j);
      myAssert(j == (i+1), "Line " S__LINE__ ": Bad result");
    }
    return true;
  };
  
  myAssert(k(h), "Line " S__LINE__ ": Bad result");
  
  std::cout << "OK" << std::endl;
  return 0;
}
