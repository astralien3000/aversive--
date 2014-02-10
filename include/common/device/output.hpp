#ifndef OUTPUT_HPP
#define OUTPUT_HPP

//! \brief Output interface, used for actuators
template<typename T>
class Output {
public:
  virtual void setValue(T)=0;
};

#endif//OUTPUT_HPP
