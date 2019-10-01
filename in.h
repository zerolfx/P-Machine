// in.h


#ifndef IN_H
#define IN_H


#include <vector>
#include <typeinfo>
using namespace std;

#include "stackmachine.h"
#include "executionerror.h"
#include "stackelement.h"
#include "instruction.h"


/**
* 	@doc		Reads from the standard input
*	@author 	Andy Zaidman
*/
class In : public Instruction
{
	public:
		In(StackElementType type);
		~In();
		void execute(StackMachine *stack);
		ostream& print(ostream &os) const;
	
	private:
		StackElementType fType;
};


#endif
