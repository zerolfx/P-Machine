// chk.h


#ifndef CHK_H
#define CHK_H


#include <vector>
#include <string>
#include <typeinfo>
using namespace std;

#include "stackmachine.h"
#include "executionerror.h"
#include "stackelement.h"
#include "instruction.h"


/**
* 	@doc		Check whether the highest stack value lies between p and q, inclusive. Halt with error message if not.
*	@author 	Andy Zaidman
*/
class Chk : public Instruction
{
	public:
		Chk(int p, int q);
		~Chk();
		void execute(StackMachine *stack);
		ostream& print(ostream &os) const;
	
	private:
		int fP;
		int fQ;
};


#endif
