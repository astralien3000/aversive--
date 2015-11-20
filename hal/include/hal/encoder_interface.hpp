#ifndef HAL_ENCODER_INTERFACE_HPP
#define HAL_ENCODER_INTERFACE_HPP

#include <base/compil.hpp>
#include <base/integer.hpp>
#include <hal/macros_define.hpp>

namespace HAL {
  
  //! \brief TIMER Driver Interface
  //! \param T : The type of a standard Timer Counter Register
  template<typename T>
  struct ENCODER_DriverInterface {
    using IO_Type = T;
      
    //! \brief The Encoder Mode
    struct Mode {
      enum class Type : u8 { UNDEFINED, CHANNEL1_COUNT, CHANNEL2_COUNT, BOTH_COUNT };
      AVERSIVE_UNAVAILABLE_ELEMENT(UNDEFINED);
      AVERSIVE_UNAVAILABLE_ELEMENT(CHANNEL1_COUNT);
      AVERSIVE_UNAVAILABLE_ELEMENT(CHANNEL2_COUNT);
      AVERSIVE_UNAVAILABLE_ELEMENT(BOTH_COUNT);
    };

    //! \brief The Encoder Polarity
    struct Polarity {
      enum class Type : u8 { UNDEFINED, RISING, FALLING, BOTH };
      AVERSIVE_UNAVAILABLE_ELEMENT(UNDEFINED);
      AVERSIVE_UNAVAILABLE_ELEMENT(RISING);
      AVERSIVE_UNAVAILABLE_ELEMENT(FALLING);
      AVERSIVE_UNAVAILABLE_ELEMENT(BOTH);
    };
        
    //! \brief The Encoder Prescaler
    struct Prescaler {
      using Type = IO_Type;
    };
        
    //! \brief TIMER Encoder Channel Settings
    struct ChannelSettings {
      typename Polarity::Type polarity;
      typename Prescaler::Type prescaler;
    }; 

    //! \brief TIMER Encoder Settings
    struct Settings {
      typename Mode::Type mode;
      ChannelSettings channel1;
      ChannelSettings channel2;
    };

    template<typename TIMERType, typename Settings>
    static void init(TIMERType timer, const Settings& settings) AVERSIVE_UNAVAILABLE;

    template<typename TIMERType>
    static IO_Type getCounter(TIMERType timer) AVERSIVE_UNAVAILABLE;

    template<typename TIMERType>
    static void setCounter(TIMERType timer, IO_Type value) AVERSIVE_UNAVAILABLE;
  };

}

#include <hal/macros_undef.hpp>

#endif//HAL_ENCODER_INTERFACE_HPP
