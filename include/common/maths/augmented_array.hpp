#ifndef AUGMENTED_ARRAY_HPP
#define AUGMENTED_ARRAY_HPP

#include "../base/array.hpp"
#include "augmented.hpp"


//! \brief Add some operations to basic types
//! \param _RawType : Type to be augmented
template<int SIZE, typename ET, typename IT = int>
class AugmentedArray : public Array<SIZE, ET, IT> {
public:
  typedef Array<SIZE, ET, IT> RawType;

  //! \brief Default Constructor
  inline AugmentedArray() : RawType() {}
  //! \brief Copy Constructor
  inline AugmentedArray(const AugmentedArray& other) {
    (*this) = other;
  }

  //! \brief Augmentation Constructor
  inline AugmentedArray(const RawType& other) {
    (RawType&)(*this) = other;
  }

  //! \brief Copy Operation
  inline AugmentedArray& operator=(const AugmentedArray& other) {
    (RawType&)(*this) = (RawType&)other;
    return (*this);
  }

  //! \brief Augmentation
  inline AugmentedArray& operator=(const RawType& other) {
    (RawType&)(*this) = other;
    return (*this);
  }

  //! \brief Convertion
  inline operator RawType() {
    return (RawType&)(*this);
  }
  
  //Operations
  //// Math
  inline AugmentedArray& operator+=(AugmentedArray& other) {
    for(int i = 0 ; i < SIZE ; i++) {
      (*this)[i] += other[i];
    }
    return (*this);
  }

  inline AugmentedArray& operator-=(AugmentedArray& other) {
    for(int i = 0 ; i < SIZE ; i++) {
      (*this)[i] -= other[i];
    }
    return (*this);
  }

  inline AugmentedArray& operator*=(AugmentedArray& other) {
    for(int i = 0 ; i < SIZE ; i++) {
      (*this)[i] *= other[i];
    }
    return (*this);
  }

  inline AugmentedArray& operator/=(AugmentedArray& other) {
    for(int i = 0 ; i < SIZE ; i++) {
      (*this)[i] /= other[i];
    }
    return (*this);
  }

  inline AugmentedArray& operator%=(AugmentedArray& other) {
    for(int i = 0 ; i < SIZE ; i++) {
      (*this)[i] %= other[i];
    }
    return (*this);
  }


  inline AugmentedArray& operator++() {
    for(int i = 0 ; i < SIZE ; i++) {
      ++(*this)[i];
    }
    return (*this);
  }

  inline AugmentedArray& operator++(int) {
    AugmentedArray<SIZE, ET, IT> ret = AugmentedArray<SIZE, ET, IT>(*this);
    for(int i = 0 ; i < SIZE ; i++) {
      ((*this)[i])++;
    }
    return ret;
  }

  inline AugmentedArray& operator--() {
    for(int i = 0 ; i < SIZE ; i++) {
      --(*this)[i];
    }
    return (*this);
  }

  inline AugmentedArray& operator--(int) {
    for(int i = 0 ; i < SIZE ; i++) {
      ((*this)[i]);
    }
    return (*this);
  }


  inline AugmentedArray& operator+(const AugmentedArray&);
  inline AugmentedArray& operator-(const AugmentedArray&);
  inline AugmentedArray& operator*(const AugmentedArray&);
  inline AugmentedArray& operator/(const AugmentedArray&);
  inline AugmentedArray& operator%(const AugmentedArray&);

  //// Logical
  //inline AugmentedArray& operator&&=(const AugmentedArray&);
  //inline AugmentedArray& operator||=(const AugmentedArray&);

  inline AugmentedArray& operator&&(const AugmentedArray&);
  inline AugmentedArray& operator||(const AugmentedArray&);
  inline AugmentedArray& operator! (void);

  //// Bitwise
  inline AugmentedArray& operator&=(const AugmentedArray&);
  inline AugmentedArray& operator|=(const AugmentedArray&);

  inline AugmentedArray& operator&(const AugmentedArray&) const;
  inline AugmentedArray& operator|(const AugmentedArray&) const;
  inline AugmentedArray& operator^ (const AugmentedArray&) const;
  inline AugmentedArray& operator~ (void) const;

  //// Compar /!\ Lexicographical order !
  inline bool operator==(const AugmentedArray&) const;
  inline bool operator!=(const AugmentedArray&) const;
  inline bool operator<=(const AugmentedArray&) const;
  inline bool operator< (const AugmentedArray&) const;
  inline bool operator>=(const AugmentedArray&) const;
  inline bool operator> (const AugmentedArray&) const;
};

#endif//AUGMENTED_ARRAY_HPP
