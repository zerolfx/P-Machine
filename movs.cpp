// movs.cpp

#include "movs.h"

/** 
*	Constructor
*	@param q	number of memory locations to copy (int)
*/
Movs::Movs(int q) : fQ(q) {}


/** 
*	Destructor
*/
Movs::~Movs() {}


/** 
*	Area to be copied has static size (q). Here the area is copied, either from the stack or from the heap to the area above STORE[SP]
*	@return			none
*	@param stack	the machine on which the operation is performed (StackMachine*)
*	@exception		ExecutionError
*/
void Movs::execute(StackMachine *stack)
{	
	StackAddress p;
	
	if((stack->fSP < 0) || (typeid(p) != typeid(*(stack->fStore[stack->fSP]))))
		throw ExecutionError("instruction movs: highest stackposition expected to be of type address.");
		
	int newaddress = stack->fStore[stack->fSP]->getValue();

	delete stack->fStore[stack->fSP];
	stack->fStore[stack->fSP] = 0;
	stack->fStore.pop_back();
	
	if(newaddress < 0)
	{	
		// copying a block from the heapspace to the top of the stack
		// pay attention to the reverse with respect to what the book describes on p50
	
		StackInteger p1;
		StackBoolean p2;
		StackAddress p3;
		StackCharacter p4;
		StackReal p5;
		StackElement p6;
				
		for(int i = 0; i <= fQ - 1; ++i)
		{
			if(typeid(p1) == typeid(*stack->fHeap[- i - newaddress - 1]))
				stack->fStore.push_back(new StackInteger(*(dynamic_cast<StackInteger*>(stack->fHeap[i - newaddress]))));
			if(typeid(p2) == typeid(*stack->fHeap[- i - newaddress - 1]))
				stack->fStore.push_back(new StackBoolean(*(dynamic_cast<StackBoolean*>(stack->fHeap[i - newaddress]))));
			if(typeid(p3) == typeid(*stack->fHeap[- i - newaddress - 1]))
				stack->fStore.push_back(new StackAddress(*(dynamic_cast<StackAddress*>(stack->fHeap[i - newaddress]))));			
			if(typeid(p4) == typeid(*stack->fHeap[- i - newaddress - 1]))
				stack->fStore.push_back(new StackCharacter(*(dynamic_cast<StackCharacter*>(stack->fHeap[i - newaddress]))));
			if(typeid(p5) == typeid(*stack->fHeap[- i - newaddress - 1]))
				stack->fStore.push_back(new StackReal(*(dynamic_cast<StackReal*>(stack->fHeap[i - newaddress]))));
			if(typeid(p6) == typeid(*stack->fHeap[- i - newaddress - 1]))
				stack->fStore.push_back(new StackElement(*(dynamic_cast<StackElement*>(stack->fHeap[i - newaddress]))));
		}
	}
	else
	{
		// copying a block from the stackspace to the top of the stack
		// pay attention to the reverse with respect to what the book describes on p50

		StackInteger p1;
		StackBoolean p2;
		StackAddress p3;
		StackCharacter p4;
		StackReal p5;
		StackElement p6;
	
		for(int i = 0; i <= fQ - 1; ++i)
		{
			if(typeid(p1) == typeid(*stack->fStore[i + newaddress]))
				stack->fStore.push_back(new StackInteger(*(dynamic_cast<StackInteger*>(stack->fStore[i + newaddress]))));
			if(typeid(p2) == typeid(*stack->fStore[i + newaddress]))
				stack->fStore.push_back(new StackBoolean(*(dynamic_cast<StackBoolean*>(stack->fStore[i + newaddress]))));
			if(typeid(p3) == typeid(*stack->fStore[i + newaddress]))
				stack->fStore.push_back(new StackAddress(*(dynamic_cast<StackAddress*>(stack->fStore[i + newaddress]))));			
			if(typeid(p4) == typeid(*stack->fStore[i + newaddress]))
				stack->fStore.push_back(new StackCharacter(*(dynamic_cast<StackCharacter*>(stack->fStore[i + newaddress]))));
			if(typeid(p5) == typeid(*stack->fStore[i + newaddress]))
				stack->fStore.push_back(new StackReal(*(dynamic_cast<StackReal*>(stack->fStore[i + newaddress]))));
			if(typeid(p6) == typeid(*stack->fStore[i + newaddress]))
				stack->fStore.push_back(new StackElement(*(dynamic_cast<StackElement*>(stack->fStore[i + newaddress]))));
		}
	}
	
	stack->fSP = stack->fSP + fQ - 1;
	
	// adding cost of this instruction
	stack->fTime.count("movs");

}

/** 
*	Prints the instuction into an outputstream
*	@return			reference to ostream filled with the printed instruction
*	@param os		reference to ostream (ostream&)	
*	@exception		none
*/
ostream& Movs::print(ostream &os) const
{
	os << "movs " << fQ << endl;
	return os;
}
