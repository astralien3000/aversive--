#define _AVERSIVE_UNAVAILABE_MESSAGE					\
  "This functionnality is not available for the microcontroller you are using"

//! \brief This define tells to the compiler (GNU) to warn the user when a marked funcionnality is used
#define _AVERSIVE_UNAVAILABLE				\
  __attribute__((error(_AVERSIVE_UNAVAILABE_MESSAGE)))

//! \brief This define tells to the compiler (GNU) to warn the user when a marked funcionnality is used
//! \todo Replace by C++14 deprecated attribute
#define _AVERSIVE_UNAVAILABLE_WARNING				\
  __attribute__((deprecated(_AVERSIVE_UNAVAILABE_MESSAGE)))

    //! \brief This is just an alias to build "deprecatable Enumerations"
#define _AVERSIVE_UNAVAILABLE_ELEMENT(elem)                        \
    static constexpr Type elem _AVERSIVE_UNAVAILABLE_WARNING = Type::elem

//! \brief This is just an alias to define an available enum value
#define _AVERSIVE_AVAILABLE_ELEMENT(elem)       \
  static constexpr Type elem = Type::elem
