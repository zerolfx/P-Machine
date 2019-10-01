// dpl.h


#ifndef DPL_H
#define DPL_H


#include <vector>
#include <typeinfo>
using namespace std;

#include "stackmachine.h"
#include "executionerror.h"
#include "stackelement.h"
#include "instruction.h"


/**
* 	@doc		Implements the dpl-instruction: duplicates the uppermost stackentry
*	@author 	Andy Zaidman
*/
class Dpl : public Instruction
{
	public:
		Dpl(StackElementType type);
		~Dpl();
		void execute(StackMachine *stack);
		ostream& print(ostream &os) const;
	
	private:
		StackElementType fType;
};


#endif
