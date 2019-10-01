// neq.h

#ifndef NEQ_H
#define NEQ_H


#include <vector>
#include <typeinfo>
using namespace std;

#include "stackmachine.h"
#include "executionerror.h"
#include "stackelement.h"
#include "instruction.h"


/**
* 	@doc		Implements the "not equal" instruction. 
*	@author 	Andy Zaidman
*/
class Neq : public Instruction
{
	public:
		Neq(StackElementType type);
		~Neq();
		void execute(StackMachine *stack);
		ostream& print(ostream &os) const;
			
	private:
		StackElementType fType;
};


#endif
