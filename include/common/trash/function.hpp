#ifndef FUNCTION_HPP
#define FUNCTION_HPP

template<typename RetType, typename... Args>
class Function {
public:
  RetType operator()(Args... args) {  }
};

#endif//FUNCTION_HPP
