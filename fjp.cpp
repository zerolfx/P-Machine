// fjp.cpp

#include "fjp.h"


/** 
*	Constructor
*	@param q	label of the portion of the program to jump to (string)
*/
Fjp::Fjp(string q) : fQ(q) {}


/** 
*	Destructor
*/
Fjp::~Fjp() {}


/** 
*	Checks STORE[SP] for the presence of a boolean, checks it for true/false and on false it jumps to the specified label
*	@return			none
*	@param stack	the machine on which the operation is performed (StackMachine*)
*	@exception		ExecutionError
*	@see			LabelCenter
*/
void Fjp::execute(StackMachine *stack)
{
	StackBoolean p;
	
	if(typeid(p) != typeid(*(stack->fStore[stack->fSP])))
		throw ExecutionError("instruction fjp: requires a boolean te be on top of the stack.");

	if(stack->fStore[stack->fSP]->getBoolean() == false)
	{
		stack->fPC = stack->fLabelCenter.getAddress(fQ);
	}
	
	delete stack->fStore[stack->fSP];
	stack->fStore.pop_back();
	--stack->fSP;
	
	// adding cost of this instruction
	stack->fTime.count("fjp");

}


/** 
*	Prints the instuction into an outputstream
*	@return			reference to ostream filled with the printed instruction
*	@param os		reference to ostream (ostream&)	
*	@exception		none
*/
ostream& Fjp::print(ostream &os) const
{
	os << "fjp " << fQ;
	return os;
}
