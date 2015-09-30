#ifdef OP

bool operator OP(const Config<RegType, Group, (1<<BITNUM)>& cfg) const;
template<int OTHER_BITNUM> bool operator OP(const BitField<RegType, Group, OTHER_BITNUM>& bf) const;
bool operator OP(const bool val) const;

#endif
