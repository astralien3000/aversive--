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
  static void sleep(int ms = 0);
  static void stop(void);
};

//! \brief Robot initialization function.
//! \brief It must declare and set up the different devices used by the code robot and some other stuff (like the scheduler for example)
//! \return True on success, false otherwise
bool robotInit();

//! \brief Robot main loop function. It must be non-blocking.
void robotLoop();

//! \brief Robot exit function. Use it if you need to properly stop devices or communications by doing specific things.
void robotExit();

#endif//AVERSIVE_HPP
