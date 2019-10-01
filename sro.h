// sro.h


#ifndef SRO_H
#define SRO_H


#include <vector>
#include <typeinfo>
using namespace std;

#include "stackmachine.h"
#include "executionerror.h"
#include "stackelement.h"
#include "instruction.h"


/**
* 	@doc		Implements the store instruction which stores at an absolute address
*	@author 	Andy Zaidman
*/
class Sro : public Instruction
{
	public:
		Sro(StackElementType type, int q);
		~Sro();
		void execute(StackMachine *stack);
		ostream& print(ostream &os) const;
		
	private:
		StackElementType fType;
		int fQ;
};


#endif
