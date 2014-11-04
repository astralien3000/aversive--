#include <math/matrix.hpp>
#include <math/vect.hpp>
#include <base/integer.hpp>
#include <cstdlib>
#include <iostream>
#include "../../../my_assert.hpp"

int main(int argc, char** argv) {
  (void) argc;
  (void) argv;
  
  Matrix<2, 2, u8> m1;
  
  for(u8 i = 0; i < 4; i++) {
    myAssert(m1.coord(i / 2, i % 2) == 0, "Line " S__LINE__": Matrix<WIDTH, HEIGHT, u8>::Matrix(void).");
  }
  
  m1.coord(0, 0) = 0;
  m1.coord(0, 1) = 1;
  m1.coord(1, 0) = 2;
  m1.coord(1, 1) = 3;
  
  Matrix<2, 2, u8> m2(m1);
  
  for(u8 i = 0; i < 4; i++) {
    myAssert(m1.coord(i / 2, i % 2) == m2.coord(i / 2, i % 2), "Line " S__LINE__": Matrix<WIDTH, HEIGHT, u8>::Matrix(const Matrix &).");
  }
  
  m2 = m1;
  
  for(u8 i = 0; i < 4; i++) {
    myAssert(m1.coord(i / 2, i % 2) == m2.coord(i / 2, i % 2), "Line " S__LINE__": Matrix<WIDTH, HEIGHT, u8>::operator=(const Matrix &).");
  }
  
  m2 = m1 + m1;
  
  for(u8 i = 0; i < 4; i++) {
    myAssert(m1.coord(i / 2, i % 2) * 2 == m2.coord(i / 2, i % 2), "Line " S__LINE__": Matrix<WIDTH, HEIGHT, u8>::operator+(const Matrix &).");
  }
  
  m2 = m1;
  m2 += m1;
  
  for(u8 i = 0; i < 4; i++) {
    myAssert(m1.coord(i / 2, i % 2) * 2 == m2.coord(i / 2, i % 2), "Line " S__LINE__": Matrix<WIDTH, HEIGHT, u8>::operator+=(const Matrix &).");
  }
  
  m2 = m2 - m1;
  
  for(u8 i = 0; i < 4; i++) {
    myAssert(m1.coord(i / 2, i % 2) == m2.coord(i / 2, i % 2), "Line " S__LINE__": Matrix<WIDTH, HEIGHT, u8>::operator-(const Matrix &).");
  }
  
  m2 -= m1;
  
  for(u8 i = 0; i < 4; i++) {
    myAssert(0 == m2.coord(i / 2, i % 2), "Line " S__LINE__": Matrix<WIDTH, HEIGHT, u8>::operator-=(const Matrix &).");
  }
  
  m2 = m1 * 2;
  
  for(u8 i = 0; i < 4; i++) {
    myAssert(m1.coord(i / 2, i % 2) * 2 == m2.coord(i / 2, i % 2), "Line " S__LINE__": Matrix<WIDTH, HEIGHT, u8>::operator*(u8).");
  }
  
  m2 *= 2;
  
  for(u8 i = 0; i < 4; i++) {
    myAssert(m1.coord(i / 2, i % 2) * 4 == m2.coord(i / 2, i % 2), "Line " S__LINE__": Matrix<WIDTH, HEIGHT, u8>::operator*=(u8).");
  }
  
  std::cout << "OK" << std::endl;
  return EXIT_SUCCESS;
}
