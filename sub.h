// sub.h


#ifndef SUB_H
#define SUB_H


#include <vector>
#include <typeinfo>
using namespace std;

#include "stackmachine.h"
#include "executionerror.h"
#include "stackelement.h"
#include "instruction.h"


/**
* 	@doc		Implements the subtraction by subtracting the 2 uppermost stackpositions and replacing them by the result
*	@author 	Andy Zaidman
*/
class Sub : public Instruction
{
	public:
		Sub(StackElementType type);
		~Sub();
		void execute(StackMachine *stack);
		ostream& print(ostream &os) const;	

	private:
		/// keeps track of the types (integer or real)
		StackElementType fType;
		
};


#endif
