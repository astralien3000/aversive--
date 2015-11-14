#ifndef AVERSIVE_BASE_COMPIL_HPP
#define AVERSIVE_BASE_COMPIL_HPP

#include <base/literal_parser.hpp>
#include <base/type_traits.hpp>

template<typename T, T VAL>
struct Compil {
  constexpr inline operator T() { return VAL; }
};

#define AVERSIVE_DEFINE_COMPIL_OPERATOR(op)				\
  template<typename T1, typename T2, T1 VAL1, T2 VAL2>			\
  constexpr inline Compil<T1, (VAL1 op VAL2)>				\
  operator op(const Compil<T1, VAL1>, const Compil<T2, VAL2>) {		\
    return Compil<T1, (VAL1 op VAL2)>();				\
  }									\

AVERSIVE_DEFINE_COMPIL_OPERATOR(+);
AVERSIVE_DEFINE_COMPIL_OPERATOR(-);
AVERSIVE_DEFINE_COMPIL_OPERATOR(*);
AVERSIVE_DEFINE_COMPIL_OPERATOR(/);
AVERSIVE_DEFINE_COMPIL_OPERATOR(%);

AVERSIVE_DEFINE_COMPIL_OPERATOR(&);
AVERSIVE_DEFINE_COMPIL_OPERATOR(|);
AVERSIVE_DEFINE_COMPIL_OPERATOR(^);
AVERSIVE_DEFINE_COMPIL_OPERATOR(&&);
AVERSIVE_DEFINE_COMPIL_OPERATOR(||);

AVERSIVE_DEFINE_COMPIL_OPERATOR(<<);
AVERSIVE_DEFINE_COMPIL_OPERATOR(>>);

AVERSIVE_DEFINE_COMPIL_OPERATOR(==);
AVERSIVE_DEFINE_COMPIL_OPERATOR(!=);
AVERSIVE_DEFINE_COMPIL_OPERATOR(<=);
AVERSIVE_DEFINE_COMPIL_OPERATOR(>=);
AVERSIVE_DEFINE_COMPIL_OPERATOR(<);
AVERSIVE_DEFINE_COMPIL_OPERATOR(>);

#undef AVERSIVE_DEFINE_COMPIL_OPERATOR

#define AVERSIVE_DEFINE_COMPIL_UNARY_OPERATOR(op)	\
  template<typename T, T VAL>				\
  constexpr inline Compil<T, (op VAL)>			\
  operator op(const Compil<T, VAL>) {			\
    return Compil<T, (op VAL)>();			\
  }							\

AVERSIVE_DEFINE_COMPIL_UNARY_OPERATOR(+);
AVERSIVE_DEFINE_COMPIL_UNARY_OPERATOR(-);
AVERSIVE_DEFINE_COMPIL_UNARY_OPERATOR(~);
AVERSIVE_DEFINE_COMPIL_UNARY_OPERATOR(!);

#undef AVERSIVE_DEFINE_COMPIL_UNARY_OPERATOR

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
  Compil<typename SecureCompil<decltype(i)>::Type, (typename SecureCompil<decltype(i)>::Type)i>()

#define AVERSIVE_DEFINE_COMPIL_LITERAL(type, name)			\
  template<char...ARGS>							\
  Compil<type, LiteralParser::Parser<LiteralParser::BEG, type, 0, ARGS...>::VALUE> \
  operator ""_##name() {						\
    return Compil<type, LiteralParser::Parser<LiteralParser::BEG, type, 0, ARGS...>::VALUE>(); \
  }

AVERSIVE_DEFINE_COMPIL_LITERAL(u8 , cu8 )
AVERSIVE_DEFINE_COMPIL_LITERAL(u16, cu16)
AVERSIVE_DEFINE_COMPIL_LITERAL(u32, cu32)
AVERSIVE_DEFINE_COMPIL_LITERAL(u64, cu64)

AVERSIVE_DEFINE_COMPIL_LITERAL(s8 , cs8 )
AVERSIVE_DEFINE_COMPIL_LITERAL(s16, cs16)
AVERSIVE_DEFINE_COMPIL_LITERAL(s32, cs32)
AVERSIVE_DEFINE_COMPIL_LITERAL(s64, cs64)

AVERSIVE_DEFINE_COMPIL_LITERAL(usys, cusys)

AVERSIVE_DEFINE_COMPIL_LITERAL(int, c)

#undef AVERSIVE_DEFINE_COMPIL_LITERAL


#endif//AVERSIVE_BASE_COMPIL_HPP
