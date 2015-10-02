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

template<typename Visitor, typename First, typename... Next>
void static_list_foreach(const StaticList<First, Next...>& list, const Visitor& visitor) {
  visitor.visit(list.first);
  static_list_foreach(list.next, visitor);
}

template<typename Visitor, typename First>
void static_list_foreach(const StaticList<First>& list, const Visitor& visitor) {
  visitor.visit(list.first);
}

template<typename List, typename First, typename... Next>
constexpr auto static_list_fusion(const StaticList<First, Next...>& list1, const List& list2) -> decltype(make_static_list(Pair<const First, const decltype(List::first)>(list1.first, list2.first), static_list_fusion(list1.next, list2.next))) {
  return make_static_list<Pair<const First, const decltype(List::first)>>(Pair<const First, const decltype(List::first)>(list1.first, list2.first), static_list_fusion(list1.next, list2.next));
}

template<typename List, typename First>
constexpr StaticList<Pair<const First, const decltype(List::first)>> static_list_fusion(const StaticList<First>& list1, const List& list2) {
  return make_static_list(Pair<const First, const decltype(List::first)>(list1.first, list2.first));
}

#endif//STATIC_LIST_HPP
