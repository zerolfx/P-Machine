// mstf.cpp

#include "mstf.h"


/** 
*	Constructor
*	@param p		difference in nesting depths (int)
*	@param q		relative address (int)
*/
Mstf::Mstf(int p, int q) : fP(p), fQ(q) {}


/** 
*	Destructor
*/
Mstf::~Mstf() {}


/** 
*	Prepares the stack for a call. Save static link, dynamic link en EP on stack.
*	@return			none
*	@param stack	the machine on which the operation is performed (StackMachine*)
*	@exception		ExecutionError
*/
void Mstf::execute(StackMachine *stack)
{	
	for(int i = 0; i < 5; ++i)
	{
		stack->fStore.push_back(new StackElement());
	}
	
	// static link
	delete stack->fStore[stack->fSP + 2];
	stack->fStore[stack->fSP + 2] = new StackAddress(stack->fStore[stack->base(fP, stack->fMP) + fQ + 1]->getValue());
	
	// dynamic link
	delete stack->fStore[stack->fSP + 3];
	stack->fStore[stack->fSP + 3] = new StackAddress(stack->fMP);
	
	// save EP
	delete stack->fStore[stack->fSP + 4];
	stack->fStore[stack->fSP + 4] = new StackAddress(stack->fEP);
	
	stack->fSP += 5;
	
	// adding cost of this instruction
	stack->fTime.count("mstf");
}


/** 
*	Prints the instuction into an outputstream
*	@return			reference to ostream filled with the printed instruction
*	@param os		reference to ostream (ostream&)	
*	@exception		none
*/
ostream& Mstf::print(ostream &os) const
{
	os << "mstf " << fP << " " << fQ;
	return os;
}
