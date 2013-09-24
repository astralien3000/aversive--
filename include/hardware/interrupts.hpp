#ifndef INTERRUPTS_HPP
#define INTERRUPTS_HPP

//! \brief class providing static routines for interruptions management
class Interrupts {
public:
  //! \brief An alias for "cli" instruction, disable interruptions
  static inline void clear(void);
  //! \brief An alias for "sei" instruction, enable interruptions
  static inline void set  (void);
  
  //! \brief Disable instructions and save some register
  /*!
    It was defined in aversive...
   */
  template<typename T> static inline void lock  (T&);
  //! \brief Enable instructions and reset some register
  /*!
    It was defined in aversive...
   */
  template<typename T> static inline void unlock(T&);
};

#endif//INTERRUPTS_HPP
