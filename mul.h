// mul.h


#ifndef MUL_H
#define MUL_H


#include <vector>
#include <typeinfo>
using namespace std;

#include "stackmachine.h"
#include "executionerror.h"
#include "stackelement.h"
#include "instruction.h"


/**
* 	@doc		Implements the multiplication by multiplying the 2 uppermost stackpositions and replacing them by the result
*	@author 	Andy Zaidman
*/
class Mul : public Instruction
{
	public:
		Mul(StackElementType type);
		~Mul();
		void execute(StackMachine *stack);
		ostream& print(ostream &os) const;
	
	private:
		/// keeps track of the types (integer or real)
		StackElementType fType;
};


#endif
