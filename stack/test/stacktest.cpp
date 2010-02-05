
// CS211  Stack class - test program as the client (by Yoshii)
//
// Note that the client knows nothing about the datamembers
// Note that the client does not know about el_t and MAX
// Look for *** to complete this program
// =========================================================

#include <iostream>
using namespace std;

#include "stack.h"    // this must be an integer stack class


int main ()
{

  cout << "************** STACK Test Program *************" << endl;
  cout << "This program tests an integer stack ADT implemented as" << endl;
  cout << "an array.  " << endl;
  cout << "It is a menu based program allowing you to test each method. "
       <<  endl;
  cout << "It displays the entire stack whenever it is modified." << endl;
  cout << "It will try to prevent errors from occuring." << endl;
  cout << "***********************************************" << endl;

  stack S;  // this is the stack object S
  
  int toadd; //this is the number the user wants to add to the stack
  
  int selection; // this will indicate what the user wants to do

  int erased; // this is the number removed from the stack


  do
    {

      cout << endl << "MENU: These are your options: " << endl << endl;
      cout << "   (1) Push an element   " << endl;
      cout << "   (2) Display the entire stack  " << endl;
      cout << "   (3) Pop the top element" << endl;
      cout << "   (4) Display the top element" << endl;
      cout << "   (5) Check to see if is it empty" << endl;
      cout << "   (6) Check to see if is it full" << endl;
      cout << "   (7) Clear the entire stack" << endl;
      cout << "    Enter ( 0 ) to quit " << endl;
      cout << "===>";

      cin >> selection;

   
      switch (selection) {


      case 1:  // the Push choice
	if (!S.isFull())
	  {
	    cout << "Enter a positive integer to be added : ";
	    cin >> toadd;
	    S.push(toadd);
	    cout << "The current contents of the stack are:  " << endl;
	    S.displayAll();
	    cout << endl;
	  }
	else
	  { cout << "Sorry, stack is already full" << endl;
	  }
	break;
	
      case 2: // the Display choice
	cout << endl;
        cout << "The current contents of the the S are: " << endl;
	S.displayAll();
	break;
	
      case 3:  // The Pop choice
	if (!S.isEmpty())
	  { 
	    int erased;
	    S.pop(erased);
	    cout << erased << " has been removed" << endl;
	    cout << "The new elements in the stack are: ";
	    S.displayAll();
	    cout << endl; 
	  }
	else cout << "Sorry, the stack is empty." << endl;
	break;
	
	
      case  4:  // the top element case to be completed
        // *** This is very similar to case 3 but
        // *** here the top element should be retrieved but not removed
        // *** display it to the user
	 int n;
	 S.topElem(n);
	 cout << n << endl;
        break;
	
      case 5:   // the check-empty case
	if (!S.isEmpty())
	  cout << "Stack is empty right now." << endl;
	else
	  cout << "Stack has some elements." << endl;
	break;
	
      case 6:   // the check-full case
	if (!S.isFull())
	  cout << "Stack is full right now." << endl;
	else
	  cout << "Stack has more room." << endl;
	break;

      case 7:   // the clear the stack case to be completed
        S.clearIt();
	break;
	
	
      }   // end of switch statement
      
      
    } while(selection!=0);
  
  cout << "Bye bye - ending the stack test program" << endl;
  
}// end of main

