// ssp.cpp

#include "ssp.h"


/** 
*	Constructor
*	@param p	size of static part of data area (int)
*/
Ssp::Ssp(int p) : fP(p) {}


/** 
*	Destructor
*/
Ssp::~Ssp() {}


/** 
*	Sets the stack pointer to SP := MP + p - 1
*	@return			none
*	@param stack	the machine on which the addition is performed (StackMachine*)
*	@exception		ExecutionError
*/
void Ssp::execute(StackMachine *stack)
{	
	int newSPvalue = stack->fMP + fP - 1;

	// get the stack consistent
	if(newSPvalue < stack->fSP)
	{
		for(int i = stack->fSP; i > newSPvalue; --i)
		{	
			delete stack->fStore[i];
			stack->fStore[i] = 0;
			stack->fStore.pop_back();
		}
	}
	else
	{
		for(int i = stack->fSP; i < newSPvalue; ++i)
		{
			stack->fStore.push_back(new StackElement());
		}
	}
	
	stack->fSP = newSPvalue;
	
	// adding cost of this instruction
	stack->fTime.count("ssp");
}


/** 
*	Prints the instuction into an outputstream
*	@return			reference to ostream filled with the printed instruction
*	@param os		reference to ostream (ostream&)	
*	@exception		none
*/
ostream& Ssp::print(ostream &os) const
{
	os << "ssp " << fP;
	return os;
}
