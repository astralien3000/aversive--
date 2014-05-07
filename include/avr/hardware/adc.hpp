#ifndef ADC_HPP
#define ADC_HPP

#include <base/singleton.hpp>

//! \brief class providing routines for microcontroller's analog-to-digital functionalities management
//! \param ID : the ID of the ADC port to use
tempate<int ID>
class Adc : public Singleton<Adc> {
public:
  inline void init(void);
  inline void reset(void);

  template<typename T> inline T getValue(void);

  template<typename Callable> inline void setEvent(Callable func);
  inline void launch(void);

private:
  inline Adc(void);

  class PrivateData;
  PrivateData data;
};

#endif//ADC_HPP
