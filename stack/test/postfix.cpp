
// CS311 Postfix Evaluation Program - Implementation file (by Vincent Grato)
//======================================================

#include <iostream>
#include <cstdlib>
#include <string>
#include "postfix.h" //needs to be after stack.h because there is a dependance

using namespace std;

// reads in string then begins evaluation
postfix::postfix() {
  cout << "Please enter postfix expression to be evaluated: " << endl;
  cin >> expression;
  evaluate(expression);
}

postfix::~postfix() {
  //nothing to do
}

void postfix::evaluate(string& expression) {
  int i = 0;
  cout << "Evaluating: " << expression << endl;
  while (expression[i] != '\0') {
    try {
      if (expression[i] >= '0' && expression[i] <= '9') { // if the char is a number
	s.push(expression[i] - '0');
      } else if (expression[i] == '+') {
	int b, a; s.pop(b); s.pop(a);
	s.push(a+b);
      } else if (expression[i] == '-') {
	int b, a; s.pop(b); s.pop(a);
	s.push(a-b);
      } else if (expression[i] == '*') {
	int b, a; s.pop(b); s.pop(a);
	s.push(a*b);
      } else if (expression[i] == '/') {
	int b, a; s.pop(b); s.pop(a);
	s.push(a/b);
      } else {
        cout << "invalid character" << endl;
	exit(1);
      }
    }
    catch (stack::Overflow) { cout << "Stack overflow error, aborting."<< endl; exit(1); }
    catch (stack::Underflow) { cout << "Stack underflow error, aborting."<< endl; exit(1); }
    i++;
  }
  int num;
  s.pop(num);
  if (s.isEmpty()) {
    cout << "The result is: " << num << endl;
  } else {
    cout << "There are still operands on the stack, an incorrect expression was given" << endl;
    s.displayAll();
  }
}

