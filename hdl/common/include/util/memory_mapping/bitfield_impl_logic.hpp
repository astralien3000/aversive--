#ifdef OP

template<typename RegType, typename Group, int BITNUM>
inline bool BitField<RegType, Group, BITNUM>::operator OP(const Config<RegType, Group, (1<<BITNUM)>& cfg) const {
  return ((bool)*this) OP cfg;
}

template<typename RegType, typename Group, int BITNUM> template<int OTHER_BITNUM>
inline bool BitField<RegType, Group, BITNUM>::operator OP(const BitField<RegType, Group, OTHER_BITNUM>& bf) const {
  return ((bool)*this) OP ((bool)bf);
}

template<typename RegType, typename Group, int BITNUM>
inline bool BitField<RegType, Group, BITNUM>::operator OP(const bool val) const {
  return ((bool)*this) OP val;
}

#endif
