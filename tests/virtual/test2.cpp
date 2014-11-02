/*
  This function is needed by the avr-gcc compiler in some cases.
 */
extern "C" void __cxa_pure_virtual() { while (1); }

/*
  Interface with a pure virtual function.
  Enable the user to have a generic class with dynamic type resolution.
*/
template<typename DataType>
class Output {
public:
  virtual void setOutput(const DataType&) = 0;
};

/*
  The real actuator class.
  All the code specific to an actuator should be defined in this type of class.
  The template parameter is needed here to create a new class for each ID, for the tests.
*/
template<int ID>
class Actuator : public Output<int> {
private:
  int intern = 0;
public:
  inline void setOutput(const int& val) { intern = val + ID; }
};


void test(Output<int>& out) {
  out.setOutput(42);
}

int main (int argc, char* argv[]) {

  /*
    Here, we create a new actuator and a new class (by changing the template parameter).
    And finally call the test method.
   */

#define ACTUATOR_TEST(n)				\
  Actuator<n> m##n;					\
  m##n.setOutput(666);					\
  test(m##n);

#define INTERFACE_TEST(n) // Nothing, actually no interface is needed

#include "macro_test"

  return 0;
}
