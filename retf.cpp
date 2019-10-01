// retf.cpp

#include "retf.h"


/** 
*	Constructor
*/
Retf::Retf() {}


/** 
*	Destructor
*/
Retf::~Retf() {}


/** 
*	Breaks down the stack and sets all internal variables of the stackmachine back to their previous state. Leaves the function result on top of the stack.
*	@return			none
*	@param stack	the machine on which the addition is performed (StackMachine*)
*	@exception		none
*/
void Retf::execute(StackMachine *stack)
{	
	StackAddress p;
	if((typeid(p) != typeid(*(stack->fStore[stack->fMP + 2]))
		|| (typeid(p) != typeid(*(stack->fStore[stack->fMP + 3])))
		|| (typeid(p) != typeid(*(stack->fStore[stack->fMP + 4])))))
	{
		throw ExecutionError("instruction retf: stackframe has been compromised.");
	}
	
	int oldSP = stack->fSP;
	
	// function result in the local stack
	stack->fSP = stack->fMP;
	
	// return branch
	stack->fPC = stack->fStore[stack->fMP + 4]->getValue();
	
	// restore EP
	stack->fEP = stack->fStore[stack->fMP + 3]->getValue();
	
	// restore MP
	stack->fMP = stack->fStore[stack->fMP + 2]->getValue();
	
	for(int i = oldSP; i > stack->fSP; --i)
	{
		delete stack->fStore[i];
		stack->fStore.pop_back();
	}
	
	// adding cost of this instruction
	stack->fTime.count("retf");

	
}


/** 
*	Prints the instuction into an outputstream
*	@return			reference to ostream filled with the printed instruction
*	@param os		reference to ostream (ostream&)	
*	@exception		none
*/
ostream& Retf::print(ostream &os) const
{
	os << "retf";
	return os;
}
