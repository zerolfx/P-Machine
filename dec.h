// dec.h


#ifndef DEC_H
#define DEC_H


#include <vector>
#include <string>
#include <typeinfo>
using namespace std;

#include "stackmachine.h"
#include "executionerror.h"
#include "stackelement.h"
#include "instruction.h"


/**
* 	@doc		Increments the element at STORE[SP]
*	@author 	Andy Zaidman
*/
class Dec : public Instruction
{
	public:
		Dec(StackElementType type, int p);
		~Dec();
		void execute(StackMachine *stack);
		ostream& print(ostream &os) const;
	
	private:
		int fP;
		StackElementType fType;
};


#endif
