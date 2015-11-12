#ifndef AVERSIVE_BASE_COMPIL_HPP
#define AVERSIVE_BASE_COMPIL_HPP

#include <base/type_traits.hpp>

template<typename T, T VAL>
struct Compil {
  constexpr inline operator T() { return VAL; }
};

#define _AVERSIVE_DEFINE_COMPIL_OPERATOR(op)				\
  template<typename T1, typename T2, T1 VAL1, T2 VAL2>			\
  constexpr inline Compil<T1, (VAL1 op VAL2)>				\
  operator op(const Compil<T1, VAL1>, const Compil<T2, VAL2>) {		\
    return Compil<T1, (VAL1 op VAL2)>();				\
  }									\

_AVERSIVE_DEFINE_COMPIL_OPERATOR(+);
_AVERSIVE_DEFINE_COMPIL_OPERATOR(-);
_AVERSIVE_DEFINE_COMPIL_OPERATOR(*);
_AVERSIVE_DEFINE_COMPIL_OPERATOR(/);
_AVERSIVE_DEFINE_COMPIL_OPERATOR(%);

_AVERSIVE_DEFINE_COMPIL_OPERATOR(&);
_AVERSIVE_DEFINE_COMPIL_OPERATOR(|);
_AVERSIVE_DEFINE_COMPIL_OPERATOR(^);
_AVERSIVE_DEFINE_COMPIL_OPERATOR(&&);
_AVERSIVE_DEFINE_COMPIL_OPERATOR(||);

_AVERSIVE_DEFINE_COMPIL_OPERATOR(<<);
_AVERSIVE_DEFINE_COMPIL_OPERATOR(>>);

_AVERSIVE_DEFINE_COMPIL_OPERATOR(==);
_AVERSIVE_DEFINE_COMPIL_OPERATOR(!=);
_AVERSIVE_DEFINE_COMPIL_OPERATOR(<=);
_AVERSIVE_DEFINE_COMPIL_OPERATOR(>=);
_AVERSIVE_DEFINE_COMPIL_OPERATOR(<);
_AVERSIVE_DEFINE_COMPIL_OPERATOR(>);

#undef _AVERSIVE_DEFINE_COMPIL_OPERATOR

#define _AVERSIVE_DEFINE_COMPIL_UNARY_OPERATOR(op)	\
  template<typename T, T VAL>				\
  constexpr inline Compil<T, (op VAL)>			\
  operator op(const Compil<T, VAL>) {			\
    return Compil<T, (op VAL)>();			\
  }							\

_AVERSIVE_DEFINE_COMPIL_UNARY_OPERATOR(+);
_AVERSIVE_DEFINE_COMPIL_UNARY_OPERATOR(-);
_AVERSIVE_DEFINE_COMPIL_UNARY_OPERATOR(~);
_AVERSIVE_DEFINE_COMPIL_UNARY_OPERATOR(!);

#undef _AVERSIVE_DEFINE_COMPIL_UNARY_OPERATOR

template<typename T> struct RemoveCompil { using Type = T; };
template<typename T, T VAL> struct RemoveCompil<Compil<T, VAL>> { using Type = T; };

template<typename T> struct SecureCompil {
  using Type =
    typename RemoveCompil<
      typename RemoveRef<
	typename RemoveConst<
	  T
	>::Type
      >::Type
    >::Type;
};

#define COMPIL(i)							\
  Compil<SecureCompil<decltype(i)>::Type, (SecureCompil<decltype(i)>::Type)i>()

#endif//AVERSIVE_BASE_COMPIL_HPP
