/*
    Aversive++                                                           
    Copyright (C) 2014 Eirbot                                            
                                                                         
    This program is free software: you can redistribute it and/or modify 
    it under the terms of the GNU General Public License as published by 
    the Free Software Foundation, either version 3 of the License, or    
    (at your option) any later version.                                  
                                                                         
    This program is distributed in the hope that it will be useful,      
    but WITHOUT ANY WARRANTY; without even the implied warranty of       
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the        
    GNU General Public License for more details.                         
                                                                         
    You should have received a copy of the GNU General Public License    
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef FUNCTION_HPP
#define FUNCTION_HPP

#include <base/integer.hpp>
#include <base/alloc.hpp>

//! \class Function function.hpp <base/function.hpp>
//! \brief Class representing a generic function (works with both standard function and lambda).
//! \param T : the function to represent prototype, eg: void(void).
template<typename T>
class Function {
public:
  //! \brief Default constructor.
  inline Function(void);
  
  //! \brief Copy constructor.
  //! \param other : The function to copy.
  inline Function(const Function& other);
  
  //! \brief Function constructor.
  //! \param func : The function to represent.
  template<typename Callable>
  inline Function(Callable func);
  
  //! \brief Destructor
  inline ~Function(void);
  
  //! \brief Copy operator.
  //! \param other : The function to copy.
  Function& operator=(const Function& other);
  
  //! \brief Function assignment.
  //! \param func : The new function to represent.
  template<typename Callable>
  Function& operator=(Callable func);
  
  //! \brief Unset the function.
  void unset(void);
  
  //! \brief Tell wether the function is set (not NULL) or not.
  //! \return True if the function is set, false otherwise.
  inline bool isSet(void) const;
  
  //! \brief Functor.
  //! \param ... : The function's parameters.
  //! \return If non-void function, this returns the value returned by the function.
  inline void operator()(...);
  
  //! \brief Tell wether the function is set (not NULL) or not.
  //! \return True if the function is set, false otherwise.
  inline operator bool(void) const;
};

//! \cond PRIVATE
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
  
  static inline void internal_memcpy(u8* p1, u8* p2, u16 size) {
    for(int i = 0 ;i < size ; i++) {
      *(p1++) = *(p2++);
    }
  }
  
  u16 _size;
  u8* _data;
  FuncType _func;
  
public:
  inline Function(void)
    : _size(0), _data(0), _func(0) {
  }
  
  inline Function(const Function& other)
    : Function() {
    *this = other;
  }
  
  template<typename Callable>
  inline Function(Callable func)
    : Function() {
    *this = func;
  }
  
  inline ~Function(void) {
    if(_data) {
      delete[] _data;
    }
  }
  
  Function& operator=(const Function& other) {
    if(_data) {
      delete[] _data;
    }
    
    _size = other._size;
    _data = new u8[_size];
    internal_memcpy((u8*) _data, (u8*) other._data, _size);
    _func = other._func;
    
    return *this;
  }
  
  template<typename Callable>
  Function& operator=(Callable func) {
    if(_data) {
      delete[] _data;
    }
    
    _size = sizeof(Callable);
    _data = new u8[_size];
    internal_memcpy((u8*) _data, (u8*) &func, _size);
    _func = StaticBinder<Callable, Ret, Args...>::exec;
    
    return *this;
  }
  
  void unset(void) {
    if(_data) {
      delete[] _data;
    }
    
    _size = 0;
    _data = 0;
    _func = 0;
  }
  
  inline bool isSet(void) const {
    return _func != 0;    
  }
  
  inline Ret operator()(Args... args) const {
    return (*_func)(_data, args...);
  }
  
  inline operator bool(void) const {
    return isSet();
  }
};
//! \endcond

#endif//FUNCTION_HPP
