/*
  This function is needed by the avr-gcc compiler in some cases.
 */
extern "C" void __cxa_pure_virtual() { while (1); }

/*
  Interface, with a pure virtual function.
  Enable the user to have a generic class with dynamic type resolution.
*/
template<typename DataType>
class Output {
public:
  virtual void setOutput(const DataType&) = 0;
};


/*
  Interface "binder", created with a reference to Actuator class.
  It's goal is to call the real actuator's "setOutput" function.
*/
template<typename DataType, class ChildClass>
class InterfaceOutput : public Output<DataType>, ChildClass {
public:
  InterfaceOutput(ChildClass& child) : Output<DataType>(), ChildClass(child) {}

  void setOutput(const DataType& val) {
    ChildClass::setOutput(val);
  }
};

/*
  Mother class of all Actuators or other output class.
  No virtual function, to let the choice to the coder to use either the template mecanism, 
  or the dynamic type resolution by using the "interface" class before.
*/
template<typename DataType>
class AbstractOutput {
public:
  void setOutput(const DataType&);
};

/*
  The real actuator class.
  All the code specific to an actuator should be defined in this type of class.
  The template parameter is needed here to create a new class for each ID, for the tests.
*/
template<int ID>
class Actuator : public AbstractOutput<int> {
private:
  int intern = 0;
public:
  inline void setOutput(const int& val) { intern = val + ID; }
};

/*
  The function which is supposed to implement a generic algorithme on an output object.
*/
void test(Output<int>& out) {
  out.setOutput(42);
}

/*
  The main function in which we create as many class as we want, 
  and then call the test function to see the comportement on the code size.
*/
int main (int argc, char* argv[]) {

  /*
    Here, we create a new actuator and a new class (by changing the template parameter).
   */

#define ACTUATOR_TEST(n)				\
  Actuator<n> m##n;					\
  m##n.setOutput(666);
  
  /*
    Then create the interface that will do the link between the "Ouput" class and Actuator
    class.
    And finally call the test method with the interface in parameter.
   */

#define INTERFACE_TEST(n)				\
  InterfaceOutput< int, Actuator<n> > im##n(m##n);	\
  test(im##n);

#include "macro_test"

  return 0;
}
