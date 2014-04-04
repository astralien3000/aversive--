#include <iostream>
#include <functional>
#include <cstdlib>
#include <cstring>
using namespace std;

#include <base/integer.hpp>
#include <base/alloc.hpp>

template<typename T>
class Function;

//! \brief Binding for lambdas and normal functions
template<typename LambdaType, typename Ret, typename... Args>
struct StaticBinder {
  static Ret exec(void* lambda, Args... args) {
    return (*(LambdaType*)lambda)(args...);
  }
};

template<typename LambdaType, typename... Args>
struct StaticBinder<LambdaType, void, Args...> {
  static void exec(void* lambda, Args... args) {
    (*(LambdaType*)lambda)(args...);
  }
};

template<typename Ret, typename... Args>
class Function<Ret(Args...)> {
private:
  typedef Ret(*FuncType)(void*, Args...);

  //! \todo : Move
  static inline void internal_memcpy(u8* p1, u8* p2, u16 size) {
    for(int i = 0 ;i < size ; i++) {
      *(p1++) = *(p2++);
    }
  }

private:
  //! \todo : Make it clean
  u16 _size;
  u8* _data;
  FuncType _func;

public:
  //! \brief Function assignment
  template<typename Callable>
  Function& operator=(Callable func) {
    if(_data) {
      delete _data;
    }

    _size = sizeof(Callable);
    _data = (u8*)malloc(_size);
    internal_memcpy((u8*)_data, (u8*)&func, _size);
    _func = StaticBinder<Callable, Ret, Args...>::exec;
  }

  //! \brief Copy operator
  Function& operator=(Function& other) {
    if(_data) {
      delete _data;
    }

    _size = other._size;
    _data = new u8[_size];
    internal_memcpy((u8*)_data, (u8*)other._data, _size);
    _func = other._func;
  }

  //! \brief Default Constructor
  Function(void)
    : _size(0), _data(0), _func(0) {
    
  }

  //! \brief Function constructor
  template<typename Callable>
  Function(Callable func)
    : Function() {
    *this = func;
  }

  //! \brief Destructor
  ~Function(void) {
    delete _data;
  }
  
  //! \brief Function operator
  inline Ret operator()(Args... args) {
    return (*_func)(_data, args...);
  }

  inline operator bool(void) {
    return _func != 0;
  }
};

void exec(Function<void(void)> f) {
  f();
  cout << "test ?" << endl;
  Function<void(void)> f1;
  cout << "test ?" << endl;
  //f1 = f;
  if(f1) {
    f1();
  }
}

void test(void) {
  cout << 1 + 42 << endl;
}

int main(int argc, char* argv[]) {
  int t = 5;
  int u = 10;
  double v = 100.2;
  exec([&](void) mutable->void {
      cout << 2 + t << endl;
    });
  exec(test);
  return 0;
}
