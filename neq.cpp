//neq.cpp

#include "neq.h"


/** 
*	Constructor
*	@param type		specifies on which type to perform the neq operation (StackElementType)
*/
Neq::Neq(StackElementType type): fType(type) {}


/** 
*	Destructor
*/
Neq::~Neq() {}


/** 
*	Checks whether the 2 uppermost stackpositions are of the right type and then performs the neq-operation.
*	@return			none
*	@param stack	the machine on which the operation is performed (StackMachine*)
*	@exception		ExecutionError
*/
void Neq::execute(StackMachine *stack) 
{
	// check if the stack contains at least two entries
	if(stack->fSP < 1)
		throw ExecutionError("instruction neq: requires 2 stackelements to be present.");

	switch(fType)
	{
		case integer:
		{
			StackInteger p1;
			// check if the two uppermost stackentries are of type integer
			if(typeid(p1) != typeid(*(stack->fStore[stack->fSP])))
				throw ExecutionError("instruction neq: SP does not point to element of type integer.");
			if(typeid(p1) != typeid(*(stack->fStore[stack->fSP - 1])))
				throw ExecutionError("instruction neq: SP - 1 does not point to element of type integer.");

			break;
		}	
		case real:
		{
			StackReal p1;
			// check if the two uppermost stackentries are of type real
			if(typeid(p1) != typeid(*(stack->fStore[stack->fSP])))
				throw ExecutionError("instruction neq: SP does not point to element of type real.");
			if(typeid(p1) != typeid(*(stack->fStore[stack->fSP - 1])))
				throw ExecutionError("instruction neq: SP - 1 does not point to element of type real.");
			break;
		}
		case boolean:
		{
			StackBoolean p1;
			// check if the two uppermost stackentries are of type real
			if(typeid(p1) != typeid(*(stack->fStore[stack->fSP])))
				throw ExecutionError("instruction neq: SP does not point to element of type boolean.");
			if(typeid(p1) != typeid(*(stack->fStore[stack->fSP - 1])))
				throw ExecutionError("instruction neq: SP - 1 does not point to element of type boolean.");
			break;
		}
		case character:
		{
			StackCharacter p1;
			// check if the two uppermost stackentries are of type real
			if(typeid(p1) != typeid(*(stack->fStore[stack->fSP])))
				throw ExecutionError("instruction neq: SP does not point to element of type character.");
			if(typeid(p1) != typeid(*(stack->fStore[stack->fSP - 1])))
				throw ExecutionError("instruction neq: SP - 1 does not point to element of type character.");
			break;
		}
		case address:
		{
			StackAddress p1;
			// check if the two uppermost stackentries are of type real
			if(typeid(p1) != typeid(*(stack->fStore[stack->fSP])))
				throw ExecutionError("instruction neq: SP does not point to element of type address.");
			if(typeid(p1) != typeid(*(stack->fStore[stack->fSP - 1])))
				throw ExecutionError("instruction neq: SP - 1 does not point to element of type address.");
			break;
		}

	}
		
	// compare
	StackBoolean *result;
	if(*(stack->fStore[stack->fSP - 1]) != *(stack->fStore[stack->fSP]))
		result = new StackBoolean(true);
	else
		result = new StackBoolean(false);
		
	// remove operands
	delete stack->fStore[stack->fSP];
	stack->fStore[stack->fSP] = 0;
	delete stack->fStore[stack->fSP - 1];
	stack->fStore[stack->fSP - 1] = 0;
	stack->fStore.pop_back();
	stack->fStore.pop_back();
	--stack->fSP;

	// put result on top of stack
	stack->fStore.push_back(result);
	
	// adding cost of this instruction
	stack->fTime.count("neq");

}


/** 
*	Prints the instuction into an outputstream
*	@return			reference to ostream filled with the printed instruction
*	@param os		reference to ostream (ostream&)	
*	@exception		none
*/
ostream& Neq::print(ostream &os) const
{
	os << "neq " << printStackElementType(fType);
	return os;
}
