// equ.h

#ifndef EQU_H
#define EQU_H


#include <vector>
#include <typeinfo>
using namespace std;

#include "stackmachine.h"
#include "executionerror.h"
#include "stackelement.h"
#include "instruction.h"


/**
* 	@doc		Implements the "equal" instruction. 
*	@author 	Andy Zaidman
*/
class Equ : public Instruction
{
	public:
		Equ(StackElementType type);
		~Equ();
		void execute(StackMachine *stack);
		ostream& print(ostream &os) const;
	
	private:
		StackElementType fType;
};


#endif
