#include <container/queue.hpp>
#include <container/list.hpp>
#include <iostream>
using namespace std;

template<int S, typename E>
ostream& operator<<(ostream& out, Queue<S, E>& queue) {
  Queue<S, E> aux;
  out << "( ";
  while(!queue.empty()) {
    aux.enqueue(queue.head());
    out << queue.head() << " ";
    queue.dequeue();
  }
  while(!aux.empty()) {
    queue.enqueue(aux.head());
    aux.dequeue();
  }
  return out << ")";
}

int main(int argc, char* argv[]) {
  Queue<10, s16> q1;
  //List<10, s16> q1;

  cout << "q1" << q1 << endl;
  return 0;
}
