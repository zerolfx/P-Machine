// and.h

#ifndef AND_H
#define AND_H


#include <vector>
#include <typeinfo>
using namespace std;

#include "stackmachine.h"
#include "executionerror.h"
#include "stackelement.h"
#include "instruction.h"


/**
* 	@doc		Implements the and instruction
*	@author 	Andy Zaidman
*/
class And : public Instruction
{
	public:
		And();
		~And();
		void execute(StackMachine *stack);
		ostream& print(ostream &os) const;
};


#endif
