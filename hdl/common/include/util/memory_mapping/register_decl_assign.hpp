#ifdef OP

template<RegType MASK> const Register& operator OP(const Config<RegType, Group, MASK>& cfg) const;
const Register& operator OP(const Register<RegType, Group>& reg) const;
const Register& operator OP(const RegType val) const;

#endif
