#include <iostream>
#include "queue.h"

int main() {
  queue q;
  string x;
  q.add("A");
  q.add("B");
  q.add("C");

  while (true) {

    q.remove(x);
    cout << "x: " << x << endl;

    q.add(x+"A");
    q.add(x+"B");
    q.add(x+"C");
  }
}
