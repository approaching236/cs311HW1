
// CS211 stack class - header file (by Vincent Grato)
// =======================================================

int const MAX = 25;   // The MAX number of elements for the stack
int const EMPTY_FLAG = -1;

typedef int el_t;    // the el_t type is integer

class stack { 
  private: // to be hidden from the client
    el_t     el[MAX];       // el is  an array of el_t's
    int      top;           // top is index to the top of stack
    void stackError(char*); // utility function for error handling
  public: // prototypes to be used by the client
  	class Overflow{};
	class Underflow{}; // used for throwing errors
    stack();   // constructor
    ~stack();  // destructor

    // HOW TO CALL: ***
    // PURPOSE: if not full, enters an element at the top
    // otherwise, calls an emergency exit routine
    void push(el_t);

    // HOW TO CALL: ***
    // PURPOSE: if not empty, removes and gives back the top element
    // otherwise, calls an emergency exit routine
    void pop(el_t&);

    // HOW TO CALL: ***
    // PURPOSE: if not empty, gives the top element without removing it
    void topElem(el_t&);

    // ************ add good comments here for each *********************  
    bool isEmpty();
    bool isFull();
    void displayAll();
    void clearIt();
        
};  

