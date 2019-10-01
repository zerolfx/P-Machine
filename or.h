// or.h

#ifndef OR_H
#define OR_H


#include <vector>
#include <typeinfo>
using namespace std;

#include "stackmachine.h"
#include "executionerror.h"
#include "stackelement.h"
#include "instruction.h"


/**
* 	@doc		Implements the or instruction.
*	@author 	Andy Zaidman
*/
class Or : public Instruction
{
	public:
		Or();
		~Or();
		void execute(StackMachine *stack);
		ostream& print(ostream &os) const;
			
};


#endif
