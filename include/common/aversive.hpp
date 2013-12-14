#ifndef AVERSIVE_HPP
#define AVERSIVE_HPP

/*!

  \mainpage Aversive++ documentation
 
  \section Introduction
 
  The aim of this library is to make easy to program a complex
  application on a microcontroller, without any operating system
  running on it.
 
  To do this, it has been designed with a special policy :

  - The most things should be determined at compile-time

  - Most functions are inline, to avoid function call

  - The resulting code for the application should not be hardware
  dependent, but if the hardware dosen't provide a functionnality, the
  error message should be explicit

  -... (TODO)

*/

class Aversive {
public:
  static inline void init();
  static inline void sleep(int ms = 0);
};

#endif//AVERSIVE_HPP
