
// CS211 QUEUE class - header file (by Yoshii)
// *** Add the HOW TO CALL comments based on Notes-7.
//
// =======================================================
#ifndef QUEUE_H
#define QUEUE_H

typedef char T;          // T is an alias for char
const int QUEUE_SIZE = 10;  // this is the max number of elements

template<class T> class queue  {
 private:
  T el[QUEUE_SIZE]; // an array called el.
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
  void add(T);

  // PURPOSE: if empty, calls an emergency exit routine
  // if not empty, removes the front element to give it back 
  // TO CALL: provide a holder for the element removed (pass by ref)
  void remove(T&);

  // PURPOSE: if empty, calls an emergency exit routine
  // if not empty, give back the front element (but does not remove it)
  // TO CALL: provide a holder for the element (pass by ref)
  void getFront(T&);

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

// PURPOSE: constructor which initializes front, rear and count
queue<T>::queue() {
  front = 0; // front will be at the zero index
  rear = -1; // once an element is added, it will be incremented to 0
  count = 0; // will account for any ambiguities
}


// PURPOSE: destructor which does nothing for the static array
queue<T>::~queue() {  /* nothing to do. */ }

// PURPOSE: to add a passed element to the queue
// PARAMS:  new element n of type T
// ALGORITHM: if not full, increment rear and place n there
//            else queueError should be called
void queue<T>::add( T n ) {
  if (isFull()) {
    throw Overflow();
  }
  rear = (rear + 1) % QUEUE_SIZE;
  count++;
  el[rear] = n;
}

// PURPOSE: removes the first element from the queue
// PARAMS: places the value in the variable passed
void queue<T>::remove(T& n) {
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
void queue<T>::getFront(T& n) {
  if (isEmpty()) {
    throw Underflow();
  }
  n = el[front];
}

// PURPOSE: returns whether the queue is empty or not
bool queue<T>::isEmpty() {
  return count == 0;
}

// PURPOSE: returns whether the queue is full or not
bool queue<T>::isFull() {
  return count >= QUEUE_SIZE;
}

// PURPOSE: returns the current number of elements in the queue
int queue<T>::getSize() {
  return count;
}

// PURPOSE: prints each element in the queue to the screen from front to back
void queue<T>::displayAll() {
  if (count == 0) {
    cout << "[ empty ]" << endl;
  }
  for (int i = 0; i < count; i++) {
    cout << el[(i+front)%QUEUE_SIZE] << endl;
  }
}

// PURPOSE: sends the first element to the back of the queue. throws an underflow if the queue is empty. 1 element is a trivial case that does not fail.
void queue<T>::goToBack() {
  if (isEmpty()) {
    throw Underflow();
  }
  T tmp;
  remove(tmp); // sets tmp as the item removed from the current queue
  add(tmp);
}

#endif

