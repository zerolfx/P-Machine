// ind.h


#ifndef IND_H
#define IND_H


#include <vector>
#include <typeinfo>
using namespace std;

#include "stackmachine.h"
#include "executionerror.h"
#include "stackelement.h"
#include "instruction.h"


/**
* 	@doc		Loads indirectly using the highest stack location.
*	@author 	Andy Zaidman
*/
class Ind : public Instruction
{
	public:
		Ind(StackElementType type);
		~Ind();
		void execute(StackMachine *stack);
		ostream& print(ostream &os) const;
	
	private:
		StackElementType fType;
};


#endif

