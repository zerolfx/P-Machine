// dpl.cpp

#include "dpl.h"

/** 
*	Constructor
*	@param type		specifies which type to duplicate (StackElementType)
*/
Dpl::Dpl(StackElementType type) : fType(type) {}


/** 
*	Destructor
*/
Dpl::~Dpl() {}


/** 
*	Checks whether the STORE[SP]-element is of the right type and then duplicates it
*	@return			none
*	@param stack	the machine on which the operation is performed (StackMachine*)
*	@exception		ExecutionError
*/
void Dpl::execute(StackMachine *stack)
{
	switch(fType)
	{
		case integer:
		{
			StackInteger p1;

			// check if uppermost stackentry is of type integer
			if(typeid(p1) != typeid(*stack->fStore[stack->fSP]))
			{
				throw ExecutionError("instruction dpl: SP does not point to element of type integer.");
			}
			else
			{
				stack->fStore.push_back(new StackInteger(*(dynamic_cast<StackInteger*>(stack->fStore[stack->fSP]))));
			}
				
			break;
		}	
		case real:
		{
			StackReal p1;
			// check if uppermost stackentry is of type real
			if(typeid(p1) != typeid(*stack->fStore[stack->fSP]))
			{
				throw ExecutionError("instruction dpl: SP does not point to element of type real.");
			}
			else
			{
				stack->fStore.push_back(new StackReal(*(dynamic_cast<StackReal*>(stack->fStore[stack->fSP]))));
			}


			break;
		}
		case boolean:
		{
			StackBoolean p1;
			
			// check if uppermost stackentry is of type boolean
			if(typeid(p1) != typeid(*stack->fStore[stack->fSP]))
			{
				throw ExecutionError("instruction dpl: SP does not point to element of type boolean.");
			}
			else
			{
				stack->fStore.push_back(new StackBoolean(*(dynamic_cast<StackBoolean*>(stack->fStore[stack->fSP]))));
			}


			break;
		}
		case character:
		{
			StackCharacter p1;
			
			// check if uppermost stackentry is of type character
			if(typeid(p1) != typeid(*stack->fStore[stack->fSP]))
			{
				throw ExecutionError("instruction dpl: SP does not point to element of type character.");
			}
			else
			{
				stack->fStore.push_back(new StackCharacter(*(dynamic_cast<StackCharacter*>(stack->fStore[stack->fSP]))));
			}


			break;
		}
		case address:
		{
			StackAddress p1;

			// check if constant is of type address
			if(typeid(p1) != typeid(*stack->fStore[stack->fSP]))
			{
				throw ExecutionError("instruction dpl: SP does not point to element of type address.");
			}
			else
			{
				stack->fStore.push_back(new StackAddress(*(dynamic_cast<StackAddress*>(stack->fStore[stack->fSP]))));
			}

			break;
		}
	}
	
	// fSP = fSP + 1
	++stack->fSP;
	
	// adding cost of this instruction
	stack->fTime.count("dpl");

}


/** 
*	Prints the instuction into an outputstream
*	@return			reference to ostream filled with the printed instruction
*	@param os		reference to ostream (ostream&)	
*	@exception		none
*/
ostream& Dpl::print(ostream &os) const
{
	os << "dpl " << printStackElementType(fType);
	return os;
}
