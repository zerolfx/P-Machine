// ent.h


#ifndef ENT_H
#define ENT_H


#include <vector>
#include <string>
#include <typeinfo>
using namespace std;

#include "stackmachine.h"
#include "executionerror.h"
#include "stackelement.h"
#include "instruction.h"

class Ent : public Instruction
{
	public:
		Ent(int p, int q);
		~Ent();
		void execute(StackMachine *stack);
		ostream& print(ostream &os) const;	
	private:
		int fP;
		int fQ;
};


#endif
