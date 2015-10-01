#ifdef OP

const Field& operator OP(const Config<RegType, Group, MASK>& cfg) const;
const Field& operator OP(const Field<RegType, Group, MASK>& field) const;
const Field& operator OP(const RegType val) const;

#endif
