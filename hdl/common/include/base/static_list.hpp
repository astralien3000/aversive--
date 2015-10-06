#ifndef STATIC_LIST_HPP
#define STATIC_LIST_HPP

#include "pair.hpp"

template<typename First, typename... Next>
struct StaticList {
  First first;
  StaticList<Next...> next;

  constexpr StaticList(First _first, Next... _next)
    : first(_first), next(_next...) {
  }

  constexpr StaticList(First _first, StaticList<Next...> _next)
    : first(_first), next(_next) {
  }
};

template<typename First>
struct StaticList<First> {
  First first;

  constexpr StaticList(First _first)
    : first(_first) {
  }
};


template<typename First, typename... Next>
constexpr StaticList<First, Next...> make_static_list(First first, Next... next) {
  return StaticList<First, Next...>(first, next...);
}

template<typename First, typename... Next>
constexpr StaticList<First, Next...> make_static_list(First first, StaticList<Next...> next) {
  return StaticList<First, Next...>(first, next);
}

template<typename Visitor, typename List>
void static_list_foreach(const List& list, const Visitor& visitor) {
  visitor.visit(list.first);
  static_list_foreach(list.next, visitor);
}

template<typename Visitor, typename First>
void static_list_foreach(const StaticList<First>& list, const Visitor& visitor) {
  visitor.visit(list.first);
}

template<typename Visitor, typename List1, typename List2>
void pair_static_list_foreach(const List1& list1, const List2& list2, const Visitor& visitor) {
  visitor.visit(list1.first, list2.first);
  pair_static_list_foreach(list1.next, list2.next, visitor);
}

template<typename Visitor, typename First1, typename First2>
void pair_static_list_foreach(const StaticList<First1>& list1, const StaticList<First2>& list2, const Visitor& visitor) {
  visitor.visit(list1.first, list2.first);
}

template<typename List1, typename List2>
constexpr auto static_list_fusion(const List1& list1, const List2& list2) -> decltype(make_static_list(Pair<const decltype(List1::first), const decltype(List2::first)>(list1.first, list2.first), static_list_fusion(list1.next, list2.next))) {
  return make_static_list<Pair<const decltype(List1::first), const decltype(List2::first)>>(Pair<const decltype(List1::first), const decltype(List2::first)>(list1.first, list2.first), static_list_fusion(list1.next, list2.next));
}

template<typename First1, typename First2>
constexpr StaticList<Pair<const First1, const First2>> static_list_fusion(const StaticList<First1>& list1, const StaticList<First2>& list2) {
  return make_static_list(Pair<const First1, const First2>(list1.first, list2.first));
}

#endif//STATIC_LIST_HPP
