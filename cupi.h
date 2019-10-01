// cupi.h

#ifndef CUPI_H
#define CUPI_H


#include <vector>
#include <typeinfo>
using namespace std;

#include "stackmachine.h"
#include "executionerror.h"
#include "stackelement.h"
#include "instruction.h"


/**
* 	@doc		Implements the cupi-instruction: call user procedure indirectly
*	@author 	Andy Zaidman
*/
class Cupi : public Instruction
{
	public:
		Cupi(int p, int q);
		~Cupi();
		void execute(StackMachine *stack);
		ostream& print(ostream &os) const;
	
	private:
		int fP;
		int fQ;
};


#endif
