#include <iostream>
#include "stack.h"

using namespace std;

int main() {
  stack s;
  int n;
  s.displayAll();
  cout << "empty? " << s.isEmpty() << endl;
  s.push(3); // in real client, this will need to be converted from char to int
  cout << "empty? " << s.isEmpty() << endl;
  cout << "full?  " << s.isFull() << endl;
  s.pop(n);
  cout << "full?  " << s.isFull() << endl;
  cout << n << endl;
}
