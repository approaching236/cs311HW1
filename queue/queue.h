
// CS211 QUEUE class - header file (by Yoshii)
// *** Add the HOW TO CALL comments based on Notes-7.
//
// =======================================================
#ifndef QUEUE_H
#define QUEUE_H

#include <string>

using namespace std;

typedef string el_t;          // el_t is an alias for char
const int QUEUE_SIZE = 10000;  // this is the max number of elements

class queue  {
 private:
  el_t el[QUEUE_SIZE]; // an array called el.
  int  count;          // how many elements do we have right now?
  int  front;          // where the front element of the queue is.
  int  rear;           // where the rear element of the queue is.

 public:    // prototypes to be used by the client
  class Overflow{};
  class Underflow{};
  queue(); // constructor 
  ~queue(); //destructor 

  // PURPOSE: returns true if queue is empty, otherwise false
  bool isEmpty();

  // PURPOSE: returns true if queue is full, otherwise false
  bool isFull();

  // PURPOSE: if full, calls an emergency exit routine
  // if not full, enters an element at the rear 
  // TO CALL: provide the element to be added
  void add(el_t);

  // PURPOSE: if empty, calls an emergency exit routine
  // if not empty, removes the front element to give it back 
  // TO CALL: provide a holder for the element removed (pass by ref)
  void remove(el_t&);

  // PURPOSE: if empty, calls an emergency exit routine
  // if not empty, give back the front element (but does not remove it)
  // TO CALL: provide a holder for the element (pass by ref)
  void getFront(el_t&);

  // PURPOSE: returns the current size to make it 
  // accessible to the client caller
  int getSize();

  // PURPOSE: display everything in the queue from front to rear
  //  enclosed in []
  // if empty, displays [ empty ]
  void displayAll();

  // PURPOSE: if empty, calls an emergency exit routine
  //if queue has just 1 element, does nothing
  //if queue has more than 1 element, moves the front one to the rear
  void goToBack();


};           
#endif

