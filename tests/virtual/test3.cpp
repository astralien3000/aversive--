/*
  This function is needed by the avr-gcc compiler in some cases.
 */
extern "C" void __cxa_pure_virtual() { while (1); }

/*
  Mother class of all Actuators or other output class.
  Function is not virtual so the there is no dynamis type resolution implied.
  This disable some useful stuff of OOP, but may decrease the code size.
  Actually this function is just here to make the redefinition of setOutput compulsory.
*/
template<typename DataType>
class Output {
public:
  void setOutput(const DataType&);
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

/*
  The function which is supposed to implement a generic algorithm on an output object.
  Here, the type of the object on which the algorithm is applied is passed in template
  parameter. Which makes the compiler duplicate the function for each type.
*/
template<class Output>
void test(Output out) {
  out.setOutput(42);
}

int main (int argc, char* argv[]) {

  /*
    Here, we create a new actuator and a new class (by changing the template parameter).
    Then the test function is called, with template parameter implied by the type of the object.
   */

#define ACTUATOR_TEST(n)				\
  Actuator<n> m##n;					\
  m##n.setOutput(666);					\
  test(m##n);
  
#define INTERFACE_TEST(n) // Nothing

#include "macro_test"

  return 0;
}
