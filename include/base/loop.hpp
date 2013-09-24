#ifndef LOOP_HPP
#define LOOP_HPP

template<int BEG, int END>
struct StaticLoop {
  template<class Callable>
  inline static void exec(Callable func) {
    StaticLoop<BEG, END-1>::exec(func);
    func(END);
  }
};

template<int BEG>
struct StaticLoop<BEG, BEG> {
  template<class Callable>
  inline static void exec(Callable func) {
    func(BEG);
  }
};

#endif//LOOP_HPP
