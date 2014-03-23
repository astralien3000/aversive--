#ifndef INPUT_CONVERTER_HPP
#define INPUT_CONVERTER_HPP

#include <device/input.hpp>

//! \brief Transform an input with some type in an input with another type
//! \param ET : Externale type (what the user see)
//! \param IT : Internal type (the true type)
//! \deprecated To be removed soon. Do not use it anymore and fix your current code using it.
template<typename ET, typename IT>
class InputConverter : public Input<ET> {
private:
  Input<IT>& _ref;

public:
  InputConverter(Input<IT>& out) : _ref(out) {}

  ET getValue(void) {
    if(sizeof(ET) < sizeof(IT)) {
      return (ET)_ref.getValue();
    }
    else {
      //! \todo : saturation ?
      return (ET)_ref.getValue();
    }
  }
};


#endif//INPUT_CONVERTER_HPP
