// geq.h

#ifndef GEQ_H
#define GEQ_H


#include <vector>
#include <typeinfo>
using namespace std;

#include "stackmachine.h"
#include "executionerror.h"
#include "stackelement.h"
#include "instruction.h"


/**
* 	@doc		Implements the geq-operation (greater or equal)
*	@author 	Andy Zaidman
*/
class Geq : public Instruction
{
	public:
		Geq(StackElementType type);
		~Geq();
		void execute(StackMachine *stack);
		ostream& print(ostream &os) const;
	
	private:
		StackElementType fType;
};


#endif

