// ixa.cpp

#include "ixa.h"


/** 
*	Constructor
*	@param q	the size of the subarray (int)
*/
Ixa::Ixa(int q) : fQ(q) {}


/** 
*	Destructor
*/
Ixa::~Ixa() {}


/** 
*	Checks whether the 2 uppermost stackpositions contain an integer and an address respectively and then performs the compuation. Leaves an address at STORE[SP]
*	@return			none
*	@param stack	the machine on which the operation is performed (StackMachine*)
*	@exception		ExecutionError
*/
void Ixa::execute(StackMachine *stack)
{
	StackAddress p1;
	StackInteger p2;
	
	if(typeid(p1) != typeid(*(stack->fStore[stack->fSP - 1])))
		throw ExecutionError("instruction ixa: STORE[SP-1] does not contain an element of type address.");
		
	if(typeid(p2) != typeid(*(stack->fStore[stack->fSP])))
		throw ExecutionError("instruction ixa: STORE[SP] does not contain an element of type integer.");
		
	StackInteger temp(fQ);
	
	int newaddress = stack->fStore[stack->fSP - 1]->getValue() + stack->fStore[stack->fSP]->getValue() * fQ;
	
	delete stack->fStore[stack->fSP - 1];
	delete stack->fStore[stack->fSP];
	stack->fStore.pop_back();
	
	--stack->fSP;
	
	stack->fStore[stack->fSP] = new StackAddress(newaddress);
	
	// adding cost of this instruction
	stack->fTime.count("ixa");
}


/** 
*	Prints the instuction into an outputstream
*	@return			reference to ostream filled with the printed instruction
*	@param os		reference to ostream (ostream&)	
*	@exception		none
*/
ostream& Ixa::print(ostream &os) const
{
	os << "ixa " << fQ;
	return os;
}
