// inc.h


#ifndef INC_H
#define INC_H


#include <vector>
#include <string>
#include <typeinfo>
using namespace std;

#include "stackmachine.h"
#include "executionerror.h"
#include "stackelement.h"
#include "instruction.h"


/**
* 	@doc		Increments the element at STORE[SP]
*	@author 	Andy Zaidman
*/
class Inc : public Instruction
{
	public:
		Inc(StackElementType type, int p);
		~Inc();
		void execute(StackMachine *stack);
		ostream& print(ostream &os) const;
	
	private:
		int fP;
		StackElementType fType;
};


#endif

