#ifndef OUTPUT_HPP
#define OUTPUT_HPP

//! \brief Output interface, used for actuators
template<typename T>
class Output {
public:
  void setOutput(T&);
};

#endif//OUTPUT_HPP
