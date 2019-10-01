// mst.cpp

#include "mst.h"


/** 
*	Constructor
*	@param p		difference in nesting depths (int)
*/
Mst::Mst(int p) : fP(p) {}


/** 
*	Destructor
*/
Mst::~Mst() {}


/** 
*	Prepares the stack for a call. Save static link, dynamic link en EP on stack.
*	@return			none
*	@param stack	the machine on which the operation is performed (StackMachine*)
*	@exception		ExecutionError
*/
void Mst::execute(StackMachine *stack)
{	
	for(int i = 0; i < 5; ++i)
	{
		stack->fStore.push_back(new StackElement());
	}

	// static link
	delete stack->fStore[stack->fSP + 2];
	stack->fStore[stack->fSP + 2] = new StackAddress(stack->base(fP, stack->fMP));

	// dynamic link
	delete stack->fStore[stack->fSP + 3];
	stack->fStore[stack->fSP + 3] = new StackAddress(stack->fMP);

	// save EP
	delete stack->fStore[stack->fSP + 4];
	stack->fStore[stack->fSP + 4] = new StackAddress(stack->fEP);
	
	stack->fSP += 5;
	
	// adding cost of this instruction
	stack->fTime.count("mst");

}


/** 
*	Prints the instuction into an outputstream
*	@return			reference to ostream filled with the printed instruction
*	@param os		reference to ostream (ostream&)	
*	@exception		none
*/
ostream& Mst::print(ostream &os) const
{
	os << "mst " << fP;
	return os;
}

