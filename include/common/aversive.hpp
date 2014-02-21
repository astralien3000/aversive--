#ifndef AVERSIVE_HPP
#define AVERSIVE_HPP

/*!

  \mainpage Aversive++ documentation
 
  \section Introduction
 
  The aim of this library is to make easier the programmation
  of a complex application on a microcontroller, without any
  operating system running on it.
 
  To fulfill this goal, it has been designed with a special policy :

  - Most of the things should be determined at compile-time

  - Most of the functions are inline, to avoid function call

  - The resulting code for the application should not be hardware
  dependent, but if the hardware dosen't provide a functionnality, an
  error message should be printed at compile-time

*/

class Aversive {
public:
  static void init(void);
  static void sleep(int ms);
  static bool sync(void);
  static void stop(void);
  static int exit(void);
  static bool isInitialized(void);
  static bool isRunning(void);
  static int returnCode(void);
  static void setReturnCode(int returnCode = 0);
};

#endif//AVERSIVE_HPP
