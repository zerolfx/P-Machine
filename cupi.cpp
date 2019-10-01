// cupi.cpp

#include "cupi.h"


/** 
*	Constructor
*	@param p	difference in nesting depths (int)
*	@param q	relative address (int)
*/
Cupi::Cupi(int p, int q) : fP(p), fQ(q) {}


/** 
*	Destructor
*/
Cupi::~Cupi() {}


/** 
*	Saves the PC at STORE[MP+4] and sets the PC to the right startaddress for the procedure
*	@return			none
*	@param stack	the machine on which the operation is performed (StackMachine*)
*	@exception		ExecutionError
*/
void Cupi::execute(StackMachine *stack)
{	
	/*
	if(stack->fMP + 4 > stack->fSP)
	{
		for(int i = 0; i < stack->fMP + 4 - stack->fSP; ++i)
		{
			stack->fStore.push_back(new StackElement());
			++stack->fSP;
		}
	}
	else
	{
		delete stack->fStore[stack->fMP + 4];
		stack->fStore[stack->fMP + 4] = 0;
	}
	*/
	
	stack->fStore[stack->fMP + 4] = new StackAddress(stack->fPC);
	
	if(stack->base(fP, stack->fStore[stack->fMP + 2]->getValue()) + fQ > stack->fSP)
	{
		throw ExecutionError("instruction cupi: trying to access a memorylocation above STORE[SP]");
	}
	stack->fPC = stack->fStore[stack->base(fP, stack->fStore[stack->fMP + 2]->getValue()) + fQ]->getValue();
	
	// adding cost of this instruction
	stack->fTime.count("cupi");
}


/** 
*	Prints the instuction into an outputstream
*	@return			reference to ostream filled with the printed instruction
*	@param os		reference to ostream (ostream&)	
*	@exception		none
*/
ostream& Cupi::print(ostream &os) const
{
	os << "cupi " << fP << " " << fQ;
	return os;
}
