// str.cpp

#include "str.h"

/** 
*	Constructor
*	@param type		specifies which type you want to store (StackElementType)
*	@param p		difference in nesting depths (int)
*	@param q		relative address (int)
*/
Str::Str(StackElementType type, int p, int q) : fType(type), fP(p), fQ(q) {}


/** 
*	Destructor
*/
Str::~Str() {}


/** 
*	Checks whether the highest stackposition is occupied by the right type and if so, it stores it at the specified stackposition.
*	@return			none
*	@param stack	the machine on which the operation is performed (StackMachine*)
*	@exception		ExecutionError
*/
void Str::execute(StackMachine *stack)
{	
	switch(fType)
	{
		case integer:
		{
			StackInteger p;

			if(typeid(p) != typeid(*stack->fStore[stack->fSP]))
				throw ExecutionError("instruction str: element you are trying to access is not of type integer.");

			break;
		}	
		case real:
		{
			StackReal p;

			if(typeid(p) != typeid(*stack->fStore[stack->fSP]))
				throw ExecutionError("instruction str: element you are trying to access is not of type real.");


			break;
		}
		case boolean:
		{
			StackBoolean p;
			
			if(typeid(p) != typeid(*stack->fStore[stack->fSP]))
				throw ExecutionError("instruction str: element you are trying to access is not of type boolean.");

			break;
		}
		case character:
		{
			StackCharacter p;

			if(typeid(p) != typeid(*stack->fStore[stack->fSP]))
				throw ExecutionError("instruction str: element you are trying to access is not of type character.");

			break;
		}
		case address:
		{
			StackAddress p;
			
			if(typeid(p) != typeid(*stack->fStore[stack->fSP]))
				throw ExecutionError("instruction str: element you are trying to access is not of type address.");

			break;
		}
	}
	
	int newaddress = stack->base(fP, stack->fMP) + fQ;
	
	if((newaddress > stack->fSP) || (newaddress < 0))
		throw ExecutionError("instruction str: trying to access element above SP or < 0.");
	
	delete stack->fStore[newaddress];
	stack->fStore[newaddress] = stack->fStore[stack->fSP];
	stack->fStore.pop_back();
	
	--stack->fSP;
	
	// adding cost of this instruction
	stack->fTime.count("str");

}


/** 
*	Prints the instuction into an outputstream
*	@return			reference to ostream filled with the printed instruction
*	@param os		reference to ostream (ostream&)	
*	@exception		none
*/
ostream& Str::print(ostream &os) const
{
	os << "str " << printStackElementType(fType) << " " << fP << " " << fQ;
	return os;
}
