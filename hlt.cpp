// hlt.cpp

#include "hlt.h"


/** 
*	Constructor
*/
Hlt::Hlt() {}


/** 
*	Destructor
*/
Hlt::~Hlt() {}


/** 
*	Simply halts execution
*	@return			none
*	@param stack	the machine on which the addition is performed (StackMachine*)
*	@exception		none
*/
void Hlt::execute(StackMachine *stack)
{
	stack->fHaltrequested = true;
	
	// adding cost of this instruction
	stack->fTime.count("hlt");

}


/** 
*	Prints the instuction into an outputstream
*	@return			reference to ostream filled with the printed instruction
*	@param os		reference to ostream (ostream&)	
*	@exception		none
*/
ostream& Hlt::print(ostream &os) const
{
	os << "hlt";
	return os;
}


