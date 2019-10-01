#include "new.h"

/** 
*	Constructor
*/
New::New() {}


/** 
*	Destructor
*/
New::~New() {}


/** 
*	Checks whether the two uppermost stackpositions contain elements of type integer and address respectively and then replaces them with a pointer to the area on the heap
*	@return			none
*	@param stack	the machine on which the operation is performed (StackMachine*)
*	@exception		ExecutionError
*/
void New::execute(StackMachine *stack)
{
	StackInteger p1;
	StackAddress p2;
	
	if(typeid(p1) != typeid(*(stack->fStore[stack->fSP])))
		throw ExecutionError("instruction new: STORE[SP] does not contain element of type integer");
		
	if(typeid(p2) != typeid(*stack->fStore[stack->fSP - 1]))
		throw ExecutionError("instruction new: STORE[SP-1] does not contain element of type address");
	
	// prepare the heap by adding empty pointers to the vector
	for(int i = 0; i < stack->fStore[stack->fSP]->getValue(); ++i)
	{
		stack->fHeap.push_back(new StackElement());
	}
	
	stack->fNP = stack->fNP - stack->fStore[stack->fSP]->getValue();
	
	if(stack->fStore[stack->fSP - 1]->heapAddress())
	{
		if(stack->fStore[stack->fSP - 1]->getValue() < stack->fNP)
		{
			throw ExecutionError("instruction new: STORE[SP-1] points to a non-existing heap address");
		}
	}
	else
	{
		if(stack->fStore[stack->fSP - 1]->getValue() > stack->fSP - 2)
		{
			throw ExecutionError("instruction new: STORE[SP-1] points to an address which is > SP");
		}
	}
	
	delete stack->fStore[stack->fStore[stack->fSP - 1]->getValue()];
	stack->fStore[stack->fStore[stack->fSP - 1]->getValue()] = new StackAddress(stack->fNP);
	delete stack->fStore[stack->fSP];
	stack->fStore[stack->fSP] = 0;
	delete stack->fStore[stack->fSP - 1];
	stack->fStore[stack->fSP - 1] = 0;
	stack->fStore.pop_back();
	stack->fStore.pop_back();
	stack->fSP -= 2;
	
	// adding cost of this instruction
	stack->fTime.count("new");

}


/** 
*	Prints the instuction into an outputstream
*	@return			reference to ostream filled with the printed instruction
*	@param os		reference to ostream (ostream&)	
*	@exception		none
*/
ostream& New::print(ostream &os) const
{	
	os << "new";
	return os;
}

