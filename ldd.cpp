//ldd.cpp

#include "ldd.h"

/** 
*	Constructor
*	@param q		relative address within descriptor array (int)
*/
Ldd::Ldd(int q) : fQ(q) {}


/** 
*	Destructor
*/
Ldd::~Ldd() {}


/** 
*	Checks whether the necessary elements are present on the stack and performs the operation.
*	@return			none
*	@param stack	the machine on which the operation is performed (StackMachine*)
*	@exception		ExecutionError
*/
void Ldd::execute(StackMachine *stack) 
{
	if(stack->fSP < 2)
		throw ExecutionError("instruction ldd: requires 3 stackelements to be present.");
	
	StackAddress p1;
	if(typeid(p1) != typeid(*(stack->fStore[stack->fSP - 2])))
		throw ExecutionError("instruction add: SP-2 does not point to element of type address.");
		
	++stack->fSP;
	
	stack->fStore.push_back(new StackInteger(stack->fStore[stack->fSP -3]->getValue() + fQ));
	
	// adding cost of this instruction
	stack->fTime.count("ldd");

}


/** 
*	Prints the instuction into an outputstream
*	@return			reference to ostream filled with the printed instruction
*	@param os		reference to ostream (ostream&)	
*	@exception		none
*/
ostream& Ldd::print(ostream &os) const
{
	os << "ldd " << fQ;
	return os;
}


