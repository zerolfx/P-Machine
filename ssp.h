// ssp.h


#ifndef SSP_H
#define SSP_H


#include <vector>
#include <string>
#include <typeinfo>
using namespace std;

#include "stackmachine.h"
#include "executionerror.h"
#include "stackelement.h"
#include "instruction.h"


/**
* 	@doc		Implements the "set stack pointer" instruction
*	@author 	Andy Zaidman
*/
class Ssp : public Instruction
{
	public:
		Ssp(int p);
		~Ssp();
		void execute(StackMachine *stack);
		ostream& print(ostream &os) const;		
	
	private:
		int fP;
};


#endif
