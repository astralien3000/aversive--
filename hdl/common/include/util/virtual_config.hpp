#ifndef VIRTUAL_CONFIG_HPP
#define VIRTUAL_CONFIG_HPP

#include "memory_mapping.hpp"
#include <base/static_list.hpp>

namespace MemoryMapping {

  //! \brief This class is the equivalent of Config class associated with Field, but for VirtualField class
  /*!
   * Basically, it is a list of Config objects.
   */
  template<typename Config, typename ... Next>
  struct VirtualConfig {
  public:
    //! \brief The list of configs
    const StaticList<const Config, const Next...> CONFIGS;
    
  public:
    //! \brief Constructor
    //! \param config : The first Config of the list 
    //! \param next : The remaining configs of the list
    constexpr VirtualConfig(const Config config, const Next... next)
      : CONFIGS(config, next...) {
    }

  };
    
  //! \brief This is a helper function that enables the developper to use auto keyword
  /*!
   * VirtualConfig type can be long to write ! Why not use auto instead of loosing your time ?
   *
   * Example : 
   *        
   *        // Create groups
   *        struct G1;
   *        struct G2;   
   *        
   *        // Create registers
   *        static constexpr Register8<G1> REG1 = 0x0001;
   *        static constexpr Register8<G2> REG2 = 0x0002;
   *        
   *        // Create fields
   *        static constexpr Field8<G1, 0b0011> FIELD1 = REG1;
   *        static constexpr Field8<G2, 0b1100> FIELD2 = REG2;
   *        
   *        // Create virtual_fields
   *        static constexpr auto VFIELD = make_virtual_field(FIELD1, FIELD2);
   * 
   *        // Create configs
   *        static constexpr auto CONFIG1 = make_config(FIELD1, 0b11);
   *        static constexpr auto CONFIG2 = make_config(FIELD2, 0b11);
   *        
   *        // Create virtual_configs
   *        static constexpr auto VCONFIG = make_virtual_config(CONFIG1, CONFIG2);
   * 
   *        [...]
   *        
   *        VFIELD = VCONFIG;
   * 
   */
  template<typename Config, typename ... Next>
  constexpr VirtualConfig<Config, Next...> make_virtual_config(const Config config, const Next... next) {
    return VirtualConfig<Config, Next...>(config, next...);
  }
  
}

#endif//VIRTUAL_CONFIG_HPP
