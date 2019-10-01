// sep.h


#ifndef SEP_H
#define SEP_H


#include <vector>
#include <string>
#include <typeinfo>
using namespace std;

#include "stackmachine.h"
#include "executionerror.h"
#include "stackelement.h"
#include "instruction.h"


/**
* 	@doc		Implements the sep instruction: sets the EP
*	@author 	Andy Zaidman
*/
class Sep : public Instruction
{
	public:
		Sep(int p);
		~Sep();
		void execute(StackMachine *stack);
		ostream& print(ostream &os) const;		
			
	private:
		int fP;
};


#endif
