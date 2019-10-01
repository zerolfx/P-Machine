// stackboolean.cpp


#include "stackboolean.h"


/** 
*	Constructor
*	@param integer		value of the StackBoolean-object (bool; default value "false")
*/
StackBoolean::StackBoolean(bool boolean) : fBoolean(boolean) {}


/** 
*	Destructor
*/
StackBoolean::~StackBoolean() {}
						

/** 
*	Checks whether the 2 StackBooleans are equal
*	@return			bool: true on equal
*	@param kOp		the second operand
*	@exception		none
*/
bool StackBoolean::equ(const StackElement *kOp) const
{
	const StackBoolean *op1 = dynamic_cast<const StackBoolean*>(kOp);
	if(fBoolean == op1->fBoolean)
		return true;
	else
		return false;
}


/** 
*	Checks whether the the current StackBoolean-value is smaller than that from kOp
*	@return			bool: true on <
*	@param kOp		the second operand
*	@exception		none
*/
bool StackBoolean::les(const StackElement *kOp) const
{
	const StackBoolean *op1 = dynamic_cast<const StackBoolean*>(kOp);
	if(fBoolean < op1->fBoolean)
		return true;
	else
		return false;
}


/** 
*	Checks whether the the current StackBoolean-value is greater than that from kOp
*	@return			bool: true on >
*	@param kOp		the second operand
*	@exception		none
*/
bool StackBoolean::grt(const StackElement *kOp) const
{
	const StackBoolean *op1 = dynamic_cast<const StackBoolean*>(kOp);
	if(fBoolean > op1->fBoolean)
		return true;
	else
		return false;
}


/** 
*	Ands the current StackBoolean value with the parameter's value
*	@return			none
*	@param kOp		the StackBoolean to and with
*	@exception		none
*/
void StackBoolean::andi(const StackElement *kOp)
{
	const StackBoolean *op1 = dynamic_cast<const StackBoolean*>(kOp);
	fBoolean = fBoolean && op1->fBoolean;
}


/** 
*	Ors the current StackBoolean value with the parameter's value
*	@return			none
*	@param kOp		the StackBoolean to or with
*	@exception		none
*/
void StackBoolean::ori(const StackElement *kOp)
{
	const StackBoolean *op1 = dynamic_cast<const StackBoolean*>(kOp);
	fBoolean = fBoolean || op1->fBoolean;
}


/** 
*	Flips the boolean value (true --> false, false --> true)
*	@return			none
*	@exception		none
*/
void StackBoolean::noti()
{
	fBoolean = !fBoolean;
}


/** 
*	Returns the boolean value containted in the class
*	@return			bool
*	@exception		none
*/
bool StackBoolean::getBoolean() const
{
	return fBoolean;
}

/** 
*	Increments the boolean value
*	@return			none
*	@param kOp		the value to increment
*	@exception		none
*/
void StackBoolean::inc(int increment)
{
	fBoolean += increment;
}


/** 
*	Prints the boolean value ("t" of "f")
*	@return			ostream& where the numeric boolean is appended
*	@param os		the stream in which to put the output (ostream&)
*	@exception		none
*/
ostream& StackBoolean::print(ostream &os) const
{
	if(fBoolean)
		os << 't';
	else
		os << 'f';
	return os;

}


/** 
*	Returns a char that specifies the type of the class
*	@return			char
*	@exception		none
*/
char StackBoolean::getType() const
{
	return 'b';
}
		
