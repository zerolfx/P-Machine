// sli.h


#ifndef SLI_H
#define SLI_H


#include <vector>
#include <typeinfo>
using namespace std;

#include "stackmachine.h"
#include "executionerror.h"
#include "stackelement.h"
#include "instruction.h"


/**
* 	@doc		Implements the sli instruction: stores the highest stackposition at STORE[SP-1]
*	@author 	Andy Zaidman
*/
class Sli : public Instruction
{
	public:
		Sli(StackElementType type);
		~Sli();
		void execute(StackMachine *stack);
		ostream& print(ostream &os) const;		
	
	private:
		StackElementType fType;
};


#endif
