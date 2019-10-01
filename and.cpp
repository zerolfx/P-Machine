//and.cpp

#include "and.h"


/** 
*	Constructor
*/
And::And() {}


/** 
*	Destructor
*/
And::~And() {}


/** 
*	Checks whether the 2 highest stackentries contain booleans and performs the and-operation on them.
*	@return			none
*	@param stack	the machine on which the operation is performed (StackMachine*)
*	@exception		ExecutionError
*/
void And::execute(StackMachine *stack) 
{
	// check if the stack contains at least two entries
	if(stack->fSP < 1)
		throw ExecutionError("instruction and: requires 2 stackelements to be present.");
		
	StackBoolean p1;
	
	if(typeid(p1) != typeid(*(stack->fStore[stack->fSP])))
		throw ExecutionError("instruction and: SP does not point to element of type boolean.");
	if(typeid(p1) != typeid(*(stack->fStore[stack->fSP - 1])))
		throw ExecutionError("instruction and: SP - 1 does not point to element of type boolean.");

	
	// actual and-operation
	stack->fStore[stack->fSP - 1]->andi(stack->fStore[stack->fSP]);
	
	// SP := SP - 1
	delete stack->fStore[stack->fSP];
	stack->fStore[stack->fSP] = 0;
	stack->fStore.pop_back();
	--stack->fSP;
	
	// adding cost of this instruction
	stack->fTime.count("add");	
}


/** 
*	Prints the instuction into an outputstream
*	@return			reference to ostream filled with the printed instruction
*	@param os		reference to ostream (ostream&)	
*	@exception		none
*/
ostream& And::print(ostream &os) const
{
	os << "and";
	return os;
}
