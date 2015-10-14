#ifndef VIRTUAL_FIELD_HPP
#define VIRTUAL_FIELD_HPP

#include <base/static_list.hpp>

namespace MemoryMapping {

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
    constexpr VirtualField(const Field field, const Next... next);

    //! \brief Assignment operation between two VirtualFields
    //! \warning The fields need to be compatible to perform this operation
    template<typename... Fields>
    inline const VirtualField& operator=(const VirtualField<Fields...>& field) const;

    //! \brief Assignment operation between a VirtualFields and a VirtualConfig
    //! \warning The fields and configs need to be compatible to perform this operation
    template<typename... Configs>
    inline const VirtualField& operator=(const VirtualConfig<Configs...>& config) const;
};

  //! \brief This is a helper function that enables the developper to use auto keyword
  /*!
   * VirtualField type can be long to write ! Why not use auto instead of loosing your time ?
   * Please, see MemoryMapping::make_virtual_config's documentation to see a full example.
   */
  template<typename Field, typename ... Next>
  constexpr VirtualField<Field, Next...> make_virtual_field(const Field field, const Next... next);
  
}

#endif//VIRTUAL_FIELD_HPP
