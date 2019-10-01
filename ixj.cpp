// ixj.cpp

#include "ixj.h"

/** 
*	Constructor
*	@param q	label of the portion of the program to jump to (string)
*/
Ixj::Ixj(string q) : fQ(q) {}


/** 
*	Destructor
*/
Ixj::~Ixj() {}


/** 
*	Checks whether STORE[SP] contains an integer and then executes the indexed branch to the address of the label (parameter q)
*	@return			none
*	@param stack	the machine on which the operation is performed (StackMachine*)
*	@exception		ExecutionError
*	@see			LabelCenter
*/
void Ixj::execute(StackMachine *stack)
{
	StackInteger p1;
			
	if(typeid(p1) != typeid(*stack->fStore[stack->fSP]))
		throw ExecutionError("instruction ixj: STORE[SP] does not contain an element of type integer.");
		
	stack->fPC = stack->fStore[stack->fSP]->getValue() + stack->fLabelCenter.getAddress(fQ);
	
	delete stack->fStore[stack->fSP];
	stack->fStore.pop_back();
	
	--stack->fSP;
	
	// adding cost of this instruction
	stack->fTime.count("ixj");

}


/** 
*	Prints the instuction into an outputstream
*	@return			reference to ostream filled with the printed instruction
*	@param os		reference to ostream (ostream&)	
*	@exception		none
*/
ostream& Ixj::print(ostream &os) const
{
	os << "ixj " << fQ;
	return os;
}
