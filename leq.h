// leq.h

#ifndef LEQ_H
#define LEQ_H


#include <vector>
#include <typeinfo>
using namespace std;

#include "stackmachine.h"
#include "executionerror.h"
#include "stackelement.h"
#include "instruction.h"


/**
* 	@doc		Implements the les-operation (less or equal)
*	@author 	Andy Zaidman
*/
class Leq : public Instruction
{
	public:
		Leq(StackElementType type);
		~Leq();
		void execute(StackMachine *stack);
		ostream& print(ostream &os) const;
			
	private:
		StackElementType fType;
};


#endif

