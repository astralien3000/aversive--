#ifdef OP

//! \brief Assignment operator for an incompatible Config object
/*!
 * This function is here to display a human readable message when
 * the user tries to operate with a Register and a Config 
 * that are not compatibles.
 */
template<typename OtherRegType, typename OtherGroup, RegType MASK> const Register& operator OP(const Config<OtherRegType, OtherGroup, MASK>& cfg) const;

//! \brief Assignment operator for a Config object
template<RegType MASK> const Register& operator OP(const Config<RegType, Group, MASK>& cfg) const;

//! \brief Assignment operator for an incompatible Register
/*!
 * This function is here to display a human readable message when
 * the user tries to operate with Registers that are not compatibles.
 */
template<typename OtherRegType, typename OtherGroup> const Register& operator OP(const Register<OtherRegType, OtherGroup>& reg) const;

//! \brief Assignment operator for an other Register
const Register& operator OP(const Register<RegType, Group>& reg) const;

//! \brief Assignment operator for an integer value
const Register& operator OP(const RegType val) const;

#endif
