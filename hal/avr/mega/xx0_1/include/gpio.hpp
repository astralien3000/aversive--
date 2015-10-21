#ifndef HAL_AVR_MEGA_XX0_1_GPIO_HPP
#define HAL_AVR_MEGA_XX0_1_GPIO_HPP

#include <hal/gpio_interface.hpp>
#include <hdl/reg.hpp>

namespace HAL {

  namespace ATMegaxx0_1 {

    template<u8 ID>
    struct GPIO : ::HAL::Private::GPIO_DriverInterface {

#define MACRO_ENUM_ELEMENT(elem)                \
      static constexpr Type elem = Type::elem
      
      struct Mode : GPIO_DriverInterface::Mode {
        MACRO_ENUM_ELEMENT(INPUT);
        MACRO_ENUM_ELEMENT(OUTPUT);
      };

#undef MACRO_ENUM_ELEMENT

      //! \name Module Enable
      //! @{
      inline static bool isModuleEnabled(void) {
        return true;
      }
      
      //inline static void enableModule(void);
      //inline static void disableModule(void);
      //! @}

      //! \name Module Sleep Enable
      //! @{
      //inline static bool isModuleSleepEnabled(void);
      //inline static void enableModuleSleep(void);
      //inline static void disableModuleSleep(void);
      //! @}
        
      //! \name Settings
      //! @{
      inline static void getPinSettings(Settings&, u8 pin_number);
      inline static void setPinSettings(const Settings&, u8 pin_number);
      inline static void setPinGroupSettings(const Settings&, u32 pin_mask);
      //! @}

      //! \name Mode
      //! @{
      inline static typename Mode::Type getPinMode(u8 pin_number) {
	if(HDL::GPIO<ID>::DDR & (1 << pin_number)) {
	  return Mode::OUTPUT;
	}
	else {
	  return Mode::INPUT;
	}
      }

      inline static void setPinGroupMode(typename Mode::Type mode, u32 pin_mask) {
	if(mode == Mode::OUTPUT) {
	  HDL::GPIO<ID>::DDR |= pin_mask;
	}
	else {
	  HDL::GPIO<ID>::DDR &= ~pin_mask;
	}
      }
      
      inline static void setPinMode(typename Mode::Type mode, u8 pin_number) {
	setPinGroupMode(mode, (1 << pin_number));
      }
      //! @}

      //! \name Output Mode
      //! @{
      //inline static typename OutputMode::Type getPinOutputMode(u8 pin_number);
      //inline static void setPinOutputMode(typename OutputMode::Type, u8 pin_number);
      //inline static void setPinGroupOutputMode(typename OutputMode::Type, u32 pin_mask);
      //! @}

      //! \name Alternate Function
      //! @{
      //inline static typename Alternate::Type getPinAlternate(u8 pin_number);
      //inline static void setPinAlternate(typename Alternate::Type, u8 pin_number);
      //inline static void setPinGroupAlternate(typename Alternate::Type, u32 pin_mask);
      //! @}

      //! \name Pull policy
      //! @{
      //inline static typename Pull::Type getPinPull(u8 pin_number);
      //inline static void setPinPull(typename Pull::Type, u8 pin_number);
      //inline static void setPinGroupPull(typename Pull::Type, u32 pin_mask);
      //! @}

      //! \name Speed
      //! @{
      //inline static typename Speed::Type getPinSpeed(u8 pin_number);
      //inline static void setPinSpeed(typename Speed::Type, u8 pin_number);
      //inline static void setPinGroupSpeed(typename Speed::Type, u32 pin_mask);
      //! @}

      //! \name External Interrupt Handler
      //! @{
      //inline static IRQ_Handler getPinExtiHandler(u8 pin_number);
      //inline static void setPinExtiHandler(IRQ_Handler, u8 pin_number);
      //! @}

      //! \name Trigger Detection
      //! @{
      //inline static typename TriggerDetection::Type getPinTriggerDetection(u8 pin_number);
      //inline static void setPinTriggerDectection(typename TriggerDetection::Type, u8 pin_number);
      //! @}

      //! \name Value
      //! @{
      inline static u32 getValue(void);
      inline static void setValue(u32 value);
      template<u32 VALUE> inline static void setValue(void);

      inline static bool getPinValue(u8 pin_number);
      inline static void setPinValue(bool value, u8 pin_number);
      inline static void togglePin(u8 pin_number);

      inline static void setPinGroupValue(bool value, u32 pin_mask);
      inline static void togglePinGroup(u32 pin_mask);
      //! @}

      //! \brief Templated PinGroup interface
      template<u32 PIN_MASK>
      struct PinGroup {
        //! \name Settings
        //! @{
        inline static void setSettings(const Settings&);
        template<typename Settings> inline static void setSettings(void);
        //! @}

        //! \name Mode
        //! @{
        inline static void setMode(typename Mode::Type);
        template<typename Mode::Type> inline static void setMode(void);
        //! @}

        //! \name Output Mode
        //! @{
        //inline static void setOutputMode(typename OutputMode::Type);
        //template<typename OutputMode::Type> inline static void setOutputMode(void);
        //! @}

        //! \name Alternate Function
        //! @{
        //inline static void setAlternate(typename Alternate::Type);
        //template<typename Alternate::Type> inline static void setAlternate(void);
        //! @}

        //! \name Pull policy
        //! @{
        //inline static void setPull(typename Pull::Type);
        //template<typename Pull::Type> inline static void setPull(void);
        //! @}

        //! \name Speed
        //! @{
        //inline static void setSpeed(typename Speed::Type);
        //template<typename Speed::Type> inline static void setSpeed(void);
        //! @}

        //! \name Value
        //! @{
        inline static void setValue(bool value);
        template<bool VALUE> inline static void setValue(void);
        inline static void toggle(void);
        //! @}
      };

      //! \brief Templated Pin interface
      template<u8 PIN_NUMBER>
      struct Pin {
        //! \name Settings
        //! @{
        inline static void getSettings(Settings&);
        inline static void setSettings(const Settings&);
        template<typename Settings> inline static void setSettings(void);
        //! @}

        //! \name Mode
        //! @{
        inline static typename Mode::Type getMode(void) {
	  if(HDL::GPIO<ID>::Fields::template DDR<PIN_NUMBER>::field) {
	    return Mode::OUTPUT;
	  }
	  else {
	    return Mode::INPUT;
	  }
	}
	
        inline static void setMode(typename Mode::Type mode) {
	  HDL::GPIO<ID>::Fields::template DDR<PIN_NUMBER>::field = (mode == Mode::OUTPUT);
	}
	
        template<typename Mode::Type MODE> inline static void setMode(void) {
	  HDL::GPIO<ID>::Fields::template DDR<PIN_NUMBER>::field = (MODE == Mode::OUTPUT);
	}
        //! @}

        //! \name Output Mode
        //! @{
        //inline static typename OutputMode::Type getOutputMode(void);
        //inline static void setOutputMode(typename OutputMode::Type);
        //template<typename OutputMode::Type> inline static void setOutputMode(void);
        //! @}

        //! \name Alternate Function
        //! @{
        //inline static typename Alternate::Type getAlternate(void);
        //inline static void setAlternate(typename Alternate::Type);
        //template<typename Alternate::Type> inline static void setAlternate(void);
        //! @}

        //! \name Pull policy
        //! @{
        //inline static typename Pull::Type getPull(void);
        //inline static void setPull(typename Pull::Type);
        //template<typename Pull::Type> inline static void setPull(void);
        //! @}

        //! \name Speed
        //! @{
        //inline static typename Speed::Type getSpeed(void);
        //inline static void setSpeed(typename Speed::Type);
        //template<typename Speed::Type> inline static void setSpeed(void);
        //! @}

        //! \name External Interrupt Handler
        //! @{
        //inline static IRQ_Handler getExtiHandler(void);
        //inline static void setExtiHandler(IRQ_Handler);
        //! @}

        //! \name Trigger Detection
        //! @{
        //inline static typename TriggerDetection::Type getTriggerDetection(void);
        //inline static void setTriggerDectection(typename TriggerDetection::Type);
        //template<typename TriggerDetection::Type> inline static void setTriggerDectection(void);
        //! @}

        //! \name Value
        //! @{
        inline static bool getValue(void) {
	  return HDL::GPIO<ID>::Fields::template PIN<PIN_NUMBER>::field;
	}
	
        inline static void setValue(bool value) {
	  HDL::GPIO<ID>::Fields::template PORT<PIN_NUMBER>::field = value;
	}
	
        inline static void toggle(void) {
	  HDL::GPIO<ID>::Fields::template PORT<PIN_NUMBER>::field =
	    ~HDL::GPIO<ID>::Fields::template PIN<PIN_NUMBER>::field;
	}
	
        template<bool VALUE> inline static void setValue(void) {
	  HDL::GPIO<ID>::Fields::template PORT<PIN_NUMBER>::field = VALUE;
	}
        //! @}

      };
    };

    using GPIO_A = GPIO<0>;
    using GPIO_B = GPIO<1>;
    using GPIO_C = GPIO<2>;
    using GPIO_D = GPIO<3>;
    using GPIO_E = GPIO<4>;
    using GPIO_F = GPIO<5>;
    using GPIO_G = GPIO<6>;
    using GPIO_H = GPIO<7>;
    using GPIO_I = GPIO<8>;
    using GPIO_J = GPIO<9>;
    using GPIO_K = GPIO<10>;
    using GPIO_L = GPIO<11>;
  }
}

namespace HAL {
  using namespace ATMegaxx0_1;
}

#endif//HAL_AVR_MEGA_XX0_1_GPIO_HPP
