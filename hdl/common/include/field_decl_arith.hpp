#ifdef OP

const RegType operator OP(const Config<RegType, Group, MASK>& cfg) const;
const RegType operator OP(const Field<RegType, Group, MASK>& field) const;
const RegType operator OP(const RegType val) const;

#endif
