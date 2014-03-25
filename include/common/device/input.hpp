#ifndef INPUT_HPP
#define INPUT_HPP

//! \class Input input.hpp <device/input.hpp>
//! \brief Input interface used by physical and virtual input devices.
//! \param T : the type of the data read from the input.
template<typename T>
class Input {
public:
  //! \brief Return the current value of the input.
  //! \return The current value of the input.
  virtual T getValue(void) = 0;
};

#endif//INPUT_HPP
