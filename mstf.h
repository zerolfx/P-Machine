// mstf.h

#ifndef MSTF_H
#define MSTF_H


#include <vector>
#include <typeinfo>
using namespace std;

#include "stackmachine.h"
#include "executionerror.h"
#include "stackelement.h"
#include "instruction.h"


/**
* 	@doc		Implements the "mark stack for formal procedure" instruction
*	@author 	Andy Zaidman
*/
class Mstf : public Instruction
{
	public:
		Mstf(int p, int q);
		~Mstf();
		void execute(StackMachine *stack);
		ostream& print(ostream &os) const;
	
	private:
		int fP;
		int fQ;
};


#endif
