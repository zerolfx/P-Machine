//xor.cpp

#include "xor.h"


/**
*	Constructor
*/
Xor::Xor() {}


/**
*	Destructor
*/
Xor::~Xor() {}


/**
*	Checks whether the 2 highest stackentries contain booleans xor performs the xor-operation on them.
*	@return			none
*	@param stack	the machine on which the operation is performed (StackMachine*)
*	@exception		ExecutionError
*/
void Xor::execute(StackMachine *stack)
{
    // check if the stack contains at least two entries
    if(stack->fSP < 1)
        throw ExecutionError("instruction xor: requires 2 stackelements to be present.");

    StackBoolean p1;

    if(typeid(p1) != typeid(*(stack->fStore[stack->fSP])))
        throw ExecutionError("instruction xor: SP does not point to element of type boolean.");
    if(typeid(p1) != typeid(*(stack->fStore[stack->fSP - 1])))
        throw ExecutionError("instruction xor: SP - 1 does not point to element of type boolean.");


    // actual xor-operation
    stack->fStore[stack->fSP - 1]->xori(stack->fStore[stack->fSP]);

    // SP := SP - 1
    delete stack->fStore[stack->fSP];
    stack->fStore[stack->fSP] = 0;
    stack->fStore.pop_back();
    --stack->fSP;

    // adding cost of this instruction
    stack->fTime.count("xor");
}


/**
*	Prints the instuction into an outputstream
*	@return			reference to ostream filled with the printed instruction
*	@param os		reference to ostream (ostream&)
*	@exception		none
*/
ostream& Xor::print(ostream &os) const
{
    os << "xor";
    return os;
}
