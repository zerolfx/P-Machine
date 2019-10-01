// str.h


#ifndef STR_H
#define STR_H


#include <vector>
#include <string>
#include <typeinfo>
using namespace std;

#include "stackmachine.h"
#include "executionerror.h"
#include "stackelement.h"
#include "instruction.h"


/**
* 	@doc		Implements the "store relative" instruction
*	@author 	Andy Zaidman
*/

class Str : public Instruction
{
	public:
		Str(StackElementType type, int p, int q);
		~Str();
		void execute(StackMachine *stack);
		ostream& print(ostream &os) const;		
	
	private:
		StackElementType fType;
		int fP;
		int fQ;
};


#endif
