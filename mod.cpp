//
// Created by zerol on 10/1/19.
//

#include "mod.h"

Mod::Mod() {}

Mod::~Mod() {}

void Mod::execute(StackMachine *stack) {
    if(typeid(StackInteger) != typeid(*(stack->fStore[stack->fSP])))
        throw ExecutionError("instruction mod: SP does not point to element of type integer.");
    if(typeid(StackInteger) != typeid(*(stack->fStore[stack->fSP - 1])))
        throw ExecutionError("instruction mod: SP - 1 does not point to element of type integer.");


    // actual addition
    stack->fStore[stack->fSP - 1]->mod(stack->fStore[stack->fSP]);

    // SP := SP - 1
    delete stack->fStore[stack->fSP];
    stack->fStore[stack->fSP] = 0;
    stack->fStore.pop_back();
    --stack->fSP;

    stack->fTime.count("mod");
}

ostream & Mod::print(ostream &os) const {
    return os << "mod";
}