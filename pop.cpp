//
// Created by zerol on 10/1/19.
//

#include "pop.h"

Pop::Pop() {}

Pop::~Pop() {}

void Pop::execute(StackMachine *stack)
{
    --stack->fSP;
}

ostream& Pop::print(ostream &os) const
{
    os << "pop";
    return os;
}