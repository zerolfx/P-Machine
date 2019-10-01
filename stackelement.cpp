// stackelement.cpp
#include "stackelement.h"


/** 
*	Constructor
*/
StackElement::StackElement() {}


/** 
*	Destructor
*/
StackElement::~StackElement() {}

void StackElement::add(StackElement *op)
{
	cerr << "add not available for class StackElement" << endl;
}

void StackElement::sub(StackElement *op)
{
	cerr << "sub not available for class StackElement" << endl;
}

void StackElement::mul(StackElement *op)
{
	cerr << "mul not available for class StackElement" << endl;
}

void StackElement::div(StackElement *op)
{
	cerr << "dib not available for class StackElement" << endl;
}

void StackElement::andi(const StackElement *kOp)
{
	cerr << "andi not available for class StackElement" << endl;
}

void StackElement::ori(const StackElement *kOp)
{
	cerr << "ori not available for class StackElement" << endl;
}

void StackElement::noti()
{
	cerr << "noti not available for class StackElement" << endl;
}

void StackElement::neg()
{
	cerr << "neg not available for class StackElement" << endl;
}

bool StackElement::equ(const StackElement *kOp) const
{
	cerr << "equ not available for class StackElement" << endl;
	return true;
}

bool StackElement::les(const StackElement *kOp) const
{
	cerr << "les not available for class StackElement" << endl;
	return true;
}

bool StackElement::grt(const StackElement *kOp) const
{
	cerr << "grt not available for class StackElement" << endl;
	return true;
}

int StackElement::getValue() const
{
	cerr << "getValue() not available for class StackElement" << endl;
	return 0;
}

bool StackElement::getBoolean() const
{
	cerr << "getBoolean() not available for class StackElement" << endl;
	return true;
}

double StackElement::getReal() const
{
	cerr << "getReal() not available for class StackElement" << endl;
	return 0;
}

void StackElement::inc(int increment)
{
	cerr << "inc() is not available for class StackElement" << endl;
}

bool StackElement::heapAddress()
{
	cerr << "heapAddress() is not available for class StackElement" << endl;
	return true;
}

bool StackElement::isZero()
{
	cerr << "isZero() is not available for class StackElement" << endl;
	return true;
}


/** Output-operator for class StackElement
*	@return		reference to ostream (ostream&)
*	@param		os	: implicit argument (ostream&)
*	@param		kOutput: StackkElement to be outputted (const StackElement&)
*	@exception	none
*	@author		Andy Zaidman
*/
ostream& operator<<(ostream &os, const StackElement &kOutput)
{ 
	return kOutput.print(os);
}


/** Compares two StackElement-derived-classes for equality (both classes should be of same static type)
*	@param kOp1		lhs operand
*	@param kOp2		rhs operand	
*	@return 		bool: true on equal
*	@exception		none
*	@author			Andy Zaidman
*/
bool operator==(const StackElement &kOp1, const StackElement &kOp2)
{
	return kOp1.equ(&kOp2);
}


/** Compares two StackElement-derived-classes for inequality (both classes should be of same static type)
*	@param kOp1		lhs operand
*	@param kOp2		rhs operand	
*	@return 		bool: true on not equal
*	@exception		none
*	@author			Andy Zaidman
*/
bool operator!=(const StackElement &kOp1, const StackElement &kOp2)
{
	return !kOp1.equ(&kOp2);
}


/** Compares two StackElement-derived-classes for >= (both classes should be of same static type)
*	@param kOp1		lhs operand
*	@param kOp2		rhs operand	
*	@return 		bool: true on >=
*	@exception		none
*	@author			Andy Zaidman
*/
bool operator>=(const StackElement &kOp1, const StackElement &kOp2)
{
	return (kOp1.equ(&kOp2) || kOp1.grt(&kOp2));
}


/** Compares two StackElement-derived-classes for <= (both classes should be of same static type)
*	@param kOp1		lhs operand
*	@param kOp2		rhs operand	
*	@return 		bool: true on <=
*	@exception		none
*	@author			Andy Zaidman
*/
bool operator<=(const StackElement &kOp1, const StackElement &kOp2)
{
	return (kOp1.equ(&kOp2) || kOp1.les(&kOp2));
}


/** Compares two StackElement-derived-classes for < (both classes should be of same static type)
*	@param kOp1		lhs operand
*	@param kOp2		rhs operand	
*	@return 		bool: true on <
*	@exception		none
*	@author			Andy Zaidman
*/
bool operator<(const StackElement &kOp1, const StackElement &kOp2)
{
	return kOp1.les(&kOp2);
}


/** Compares two StackElement-derived-classes for > (both classes should be of same static type)
*	@param kOp1		lhs operand
*	@param kOp2		rhs operand	
*	@return 		bool: true on >
*	@exception		none
*	@author			Andy Zaidman
*/
bool operator>(const StackElement &kOp1, const StackElement &kOp2)
{
	return kOp1.grt(&kOp2);
}

ostream& StackElement::print(ostream &os) const
{
	os << "empty space";
	return os;
}

char StackElement::getType() const
{
	return ' ';
}







	

