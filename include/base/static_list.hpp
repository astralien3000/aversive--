#ifndef STATIC_LIST_HPP
#define STATIC_LIST_HPP

template<int E1, int ... ARGS> struct StaticList {
  typedef StaticList<ARGS...> Next;
  enum { SIZE = (1 + Next::SIZE) };
  enum { ELEM = E1 };
};

template<int E1> struct StaticList<E1> {
  enum { SIZE = 1 };
  enum { ELEM = E1 };
};

template<typename List, int INDEX>
struct StaticListIterator {
  typedef StaticListIterator<typename List::Next, INDEX-1> Next;
  enum { VALUE = Next::VALUE };
};

template<typename List>
struct StaticListIterator<List,0> {
  enum { VALUE = List::ELEM };
};

template<typename List1, typename List2, int _SIZE = List1::SIZE>
struct StaticListLooper {
  template<typename Callable> static inline void exec(Callable func) {
    static_assert(List1::SIZE <= _SIZE, "Error static list overflow !");
    static_assert(List2::SIZE <= _SIZE, "Error static list overflow !");
    func(List1::ELEM, List2::ELEM);
    StaticListLooper<typename List1::Next, typename List2::Next, (_SIZE - 1)>::exec(func);
  }
};

template<typename List1, typename List2>
struct StaticListLooper<List1, List2, 1> {
  template<typename Callable> static inline void exec(Callable func) {
    func(List1::ELEM, List2::ELEM);
  }
};

template<typename Operator, typename List1, typename List2, int _SIZE = List1::SIZE>
struct StaticListOperation {
  static inline void exec(void) {
    Operator::exec(List1::ELEM, List2::ELEM);
    StaticListOperation<Operator, typename List1::Next, typename List2::Next, (_SIZE - 1)>::exec();
  }
};

template<typename Operator, typename List1, typename List2>
struct StaticListOperation<Operator, List1, List2, 1> {
  static inline void exec(void) {
    Operator::exec(List1::ELEM, List2::ELEM);
  }
};

#endif//STATIC_LIST_HPP
