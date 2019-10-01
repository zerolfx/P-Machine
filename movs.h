// movs.h


#ifndef MOVS_H
#define MOVS_H


#include <vector>
#include <string>
#include <typeinfo>
using namespace std;

#include "stackmachine.h"
#include "executionerror.h"
#include "stackelement.h"
#include "instruction.h"


/**
* 	@doc		Implements the "move static" instruction. Copies an area of size q to the top of the stack from the address that is located at the top of the stack
*	@author 	Andy Zaidman
*/
class Movs : public Instruction
{
	public:
		Movs(int q);
		~Movs();
		void execute(StackMachine *stack);
		ostream& print(ostream &os) const;
			
	private:
		int fQ;
};


#endif

