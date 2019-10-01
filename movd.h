// movd.h


#ifndef MOVD_H
#define MOVD_H


#include <vector>
#include <string>
#include <typeinfo>
using namespace std;

#include "stackmachine.h"
#include "executionerror.h"
#include "stackelement.h"
#include "instruction.h"


/**
* 	@doc		Implements the dynamic move instruction. Copies an array from a given array descriptor (to be found at relative address q).
*	@author 	Andy Zaidman
*/
class Movd : public Instruction
{
	public:
		Movd(int q);
		~Movd();
		void execute(StackMachine *stack);
		ostream& print(ostream &os) const;
	
	private:
		int fQ;
};


#endif
