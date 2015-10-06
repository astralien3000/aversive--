#ifdef OP

template<RegType MASK> const RegType operator OP(const Config<RegType, Group, MASK>& cfg) const;
const RegType operator OP(const Register<RegType, Group>& reg) const;
const RegType operator OP(const RegType val) const;

#endif
