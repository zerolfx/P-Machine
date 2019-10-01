//
// Created by zerol on 10/1/19.
//

#ifndef P_MOD_H
#define P_MOD_H


#include <vector>
#include <typeinfo>
using namespace std;

#include "stackmachine.h"
#include "executionerror.h"
#include "stackelement.h"
#include "instruction.h"

class Mod : public Instruction
{
public:
    Mod();
    ~Mod();
    void execute(StackMachine *stack);
    ostream& print(ostream &os) const;
};

#endif //P_MOD_H
