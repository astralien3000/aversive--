#ifdef OP

template<typename RegType, typename Group, RegType MASK>
inline const RegType Field<RegType, Group, MASK>::operator OP(const Config<RegType, Group, MASK>& cfg) const {
  return REGISTER OP cfg.VALUE;
}

template<typename RegType, typename Group, RegType MASK>
inline const RegType Field<RegType, Group, MASK>::operator OP(const Field<RegType, Group, MASK>& field) const {
  return REGISTER OP field.REGISTER;
}

template<typename RegType, typename Group, RegType MASK>
inline const RegType Field<RegType, Group, MASK>::operator OP(const RegType val) const {
  return REGISTER OP make_config(*this, val);
}

#endif
