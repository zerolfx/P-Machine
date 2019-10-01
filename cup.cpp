// cup.cpp

#include "cup.h"

/** 
*	Constructor
*	@param p	difference in nesting depths (int)
*	@param q	label of part of the program to jump to (const string&)
*/
Cup::Cup(int p, const string &q) : fP(p), fQ(q) {}


/** 
*	Destructor
*/
Cup::~Cup() {}


/** 
*	Sets the MP and the PC
*	@return			none
*	@param stack	the machine on which the operation is performed (StackMachine*)
*	@exception		ExecutionError
*/
void Cup::execute(StackMachine *stack)
{	
	stack->fMP = stack->fSP - (fP + 4);
	
	stack->fStore[stack->fMP + 4] = new StackAddress(stack->fPC);
	
	stack->fPC = stack->fLabelCenter.getAddress(fQ);
	
	// adding cost of this instruction
	stack->fTime.count("cup");

}


/** 
*	Prints the instuction into an outputstream
*	@return			reference to ostream filled with the printed instruction
*	@param os		reference to ostream (ostream&)	
*	@exception		none
*/
ostream& Cup::print(ostream &os) const
{
	os << "cup " << fP << " " << fQ;
	return os;
}
