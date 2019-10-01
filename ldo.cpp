// ldo.cpp

#include "ldo.h"

/** 
*	Constructor
*	@param type		specifies which type to load (StackElementType)
*	@param q		absolute address from which to load element (int)
*/
Ldo::Ldo(StackElementType type, int q) : fType(type), fQ(q) {}


/** 
*	Destructor
*/
Ldo::~Ldo() {}


/** 
*	Checks whether the element at location q is of the right type and then places it at STORE[SP]
*	@return			none
*	@param stack	the machine on which the operation is performed (StackMachine*)
*	@exception		ExecutionError
*/
void Ldo::execute(StackMachine *stack)
{
	if(stack->fSP < fQ)
		throw ExecutionError("instruction ldo: no element present at STORE[q].");
		
	switch(fType)
	{
		case integer:
		{
			StackInteger p1;

			// check if STORE[q] is of type integer
			if(typeid(p1) != typeid(*stack->fStore[fQ]))
			{
				throw ExecutionError("instruction ldo: type of STORE[q] is not of type integer.");
			}
			else
			{
				stack->fStore.push_back(new StackInteger(*(dynamic_cast<StackInteger*>(stack->fStore[fQ]))));
			}
				
			break;
		}	
		case real:
		{
			StackReal p1;
			
			// check if STORE[q] is of type real
			if(typeid(p1) != typeid(*stack->fStore[fQ]))
			{
				throw ExecutionError("instruction ldo: type of STORE[q] is not of type real.");
			}
			else
			{
				stack->fStore.push_back(new StackReal(*(dynamic_cast<StackReal*>(stack->fStore[fQ]))));
			}


			break;
		}
		case boolean:
		{
			StackBoolean p1;
			
			// check if STORE[q] is of type boolean
			if(typeid(p1) != typeid(*stack->fStore[fQ]))
			{
				throw ExecutionError("instruction ldo: type of STORE[q] is not of type boolean.");
			}
			else
			{
				stack->fStore.push_back(new StackBoolean(*(dynamic_cast<StackBoolean*>(stack->fStore[fQ]))));
			}


			break;
		}
		case character:
		{
			StackCharacter p1;
			
			// check if STORE[q] is of type character
			if(typeid(p1) != typeid(*stack->fStore[fQ]))
			{
				throw ExecutionError("instruction ldo: type of STORE[q] is not of type character.");
			}
			else
			{
				stack->fStore.push_back(new StackCharacter(*(dynamic_cast<StackCharacter*>(stack->fStore[fQ]))));
			}


			break;
		}
		case address:
		{
			StackAddress p1;

			// check if STORE[q] is of type address
			if(typeid(p1) != typeid(*stack->fStore[fQ]))
			{
				throw ExecutionError("instruction ldo: type of STORE[q] is not of type address.");
			}
			else
			{
				stack->fStore.push_back(new StackAddress(*(dynamic_cast<StackAddress*>(stack->fStore[fQ]))));
			}

			break;
		}
	}
	
	// fSP = fSP + 1
	++stack->fSP;
	
	// adding cost of this instruction
	stack->fTime.count("ldo");

}


/** 
*	Prints the instuction into an outputstream
*	@return			reference to ostream filled with the printed instruction
*	@param os		reference to ostream (ostream&)	
*	@exception		none
*/
ostream& Ldo::print(ostream &os) const
{
	os << "ldo " << printStackElementType(fType) << " " << fQ;
	return os;
}
