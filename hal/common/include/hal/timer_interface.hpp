#ifndef HAL_COMMON_TIMER_INTERFACE_HPP
#define HAL_COMMON_TIMER_INTERFACE_HPP

#include <base/integer.hpp>
#include <hal/macros_define.hpp>

namespace HAL {
  
  //! \brief TIMER Driver Interface
  //! \param T : The type of a standard Timer Counter Register
  template<typename T>
  struct TIMER_DriverInterface {
    using IO_Type = T;
      
    //! \brief Interrupt Handler
    //! \todo May be gatered with others IRQ_Handlers
    using IRQ_Handler = void (*)(void);

    //! \brief The TIMER Counter Mode
    struct CounterMode {
      enum class Type : u8 { UNDEFINED, UP, DOWN, CENTER_ALIGNED };
      _AVERSIVE_UNAVAILABLE_ELEMENT(UNDEFINED);
      _AVERSIVE_UNAVAILABLE_ELEMENT(UP);
      _AVERSIVE_UNAVAILABLE_ELEMENT(DOWN);
      _AVERSIVE_UNAVAILABLE_ELEMENT(CENTER_ALIGNED);
    };

    //! \brief The TIMER Clock Selection
    struct ClockSelect {
      enum class Type : u8 { UNDEFINED, INTERNAL };
      _AVERSIVE_UNAVAILABLE_ELEMENT(UNDEFINED);
      _AVERSIVE_UNAVAILABLE_ELEMENT(INTERNAL);
    };

    //! \brief The TIMER Clock Prescaler
    struct Prescaler {
      using Type = IO_Type;
    };

    //! \brief The TIMER Counter Period
    struct Period {
      using Type = IO_Type;
    };

    //! \brief TIMER Settings
    struct Settings {
      typename CounterMode::Type counter_mode;
      typename ClockSelect::Type clock_select;
      typename Prescaler::Type prescaler;
      typename Period::Type period;
    };

    //! \brief The OutputCompare Mode
    struct OCMode {
      enum class Type : u8 { UNDEFINED, PWM };
      _AVERSIVE_UNAVAILABLE_ELEMENT(UNDEFINED);
      _AVERSIVE_UNAVAILABLE_ELEMENT(PWM);
    };

    //! \brief The OutputCompare Signal Polarity
    struct OCPolarity {
      enum class Type : u8 { UNDEFINED, HIGH, LOW };
      _AVERSIVE_UNAVAILABLE_ELEMENT(UNDEFINED);
      _AVERSIVE_UNAVAILABLE_ELEMENT(HIGH);
      _AVERSIVE_UNAVAILABLE_ELEMENT(LOW);
    };

    //! \brief The OutputCompare Pulse Width
    struct OCPulseWidth {
      using Type = IO_Type;
    };
        
    //! \brief The OutputCompare Pulse Width
    struct OCSettings {
      typename OCMode::Type mode;
      typename OCPolarity::Type polarity;
      typename OCPulseWidth::Type pulse_width;
    };

    //! \brief The Encoder Mode
    struct EncoderMode {
      enum class Type : u8 { UNDEFINED, CHANNEL1_COUNT, CHANNEL2_COUNT, BOTH_COUNT };
      _AVERSIVE_UNAVAILABLE_ELEMENT(UNDEFINED);
      _AVERSIVE_UNAVAILABLE_ELEMENT(CHANNEL1_COUNT);
      _AVERSIVE_UNAVAILABLE_ELEMENT(CHANNEL2_COUNT);
      _AVERSIVE_UNAVAILABLE_ELEMENT(BOTH_COUNT);
    };

    //! \brief The Encoder Polarity
    struct EncoderPolarity {
      enum class Type : u8 { UNDEFINED, RISING, FALLING, BOTH };
      _AVERSIVE_UNAVAILABLE_ELEMENT(UNDEFINED);
      _AVERSIVE_UNAVAILABLE_ELEMENT(RISING);
      _AVERSIVE_UNAVAILABLE_ELEMENT(FALLING);
      _AVERSIVE_UNAVAILABLE_ELEMENT(BOTH);
    };
        
    //! \brief The Encoder Prescaler
    struct EncoderPrescaler {
      using Type = IO_Type;
    };
        
    //! \brief TIMER Encoder Channel Settings
    struct EncoderChannelSettings {
      typename EncoderPolarity::Type polarity;
      typename EncoderPrescaler::Type prescaler;
    }; 

    //! \brief TIMER Encoder Settings
    struct EncoderSettings {
      typename EncoderMode::Type mode;
      EncoderChannelSettings channel1;
      EncoderChannelSettings channel2;
    };
      
    //! \name Module Enable
    //! @{
    static bool isModuleEnabled(void) _AVERSIVE_UNAVAILABLE;
    static void enableModule(void)    _AVERSIVE_UNAVAILABLE;
    static void disableModule(void)   _AVERSIVE_UNAVAILABLE;
    //! @}

    //! \name Module Sleep Enable
    //! @{
    static bool isModuleSleepEnabled(void) _AVERSIVE_UNAVAILABLE;
    static void enableModuleSleep(void)    _AVERSIVE_UNAVAILABLE;
    static void disableModuleSleep(void)   _AVERSIVE_UNAVAILABLE;
    //! @}

    //! \name Settings
    //! @{
    static void setSettings(const Settings&)            _AVERSIVE_UNAVAILABLE;
    static void getSettings(Settings&)                  _AVERSIVE_UNAVAILABLE;
    template<typename Settings> static void setSettings(void) _AVERSIVE_UNAVAILABLE;
    //! @}
        
    //! \name Counter Mode
    //! @{
    static void setCounterMode(typename CounterMode::Type)                _AVERSIVE_UNAVAILABLE;
    template<typename CounterMode::Type> static void setCounterMode(void) _AVERSIVE_UNAVAILABLE;
    static typename CounterMode::Type getCounterMode(void)                _AVERSIVE_UNAVAILABLE;
    //! @}

    //! \name Clock Select
    //! @{
    static void setClockSelect(typename ClockSelect::Type)                _AVERSIVE_UNAVAILABLE;
    template<typename ClockSelect::Type> static void setClockSelect(void) _AVERSIVE_UNAVAILABLE;
    static typename ClockSelect::Type getClockSelect(void)                _AVERSIVE_UNAVAILABLE;
    //! @}

    //! \name Prescaler
    //! @{
    static void setPrescaler(typename Prescaler::Type)                _AVERSIVE_UNAVAILABLE;
    template<typename Prescaler::Type> static void setPrescaler(void) _AVERSIVE_UNAVAILABLE;
    static typename Prescaler::Type getPrescaler(void)                _AVERSIVE_UNAVAILABLE;
    //! @}

    //! \name Overflow Handler
    //! @{
    static void setOverflowHandler(IRQ_Handler) _AVERSIVE_UNAVAILABLE;
    static IRQ_Handler getOverflowHandler(void) _AVERSIVE_UNAVAILABLE;
    //! @}

    //! \name OutputCompare Dynamic Functions
    //! @{
    static void setOutputCompareSettings(u8 channel, const OCSettings&) _AVERSIVE_UNAVAILABLE;
    static void getOutputCompareSettings(u8 channel, OCSettings&)              _AVERSIVE_UNAVAILABLE;

    static void setOutputCompareMode(u8 channel, typename OCMode::Type) _AVERSIVE_UNAVAILABLE;
    static typename OCMode::Type getOutputCompareMode(u8 channel)       _AVERSIVE_UNAVAILABLE;

    static void setOutputComparePolarity(u8 channel, typename OCPolarity::Type) _AVERSIVE_UNAVAILABLE;
    static typename OCPolarity::Type getOutputComparePolarity(u8 channel)       _AVERSIVE_UNAVAILABLE;

    static void setOutputComparePulseWidth(u8 channel, typename OCPulseWidth::Type) _AVERSIVE_UNAVAILABLE;
    static typename OCPulseWidth::Type getOutputComparePulseWidth(u8 channel)              _AVERSIVE_UNAVAILABLE;

    static void setOutputCompareHandler(u8 channel, IRQ_Handler) _AVERSIVE_UNAVAILABLE;
    static IRQ_Handler getOutputCompareHandler(u8 channel)       _AVERSIVE_UNAVAILABLE;
    //! @}
      
    //! \brief Templated OutputCompare interface
    template<u8 CHANNEL>
    struct OutputCompare {
      //! \name Settings
      //! @{
      static void setSettings(const OCSettings&) _AVERSIVE_UNAVAILABLE;
      template<typename Settings> static void setSettings(void)      _AVERSIVE_UNAVAILABLE;
      static void getSettings(OCSettings&)        _AVERSIVE_UNAVAILABLE;
      //! @}

      //! \name Mode
      //! @{
      static void setMode(typename OCMode::Type)                _AVERSIVE_UNAVAILABLE;
      template<typename OCMode::Type> static void setMode(void) _AVERSIVE_UNAVAILABLE;
      static typename OCMode::Type getMode(void)                _AVERSIVE_UNAVAILABLE;
      //! @}

      //! \name Polarity
      //! @{
      static void setPolarity(typename OCPolarity::Type)                _AVERSIVE_UNAVAILABLE;
      template<typename OCPolarity::Type> static void setPolarity(void) _AVERSIVE_UNAVAILABLE;
      static typename OCPolarity::Type getPolarity(void)                _AVERSIVE_UNAVAILABLE;
      //! @}

      //! \name Pulse Width
      //! @{
      static void setPulseWidth(typename OCPulseWidth::Type)                _AVERSIVE_UNAVAILABLE;
      template<typename OCPulseWidth::Type> static void setPulseWidth(void) _AVERSIVE_UNAVAILABLE;
      static typename OCPulseWidth::Type getPulseWidth(void)                       _AVERSIVE_UNAVAILABLE;
      //! @}

      //! \name Output Compare Handler
      //! @{
      static void setHandler(IRQ_Handler) _AVERSIVE_UNAVAILABLE;
      static IRQ_Handler getHandler(void) _AVERSIVE_UNAVAILABLE;
      //! @}
    };

    //! \brief Encoder interface
    struct Encoder {
      //! \name Settings
      //! @{
      static void setSettings(const EncoderSettings&)         _AVERSIVE_UNAVAILABLE;
      template<typename Settings> static void setSettings(void) _AVERSIVE_UNAVAILABLE;
      static void getSettings(EncoderSettings&)                _AVERSIVE_UNAVAILABLE;
      //! @}

      //! \name Mode
      //! @{
      static void setMode(typename EncoderMode::Type)                _AVERSIVE_UNAVAILABLE;
      template<typename EncoderMode::Type> static void setMode(void) _AVERSIVE_UNAVAILABLE;
      static typename EncoderMode::Type getEncoderMode(void)         _AVERSIVE_UNAVAILABLE;
      //! @}

      //! \name Channel Dynamic Functions
      //! @{
      static void setChannelPolarity(u8 channel, typename EncoderPolarity::Type) _AVERSIVE_UNAVAILABLE;
      static typename EncoderPolarity::Type getChannelPolarity(u8 channel)       _AVERSIVE_UNAVAILABLE;

      static void setChannelPrescaler(u8 channel, typename EncoderPrescaler::Type) _AVERSIVE_UNAVAILABLE;
      static typename EncoderPrescaler::Type getChannelPrescaler(u8 channel)       _AVERSIVE_UNAVAILABLE;
      //! @}

      //! \brief Encoder Channel interface
      template<u8 CHANNEL>
      struct Channel {
        //! \name Polarity
        //! @{
        static void setPolarity(typename EncoderPolarity::Type)                _AVERSIVE_UNAVAILABLE;
        template<typename EncoderPolarity::Type> static void setPolarity(void) _AVERSIVE_UNAVAILABLE;
        static typename EncoderPolarity::Type getPolarity(void)                _AVERSIVE_UNAVAILABLE;
        //! @}
            
        //! \name Prescaler
        //! @{
        static void setPrescaler(typename EncoderPrescaler::Type)                _AVERSIVE_UNAVAILABLE;
        template<typename EncoderPrescaler::Type> static void setPrescaler(void) _AVERSIVE_UNAVAILABLE;
        static typename EncoderPrescaler::Type getPrescaler(void)                _AVERSIVE_UNAVAILABLE;
        //! @}
      };
    };
  };

}

#include <hal/macros_undef.hpp>

#endif//HAL_COMMON_TIMER_INTERFACE_HPP
