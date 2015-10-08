#ifdef OP

//! \brief Arithmetic operator with an incompatible Config object
/*!
 * This function is here to display a human readable message when
 * the user tries to operate with a Register and a Config 
 * that are not compatibles.
 */
template<typename OtherRegType, typename OtherGroup, RegType MASK> const RegType operator OP(const Config<OtherRegType, OtherGroup, MASK>& cfg) const;

//! \brief Arithmetic operator with a Config object
template<RegType MASK> const RegType operator OP(const Config<RegType, Group, MASK>& cfg) const;

//! \brief Arithmetic operator with an incompatible Register
/*!
 * This function is here to display a human readable message when
 * the user tries to operate with Registers that are not compatibles.
 */
template<typename OtherRegType, typename OtherGroup>
const RegType operator OP(const Register<OtherRegType, OtherGroup>& reg) const;

//! \brief Arithmetic operator with an other Register
const RegType operator OP(const Register<RegType, Group>& reg) const;

//! \brief Arithmetic operator with an integer value
const RegType operator OP(const RegType val) const;

#endif
