//
// Created by zerol on 10/1/19.
//

#ifndef P_POP_H
#define P_POP_H

#include <vector>
#include <string>
#include <typeinfo>
using namespace std;

#include "stackmachine.h"
#include "executionerror.h"
#include "stackelement.h"
#include "instruction.h"


class Pop : public Instruction
{
    public:
        Pop();
        ~Pop();
        void execute(StackMachine *stack);
        ostream& print(ostream &os) const;

};


#endif //P_POP_H
