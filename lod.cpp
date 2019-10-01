// lod.cpp

#include "lod.h"


/** 
*	Constructor
*	@param type	type of the element to be loaded (StackElementType)
*	@param p	difference in nesting depths (int)
*	@param q	relative address (int)
*/
Lod::Lod(StackElementType type, int p, int q) : fType(type), fP(p), fQ(q) {}


/** 
*	Destructor
*/
Lod::~Lod() {}


/** 
*	Checks whether the element at the give address is of the right type, the loads it to STORE[SP]
*	@return			none
*	@param stack	the machine on which the addition is performed (StackMachine*)
*	@exception		ExecutionError
*/
void Lod::execute(StackMachine *stack)
{

	if(stack->base(fP, stack->fMP) + fQ > stack->fSP)
		throw ExecutionError("instruction lod: trying to access element above SP");
		
	StackElement *element = stack->fStore[stack->base(fP, stack->fMP) + fQ];
	
	switch(fType)
	{
		case integer:
		{
			StackInteger p;

			if(typeid(p) != typeid(*element))
			{
				strstream convertor;
				convertor << "instruction lod: element at MP + " << fQ << " you are trying to access is not of type integer.";
				throw ExecutionError(convertor.str());
			}
			else
				stack->fStore.push_back(new StackInteger(*(dynamic_cast<StackInteger*>(element))));

			break;
		}	
		case real:
		{
			StackReal p;

			if(typeid(p) != typeid(*element))
			{
				strstream convertor;
				convertor << "instruction lod: element at MP + " << fQ << " you are trying to access is not of type real.";
				throw ExecutionError(convertor.str());
			}
			else
				stack->fStore.push_back(new StackReal(*(dynamic_cast<StackReal*>(element))));


			break;
		}
		case boolean:
		{
			StackBoolean p;
			
			if(typeid(p) != typeid(*element))
			{
				strstream convertor;
				convertor << "instruction lod: element at MP + " << fQ << " you are trying to access is not of type boolean.";
				throw ExecutionError(convertor.str());
			}
			else
				stack->fStore.push_back(new StackBoolean(*(dynamic_cast<StackBoolean*>(element))));


			break;
		}
		case character:
		{
			StackCharacter p;

			if(typeid(p) != typeid(*element))
			{
				strstream convertor;
				convertor << "instruction lod: element at MP + " << fQ << " you are trying to access is not of type character.";
				throw ExecutionError(convertor.str());
			}
			else
				stack->fStore.push_back(new StackCharacter(*(dynamic_cast<StackCharacter*>(element))));


			break;
		}
		case address:
		{
			StackAddress p;
			
			if(typeid(p) != typeid(*element))
			{
				strstream convertor;
				convertor << "instruction lod: element at MP + " << fQ << " you are trying to access is not of type address.";
				throw ExecutionError(convertor.str());
			}
			else
				stack->fStore.push_back(new StackAddress(*(dynamic_cast<StackAddress*>(element))));


			break;
		}
	}
	
	++stack->fSP;
	
	// adding cost of this instruction
	stack->fTime.count("lod");

}


/** 
*	Prints the instuction into an outputstream
*	@return			reference to ostream filled with the printed instruction
*	@param os		reference to ostream (ostream&)	
*	@exception		none
*/
ostream& Lod::print(ostream &os) const
{
	os << "lod " << printStackElementType(fType) << " " << fP << " " << fQ;
	return os;
}
