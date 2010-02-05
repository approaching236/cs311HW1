#include "queue.h"
#include <iostream>

using namespace std;

int main() {
  queue q;
  char c;
  q.displayAll();
  q.add('a');
  q.displayAll();
  q.remove(c);
  cout << "c is: " << c << endl;
  q.displayAll();
}
