#ifndef VIRTUAL_CONFIG_IMPL_HPP
#define VIRTUAL_CONFIG_IMPL_HPP

namespace MemoryMapping {

  template<typename Config, typename ... Next>
  inline constexpr VirtualConfig<Config,Next...>::VirtualConfig(const Config config, const Next... next)
    : CONFIGS(config, next...) {
  }

  template<typename Config, typename ... Next>
  constexpr VirtualConfig<Config, Next...> make_virtual_config(const Config config, const Next... next) {
    return VirtualConfig<Config, Next...>(config, next...);
  }
    
}

#endif//VIRTUAL_CONFIG_IMPL_HPP
