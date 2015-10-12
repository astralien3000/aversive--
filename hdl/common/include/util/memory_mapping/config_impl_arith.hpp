#ifdef OP


template<typename RegType, typename Group, RegType MASK> template<typename OtherRegType, typename OtherGroup, OtherRegType OTHER_MASK>
inline constexpr Config<RegType, Group, MASK | OTHER_MASK> Config<RegType, Group, MASK>::operator OP(const Config<OtherRegType, OtherGroup, OTHER_MASK>& ) const {
  static_assert(!sizeof(RegType) && sizeof(RegType), "Incompatibles Configs");
}

template<typename RegType, typename Group, RegType MASK> template<RegType OTHER_MASK>
inline constexpr Config<RegType, Group, MASK | OTHER_MASK> Config<RegType, Group, MASK>::operator OP(const Config<RegType, Group, OTHER_MASK>& cfg) const {
  return Config<RegType, Group, MASK | OTHER_MASK>(VALUE OP cfg.VALUE);
}

template<typename RegType, typename Group, RegType MASK> template<typename OtherRegType, typename OtherGroup>
inline constexpr RegType Config<RegType, Group, MASK>::operator OP(const Register<OtherRegType, OtherGroup>& ) const {
  static_assert(!sizeof(RegType) && sizeof(RegType), "Incompatibles Register and Config");
}

template<typename RegType, typename Group, RegType MASK>
inline constexpr RegType Config<RegType, Group, MASK>::operator OP(const Register<RegType, Group>& reg) const {
  return VALUE OP *reg.ADDRESS;
}

template<typename RegType, typename Group, RegType MASK>
inline constexpr RegType Config<RegType, Group, MASK>::operator OP(const RegType val) const {
  return VALUE OP val;
}

#endif
