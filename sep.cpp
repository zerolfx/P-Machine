// sep.cpp

#include "sep.h"


/** 
*	Constructor
*	@param p		maximum depth of local stack (int)
*/
Sep::Sep(int p) : fP(p) {}


/** 
*	Destructor
*/
Sep::~Sep() {}


/** 
*	Sets EP:=EP+p
*	@return			none
*	@param stack	the machine on which the instruction is performed (StackMachine*)
*	@exception		ExecutionError
*/
void Sep::execute(StackMachine *stack)
{	
	stack->fEP = stack->fSP + fP;
	
	// adding cost of this instruction
	stack->fTime.count("sep");

}


/** 
*	Prints the instuction into an outputstream
*	@return			reference to ostream filled with the printed instruction
*	@param os		reference to ostream (ostream&)	
*	@exception		none
*/
ostream& Sep::print(ostream &os) const
{
	os << "sep " << fP;
	return os;
}
