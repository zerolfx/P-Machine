// ent.cpp

#include "ent.h"


/** 
*	Constructor
*	@param p	data-area size (int)
*	@param q	maximum depth of local stack (int)
*/
Ent::Ent(int p, int q) : fP(p), fQ(q) {}


/** 
*	Destructor
*/
Ent::~Ent() {}


/** 
*	SP, EP are set
*	@return			none
*	@param stack	the machine on which the operation is performed (StackMachine*)
*	@exception		none
*/
void Ent::execute(StackMachine *stack)
{	
	int oldSP = stack->fSP;
	
	// q data-area size
	stack->fSP = stack->fMP + fQ - 1;
	
	for(int i = oldSP + 1; i <= stack->fSP; ++i)
	{
		stack->fStore.push_back(new StackElement());
	}
	
	// p max depth of local stack
	stack->fEP = stack->fSP + fP;
	
	// adding cost of this instruction
	stack->fTime.count("ent");

}


/** 
*	Prints the instuction into an outputstream
*	@return			reference to ostream filled with the printed instruction
*	@param os		reference to ostream (ostream&)	
*	@exception		none
*/
ostream& Ent::print(ostream &os) const
{
	os << "ent " << fP << " " << fQ;
	return os;
}
