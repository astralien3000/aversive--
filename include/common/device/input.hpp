#ifndef INPUT_HPP
#define INPUT_HPP

//! \brief Input interface, used for sensors
template<typename T>
class Input {
public:
  virtual T getValue(void)=0;
};

#endif//INPUT_HPP
