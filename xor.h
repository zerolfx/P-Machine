// xor.h

#ifndef Xor_H
#define Xor_H


#include <vector>
#include <typeinfo>
using namespace std;

#include "stackmachine.h"
#include "executionerror.h"
#include "stackelement.h"
#include "instruction.h"


/**
* 	@doc		Implements the xor instruction
*	@author 	Andy Zaidman
*/
class Xor : public Instruction
{
public:
    Xor();
    ~Xor();
    void execute(StackMachine *stack);
    ostream& print(ostream &os) const;
};


#endif
