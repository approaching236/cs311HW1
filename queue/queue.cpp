// CS211 Queue class - Implementation file (by Vincent Grato)
//======================================================

#include <iostream>
#include <cstdlib>
#include "queue.h"

using namespace std;


// PURPOSE: constructor which initializes front, rear and count
queue::queue() {
  front = 0; // front will be at the zero index
  rear = -1; // once an element is added, it will be incremented to 0
  count = 0; // will account for any ambiguities
}


// PURPOSE: destructor which does nothing for the static array
queue::~queue() {  /* nothing to do. */ }

// PURPOSE: to add a passed element to the queue
// PARAMS:  new element n of type el_t
// ALGORITHM: if not full, increment rear and place n there
//            else queueError should be called
void queue::add( el_t n ) {
  if (isFull()) {
    throw Overflow();
  }
  rear = (rear + 1) % QUEUE_SIZE;
  count++;
  el[rear] = n;
}

// PURPOSE: removes the first element from the queue
// PARAMS: places the value in the variable passed
void queue::remove(el_t& n) {
  if (isEmpty()) {
    throw Underflow();
  }
  n = el[front];
  front = (front + 1) % QUEUE_SIZE;
  count--;
}

// PURPOSE: non-destructively obtains the first value in the queue
// PARAMS: sets the value to the variable passed
//comment ***
void queue::getFront(el_t& n) {
  if (isEmpty()) {
    throw Underflow();
  }
  n = el[front];
}

// PURPOSE: returns whether the queue is empty or not
bool queue::isEmpty() {
  return count == 0;
}

// PURPOSE: returns whether the queue is full or not
bool queue::isFull() {
  return count >= QUEUE_SIZE;
}

// PURPOSE: returns the current number of elements in the queue
int queue::getSize() {
  return count;
}

// PURPOSE: prints each element in the queue to the screen from front to back
void queue::displayAll() {
  if (count == 0) {
    cout << "[ empty ]" << endl;
  }
  for (int i = 0; i < count; i++) {
    cout << el[(i+front)%QUEUE_SIZE] << endl;
  }
}

// PURPOSE: sends the first element to the back of the queue. throws an underflow if the queue is empty. 1 element is a trivial case that does not fail.
void queue::goToBack() {
  if (isEmpty()) {
    throw Underflow();
  }
  el_t tmp;
  remove(tmp); // sets tmp as the item removed from the current queue
  add(tmp);
}

