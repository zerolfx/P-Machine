// retf.h


#ifndef RETF_H
#define RETF_H


#include <vector>
#include <string>
#include <typeinfo>
using namespace std;

#include "stackmachine.h"
#include "executionerror.h"
#include "stackelement.h"
#include "instruction.h"


/**
* 	@doc		Implements the "return from function" instruction: the return value is put on top of the stack
*	@author 	Andy Zaidman
*/
class Retf : public Instruction
{
	public:
		Retf();
		~Retf();
		void execute(StackMachine *stack);
		ostream& print(ostream &os) const;
};


#endif
