// chk.cpp

#include "chk.h"


/** 
*	Constructor
*	@param p		lower bound (int)
*	@param q		higher bound (int)
*/
Chk::Chk(int p, int q) : fP(p), fQ(q) {}


/** 
*	Destructor
*/
Chk::~Chk() {}


/** 
*	Checks whether STORE[SP] containts an integer and then checks if it lies between p and q
*	@return			none
*	@param stack	the machine on which the operation is performed (StackMachine*)
*	@exception		ExecutionError
*/
void Chk::execute(StackMachine *stack)
{
	StackInteger p;
	if(typeid(p) != typeid(*(stack->fStore[stack->fSP])))
	{
		throw ExecutionError("instruction chk: STORE[SP] does not contain element of type integer.");
	}
	
	if((stack->fStore[stack->fSP]->getValue() < fP) || (stack->fStore[stack->fSP]->getValue() > fQ))
	{
		throw ExecutionError("instruction chk: value out of range.");
	}
	
	// adding cost of this instruction
	stack->fTime.count("chk");

}


/** 
*	Prints the instuction into an outputstream
*	@return			reference to ostream filled with the printed instruction
*	@param os		reference to ostream (ostream&)	
*	@exception		none
*/
ostream& Chk::print(ostream &os) const
{
	os << "chk " << fP << " " << fQ;
	return os;
}
