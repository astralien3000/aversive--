#ifndef HAL_PINGROUP_INTERFACE_HPP
#define HAL_PINGROUP_INTERFACE_HPP

#include <hal/gpio_interface.hpp>

#include <base/integer.hpp>
#include <base/compil.hpp>
#include <hal/macros_define.hpp>

namespace HAL {

  //! \brief PINGROUP Driver Interface
  //! \param T : The type of a standard GPIO I/O Register
  /*!
   * This interface exists to show the develloper what can be implemented.
   * But the developper may not implement everything, since not every mirocontroller has as much functionnalities.
   * If a microcontroller provides a service that does not fit this interface, please, contact the main developpers of this project.
   */
  template<typename T>
  struct PINGROUP_DriverInterface : GPIO_DriverInterface<T> {
    using Settings = typename GPIO_DriverInterface<T>::Settings;
    
    //! \name Settings
    //! @{
    template<typename GPIOType, typename MASKType>
    static void init(GPIOType gpio, GPIOType mask, const Settings& settings) AVERSIVE_UNAVAILABLE;
    //! @}

    //! \name Value
    //! @{
    template<typename GPIOType, typename MASKType, typename ValueType>
    static void setValue(GPIOType gpio, MASKType  mask, ValueType value) AVERSIVE_UNAVAILABLE;

    template<typename GPIOType, typename MASKType>
    static void toggle(GPIOType gpio, MASKType mask) AVERSIVE_UNAVAILABLE;
    //! @}
  };
    
}

#include <hal/macros_undef.hpp>

#endif//HAL_PINGROUP_INTERFACE_HPP
