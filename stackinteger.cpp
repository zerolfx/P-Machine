// stackinteger.cpp

#include "stackinteger.h"


/** 
*	Constructor
*	@param integer		value of the StackInteger-object (int; default value "0")
*/
StackInteger::StackInteger(int integer) : fInteger(integer) {}


/** 
*	Destructor
*/
StackInteger::~StackInteger() {}


/** 
*	Adds the parameter to the current StackInteger-value
*	@return			none
*	@param op		the StackInteger you want to add to the current one (StackElement*)
*	@exception		none
*/
void StackInteger::add(StackElement *op)
{
	StackInteger *op1 = dynamic_cast<StackInteger*>(op);
	fInteger += op1->fInteger;
}


/** 
*	Subtracts the parameter from the current StackInteger-value
*	@return			none
*	@param op		the StackInteger you want to subtract from the current one (StackElement*)
*	@exception		none
*/
void StackInteger::sub(StackElement *op)
{
	StackInteger *op1 = dynamic_cast<StackInteger*>(op);
	fInteger -= op1->fInteger;
}


/** 
*	Multiplies the parameter with the current StackInteger-value
*	@return			none
*	@param op		the StackInteger you want to multiply with the current one (StackElement*)
*	@exception		none
*/
void StackInteger::mul(StackElement *op)
{
	StackInteger *op1 = dynamic_cast<StackInteger*>(op);
	fInteger *= op1->fInteger;
}


/** 
*	Divides the current StackInteger value with the parameter's value
*	@return			none
*	@param op		the StackInteger that contains the divider
*	@exception		none
*/
void StackInteger::div(StackElement *op)
{
	StackInteger *op1 = dynamic_cast<StackInteger*>(op);
	fInteger /= op1->fInteger;
}


/** 
*	Switches the sign of the current StackInteger-value
*	@return			none
*	@exception		none
*/
void StackInteger::neg()
{
	fInteger = -fInteger;
}


/** 
*	Checks whether the 2 StackIntegers are equal
*	@return			bool: true on equal
*	@param kOp		the second operand
*	@exception		none
*/
bool StackInteger::equ(const StackElement *kOp) const
{
	const StackInteger *op1 = dynamic_cast<const StackInteger*>(kOp);
	if(fInteger == op1->fInteger)
		return true;
	else
		return false;
}


/** 
*	Checks whether the the current StackInteger-value is smaller than that from kOp
*	@return			bool: true on <
*	@param kOp		the second operand
*	@exception		none
*/
bool StackInteger::les(const StackElement *kOp) const
{
	const StackInteger *op1 = dynamic_cast<const StackInteger*>(kOp);
	if(fInteger < op1->fInteger)
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
bool StackInteger::grt(const StackElement *kOp) const
{
	const StackInteger *op1 = dynamic_cast<const StackInteger*>(kOp);
	if(fInteger > op1->fInteger)
		return true;
	else
		return false;

}


/** 
*	Returns the numeric value containted in the class
*	@return			int
*	@exception		none
*/
int StackInteger::getValue() const
{
	return fInteger;
}


/** 
*	Increments the numeric value
*	@return			none
*	@param kOp		the value to increment
*	@exception		none
*/
void StackInteger::inc(int increment)
{
	fInteger += increment;
}


/** 
*	Checks if the numeric value is zero (used to detect division by zero)
*	@return			bool: true if numeric value is zero
*	@exception		none
*/
bool StackInteger::isZero()
{
	if (fInteger == 0)
		return true;
	else
		return false;
}


/** 
*	Prints the numeric value
*	@return			ostream& where the numeric value is appended
*	@param os		the stream in which to put the output (ostream&)
*	@exception		none
*/
ostream& StackInteger::print(ostream &os) const
{
	os << fInteger;
	return os;
}


/** 
*	Returns a char that specifies the type of the class
*	@return			char
*	@exception		none
*/
char StackInteger::getType() const
{
	return 'i';
}
