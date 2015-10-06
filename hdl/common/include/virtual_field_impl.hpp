#ifndef VIRTUAL_FIELD_IMPL_HPP
#define VIRTUAL_FIELD_IMPL_HPP

#include "memory_mapping.hpp"

namespace MemoryMapping {

  template<typename Field, typename ... Next>
  inline constexpr VirtualField<Field,Next...>::VirtualField(const Field field, const Next... next)
    : FIELDS(field, next...) {
  }

  namespace Private {    
    struct VirtualFieldAssignVisitor {
      template<typename T1, typename T2>
      void visit(T1 left, T2 right) const {
	left = right;
	//var = 0;
      }
    };
  }

  template<typename Field, typename... Next>
  inline const VirtualField<Field, Next...>& VirtualField<Field, Next...>::operator=(const VirtualField<Field, Next...>& field) const {
    pair_static_list_foreach(FIELDS, field.FIELDS, Private::VirtualFieldAssignVisitor());
    return *this;
  }

  template<typename Field, typename... Next> template<typename... Configs>
  inline const VirtualField<Field, Next...>& VirtualField<Field, Next...>::operator=(const VirtualConfig<Configs...>& config) const {
    pair_static_list_foreach(FIELDS, config.CONFIGS, Private::VirtualFieldAssignVisitor());
    return *this;
  }
  
  template<typename Field, typename ... Next>
  constexpr VirtualField<Field, Next...> make_virtual_field(const Field field, const Next... next) {
    return VirtualField<Field, Next...>(field, next...);
  }
    
}

#endif//VIRTUAL_FIELD_IMPL_HPP
