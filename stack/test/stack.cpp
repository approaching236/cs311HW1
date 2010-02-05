
// CS211 stack class - Implementation file (by Vincent Grato)
//======================================================

#include <iostream>
#include <cstdlib>
#include "stack.h"

using namespace std;

// PURPOSE: constructor which initializes top to the EMPTY_FLAG
stack::stack() {
  top = EMPTY_FLAG;
}

// PURPOSE: destructor which does nothing for the static array
stack::~stack() {
  /* nothing to do. */ 
}

// PURPOSE: pushes the el_t type object n to the stack
// PARAMS:  n is the element to be pushed to the stack
// ALGORITHM: checks if the stack is empty. if it isn't it pushes the object to the stack. else it errors.
void stack::push( el_t n )  {
  if (!isFull()) {
    top++;
    el[top] = n;
  } else {
    throw Overflow();
  }
}

// PURPOSE: pops an element to the stack
// PARAMS: the param is where the method will place the value
// ALGORITHM: checks to see if the stack would underflow, then places the value in n and decrements top
void stack::pop(el_t& n) {
  if (!isEmpty()) {
    n = el[top];
    top--;
  } else {
    throw Underflow();
  }
}

// PURPOSE: shows the top element without removing it
// PARAMS: places the value of the top element in n
// ALGORITHM: checks to see if the stack is empty, then places the value in n
void stack::topElem(el_t& n) {
  if (!isEmpty()) {
    n = el[top];
  } else {
    cout << "[ empty ]" << endl;
  }
}

// PURPOSE: returns whether the stack is empty or not
// ALGORITHM: returns if the top element matches the EMPTY_FLAG
bool stack::isEmpty() {
  return top == EMPTY_FLAG;
}

// PURPOSE: returns whether the stack is full or not
// ALGORITHM: returns if the top of the stack is at the max size allowable. (or greater just in case)
bool stack::isFull() {
  return top >= MAX - 1;
}

// PURPOSE: displays all of the elements of the stack (or if it is empty). This is non-destructive.
// ALGORITHM: loops over the elements of the stack, starting at the top.
void stack::displayAll() {
  if (isEmpty()) cout << "[ empty ]" <<endl;
  else {
    for (int i = top; i >= 0; i--) {
      cout << el[i] << endl; 
    }
  }
}

// PURPOSE: "clears" the stack of all elements.
// ALGORITHM: change top to empty, and all the values that are there technically don't matter any more.
void stack::clearIt() {
  top = EMPTY_FLAG;
}

