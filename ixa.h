// ixa.h


#ifndef IXA_H
#define IXA_H


#include <vector>
#include <typeinfo>
using namespace std;

#include "stackmachine.h"
#include "executionerror.h"
#include "stackelement.h"
#include "instruction.h"


/**
* 	@doc		Computation of indexed address. STORE[SP-1] contains a start address, STORE[SP] contains the index of the selected subarray and q contains the size of the subarray.
*	@author 	Andy Zaidman
*/
class Ixa : public Instruction
{
	public:
		Ixa(int q);
		~Ixa();
		void execute(StackMachine *stack);
		ostream& print(ostream &os) const;
	
	private:
		int fQ;
};


#endif

