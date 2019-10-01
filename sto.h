// sto.h


#ifndef STO_H
#define STO_H


#include <vector>
#include <typeinfo>
using namespace std;

#include "stackmachine.h"
#include "executionerror.h"
#include "stackelement.h"
#include "instruction.h"


/**
* 	@doc		Implements the store instruction: stores in STORE[SP] in the location pointed to by STORE[SP-1].
*	@author 	Andy Zaidman
*/
class Sto : public Instruction
{
	public:
		Sto(StackElementType type);
		~Sto();
		void execute(StackMachine *stack);
		ostream& print(ostream &os) const;
	
	private:
		StackElementType fType;
};


#endif
