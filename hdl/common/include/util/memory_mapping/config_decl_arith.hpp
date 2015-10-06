#ifdef OP

template<RegType OTHER_MASK> const Config<RegType, Group, MASK | OTHER_MASK> operator OP(const Config<RegType, Group, OTHER_MASK>& cfg) const;
const RegType operator OP(const Register<RegType, Group>& reg) const;
const RegType operator OP(const RegType val) const;

#endif
