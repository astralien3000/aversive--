#ifndef VIRTUAL_CONFIG_HPP
#define VIRTUAL_CONFIG_HPP

#include "memory_mapping.hpp"
#include "static_list.hpp"

namespace MemoryMapping {

  template<typename Config, typename ... Next>
  struct VirtualConfig {
  public:
    const StaticList<const Config, const Next...> CONFIGS;
    
  public:
    constexpr VirtualConfig(const Config config, const Next... next);

  };
    
  template<typename Config, typename ... Next>
  constexpr VirtualConfig<Config, Next...> make_virtual_config(const Config config, const Next... next);
  
}

#endif//VIRTUAL_CONFIG_HPP
