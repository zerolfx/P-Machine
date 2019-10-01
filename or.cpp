//or.cpp

#include "or.h"


/** 
*	Constructor
*/
Or::Or() {}


/** 
*	Destructor
*/
Or::~Or() {}


/** 
*	Checks whether the top 2 elements are of type boolean and then performs the OR operation on them. The boolean result replaces the result on the top of the stack.
*	@return			none
*	@param stack	the machine on which the addition is performed (StackMachine*)
*	@exception		ExecutionError
*/
void Or::execute(StackMachine *stack) 
{
	// check if the stack contains at least two entries
	if(stack->fSP < 1)
		throw ExecutionError("instruction or: requires 2 stackelements to be present.");
		
	StackBoolean p1;
	
	if(typeid(p1) != typeid(*(stack->fStore[stack->fSP])))
		throw ExecutionError("instruction or: SP does not point to element of type boolean.");
	if(typeid(p1) != typeid(*(stack->fStore[stack->fSP - 1])))
		throw ExecutionError("instruction or: SP - 1 does not point to element of type boolean.");

	
	// actual or-operation
	stack->fStore[stack->fSP - 1]->ori(stack->fStore[stack->fSP]);
	
	// SP := SP - 1
	delete stack->fStore[stack->fSP];
	stack->fStore[stack->fSP] = 0;
	stack->fStore.pop_back();
	--stack->fSP;
	
	// adding cost of this instruction
	stack->fTime.count("or");

}


/** 
*	Prints the instuction into an outputstream
*	@return			reference to ostream filled with the printed instruction
*	@param os		reference to ostream (ostream&)	
*	@exception		none
*/
ostream& Or::print(ostream &os) const
{
	os << "or";
	return os;
}
