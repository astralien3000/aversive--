#ifdef OP

//! \brief Arithmetic operator with an incompatible Config
template<typename OtherRegType, typename OtherGroup, OtherRegType OTHER_MASK> constexpr Config<RegType, Group, MASK | OTHER_MASK> operator OP(const Config<OtherRegType, OtherGroup, OTHER_MASK>& cfg) const;

//! \brief Arithmetic operator with an other Config
template<RegType OTHER_MASK> constexpr Config<RegType, Group, MASK | OTHER_MASK> operator OP(const Config<RegType, Group, OTHER_MASK>& cfg) const;

//! \brief Arithmetic operator with an incompatible Register
template<typename OtherRegType, typename OtherGroup> constexpr RegType operator OP(const Register<OtherRegType, OtherGroup>& reg) const;

//! \brief Arithmetic operator with a Register object
constexpr RegType operator OP(const Register<RegType, Group>& reg) const;

//! \brief Arithmetic operator with an integer value
constexpr RegType operator OP(const RegType val) const;

#endif
