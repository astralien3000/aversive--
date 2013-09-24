#ifndef ADC_HPP
#define ADC_HPP

//! \brief class providing routines for microcontroller's analog-to-digital functionalities management
//! \todo Not completely defined yet...
class Adc {
public:
  static inline void init(void);
  static inline void quit(void);

  static inline ArchiHandler::AdcType getValue(int bit);

  template<typename Callable> static inline void setEvent(Callable func);
};

#endif//ADC_HPP
