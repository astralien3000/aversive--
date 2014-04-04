#ifndef FUNCTION_HPP
#define FUNCTION_HPP

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
    
    return *this;
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

    return *this;
  }

  //! \brief Reset operator
  /*
    
    The function is null event if the parameter is not null.
    
   */
  Function& operator=(int val) {
    (void)val;
    if(_data) {
      delete _data;
    }
      
    _size = 0;
    _data = 0;
    _func = 0;

    return *this;
  }

  //! \brief Default Constructor
  Function(void)
    : _size(0), _data(0), _func(0) {
    
  }

  Function(int val) {
    *this = val;
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
  inline Ret operator()(Args... args) const {
    return (*_func)(_data, args...);
  }

  //! \brief If the function pointer is NULL or not.
  inline operator bool(void) const {
    return _func != 0;
  }
};

#endif//FUNCTION_HPP
