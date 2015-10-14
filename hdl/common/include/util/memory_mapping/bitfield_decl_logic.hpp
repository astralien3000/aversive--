#ifdef OP

//! \brief Logic operator with a Config object
bool operator OP(const Config<RegType, Group, (1<<BITNUM)>& cfg) const;

//! \brief Logic operator with an other BitField
/*!
 * Unlike the other classes, BitFields can be used with any other BitField,
 * because a boolean is a boolean !
 */
template<typename OtherRegType, typename OtherGroup, int OTHER_BITNUM> bool operator OP(const BitField<OtherRegType, OtherGroup, OTHER_BITNUM>& bf) const;

//! \brief Logic operator with a bool value
bool operator OP(const bool val) const;

#endif
