// Les.h

#ifndef LES_H
#define LES_H


#include <vector>
#include <typeinfo>
using namespace std;

#include "stackmachine.h"
#include "executionerror.h"
#include "stackelement.h"
#include "instruction.h"


/**
* 	@doc		Implements the les-operation
*	@author 	Andy Zaidman
*/
class Les : public Instruction
{
	public:
		Les(StackElementType type);
		~Les();
		void execute(StackMachine *stack);
		ostream& print(ostream &os) const;
			
	private:
		StackElementType fType;
};


#endif

