// ind.cpp

#include "ind.h"

/** 
*	Constructor
*	@param type		specifies on which type to load indirectly (StackElementType)
*/
Ind::Ind(StackElementType type) : fType(type) {}


/** 
*	Destructor
*/
Ind::~Ind() {}


/** 
*	Checks whether the location pointed to by STORE[SP] contains an element of type address. Distinguishes between an indirect load from the stack or from the heap and then loads the element if the type of the element is correct
*	@return			none
*	@param stack	the machine on which the operation is performed (StackMachine*)
*	@exception		ExecutionError
*/
void Ind::execute(StackMachine *stack)
{
	StackAddress p;
	
	if(typeid(p) != typeid(*(stack->fStore[stack->fSP])))
		throw ExecutionError("instruction ind: type pointed to by SP is not of type address.");
		
	StackAddress *oldpointer = dynamic_cast<StackAddress*>(stack->fStore[stack->fSP]);	
	
	StackElement *object;
	if(stack->fStore[stack->fSP]->heapAddress())
	{
		if(stack->fStore[stack->fSP]->getValue() < stack->fNP)
		{
			throw ExecutionError("instruction ind: invalid heap address.");
		}
		else
		{
			object = stack->fHeap[-stack->fStore[stack->fSP]->getValue() - 1];
		}
	}
	else
	{
		if(stack->fStore[stack->fSP]->getValue() > stack->fSP)
			throw ExecutionError("instruction ind: invalid stack address.");
		else
			object = stack->fStore[stack->fStore[stack->fSP]->getValue()];
	}
	
	switch(fType)
	{
		case integer:
		{
			StackInteger p1;

			if(typeid(p1) != typeid(*object))
			{
				throw ExecutionError("instruction ind: type pointed to is not of type integer.");
			}
			else
			{
				stack->fStore[stack->fSP] = new StackInteger(*(dynamic_cast<StackInteger*>(object)));
			}
				
			break;
		}	
		case real:
		{
			StackReal p1;

			if(typeid(p1) != typeid(*object))
			{
				throw ExecutionError("instruction ind: type pointed to is not of type real.");
			}
			else
			{
				stack->fStore[stack->fSP] = new StackReal(*(dynamic_cast<StackReal*>(object)));

			}

			break;
		}
		case boolean:
		{
			StackBoolean p1;
			
			if(typeid(p1) != typeid(*object))
			{
				throw ExecutionError("instruction ind: type pointed to is not of type boolean.");
			}
			else
			{
				stack->fStore[stack->fSP] = new StackBoolean(*(dynamic_cast<StackBoolean*>(object)));
			}

			break;
		}
		case character:
		{
			StackCharacter p1;
			
			if(typeid(p1) != typeid(*object))
			{
				throw ExecutionError("instruction ind: type pointed to is not of type character.");
			}
			else
			{
				stack->fStore[stack->fSP] = new StackCharacter(*(dynamic_cast<StackCharacter*>(object)));
			}


			break;
		}
		case address:
		{
			StackAddress p1;

			if(typeid(p1) != typeid(*object))
			{
				throw ExecutionError("instruction ind: type pointed to is not of type address.");
			}
			else
			{
				stack->fStore[stack->fSP] = new StackAddress(*(dynamic_cast<StackAddress*>(object)));
			}
				
			break;
		}
	}
	
	delete oldpointer;	
	
	// adding cost of this instruction
	stack->fTime.count("ind");

}


/** 
*	Prints the instuction into an outputstream
*	@return			reference to ostream filled with the printed instruction
*	@param os		reference to ostream (ostream&)	
*	@exception		none
*/
ostream& Ind::print(ostream &os) const
{
	os << "ind " << printStackElementType(fType);
	return os;
}
