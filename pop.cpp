//
// Created by zerol on 10/1/19.
//

#include "pop.h"

Pop::Pop() {}

Pop::~Pop() {}

void Pop::execute(StackMachine *stack)
{
    // SP := SP - 1
    delete stack->fStore[stack->fSP];
    stack->fStore[stack->fSP] = 0;
    stack->fStore.pop_back();
    --stack->fSP;

    stack->fTime.count("pop");
}

ostream& Pop::print(ostream &os) const
{
    return os << "pop";
}