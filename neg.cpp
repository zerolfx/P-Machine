//neg.cpp

#include "neg.h"


/** 
*	Constructor
*	@param type		specifies on which type (integer, real)to perform the neg operation (StackElementType)
*/
Neg::Neg(StackElementType type) : fType(type) {}


/** 
*	Destructor
*/
Neg::~Neg() {}


/** 
*	Checks whether the uppermost stackentry is of type integer/real and then negates it.
*	@return			none
*	@param stack	the machine on which the operation is performed (StackMachine*)
*	@exception		ExecutionError
*/
void Neg::execute(StackMachine *stack) 
{
	// check if the stack contains at least one entry
	if(stack->fSP < 0)
		throw ExecutionError("instruction neg: requires 1 stackelement to be present.");
		
	switch(fType)
	{
		case integer:
		{
			StackInteger p1;

			// check if the uppermost stackentry is of type integer
			if(typeid(p1) != typeid(*(stack->fStore[stack->fSP])))
				throw ExecutionError("instruction add: SP does not point to element of type integer.");

			break;
		}	
		case real:
		{
			StackReal p1;
			// check if the uppermost stackentry is of type real
			if(typeid(p1) != typeid(*(stack->fStore[stack->fSP])))
				throw ExecutionError("instruction add: SP does not point to element of type real.");
				
			break;
		}
	}
	
	// actual operation
	stack->fStore[stack->fSP]->neg();
	
	// adding cost of this instruction
	stack->fTime.count("neg");
}


/** 
*	Prints the instuction into an outputstream
*	@return			reference to ostream filled with the printed instruction
*	@param os		reference to ostream (ostream&)	
*	@exception		none
*/
ostream& Neg::print(ostream &os) const
{
	os << "neg " << printStackElementType(fType);
	return os;
}
