// out.h


#ifndef OUT_H
#define OUT_H


#include <vector>
#include <typeinfo>
using namespace std;

#include "stackmachine.h"
#include "executionerror.h"
#include "stackelement.h"
#include "instruction.h"


/**
* 	@doc		Implements the output instruction... Two variants exists: one which specifies a precision for outputting reals, the other uses the standard output precision.
*	@author 	Andy Zaidman
*/
class Out : public Instruction
{
	public:
		Out(StackElementType type);
		Out(StackElementType type, bool precisionmarker);
		~Out();
		void execute(StackMachine *stack);
		ostream& print(ostream &os) const;
	
	private:
		StackElementType fType;
		bool fPrecisionMarker;
		int fPrecision;
};


#endif
