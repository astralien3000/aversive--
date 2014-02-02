#include <container/list.hpp>
#include <iostream>
using namespace std;

template<int S, typename E>
ostream& operator<<(ostream& out, List<S, E>& list) {
  out << "( ";
  list.doForeach([&out](const E& e) {
      out << e << " ";
    });
  return out << ")";
}

int main(int argc, char* argv[]) {
  List<10, int> l1(10,5,8,20);
  List<10, int> l2(5,3,1,6,7,12,16,44,66,42);
  List<10, int> l3 = l1;

  cout << "l1 " << l1 << endl;
  cout << "l2 " << l2 << endl;
  cout << "l3 " << l3 << endl;

  l3.insert(0, l2.get(0));
  cout << "l3 " << l3 << endl;

  l3.remove(2);
  cout << "l3 " << l3 << endl;
  
  cout << "Full :" << endl;
  l2.insert(5, 666); // Out of capacity
  cout << "l2 " << l2 << endl;

  cout << "==" << endl;
  l2.remove(0);
  cout << "l2 " << l2 << endl;

  cout << "Invalid index :" << endl; 
  l2.insert(9, 666); // Out of size
  cout << "l2 " << l2 << endl;

  l2.insert(-1, 666); // Out of size
  cout << "l2 " << l2 << endl;
  return 0;
}
