#ifndef HAL_PORT_INTERFACE_HPP
#define HAL_PORT_INTERFACE_HPP

#include <hal/gpio_interface.hpp>

#include <base/compil.hpp>
#include <base/integer.hpp>
#include <hal/macros_define.hpp>

namespace HAL {

  //! \brief PORT Driver Interface
  //! \param T : The type of a standard PORT I/O Register
  /*!
   * This interface exists to show the developer what can be implemented.
   * But the developper may not implement everything, since not every mirocontroller has as much functionnalities.
   * If a microcontroller provides a service that does not fit this interface, please, contact the main developpers of this project.
   */
  template<typename T>
  struct PORT_DriverInterface : GPIO_DriverInterface<T> {
    using IO_Type = typename GPIO_DriverInterface<T>::IO_Type;
    using Settings = typename GPIO_DriverInterface<T>::Settings;
    
    //! \name Settings
    //! @{
    template<typename GPIOType, typename Settings>
    static void init(GPIOType gpio, const Settings& settings) AVERSIVE_UNAVAILABLE;
    //! @}

    //! \name Value
    //! @{
    template<typename GPIOType>
    static IO_Type getValue(GPIOType gpio) AVERSIVE_UNAVAILABLE;
    
    template<typename GPIOType, typename ValueType>
    static void setValue(GPIOType gpio, ValueType value) AVERSIVE_UNAVAILABLE;
    //! @}
  };
    
}

#include <hal/macros_undef.hpp>

#endif//HAL_PORT_INTERFACE_HPP
