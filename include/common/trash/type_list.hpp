#ifndef TYPE_LIST_HPP
#define TYPE_LIST_HPP

template<typename T1, typename... TArgs>
struct TypeList {
public:
  typedef T1 Elem;
  typedef TypeList<TArgs...> Next;
};

template<typename T1>
struct TypeList<T1> {
public:
  typedef T1 Elem;
};

template<typename List, int ID>
struct TypeListIterator {
  typedef TypeListIterator<typename List::Next, ID-1> Next;
  typedef typename Next::Value Value;
};

template<typename List>
struct TypeListIterator<List, 0> {
  typedef typename List::Elem Value;
};

template<int BEG, int END, template<int PARAM> class Template>
struct EnumerateTypeList {
public:
  typedef Template<BEG> Elem;
  typedef EnumerateTypeList<BEG+1, END, Template> Next;
};

template<int END, template<int PARAM> class Template>
struct EnumerateTypeList<END, END, Template> {
public:
  typedef Template<END> Elem;
};

#endif//TYPE_LIST_HPP
