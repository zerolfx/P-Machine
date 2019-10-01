// ret.h


#ifndef RETP_H
#define RETP_H


#include <vector>
#include <string>
#include <typeinfo>
using namespace std;

#include "stackmachine.h"
#include "executionerror.h"
#include "stackelement.h"
#include "instruction.h"


/**
* 	@doc		Implements the "return from procedure" instruction
*	@author 	Andy Zaidman
*/
class Retp : public Instruction
{
	public:
		Retp();
		~Retp();
		void execute(StackMachine *stack);
		ostream& print(ostream &os) const;		
};


#endif
