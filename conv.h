// conv.h


#ifndef CONV_H
#define CONV_H

#include <vector>
#include <typeinfo>
using namespace std;

#include "stackmachine.h"
#include "executionerror.h"
#include "stackelement.h"
#include "instruction.h"


/**
*	@doc	Implements a conversion instruction: converts the element at STORE[SP]
*	@author	Andy Zaidman
*/
class Conv : public Instruction
{
	public:
		Conv(StackElementType type1, StackElementType type2);
		~Conv();
		void execute(StackMachine *stack);
		ostream& print(ostream &os) const;
		
	private:
		const StackElementType fType1;
		const StackElementType fType2;
};

#endif
