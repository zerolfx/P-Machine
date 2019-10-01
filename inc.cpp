// inc.cpp

#include "inc.h"


/** 
*	Constructor
*	@param type	type to increment (StackElementType)
*	@param q	incrementation value (int)
*/
Inc::Inc(StackElementType type, int p) : fType(type), fP(p) {}


/** 
*	Destructor
*/
Inc::~Inc() {}


/** 
*	Checks whether the element at STORE[SP] is of the right type and then increments it
*	@return			none
*	@param stack	the machine on which the operation is performed (StackMachine*)
*	@exception		ExecutionError
*/
void Inc::execute(StackMachine *stack)
{
	// check if the stack contains at least one entry
	
	if(stack->fSP < 0)
		throw ExecutionError("instruction inc: requires 1 stackelement to be present.");
		
	switch(fType)
	{
		case integer:
		{
			StackInteger p1;

			// check if the  uppermost stackentry is of type integer
			if(typeid(p1) != typeid(*(stack->fStore[stack->fSP])))
				throw ExecutionError("instruction inc: SP does not point to element of type integer.");

			break;
		}	
		case real:
		{
			StackReal p1;
			// check if the  uppermost stackentry is of type real
			if(typeid(p1) != typeid(*(stack->fStore[stack->fSP])))
				throw ExecutionError("instruction inc: SP does not point to element of type real.");

			break;
		}
		case boolean:
		{
			StackBoolean p1;
			// check if the  uppermost stackentry is of type boolean
			if(typeid(p1) != typeid(*(stack->fStore[stack->fSP])))
				throw ExecutionError("instruction inc: SP does not point to element of type boolean.");

			break;
		}
		case character:
		{
			StackCharacter p1;
			// check if the  uppermost stackentriy is of type character
			if(typeid(p1) != typeid(*(stack->fStore[stack->fSP])))
				throw ExecutionError("instruction inc: SP does not point to element of type character.");

			break;
		}
		case address:
		{
			StackAddress p1;
			// check if the uppermost stackentry is of type address
			if(typeid(p1) != typeid(*(stack->fStore[stack->fSP])))
				throw ExecutionError("instruction inc: SP does not point to element of type address.");

			break;
		}
	}
	
	// actual increment
	stack->fStore[stack->fSP]->inc(fP);
	
	// adding cost of this instruction
	stack->fTime.count("inc");

}


/** 
*	Prints the instuction into an outputstream
*	@return			reference to ostream filled with the printed instruction
*	@param os		reference to ostream (ostream&)	
*	@exception		none
*/
ostream& Inc::print(ostream &os) const
{
	os << "inc " << printStackElementType(fType) << " " << fP;
	return os;
}
