#ifndef OUTPUT_HPP
#define OUTPUT_HPP

//! \class Output output.hpp <device/output.hpp>
//! \brief Output interface used by physical and virtual output devices.
//! \param T : the type of the data written into the output.
template<typename T>
class Output {
public:
  //! \brief Set the value of the output to a new value.
  //! \param value : the new value of the output.
  //! \todo Turn the parameter into a const reference (and then update all child classes + re-run tests)
  virtual void setValue(T value) = 0;
};

#endif//OUTPUT_HPP
