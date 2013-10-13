#ifndef SINGLETON_HPP
#define SINGLETON_HPP

//! \brief Base class for all objects which must be single.
template<class _Base>
class Singleton {
protected:
  //! \brief Private Default Constructor, to avoid instanciation
  Singleton(void) {}
public:
  //! \brief Access to the single instance of the class
  static inline _Base& instance(void) {
    static _Base inst;
    return inst;
  }
};

#endif//SINGLETON_HPP
