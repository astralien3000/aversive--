#ifndef HAL_GPIO_INTERFACE_HPP
#define HAL_GPIO_INTERFACE_HPP

#include <base/compil.hpp>
#include <base/integer.hpp>
#include <hal/macros_define.hpp>

namespace HAL {

  //! \brief GPIO Driver Interface
  //! \param T : The type of a standard GPIO I/O Register
  /*!
   * This interface exists to show the developer what can be implemented.
   * But the developper may not implement everything, since not every mirocontroller has as much functionnalities.
   * If a microcontroller provides a service that does not fit this interface, please, contact the main developpers of this project.
   */
  template<typename T>
  struct GPIO_DriverInterface {
    using IO_Type = T;
      
    //! \brief The GPIO Pin Mode
    struct Mode {
      enum class Type : u8 { UNDEFINED = 0, INPUT, OUTPUT };
      _AVERSIVE_UNAVAILABLE_ELEMENT(UNDEFINED);
      _AVERSIVE_UNAVAILABLE_ELEMENT(INPUT);
      _AVERSIVE_UNAVAILABLE_ELEMENT(OUTPUT);
    };
    
    //! \brief The GPIO Pin Output Mode
    struct OutputMode {
      enum class Type : u8 { UNDEFINED = 0, PUSH_PULL, OPEN_DRAIN };
      _AVERSIVE_UNAVAILABLE_ELEMENT(UNDEFINED);
      _AVERSIVE_UNAVAILABLE_ELEMENT(PUSH_PULL);
      _AVERSIVE_UNAVAILABLE_ELEMENT(OPEN_DRAIN);
    };

    //! \brief The GPIO Pin Pull Policy
    struct Pull {
      enum class Type : u8 { UNDEFINED = 0, UP, DOWN };
      _AVERSIVE_UNAVAILABLE_ELEMENT(UNDEFINED);
      _AVERSIVE_UNAVAILABLE_ELEMENT(UP);
      _AVERSIVE_UNAVAILABLE_ELEMENT(DOWN);
    };

    //! \brief GPIO Settings
    struct Settings {
      typename Mode::Type mode;
      typename OutputMode::Type output_mode;
      typename Pull::Type pull;
    };
  };
    
}

#include <hal/macros_undef.hpp>

#endif//HAL_GPIO_INTERFACE_HPP
