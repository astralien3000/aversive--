#ifndef AVERSIVE_HPP
#define AVERSIVE_HPP

/*!
  
  \mainpage Aversive++ documentation
  
  \section Introduction
  
  The aim of this library is to make easier the programmation
  of a complex application on a microcontroller, without any
  operating system running on it and that the application runs
  as fast as possible.
  
  To fulfill this goal, it has been designed with a specific policy:
  
  - Most of the things should be determined at compile-time;
  
  - Most of the functions are inline, to avoid function call;
  
  - The code of the application should not be hardware dependent,
  but if the hardware the code is compiled for does not support
  a functionnality used in the code, an error message should be
  displayed at compile-time.
  
*/

//! \brief Aversive++ main class.
class Aversive {
public:
  //! \brief Initialize Aversive++.
  //! It must be the first operation done at the beginning of the main.
  //! Please refer to "Create a project" tutorial.
  static void init(void);
  
  //! \brief Sleep for a certain amount of time
  //! \param ms : the amount of milliseconds to sleep.
  static void sleep(int ms);
  
  //! \brief Synchronize the main while loop(s).
  //! \return Boolean telling if the application must keep running.
  //! It must be used for simulation purpose.
  //! Please refer to "Create a project" tutorial.
  static bool sync(void);
  
  //! \brief Tell the application it has to stop.
  static void stop(void);
  
  //! \brief Uninitialize Aversive++.
  //! \return The application's return code.
  //! It must be used to properly uninitialize Aversive++ before the main returns.
  //! Please refer to "Create a project" tutorial.
  static int exit(void);
  
  //! \brief Tell whether Aversive++ has been initialized or not.
  static bool isInitialized(void);
  
  //! \brief Tell whether the application is running or in the process of stopping.
  static bool isRunning(void);
  
  //! \brief Tell the current return code of the application.
  static int returnCode(void);
  
  //! \brief Change the return code of the application.
  //! \param returnCode : the new return code.
  static void setReturnCode(int returnCode = 0);
};

#endif//AVERSIVE_HPP
