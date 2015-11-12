#ifndef BASE_TYPE_TRAITS_HPP
#define BASE_TYPE_TRAITS_HPP

template<typename T> struct RemoveConst { using Type = T; };
template<typename T> struct RemoveConst<const T> { using Type = T; };

template<typename T> struct RemoveRef { using Type = T; };
template<typename T> struct RemoveRef<T&> { using Type = T; };
template<typename T> struct RemoveRef<T&&> { using Type = T; };

#endif//BASE_TYPE_TRAITS_HPP
