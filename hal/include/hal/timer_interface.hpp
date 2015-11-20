#ifndef HAL_TIMER_INTERFACE_HPP
#define HAL_TIMER_INTERFACE_HPP

#include <base/compil.hpp>
#include <base/integer.hpp>
#include <hal/macros_define.hpp>

namespace HAL {
  
  //! \brief TIMER Driver Interface
  //! \param T : The type of a standard Timer Counter Register
  struct TIMER_DriverInterface {
  public:
    //! \brief The TIMER Counter Period
    struct Period {
      using Type = u32;
    };

    template<typename PeriodType>
    struct GenericSettings {
      PeriodType period;
    };
    
    using Settings = GenericSettings<
      typename Period::Type
      >;

    template<typename TIMERType, typename Settings>
    static void init(TIMERType timer, const Settings&) AVERSIVE_UNAVAILABLE;

    template<typename TIMERType, typename IRQ_Handler>
    static void setOverflowHandler(TIMERType timer, IRQ_Handler handler) AVERSIVE_UNAVAILABLE;
  };

}

#include <hal/macros_undef.hpp>

#endif//HAL_TIMER_INTERFACE_HPP
