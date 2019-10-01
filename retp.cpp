// retp.cpp

#include "retp.h"


/** 
*	Constructor
*/
Retp::Retp() {}


/** 
*	Destructor
*/
Retp::~Retp() {}


/** 
*	Breaks down the stack and sets all internal variables of the stackmachine back to their previous state
*	@return			none
*	@param stack	the machine on which the addition is performed (StackMachine*)
*	@exception		none
*/
void Retp::execute(StackMachine *stack)
{	
	StackAddress p;
	if((typeid(p) != typeid(*(stack->fStore[stack->fMP + 2]))
		|| (typeid(p) != typeid(*(stack->fStore[stack->fMP + 3])))
		|| (typeid(p) != typeid(*(stack->fStore[stack->fMP + 4])))))
	{
		throw ExecutionError("instruction retp: stackframe has been compromised.");
	}
	
	int oldSP = stack->fSP;
	
	// proper procedure with no results
	stack->fSP = stack->fMP - 1;
	
	// return branch
	stack->fPC = stack->fStore[stack->fMP + 4]->getValue();
	
	// restore EP
	stack->fEP = stack->fStore[stack->fMP + 3]->getValue();

	// dynamic link
	stack->fMP = stack->fStore[stack->fMP + 2]->getValue();
	
	for(int i = oldSP; i > stack->fSP; --i)
	{
		delete stack->fStore[i];
		stack->fStore.pop_back();
	}
	
	// adding cost of this instruction
	stack->fTime.count("retp");

}


/** 
*	Prints the instuction into an outputstream
*	@return			reference to ostream filled with the printed instruction
*	@param os		reference to ostream (ostream&)	
*	@exception		none
*/
ostream& Retp::print(ostream &os) const
{
	os << "retp";
	return os;
}

