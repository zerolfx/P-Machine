// neg.h

#ifndef NEG_H
#define NEG_H


#include <vector>
#include <typeinfo>
using namespace std;

#include "stackmachine.h"
#include "executionerror.h"
#include "stackelement.h"
#include "instruction.h"


/**
* 	@doc		Implements the "negation" instruction. Replace the value of the integer/real at STORE[SP] with "-value".
*	@author 	Andy Zaidman
*/
class Neg : public Instruction
{
	public:
		Neg(StackElementType type);
		~Neg();
		void execute(StackMachine *stack);
		ostream& print(ostream &os) const;
		
	private:
		StackElementType fType;
	
};


#endif
