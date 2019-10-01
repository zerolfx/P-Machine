// lda.h


#ifndef LDA_H
#define LDA_H


#include <vector>
#include <string>
#include <typeinfo>
using namespace std;

#include "stackmachine.h"
#include "executionerror.h"
#include "stackelement.h"
#include "instruction.h"


/**
* 	@doc		Implements the lda-instruction (load address for given difference in nesting depths p and a given relative address q)
*	@author 	Andy Zaidman
*/
class Lda : public Instruction
{
	public:
		Lda(int p, int q);
		~Lda();
		void execute(StackMachine *stack);
		ostream& print(ostream &os) const;
			
	private:
		int fP;
		int fQ;
};


#endif
