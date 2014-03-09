#ifndef AVERSIVE_HPP
#define AVERSIVE_HPP

//! \class Aversive aversive.hpp <aversive.hpp>
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
  //! \return The current application's return code.
  //! It must be used to properly uninitialize Aversive++ before the main returns.
  //! Please refer to "Create a project" tutorial.
  static int exit(void);
  
  //! \brief Tell whether Aversive++ has been initialized or not.
  static bool isInitialized(void);
  
  //! \brief Tell whether the application is running or in the process of stopping.
  static bool isRunning(void);
  
  //! \brief Tell the current return code of the application.
  //! \return The current application's return code.
  static int returnCode(void);
  
  //! \brief Change the return code of the application.
  //! \param returnCode : the new return code.
  static void setReturnCode(int returnCode = 0);
};

#endif//AVERSIVE_HPP
