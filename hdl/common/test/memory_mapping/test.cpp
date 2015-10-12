#include <util/memory_mapping.hpp>
#include <util/dummy.hpp>
#include <assert.h>
#include <iostream>
#include <vector>

using namespace MemoryMapping;
using namespace MemoryMapping;

volatile u8 r1 = 0;
volatile u8 r2 = 0;
volatile u8 r3 = 0;

struct G1;
struct G2;

constexpr Register8<G1> R1 = &r1;
constexpr Register8<G1> R2 = (usys)&r2;
constexpr Register8<G2> R3 = (u8*)&r3;

constexpr Field8<G1, 0b00101100> R1F1 = R1;
constexpr Field8<G1, 0b00101100> R2F1 = R2;
constexpr Field8<G1, 0b11000000> R1F2 = R1;
constexpr Field8<G2, 0b11000000> R3F2 = R3;

constexpr BitField8<G1, 1> R1B1 = R1;
constexpr BitField8<G1, 0> R2B0 = R2;
constexpr BitField8<G2, 0> R3B0 = R3;

constexpr auto G1F1C1 = make_config(R1F1, 0b001);
constexpr auto G1F1C2 = make_config(R1F1, 0b101);

constexpr auto G1F2C1 = make_config(R1F2, 0b10);

constexpr auto G1B1C1 = make_config(R1B1, true);

constexpr auto G2F2C1 = make_config(R3F2, 0b01);
constexpr auto G2F2C2 = make_config(R3F2, 0b11);

struct Test {
  static std::vector<const char*> list;

  ~Test(void) {
    std::cout << "PASSED" << std::endl;
  }
};

std::vector<const char*> Test::list;

#define MACRO_TEST_CLASS(name)				\
  struct _##name {					\
    _##name(void) { Test::list.push_back(#name); }	\
  };							\
  _##name _##name##_elem;					\
  template<DummyType DUMMY = DUMMY_VALUE>		\
  struct name : Test


////////////////////////////////////////////////////////////////
// Registers

MACRO_TEST_CLASS(TestRegistersSimpleAssignOK) {
  void run(void) {
    r1 = 0;
    r2 = 0;
    
    R2 = 0b10101010;
    R1 = R2;
    
    assert(r1 == 0b10101010);
    assert(r2 == 0b10101010);
  }
};

MACRO_TEST_CLASS(TestRegistersArithAssignOK) {
  void test_add(void) {
    r1 = 1;
    r2 = 1;
    
    R1 += R2;
    
    assert(r1 == 2);
    assert(r2 == 1);
  }

  void test_sub(void) {
    r1 = 1;
    r2 = 1;
    
    R1 -= R2;
    
    assert(r1 == 0);
    assert(r2 == 1);
  }

  void test_mul(void) {
    r1 = 2;
    r2 = 2;
    
    R1 *= R2;
    
    assert(r1 == 4);
    assert(r2 == 2);
  }

  void test_div(void) {
    r1 = 2;
    r2 = 2;
    
    R1 /= R2;
    
    assert(r1 == 1);
    assert(r2 == 2);
  }

  void test_mod(void) {
    r1 = 2;
    r2 = 2;
    
    R1 %= R2;
    
    assert(r1 == 0);
    assert(r2 == 2);
  }

  void run(void) {
    test_add();
    test_sub();
    test_mul();
    test_div();
    test_mod();
  }
};

MACRO_TEST_CLASS(TestRegistersBitAssignOK) {
  void test_and(void) {
    r1 = 0b110;
    r2 = 0b101;
    
    R1 &= R2;
    
    assert(r1 == 0b100);
    assert(r2 == 0b101);
  }

  void test_or(void) {
    r1 = 0b110;
    r2 = 0b101;
    
    R1 |= R2;
    
    assert(r1 == 0b111);
    assert(r2 == 0b101);
  }


  void test_xor(void) {
    r1 = 0b110;
    r2 = 0b101;
    
    R1 ^= R2;
    
    assert(r1 == 0b011);
    assert(r2 == 0b101);
  }

  void run(void) {
    test_and(); 
    test_or();
    test_xor();
  }
};

MACRO_TEST_CLASS(TestRegistersSimpleAssignKO) {
  void run(void) {
    R1 = R3;
  }
};

MACRO_TEST_CLASS(TestRegistersAddAssignKO) {
  void run(void) {
    R1 += R3;
  };
};

MACRO_TEST_CLASS(TestRegistersSubAssignKO) {
  void run(void) {
    R1 -= R3;
  };
};

MACRO_TEST_CLASS(TestRegistersMulAssignKO) {
  void run(void) {
    R1 *= R3;
  };
};

MACRO_TEST_CLASS(TestRegistersDivAssignKO) {
  void run(void) {
    R1 /= R3;
  };
};

MACRO_TEST_CLASS(TestRegistersModAssignKO) {
  void run(void) {
    R1 %= R3;
  };
};

MACRO_TEST_CLASS(TestRegistersBitAndAssignKO) {
  void run(void) {
    R1 &= R3;
  }
};

MACRO_TEST_CLASS(TestRegistersBitOrAssignKO) {
  void run(void) {
    R1 |= R3;
  }
};

MACRO_TEST_CLASS(TestRegistersBitXorAssignKO) {
  void run(void) {
    R1 ^= R3;
  }
};


////////////////////////////////////////////////////////////////
// Fields

MACRO_TEST_CLASS(TestFieldsSimpleAssignOK) {
  void run(void) {
    r1 = 0;
    r2 = 0;
    
    R2F1 = 0b111;
    R1F1 = R2F1;
    
    assert(r1 == 0b00101100);
    assert(r2 == 0b00101100);
  }
};

MACRO_TEST_CLASS(TestFieldsSimpleAssign2OK) {
  void run(void) {
    r1 = 0b11111111;
    r2 = 0b11111111;
    
    R2F1 = 0b000;
    R1F1 = R2F1;
    
    assert(r1 == 0b11010011);
    assert(r2 == 0b11010011);
  }
};

MACRO_TEST_CLASS(TestFieldsSimpleAssign3OK) {
  void run(void) {
    r1 = 0;
    r2 = 0;
    
    R2F1 = 0b101;
    R1F1 = R2F1;
    
    assert(r1 == 0b00100100);
    assert(r2 == 0b00100100);
  }
};

MACRO_TEST_CLASS(TestFieldsSimpleAssignKO) {
  void run(void) {
    R1F1 = R1F2;
  }
};

MACRO_TEST_CLASS(TestFieldsSimpleAssign2KO) {
  void run(void) {
    R1F2 = R3F2;
  }
};

////////////////////////////////////////////////////////////////
// BitFields

MACRO_TEST_CLASS(TestBitFieldsSimpleAssignOK) {
  void run(void) {
    r1 = 0;
    r2 = 0;
    
    R2B0 = true;
    R1B1 = R2B0;
    
    assert(r1 == 0b10);
    assert(r2 == 0b01);
  }
};

MACRO_TEST_CLASS(TestBitFieldsSimpleAssign2OK) {
  void run(void) {
    r1 = 0b11111111;
    r2 = 0b11111111;
    
    R2B0 = false;
    R1B1 = R2B0;
    
    assert(r1 == 0b11111101);
    assert(r2 == 0b11111110);
  }
};

MACRO_TEST_CLASS(TestBitFieldsSimpleAssign3OK) {
  void run(void) {
    r1 = 0b11111101;
    r2 = 0b11111110;
    r3 = 0b00000001;
    
    R2B0 = R1B1 = R3B0;
    
    assert(r1 == 0b11111111);
    assert(r2 == 0b11111111);
    assert(r3 == 0b00000001);
  }
};

MACRO_TEST_CLASS(TestBitFieldsLogicOK) {
  void run(void) {
    r1 = 0b11111111;
    r2 = 0b11111111;
    
    bool test = false;
    
    test = R1B1 && R2B0;    
    assert(test);

    test = R1B1 && R2B0;    
    assert(test);

    test = R1B1 || !R2B0;    
    assert(test);

    test = !R1B1 || R2B0;    
    assert(test);

    r1 = 0;
    test = R1B1 && R2B0;    
    assert(!test);

    test = R1B1 || R2B0;    
    assert(test);

    test = R1B1 || R2B0;    
    assert(test);

    test = !R1B1;
    assert(test);

    test = R1B1;
    assert(!test);

    if(R2B0) {
      assert(true);
    }
    else {
      assert(false);
    }
  }
};

////////////////////////////////////////////////////////////////
// Configs

MACRO_TEST_CLASS(TestConfigsSimpleAssignOK) {
  void run(void) {
    r1 = 0;
    
    r1 = 0;
    R1 = G1F1C1;
    assert(r1 == 0b00000100);

    r1 = 0;
    R1F1 = G1F1C2;
    assert(r1 == 0b00100100);

    r1 = 0;
    R1B1 = G1B1C1;
    assert(r1 == 0b00000010);
  }
};

MACRO_TEST_CLASS(TestConfigsSimpleAssignKO) {
  void run(void) {
    R1 = G2F2C1;
  }
};

MACRO_TEST_CLASS(TestConfigsSimpleAssign2KO) {
  void run(void) {
    R1F1 = G1F2C1;
  }
};

MACRO_TEST_CLASS(TestConfigsSimpleAssign3KO) {
  void run(void) {
    R1B1 = G1F2C1;
  }
};

MACRO_TEST_CLASS(TestConfigsArithOK) {
  void run(void) {
    auto RES1 = G1F1C1 & G1F2C1;
    assert(RES1.VALUE == 0b00000000);
  }
};

MACRO_TEST_CLASS(TestConfigsArith2OK) {
  void run(void) {
    auto RES1 = G1F1C1 | G1F2C1;
    assert(RES1.VALUE == 0b10000100);
  }
};


int main(int, char**) {
#if defined DISPLAY_LIST
  for(unsigned int i = 0 ; i < Test::list.size() ; i++) {
    std::cout << Test::list[i] << std::endl;
  }
#else
  TEST<> test;
  test.run();
#endif
  return 0;
}
