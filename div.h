// div.h


#ifndef DIV_H
#define DIV_H


#include <vector>
#include <typeinfo>
using namespace std;

#include "stackmachine.h"
#include "executionerror.h"
#include "stackelement.h"
#include "instruction.h"

class Div : public Instruction
{
	public:
		Div(StackElementType type);
		~Div();
		void execute(StackMachine *stack);
		ostream& print(ostream &os) const;
	
	private:
		StackElementType fType;
};


#endif
