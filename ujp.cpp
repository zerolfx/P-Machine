// ujp.cpp

#include "ujp.h"


/** 
*	Constructor
*	@param q	the name of the label to which the program should jump (string)
*/
Ujp::Ujp(string q) : fQ(q) {}


/** 
*	Destructor
*/
Ujp::~Ujp() {}


/** 
*	Translates the label to the right instruction and adjusts the PC accordingly.
*	@return			none
*	@param stack	the machine on which the operation is performed (StackMachine*)
*	@exception		ExecutionError
*/
void Ujp::execute(StackMachine *stack)
{
	stack->fPC = stack->fLabelCenter.getAddress(fQ);
	
	// adding cost of this instruction
	stack->fTime.count("ujp");
}


/** 
*	Prints the instuction into an outputstream
*	@return			reference to ostream filled with the printed instruction
*	@param os		reference to ostream (ostream&)	
*	@exception		none
*/
ostream& Ujp::print(ostream &os) const
{
	os << "ujp " << fQ;
	return os;
}
