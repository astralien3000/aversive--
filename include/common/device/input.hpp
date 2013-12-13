#ifndef INPUT_HPP
#define INPUT_HPP

//! \brief Input interface, used for sensors
template<typename T>
class Input {
public:
  T& getInput(void);
};

#endif//INPUT_HPP
