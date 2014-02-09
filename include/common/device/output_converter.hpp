#ifndef OUTPUT_CONVERTER_HPP
#define OUTPUT_CONVERTER_HPP

#include <device/output.hpp>

//! \brief Transform an output with some type in an output with another type
//! \param ET : Externale type (what the user see)
//! \param IT : Internal type (the true type)
template<typename ET, typename IT>
class OutputConverter : public Output<ET> {
private:
  Output<IT>& _ref;

public:
  OutputConverter(Output<IT>& out) : _ref(out) {}

  void setValue(ET val) {
    if(sizeof(ET) < sizeof(IT)) {
      _ref.setValue(val);
    }
    else {
      _ref.setValue(Math::saturate<-127, 127>(val));
    }
  }
};

#endif//OUTPUT_CONVERTER_HPP
