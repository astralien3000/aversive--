#ifndef STATIC_CONTAINER_HPP
#define STATIC_CONTAINER_HPP

#include "type_list.hpp"

template<typename T1, typename... TArgs>
struct StaticContainer {
  typedef TypeList<T1, TArgs...> Types;
  typedef StaticContainer<TArgs...> NextContainer;
  T1 elem;
  StaticContainer<TArgs...> next;
};

template<typename T1>
struct StaticContainer<T1> {
  typedef TypeList<T1> Types;
  T1 elem;
};

template<typename SC, int ID>
struct StaticContainerIterator {
  static inline typename TypeListIterator<typename SC::Types, ID>::Value& value(SC& cont) {
    return StaticContainerIterator<typename SC::NextContainer, ID-1>::value(cont.next);
  }
};

template<typename SC>
struct StaticContainerIterator<SC, 0> {
  static inline typename SC::Types::Elem& value(SC& cont) {
    return cont.elem;
  }
};

template<int BEG, int END, template<int PARAM> class Template>
struct EnumerateStaticContainer {
  typedef EnumerateTypeList<BEG, END, Template> Types;
  typedef EnumerateStaticContainer<BEG+1, END, Template> NextContainer;
  Template<BEG> elem;
  NextContainer next;
};

template<int END, template<int PARAM> class Template>
struct EnumerateStaticContainer<END, END, Template> {
  typedef EnumerateTypeList<END, END, Template> Types;
  Template<END> elem;
};


#endif//STATIC_CONTAINER_HPP
