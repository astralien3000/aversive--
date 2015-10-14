#ifdef OP

template<typename RegType, typename Group> template<typename OtherRegType, typename OtherGroup, RegType MASK>
inline const RegType Register<RegType, Group>::operator OP(const Config<OtherRegType, OtherGroup, MASK>& ) const {
  static_assert(!sizeof(RegType) && sizeof(RegType), "Incompatibles Register and Config");
  return 0;
}

template<typename RegType, typename Group> template<RegType MASK>
inline const RegType Register<RegType, Group>::operator OP(const Config<RegType, Group, MASK>& cfg) const {
  return *(volatile RegType*)ADDRESS OP cfg.VALUE;
}

template<typename RegType, typename Group> template<typename OtherRegType, typename OtherGroup>
inline const RegType Register<RegType, Group>::operator OP(const Register<OtherRegType, OtherGroup>& ) const {
  static_assert(!sizeof(RegType) && sizeof(RegType), "Incompatibles Registers");
  return 0;
}

template<typename RegType, typename Group>
inline const RegType Register<RegType, Group>::operator OP(const Register<RegType, Group>& reg) const {
  return *(volatile RegType*)ADDRESS OP *(volatile RegType*)reg.ADDRESS;
}

template<typename RegType, typename Group>
inline const RegType Register<RegType, Group>::operator OP(const RegType val) const {
  return *(volatile RegType*)ADDRESS OP val;
}

#endif
