#ifdef OP

template<typename RegType, typename Group, RegType MASK> template<RegType OTHER_MASK>
inline const Config<RegType, Group, MASK | OTHER_MASK> Config<RegType, Group, MASK>::operator OP(const Config<RegType, Group, OTHER_MASK>& cfg) const {
  return Config<RegType, Group, MASK>(VALUE OP cfg.VALUE);
}

template<typename RegType, typename Group, RegType MASK>
inline const RegType Config<RegType, Group, MASK>::operator OP(const Register<RegType, Group>& reg) const {
  return VALUE OP *reg.ADDRESS;
}

template<typename RegType, typename Group, RegType MASK>
inline const RegType Config<RegType, Group, MASK>::operator OP(const RegType val) const {
  return VALUE OP val;
}

#endif
