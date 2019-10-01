//in.cpp

#include "in.h"


/** 
*	Constructor
*	@param type		specifies of which type the input is (StackElementType)
*/
In::In(StackElementType type) : fType(type) {}


/** 
*	Destructor
*/
In::~In() {}


/** 
*	Reads from stdin and creates an appropriate StackElement-derived-class
*	@return			none
*	@param stack	the machine on which the operation is performed (StackMachine*)
*	@exception		none
*/
void In::execute(StackMachine *stack) 
{	
	switch(fType)
	{
		case integer:
		{
			int inputvalue;
			cin >> inputvalue;
			stack->fStore.push_back(new StackInteger(inputvalue));
			break;
		}	
		case real:
		{
			double inputvalue;
			cin >> inputvalue;
			stack->fStore.push_back(new StackReal(inputvalue));
			break;
		}
		case character:
		{
			char inputvalue;
			cin >> inputvalue;
			stack->fStore.push_back(new StackCharacter(inputvalue));
			break;
		}
		case boolean:
		{
			bool inputvalue;
			cin >> inputvalue;
			stack->fStore.push_back(new StackBoolean(inputvalue));
			break;
		}
		case address:
		{
			throw ExecutionError("instruction in: input of address at runtime is not allowed");
		}
	}
	
	// SP := SP + 1
	++stack->fSP;
	
	// adding cost of this instruction
	stack->fTime.count("in");

}


/** 
*	Prints the instuction into an outputstream
*	@return			reference to ostream filled with the printed instruction
*	@param os		reference to ostream (ostream&)	
*	@exception		none
*/
ostream& In::print(ostream &os) const
{
	os << "in " << printStackElementType(fType);
	return os;
}


