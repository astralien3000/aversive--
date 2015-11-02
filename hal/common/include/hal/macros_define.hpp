//! \brief This define tells to the compiler (GNU) to warn the user when a marked funcionnality is used
//! \todo Replace by C++14 deprecated attribute
#define _AVERSIVE_UNAVAILABLE                                           \
  __attribute__((deprecated("This functionnality is not available for the microcontroller you are using")))

    //! \brief This is just an alias to build "deprecatable Enumerations"
#define _AVERSIVE_UNAVAILABLE_ELEMENT(elem)                        \
    static constexpr Type elem _AVERSIVE_UNAVAILABLE = Type::elem

//! \brief This is just an alias to define an available enum value
#define _AVERSIVE_AVAILABLE_ELEMENT(elem)       \
  static constexpr Type elem = Type::elem
