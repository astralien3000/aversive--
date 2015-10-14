#ifndef FIELD_IMPL_HPP
#define FIELD_IMPL_HPP

namespace MemoryMapping {

  template<typename RegType, typename Group, RegType MASK>
  inline constexpr Field<RegType, Group, MASK>::Field(const Register<RegType, Group> reg)
    : REGISTER(reg) {
  }

  // Assignment
  template<typename RegType, typename Group, RegType MASK> template<typename OtherRegType, typename OtherGroup, OtherRegType OTHER_MASK>
  inline const Field<RegType, Group, MASK>& Field<RegType, Group, MASK>::operator=(const Config<OtherRegType, OtherGroup, OTHER_MASK>& cfg) const {
    static_assert(!sizeof(RegType) && sizeof(RegType), "Incompatible Field and Config");
    return *this;
  }

  template<typename RegType, typename Group, RegType MASK>
  inline const Field<RegType, Group, MASK>& Field<RegType, Group, MASK>::operator=(const Config<RegType, Group, MASK>& cfg) const {
    REGISTER = (REGISTER & (RegType)(~MASK)) | cfg.VALUE;
    return *this;
  }


  template<typename RegType, typename Group, RegType MASK> template<typename OtherRegType, typename OtherGroup, OtherRegType OTHER_MASK>
  inline const Field<RegType, Group, MASK>& Field<RegType, Group, MASK>::operator=(const Field<OtherRegType, OtherGroup, OTHER_MASK>& field) const {
    static_assert(!sizeof(RegType) && sizeof(RegType), "Incompatible Fields");
    return *this;
  }


  template<typename RegType, typename Group, RegType MASK>
  inline const Field<RegType, Group, MASK>& Field<RegType, Group, MASK>::operator=(const Field<RegType, Group, MASK>& field) const {
    REGISTER = (REGISTER & (RegType)(~MASK)) | (field.REGISTER & MASK);
    return *this;
  }


  template<typename RegType, typename Group, RegType MASK>
  inline const Field<RegType, Group, MASK>& Field<RegType, Group, MASK>::operator=(const RegType val) const {
    (*this) = make_config(*this, val);
    return *this;
  }
}

#endif//FIELD_IMPL_HPP
