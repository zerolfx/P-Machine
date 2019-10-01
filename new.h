// new.h


#ifndef NEW_H
#define NEW_H


#include <vector>
#include <string>
#include <typeinfo>
using namespace std;

#include "stackmachine.h"
#include "executionerror.h"
#include "stackelement.h"
#include "instruction.h"


/**
* 	@doc		Implements the new instruction. Leaves a pointer on top of the stack.
*	@author 	Andy Zaidman
*/
class New : public Instruction
{
	public:
		New();
		~New();
		void execute(StackMachine *stack);
		ostream& print(ostream &os) const;
};


#endif
