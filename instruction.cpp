//instruction.cpp

#include "instruction.h"

/** 
*	Constructor
*/
Instruction::Instruction() {;}


/**
*	Destructor
*/
Instruction::~Instruction() {;}


/** 
*	Helper function for printing the type of the element
*	@return		string containing the typespecification
*	@param type	enumeration type consisting of all types of the P-machine (StackElementType)
*	@exception	none
*/
string printStackElementType(StackElementType type)
{
	switch(type)
	{
		case integer:
			return "i";
			break;
		case real:
			return "r";
			break;
		case character:
			return "c";
			break;
		case boolean:
			return "b";
			break;
		case address:
			return "a";
			break;
	}
}


/** Output-operator for class Instruction
*	@return		reference to ostream (ostream&)
*	@param		os	: implicit argument (ostream&)
*	@param		kOutput: Instruction to be outputted (Instruction&)
*	@exception	none
*/
ostream& operator<<(ostream &os, const Instruction &kOutput)
{ 
	return kOutput.print(os);
}
