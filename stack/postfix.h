
// CS311 Postfix Evaluation Program - header file (by Vincent Grato)
// =======================================================

#ifndef POSTFIX_H
#define POSTFIX_H
#include <string>
#include "stack.h"

using namespace std;

class postfix { 
  private:
  	stack s;
	string expression;
  public:
  	class Overflow{};
	class Underflow{}; // used for throwing errors
	postfix();
	~postfix();
	void evaluate(string& expression);
}; 
#endif

