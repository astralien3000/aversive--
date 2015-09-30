#ifdef OP

template<typename RegType, typename Group> template<RegType MASK>
inline const Register<RegType, Group>& Register<RegType, Group>::operator OP(const Config<RegType, Group, MASK>& cfg) const {
  *(RegType*)ADDRESS OP cfg.VALUE;
  return *this;
}

template<typename RegType, typename Group>
inline const Register<RegType, Group>& Register<RegType, Group>::operator OP(const Register<RegType, Group>& reg) const {
  *(RegType*)ADDRESS OP *(RegType*)reg.ADDRESS;
  return *this;
}

template<typename RegType, typename Group>
inline const Register<RegType, Group>& Register<RegType, Group>::operator OP(const RegType val) const {
  *(RegType*)ADDRESS OP val;
  return *this;
}

#endif
