// smp.cpp

#include "smp.h"

/** 
*	Constructor
*	@param p		(int)
*/
Smp::Smp(int p) : fP(p) {}

/** 
*	Destructor
*/
Smp::~Smp() {}

/** 
*	Set the MP to MP:= SP - (p + 4)
*	@return			none
*	@param stack	the machine on which the instruction is performed (StackMachine*)
*	@exception		ExecutionError
*/
void Smp::execute(StackMachine *stack)
{	
	stack->fMP = stack->fSP - (fP + 4);
	
	// adding cost of this instruction
	stack->fTime.count("smp");

}


/** 
*	Prints the instuction into an outputstream
*	@return			reference to ostream filled with the printed instruction
*	@param os		reference to ostream (ostream&)	
*	@exception		none
*/
ostream& Smp::print(ostream &os) const
{
	os << "smp " << fP;
	return os;
}

