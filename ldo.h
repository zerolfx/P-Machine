// ldo.h

#ifndef LDO_H
#define LDO_H


#include <vector>
#include <typeinfo>
using namespace std;

#include "stackmachine.h"
#include "executionerror.h"
#include "stackelement.h"
#include "instruction.h"


/**
* 	@doc		Implements the ldo-instruction. Load from absolute address.
*	@author 	Andy Zaidman
*/
class Ldo : public Instruction
{
	public:
		Ldo(StackElementType type, int q);
		~Ldo();
		void execute(StackMachine *stack);
		ostream& print(ostream &os) const;
			
	private:
		StackElementType fType;
		int fQ;
};


#endif

