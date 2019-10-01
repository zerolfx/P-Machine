// add.h


#ifndef ADD_H
#define ADD_H


#include <vector>
#include <typeinfo>
using namespace std;

#include "stackmachine.h"
#include "executionerror.h"
#include "stackelement.h"
#include "instruction.h"


/**
* 	@doc		Implements the addition by adding the 2 uppermost stackpositions and replacing them by the result
*	@author 	Andy Zaidman
*/
class Add : public Instruction
{
	public:
		Add(StackElementType type);
		~Add();
		void execute(StackMachine *stack);
		ostream& print(ostream &os) const;
	
	private:
		/// keeps track of the types (integer or real)
		StackElementType fType;
};


#endif
