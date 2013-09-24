#ifndef AUGMENTED_HPP
#define AUGMENTED_HPP

//! \brief Add some operations to basic types
//! \param _RawType : Type to be augmented
template<typename _RawType>
class Augmented : public _RawType {
public:
  typedef _RawType RawType;

  //! \brief Default Constructor
  inline Augmented();
  //! \brief Copy Constructor
  inline Augmented(const Augmented&);
  //! \brief Augmentation Constructor
  inline Augmented(const RawType&);

  //! \brief Copy Operation
  inline Augmented& operator=(const Augmented&);
  //! \brief Augmentation
  inline Augmented& operator=(const RawType&);

  //! \brief Convertion
  inline operator RawType();
  
  //Operations
  //// Math
  inline Augmented& operator+=(const Augmented&);
  inline Augmented& operator-=(const Augmented&);
  inline Augmented& operator*=(const Augmented&);
  inline Augmented& operator/=(const Augmented&);
  inline Augmented& operator%=(const Augmented&);

  inline Augmented& operator++();
  inline Augmented& operator++(int);
  inline Augmented& operator--();
  inline Augmented& operator--(int);

  inline Augmented& operator+(const Augmented&);
  inline Augmented& operator-(const Augmented&);
  inline Augmented& operator*(const Augmented&);
  inline Augmented& operator/(const Augmented&);
  inline Augmented& operator%(const Augmented&);

  //// Logical
  //inline Augmented& operator&&=(const Augmented&);
  //inline Augmented& operator||=(const Augmented&);

  inline Augmented& operator&&(const Augmented&);
  inline Augmented& operator||(const Augmented&);
  inline Augmented& operator! (void);

  //// Bitwise
  inline Augmented& operator&=(const Augmented&);
  inline Augmented& operator|=(const Augmented&);

  inline Augmented& operator&(const Augmented&) const;
  inline Augmented& operator|(const Augmented&) const;
  inline Augmented& operator^ (const Augmented&) const;
  inline Augmented& operator~ (void) const;

  //// Compar /!\ Lexicographical order !
  inline bool operator==(const Augmented&) const;
  inline bool operator!=(const Augmented&) const;
  inline bool operator<=(const Augmented&) const;
  inline bool operator< (const Augmented&) const;
  inline bool operator>=(const Augmented&) const;
  inline bool operator> (const Augmented&) const;
};

#endif//AUGMENTED_HPP
