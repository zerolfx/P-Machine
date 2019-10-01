// ldc.cpp

#include "ldc.h"

/** 
*	Constructor
*	@param type			indicates which kind of element is loaded(StackElementType)
*	@param constant		pointer to element which will be loaded at runtime(StackElement*)
*/
Ldc::Ldc(StackElementType type, StackElement *constant) : fType(type), fConstant(constant) {}


/** 
*	Destructor
*/
Ldc::~Ldc()
{
	delete fConstant;
}

/** 
*	Checks whether the indicated type is the same as the loaded type and then loads it.
*	@return			none
*	@param stack	the machine on which the operation is performed (StackMachine*)
*	@exception		ExecutionError
*/
void Ldc::execute(StackMachine *stack)
{
	switch(fType)
	{
		case integer:
		{
			StackInteger p1;

			// check if constant is of type integer
			if(typeid(p1) != typeid(*fConstant))
			{
				throw ExecutionError("instruction ldc: type of constant is not of type integer.");
			}
			else
			{
				stack->fStore.push_back(new StackInteger(*(dynamic_cast<StackInteger*>(fConstant))));
			}
				
			break;
		}	
		case real:
		{
			StackReal p1;
			// check if constant is of type real
			if(typeid(p1) != typeid(*fConstant))
			{
				throw ExecutionError("instruction ldc: type of constant is not of type real.");
			}
			else
			{
				stack->fStore.push_back(new StackReal(*(dynamic_cast<StackReal*>(fConstant))));
			}

			break;
		}
		case boolean:
		{
			StackBoolean p1;
			
			// check if constant is of type boolean
			if(typeid(p1) != typeid(*fConstant))
			{
				throw ExecutionError("instruction ldc: type of constant is not of type boolean.");
			}
			else
			{
				stack->fStore.push_back(new StackBoolean(*(dynamic_cast<StackBoolean*>(fConstant))));
			}

			break;
		}
		case character:
		{
			StackCharacter p1;
			
			// check if constant is of type character
			if(typeid(p1) != typeid(*fConstant))
			{
				throw ExecutionError("instruction ldc: type of constant is not of type character.");
			}
			else
			{
				stack->fStore.push_back(new StackCharacter(*(dynamic_cast<StackCharacter*>(fConstant))));
			}

			break;
		}
		case address:
		{
			StackAddress p1;

			// check if constant is of type address
			
			if(typeid(p1) != typeid(*fConstant))
			{
				throw ExecutionError("instruction ldc: type of constant is not of type address.");
			}
			else
			{
				stack->fStore.push_back(new StackAddress(*(dynamic_cast<StackAddress*>(fConstant))));
			}

			break;
		}
	}
	
	// fSP = fSP + 1
	++stack->fSP;
	
	// adding cost of this instruction
	stack->fTime.count("ldc");

}


/** 
*	Prints the instuction into an outputstream
*	@return			reference to ostream filled with the printed instruction
*	@param os		reference to ostream (ostream&)	
*	@exception		none
*/
ostream& Ldc::print(ostream &os) const
{
	os << "ldc " << printStackElementType(fType) << " " << *fConstant;
	return os;
}
