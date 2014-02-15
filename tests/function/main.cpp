#include <iostream>
#include <functional>
#include <cstdlib>
#include <cstring>
using namespace std;

#define u8 unsigned char

template<typename T>
class Function;

template<typename Ret, typename... Args>
class Function<Ret(Args...)> {
private:
  typedef Ret(*FuncType)(void*, Args...);

  //! \brief Binding for lambdas and normal functions
  struct StaticBinder {
    template<typename LambdaType>
    static Ret exec(void* lambda, Args... args) {
      return (*(LambdaType*)lambda)(args...);
    }
  };

  //! \todo : Move
  template<int SIZE>
  static inline void internal_memcpy(u8* p1, u8* p2) {
    for(int i = 0 ;i < SIZE ; i++) {
      *(p1++) = *(p2++);
    }
  }

private:
  //! \todo : Make it clean
  unsigned char _data[8];
  FuncType _func;

public:
  //! \brief Function Constructor
  template<typename Callable>
  Function(Callable func) {
    static_assert(sizeof(func) <= sizeof(_data), "ERROR : lambda memory size not handled");
    internal_memcpy<sizeof(func)>((u8*)_data, (u8*)&func);
    _func = StaticBinder::exec<Callable>;
  }
  
  //! \brief Function operator
  inline Ret operator()(Args... args) {
    return (*_func)(_data, args...);
  }
};

void exec(Function<int(int)> f) {
  cout << f(10) << endl;
}

int test(int val) {
  return val + 42;
}

int main(int argc, char* argv[]) {
  int t = 5;
  int u = 10;
  double v = 100.2;
  exec([&](int val) mutable->int {
      return val + t;
    });
  exec(test);
  return 0;
}
