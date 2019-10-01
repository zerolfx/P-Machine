// lda.cpp

#include "lda.h"


/** 
*	Constructor
*	@param p	difference in nesting depths (int)
*	@param q	relative address (int)
*/
Lda::Lda(int p, int q) : fP(p), fQ(q) {}


/** 
*	Destructor
*/
Lda::~Lda() {}


/** 
*	Loads the address of the element pointed to.
*	@return			none
*	@param stack	the machine on which the operation is performed (StackMachine*)
*	@exception		ExecutionError
*/
void Lda::execute(StackMachine *stack)
{
	stack->fStore.push_back(new StackAddress(stack->base(fP, stack->fMP) + fQ));
	
	++stack->fSP;
	
	// adding cost of this instruction
	stack->fTime.count("lda");

}


/** 
*	Prints the instuction into an outputstream
*	@return			reference to ostream filled with the printed instruction
*	@param os		reference to ostream (ostream&)	
*	@exception		none
*/
ostream& Lda::print(ostream &os) const
{
	os << "lda " << fP << " " << fQ;
	return os;
}
