// sro.cpp

#include "sro.h"

/** 
*	Constructor
*	@param type		type of data to store (StackElementType)
*	@param p		absolute address to store data at (int)
*/
Sro::Sro(StackElementType type, int q) : fType(type), fQ(q) {}


/** 
*	Destructor
*/
Sro::~Sro() {}


/** 
*	Checks whether the highest stack position is occupied by an element of the right type and then stores it at the given abolsute address
*	@return			none
*	@param stack	the machine on which the instruction is performed (StackMachine*)
*	@exception		ExecutionError
*/
void Sro::execute(StackMachine *stack)
{
	if(stack->fSP < 1)
		throw ExecutionError("instruction sro: at least 1 stackelement is required for this operation");

				
	switch(fType)
	{
		case integer:
		{
			StackInteger p1;

			if(typeid(p1) != typeid(*(stack->fStore[stack->fSP])))
			{
				throw ExecutionError("instruction sro: type pointed to by SP is not of type integer.");
			}
				
			break;
		}	
		case real:
		{
			StackReal p1;

			if(typeid(p1) != typeid(*(stack->fStore[stack->fSP])))
			{
				throw ExecutionError("instruction sro: type pointed to by SP is not of type real.");
			}

			break;
		}
		case boolean:
		{
			StackBoolean p1;
			
			if(typeid(p1) != typeid(*(stack->fStore[stack->fSP])))
			{
				throw ExecutionError("instruction sro: type pointed to by SP is not of type boolean.");
			}

			break;
		}
		case character:
		{
			StackCharacter p1;
			
			if(typeid(p1) != typeid(*(stack->fStore[stack->fSP])))
			{
				throw ExecutionError("instruction sro: type pointed to by SP is not of type character.");
			}


			break;
		}
		case address:
		{
			StackAddress p1;

			if(typeid(p1) != typeid(*(stack->fStore[stack->fSP])))
			{
				throw ExecutionError("instruction sro: type pointed to by SP is not of type address.");
			}
				
			break;
		}
	}
	
	if(fQ < 0)
	{
		// address on the heap
		if(fQ < stack->fNP)
			throw ExecutionError("instruction ind: invalid heap address.");
		else
		{
			stack->fHeap[fQ] = stack->fStore[stack->fSP];
		}
	}
	else
	{
		// address on the stack
		if(fQ > stack->fSP)
			throw ExecutionError("instruction ind: invalid stack address.");
		else
		{
			stack->fStore[fQ] = stack->fStore[stack->fSP];
		}
	}
	
	stack->fStore.pop_back();

	--stack->fSP;
	
	// adding cost of this instruction
	stack->fTime.count("sro");
}


/** 
*	Prints the instuction into an outputstream
*	@return			reference to ostream filled with the printed instruction
*	@param os		reference to ostream (ostream&)	
*	@exception		none
*/
ostream& Sro::print(ostream &os) const
{
	os << "sro " << printStackElementType(fType) << " " << fQ;
	return os;
}
