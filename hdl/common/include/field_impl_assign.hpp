#ifdef OP

template<typename RegType, typename Group, RegType MASK>
inline const Field<RegType, Group, MASK>& Field<RegType, Group, MASK>::operator OP(const Config<RegType, Group, MASK>& cfg) const {
  REGISTER OP cfg.VALUE;
  return *this;
}


template<typename RegType, typename Group, RegType MASK>
inline const Field<RegType, Group, MASK>& Field<RegType, Group, MASK>::operator OP(const Field<RegType, Group, MASK>& field) const {
  REGISTER = field.REGISTER;
  return *this;
}

template<typename RegType, typename Group, RegType MASK>
inline const Field<RegType, Group, MASK>& Field<RegType, Group, MASK>::operator OP(const RegType val) const {
  REGISTER OP make_config(*this, val);
  return *this;
}

#endif
