#ifndef HAL_PWM_INTERFACE_HPP
#define HAL_PWM_INTERFACE_HPP

#include <base/compil.hpp>
#include <base/integer.hpp>
#include <hal/macros_define.hpp>

namespace HAL {
  
  //! \brief TIMER Driver Interface
  //! \param T : The type of a standard Timer Counter Register
  template<typename T>
  struct PWM_DriverInterface {
    using IO_Type = T;
    
    //! \brief The OutputCompare Signal Polarity
    struct Polarity {
      enum class Type : u8 { UNDEFINED, HIGH, LOW };
      AVERSIVE_UNAVAILABLE_ELEMENT(UNDEFINED);
      AVERSIVE_UNAVAILABLE_ELEMENT(HIGH);
      AVERSIVE_UNAVAILABLE_ELEMENT(LOW);
    };
        
    //! \brief The OutputCompare Pulse Width
    struct Settings {
      typename Polarity::Type polarity;
    };

    template<typename TIMERType, typename ChannelType, typename Settings>
    static void init(TIMERType timer, ChannelType channel, const Settings& settings) AVERSIVE_UNAVAILABLE;

    template<typename TIMERType, typename ChannelType>
    static void setPulseWidth(TIMERType timer, ChannelType channel, IO_Type value) AVERSIVE_UNAVAILABLE;

    template<typename TIMERType, typename ChannelType>
    static IO_Type getPulseWidth(TIMERType timer, ChannelType channel) AVERSIVE_UNAVAILABLE;

    template<typename TIMERType, typename ChannelType, typename IRQ_Handler>
    static void setComparHandler(TIMERType timer, ChannelType channel, IRQ_Handler handler) AVERSIVE_UNAVAILABLE;

  };

}

#include <hal/macros_undef.hpp>

#endif//HAL_PWM_INTERFACE_HPP
