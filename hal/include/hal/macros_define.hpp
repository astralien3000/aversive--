#include <base/compil.hpp>

#define AVERSIVE_UNAVAILABE_MESSAGE					\
  "This functionnality is not available for the microcontroller you are using"

//! \brief This define tells to the compiler (GNU) to warn the user when a marked funcionnality is used
#define AVERSIVE_UNAVAILABLE				\
  __attribute__((error(AVERSIVE_UNAVAILABE_MESSAGE)))

//! \brief This define tells to the compiler (GNU) to warn the user when a marked funcionnality is used
//! \todo Replace by C++14 deprecated attribute
#define AVERSIVE_UNAVAILABLE_WARNING				\
  __attribute__((deprecated(AVERSIVE_UNAVAILABE_MESSAGE)))

    //! \brief This is just an alias to build "deprecatable Enumerations"
#define AVERSIVE_UNAVAILABLE_ELEMENT(elem)                        \
  static constexpr auto elem AVERSIVE_UNAVAILABLE_WARNING = COMPIL(Type::elem)

//! \brief This is just an alias to define an available enum value
#define AVERSIVE_AVAILABLE_ELEMENT(elem)       \
  static constexpr auto elem = COMPIL(Type::elem)
