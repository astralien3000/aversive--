#ifndef VIRTUAL_FIELD_HPP
#define VIRTUAL_FIELD_HPP

#include "memory_mapping.hpp"
#include "static_list.hpp"

namespace MemoryMapping {

  template<typename Field, typename ... Next>
  struct VirtualField {
  public:
    const StaticList<const Field, const Next...> FIELDS;
    
  public:
    constexpr VirtualField(const Field field, const Next... next);

    inline const VirtualField& operator=(const VirtualField& field) const;

    template<typename... Configs>
    inline const VirtualField& operator=(const VirtualConfig<Configs...>& field) const;
};
  
  template<typename Field, typename ... Next>
  constexpr VirtualField<Field, Next...> make_virtual_field(const Field field, const Next... next);
  
}

#endif//VIRTUAL_FIELD_HPP
