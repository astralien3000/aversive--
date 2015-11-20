#ifndef HAL_PIN_INTERFACE_HPP
#define HAL_PIN_INTERFACE_HPP

#include <hal/gpio_interface.hpp>

#include <base/integer.hpp>
#include <base/compil.hpp>
#include <hal/macros_define.hpp>

namespace HAL {

  //! \brief PIN Driver Interface
  //! \param T : The type of a standard GPIO I/O Register
  /*!
   * This interface exists to show the develloper what can be implemented.
   * But the developper may not implement everything, since not every mirocontroller has as much functionnalities.
   * If a microcontroller provides a service that does not fit this interface, please, contact the main developpers of this project.
   */
  template<typename T>
  struct PIN_DriverInterface : GPIO_DriverInterface<T> {
    using Settings = typename GPIO_DriverInterface<T>::Settings;
    
    //! \name Settings
    //! @{
    template<typename GPIOType, typename PinType, typename Settings>
    static void init(GPIOType gpio, PinType pin, const Settings& settings) AVERSIVE_UNAVAILABLE;
    //! @}

    //! \name Value
    //! @{
    template<typename GPIOType, typename PinType>
    static bool getValue(GPIOType gpio, PinType pin) AVERSIVE_UNAVAILABLE;

    template<typename GPIOType, typename PinType, typename ValueType>
    static void setValue(GPIOType gpio, PinType  pin, ValueType value) AVERSIVE_UNAVAILABLE;

    template<typename GPIOType, typename PinType>
    static void toggle(GPIOType gpio, PinType pin) AVERSIVE_UNAVAILABLE;
    //! @}
  };
    
}

#include <hal/macros_undef.hpp>

#endif//HAL_PIN_INTERFACE_HPP
