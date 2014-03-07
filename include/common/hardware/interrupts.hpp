#ifndef INTERRUPTS_HPP
#define INTERRUPTS_HPP

#include <base/integer.hpp>

//! \brief Class providing routines for interruption management
class Interrupts {
  static volatile u16 counter;
public:
  //! \brief Start the interruptions
  static inline void init(void);
  
  //! \brief Stop the interruptions
  static inline void stop(void);
  
  //! \brief Disable temporarily the interruptions if needed
  //! \note Use it at the beginning of a critical section
  static inline void lock(void);
  
  //! \brief Revive the interruptions if needed
  //! \note Use it at the end of a critical section
  static inline void unlock(void);
  
  //! \brief An alias for "cli" instruction, disable interruptions
  //! \warning Use it only if you know what you are doing (see the other methods otherwise)
  static inline void clear(void);
  
  //! \brief An alias for "sei" instruction, enable interruptions
  //! \warning Use it only if you know what you are doing (see the other methods otherwise)
  static inline void set(void);
};

#endif//INTERRUPTS_HPP
