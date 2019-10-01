// sli.cpp

#include "sli.h"

/** 
*	Constructor
*	@param type		type of element at STORE[SP] (StackElementType)
*/
Sli::Sli(StackElementType type) : fType(type) {}


/** 
*	Destructor
*/
Sli::~Sli() {}


/** 
*	Checks whether the highest stack position is occupied by an element of the right type and then stores it at STORE[SP-1]
*	@return			none
*	@param stack	the machine on which the instruction is performed (StackMachine*)
*	@exception		ExecutionError
*/
void Sli::execute(StackMachine *stack)
{
	if(stack->fSP < 1)
		throw ExecutionError("instruction sli: requires 2 stackelements to be present.");

	switch(fType)
	{
		case integer:
		{
			StackInteger p1;

			// check if uppermost stackentry is of type integer
			if(typeid(p1) != typeid(*stack->fStore[stack->fSP]))
				throw ExecutionError("instruction sli: SP does not point to element of type integer.");

			break;
		}	
		case real:
		{
			StackReal p1;
			// check if uppermost stackentry is of type real
			if(typeid(p1) != typeid(*stack->fStore[stack->fSP]))
				throw ExecutionError("instruction sli: SP does not point to element of type real.");

			break;
		}
		case boolean:
		{
			StackBoolean p1;
			
			// check if uppermost stackentry is of type boolean
			if(typeid(p1) != typeid(*stack->fStore[stack->fSP]))
				throw ExecutionError("instruction sli: SP does not point to element of type boolean.");

			break;
		}
		case character:
		{
			StackCharacter p1;
			
			// check if uppermost stackentry is of type character
			if(typeid(p1) != typeid(*stack->fStore[stack->fSP]))
				throw ExecutionError("instruction sli: SP does not point to element of type character.");

			break;
		}
		case address:
		{
			StackAddress p1;

			// check if constant is of type address
			if(typeid(p1) != typeid(*stack->fStore[stack->fSP]))
				throw ExecutionError("instruction sli: SP does not point to element of type address.");

			break;
		}
	}
	
	// actual operation
	delete stack->fStore[stack->fSP - 1];
	stack->fStore[stack->fSP - 1] = 0;
	stack->fStore[stack->fSP - 1] = stack->fStore[stack->fSP];
	stack->fStore.pop_back();
	
	// fSP = fSP - 1
	--stack->fSP;
	
	// adding cost of this instruction
	stack->fTime.count("sli");

}


/** 
*	Prints the instuction into an outputstream
*	@return			reference to ostream filled with the printed instruction
*	@param os		reference to ostream (ostream&)	
*	@exception		none
*/
ostream& Sli::print(ostream &os) const
{
	os << "sli " << printStackElementType(fType);
	return os;
}
