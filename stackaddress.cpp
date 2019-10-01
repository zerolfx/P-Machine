// stackadddress.cpp

#include "stackaddress.h"


/** 
*	Constructor
*	@param address		value of the StackAddress-object (int; default value "0")
*/
StackAddress::StackAddress(int address) : fAddress(address) {}


/** 
*	Destructor
*/
StackAddress::~StackAddress() {}


/** 
*	Adds the parameter to the current StackAddress-value
*	@return			none
*	@param op		the StackAddress you want to add to the current one (StackElement*)
*	@exception		none
*/
void StackAddress::add(StackElement *op)
{
	StackAddress *op1 = dynamic_cast<StackAddress*>(op);
	fAddress += op1->fAddress;
}


/** 
*	Subtracts the parameter from the current StackAddress-value
*	@return			none
*	@param op		the StackAddress you want to subtract from the current one (StackElement*)
*	@exception		none
*/
void StackAddress::sub(StackElement *op)
{
	StackAddress *op1 = dynamic_cast<StackAddress*>(op);
	fAddress -= op1->fAddress;
}


/** 
*	Multiplies the parameter with the current StackAddress-value
*	@return			none
*	@param op		the StackAddress you want to multiply with the current one (StackElement*)
*	@exception		none
*/
void StackAddress::mul(StackElement *op)
{
	StackAddress *op1 = dynamic_cast<StackAddress*>(op);
	fAddress *= op1->fAddress;
}


/** 
*	Divides the current StackAddress value with the parameter's value
*	@return			none
*	@param op		the StackAddress that contains the divider
*	@exception		none
*/
void StackAddress::div(StackElement *op)
{
	StackAddress *op1 = dynamic_cast<StackAddress*>(op);
	fAddress /= op1->fAddress;
}


/** 
*	Switches the sign of the current StackAddress-value
*	@return			none
*	@exception		none
*/
void StackAddress::neg()
{
	fAddress = -fAddress;
}


/** 
*	Checks whether the 2 StackAddress are equal
*	@return			bool: true on equal
*	@param kOp		the second operand
*	@exception		none
*/
bool StackAddress::equ(const StackElement *kOp) const
{
	const StackAddress *op1 = dynamic_cast<const StackAddress*>(kOp);
	if(fAddress == op1->fAddress)
		return true;
	else
		return false;
}


/** 
*	Checks whether the the current StackAddress-value is smaller than that from kOp
*	@return			bool: true on <
*	@param kOp		the second operand
*	@exception		none
*/
bool StackAddress::les(const StackElement *kOp) const
{
	const StackAddress *op1 = dynamic_cast<const StackAddress*>(kOp);
	if(fAddress < op1->fAddress)
		return true;
	else
		return false;
}


/** 
*	Checks whether the the current StackAddress-value is greater than that from kOp
*	@return			bool: true on >
*	@param kOp		the second operand
*	@exception		none
*/
bool StackAddress::grt(const StackElement *kOp) const
{
	const StackAddress *op1 = dynamic_cast<const StackAddress*>(kOp);
	if(fAddress > op1->fAddress)
		return true;
	else
		return false;
}


/** 
*	Returns the numeric value containted in the class
*	@return			int
*	@exception		none
*/
int StackAddress::getValue() const
{
	return fAddress;
}


/** 
*	Increments the numeric value
*	@return			none
*	@param kOp		the value to increment
*	@exception		none
*/
void StackAddress::inc(int increment)
{
	fAddress += increment;
}


/** 
*	Checks whether the address is a heap-address
*	@return			bool: true if the address is an address on the heap
*	@param kOp		the value to increment
*	@exception		none
*/
bool StackAddress::heapAddress()
{
	if(fAddress < 0)
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
ostream& StackAddress::print(ostream &os) const
{
	os << fAddress;
	return os;
}


/** 
*	Returns a char that specifies the type of the class
*	@return			char
*	@exception		none
*/
char StackAddress::getType() const
{
	return 'a';
}
