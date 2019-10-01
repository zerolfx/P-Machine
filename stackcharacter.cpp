// stackcharacter.cpp

#include "stackcharacter.h"


/** 
*	Constructor
*	@param character		value of the StackCharacter-object (char)
*/
StackCharacter::StackCharacter(char character) : fCharacter(character) {}


/** 
*	Destructor
*/
StackCharacter::~StackCharacter() {}


/** 
*	Checks whether the 2 StackCharacters are equal
*	@return			bool: true on equal
*	@param kOp		the second operand
*	@exception		none
*/
bool StackCharacter::equ(const StackElement *kOp) const
{
	const StackCharacter *op1 = dynamic_cast<const StackCharacter*>(kOp);
	if(fCharacter == op1->fCharacter)
		return true;
	else
		return false;
}

/** 
*	Checks whether the the current StackCharacter-value is smaller than that from kOp
*	@return			bool: true on <
*	@param kOp		the second operand
*	@exception		none
*/
bool StackCharacter::les(const StackElement *kOp) const
{
	const StackCharacter *op1 = dynamic_cast<const StackCharacter*>(kOp);
	if(fCharacter < op1->fCharacter)
		return true;
	else
		return false;

}


/** 
*	Checks whether the the current StackInteger-value is greater than that from kOp
*	@return			bool: true on >
*	@param kOp		the second operand
*	@exception		none
*/
bool StackCharacter::grt(const StackElement *kOp) const
{
	const StackCharacter *op1 = dynamic_cast<const StackCharacter*>(kOp);
	if(fCharacter > op1->fCharacter)
		return true;
	else
		return false;
}


/** 
*	Returns the numeric value containted in the class (implicit conversion to int!!!)
*	@return			int
*	@exception		none
*/
int StackCharacter::getValue() const
{
	return static_cast<int>(fCharacter);
}


/** 
*	Increments the numeric value (the ASCII value)
*	@return			none
*	@param kOp		the value to increment
*	@exception		none
*/
void StackCharacter::inc(int increment)
{
	fCharacter += increment;
}


/** 
*	Prints the character
*	@return			ostream& where the character is appended
*	@param os		the stream in which to put the output (ostream&)
*	@exception		none
*/
ostream& StackCharacter::print(ostream &os) const
{
	os << fCharacter;
	return os;
}


/** 
*	Returns a char that specifies the type of the class
*	@return			char
*	@exception		none
*/
char StackCharacter::getType() const
{
	return 'c';
}
