//not.cpp

#include "not.h"

/** 
*	Constructor
*/
Not::Not() {}


/** 
*	Destructor
*/
Not::~Not() {}


/** 
*	Checks whether STORE[SP] contains an element of type boolean and performs the not operation on it
*	@return			none
*	@param stack	the machine on which the operation is performed (StackMachine*)
*	@exception		ExecutionError
*/
void Not::execute(StackMachine *stack) 
{
	// check if the stack contains at least one entry
	if(stack->fSP < 0)
		throw ExecutionError("instruction not: requires 1 stackelement to be present.");
		
	StackBoolean p1;
	
	if(typeid(p1) != typeid(*(stack->fStore[stack->fSP])))
		throw ExecutionError("instruction not: SP does not point to element of type boolean.");

	
	// actual not-operation
	stack->fStore[stack->fSP]->noti();
	
	// adding cost of this instruction
	stack->fTime.count("not");

	
}


/** 
*	Prints the instuction into an outputstream
*	@return			reference to ostream filled with the printed instruction
*	@param os		reference to ostream (ostream&)	
*	@exception		none
*/
ostream& Not::print(ostream &os) const
{
	os << "not";
	return os;
}
