// mst.h


#ifndef MST_H
#define MST_H


#include <vector>
#include <string>
#include <typeinfo>
using namespace std;

#include "stackmachine.h"
#include "executionerror.h"
#include "stackelement.h"
#include "instruction.h"


/**
* 	@doc		Implements the "mark stack" instruction
*	@author 	Andy Zaidman
*/
class Mst : public Instruction
{
	public:
		Mst(int p);
		~Mst();
		void execute(StackMachine *stack);
		ostream& print(ostream &os) const;
			
	private:
		int fP;
};


#endif
