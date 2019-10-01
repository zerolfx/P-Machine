// stackreal.cpp

#include "stackreal.h"


/** 
*	Constructor
*	@param real		value of the StackReal-object (double; default value "0")
*/
StackReal::StackReal(double real) : fReal(real) {}


/** 
*	Destructor
*/
StackReal::~StackReal() {}


/** 
*	Adds the parameter to the current StackReal-value
*	@return			none
*	@param op		the StackReal you want to add to the current one (StackElement*)
*	@exception		none
*/
void StackReal::add(StackElement *op)
{
	StackReal *op1 = dynamic_cast<StackReal*>(op);
	fReal += op1->fReal;
}


/** 
*	Subtracts the parameter from the current StackReal-value
*	@return			none
*	@param op		the StackReal you want to subtract from the current one (StackElement*)
*	@exception		none
*/
void StackReal::sub(StackElement *op)
{
	StackReal *op1 = dynamic_cast<StackReal*>(op);
	fReal -= op1->fReal;
}


/** 
*	Multiplies the parameter with the current StackReal-value
*	@return			none
*	@param op		the StackReal you want to multiply with the current one (StackElement*)
*	@exception		none
*/
void StackReal::mul(StackElement *op)
{
	StackReal *op1 = dynamic_cast<StackReal*>(op);
	fReal *= op1->fReal;
}


/** 
*	Divides the current StackReal value with the parameter's value
*	@return			none
*	@param op		the StackReal that contains the divider
*	@exception		none
*/
void StackReal::div(StackElement *op)
{
	StackReal *op1 = dynamic_cast<StackReal*>(op);
	fReal /= op1->fReal;
}


/** 
*	Switches the sign of the current StackReal-value
*	@return			none
*	@exception		none
*/
void StackReal::neg()
{
	fReal = -fReal;
}


/** 
*	Checks whether the 2 StackReals are equal
*	@return			bool: true on equal
*	@param kOp		the second operand
*	@exception		none
*/
bool StackReal::equ(const StackElement *kOp) const
{
	const StackReal *op1 = dynamic_cast<const StackReal*>(kOp);
	if(fReal == op1->fReal)
		return true;
	else
		return false;
}


/** 
*	Checks whether the the current StackReal-value is smaller than that from kOp
*	@return			bool: true on <
*	@param kOp		the second operand
*	@exception		none
*/
bool StackReal::les(const StackElement *kOp) const
{
	const StackReal *op1 = dynamic_cast<const StackReal*>(kOp);
	if(fReal < op1->fReal)
		return true;
	else
		return false;
}


/** 
*	Checks whether the the current StackReal-value is greater than that from kOp
*	@return			bool: true on >
*	@param kOp		the second operand
*	@exception		none
*/
bool StackReal::grt(const StackElement *kOp) const
{
	const StackReal *op1 = dynamic_cast<const StackReal*>(kOp);
	if(fReal > op1->fReal)
		return true;
	else
		return false;
}


/** 
*	Returns the numeric value containted in the class
*	@return			double
*	@exception		none
*/
double StackReal::getReal() const
{
	return fReal;
}


/** 
*	Increments the numeric value
*	@return			none
*	@param kOp		the value to increment
*	@exception		none
*/
void StackReal::inc(int increment)
{	
	fReal += increment;
}


/** 
*	Checks if the numeric value is zero (used to detect division by zero)
*	@return			bool: true if numeric value is zero
*	@exception		none
*/
bool StackReal::isZero()
{
	if (fReal == 0)
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
ostream& StackReal::print(ostream &os) const
{
	os << fReal;
	return os;
}


/** 
*	Returns a char that specifies the type of the class
*	@return			char
*	@exception		none
*/
char StackReal::getType() const
{
	return 'r';
}

