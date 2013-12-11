#ifndef EXTRACT_HPP
#define EXTRACT_HPP

//! \brief Extract a part of an integer...
/*!
  Actually I don't know why it was defined in aversive...
 */
template<typename ExtrType, char BYTE_OFFSET, typename BaseType>
inline ExtrType extract(BaseType v) {
  return (*(ExtrType*)((char*)(&v) + BYTE_OFFSET));
}

#endif//EXTRACT_HPP
