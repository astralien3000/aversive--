#ifndef VIRTUAL_FIELD_HPP
#define VIRTUAL_FIELD_HPP

#include "memory_mapping.hpp"
#include <base/static_list.hpp>

namespace MemoryMapping {

  namespace Private {    
    struct VirtualFieldAssignVisitor {
      template<typename T1, typename T2>
      void visit(T1 left, T2 right) const {
	left = right;
      }
    };
    struct VirtualFieldIsEqualVisitor {
      bool res = true;
      template<typename T1, typename T2>
      void visit(T1 left, T2 right) {
	res &= (left == right);
      }
    };
  }
  
  //! \brief This class represents a "meta" Field that is splitted between several Registers
  /*!
   * It is quite common to find this case in AVR MCUs. To enable the user to handle a field as one entity, 
   * the developpers has to create several separated Fields (one for each Register that contains a part of the field),
   * and then, create a VirtualField, that is basically a list of fields.
   */
  template<typename Field, typename ... Next>
  struct VirtualField {
  public:
    //! \brief The list of fields
    const StaticList<const Field, const Next...> FIELDS;
    
  public:
    //! \brief Constructor
    //! \param field : The first Field of the list 
    //! \param next : The remaining fields of the list
    constexpr VirtualField(const Field field, const Next... next)
      : FIELDS(field, next...) {
    }

    //! \brief Assignment operation between two VirtualFields
    //! \warning The fields need to be compatible to perform this operation
    template<typename... Fields>
    inline const VirtualField& operator=(const VirtualField<Fields...>& field) const {
      const Private::VirtualFieldAssignVisitor visitor;
      pair_static_list_foreach(FIELDS, field.FIELDS, visitor);
      return *this;
    }

    //! \brief Assignment operation between a VirtualFields and a VirtualConfig
    //! \warning The fields and configs need to be compatible to perform this operation
    template<typename... Configs>
    inline const VirtualField& operator=(const VirtualConfig<Configs...>& config) const {
      const Private::VirtualFieldAssignVisitor visitor;
      pair_static_list_foreach(FIELDS, config.CONFIGS, visitor);
      return *this;
    }

#define MACRO_DEFINE_COMPAR(op)						\
    template<typename... Fields>					\
    inline bool operator op(const VirtualField<Fields...>& other) const { \
      Private::VirtualFieldIsEqualVisitor visitor;			\
      pair_static_list_foreach(FIELDS, other.FIELDS, visitor);		\
      return visitor.res op true;					\
    }									\
    template<typename... Configs>					\
    inline bool operator op(const VirtualConfig<Configs...>& cfg) const { \
      Private::VirtualFieldIsEqualVisitor visitor;			\
      pair_static_list_foreach(FIELDS, cfg.CONFIGS, visitor);		\
      return visitor.res op true;					\
    }									\

    MACRO_DEFINE_COMPAR(==);
    MACRO_DEFINE_COMPAR(!=);
    
#undef MACRO_DEFINE_COMPAR

  };

  //! \brief This is a helper function that enables the developper to use auto keyword
  /*!
   * VirtualField type can be long to write ! Why not use auto instead of loosing your time ?
   * Please, see MemoryMapping::make_virtual_config's documentation to see a full example.
   */
  template<typename Field, typename ... Next>
  constexpr VirtualField<Field, Next...> make_virtual_field(const Field field, const Next... next) {
    return VirtualField<Field, Next...>(field, next...);
  }
  
}

#endif//VIRTUAL_FIELD_HPP
